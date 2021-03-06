#ifndef STRING_ARRAY_HPP_
#define STRING_ARRAY_HPP_

#include <ruby.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

static VALUE string_array_init(VALUE self) {
    return self;
}

static VALUE string_array_first(VALUE self) {
    return rb_ary_entry(self, 0);
}

static VALUE string_array_last(VALUE self) {
    const long length = RARRAY_LEN(self);
    if (length == 0) return Qnil;
    return rb_ary_entry(self, length - 1);
}

static VALUE string_array_bracket(VALUE self, VALUE index) {
    return rb_ary_entry(self, NUM2LONG(index));
}

static VALUE string_array_bracket_equal(VALUE self, VALUE index, VALUE value) {
    if (TYPE(value) == T_STRING) {
        long i = NUM2LONG(index);
        rb_ary_store(self, i, value);
        return value;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE string_array_push(VALUE self, VALUE value) {
    if (TYPE(value) == T_STRING) {
        rb_ary_push(self, value);
        return self;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE string_array_size(VALUE self) {
    return LONG2NUM(RARRAY_LEN(self));
}

static VALUE string_array_clear(VALUE self) {
    rb_ary_clear(self);
    return self;
}

static VALUE string_array_map(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    VALUE collection = rb_obj_dup(self);

    for(int i = 0; i < size; i++) {
        VALUE val = string_array_bracket(self, INT2NUM(i));
        string_array_bracket_equal(collection, INT2NUM(i), rb_yield(val));
    }

    return collection;
}

static VALUE string_array_destructive_map(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    for(int i = 0; i < size; i++) {
        VALUE val = string_array_bracket(self, INT2NUM(i));
        string_array_bracket_equal(self, INT2NUM(i), rb_yield(val));
    }

    return self;
}

static VALUE string_array_each_with_index(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    VALUE collection = rb_obj_dup(self);

    for(int i = 0; i < size; i++) {
        VALUE val = string_array_bracket(self, INT2NUM(i));
        VALUE key_value = rb_ary_new2(2);
        rb_ary_push(key_value, val);
        rb_ary_push(key_value, INT2NUM(i));
        rb_ary_push(collection, rb_yield(key_value));
    }

    return collection;
}

static VALUE string_array_convert_array(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = string_array_bracket(self, INT2NUM(i));
        rb_ary_push(collection, val);
    }

    return collection;
}

static VALUE string_array_import_array(VALUE self, VALUE ary) {

    std::size_t size = RARRAY_LEN(ary);

    for(int i = 0; i < size; i++) {
        VALUE val = rb_ary_entry(ary, i);
        string_array_push(self, val);
    }

    return self;
}

static VALUE string_array_sum(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    VALUE result = rb_str_new(0, 0);

    for (int i = 0; i < size; i++) {
        VALUE val = string_array_bracket(self, INT2NUM(i));
        result = rb_str_plus(result, val);
    }
    
    return result;
}

static VALUE string_array_sort(VALUE self) {
    return rb_ary_sort(self);
}

extern "C" {
    inline void Init_string_array(VALUE mTatara) {
        VALUE rb_cStringArray = rb_define_class_under(mTatara, "StringArray", rb_cArray);

        rb_define_private_method(rb_cStringArray, "initialize", string_array_init, 0);
        rb_define_method(rb_cStringArray, "first", string_array_first, 0);
        rb_define_method(rb_cStringArray, "last", string_array_last, 0);
        rb_define_method(rb_cStringArray, "[]", string_array_bracket, 1);
        rb_define_method(rb_cStringArray, "[]=", string_array_bracket_equal, 2);
        rb_define_method(rb_cStringArray, "push", string_array_push, 1);
        rb_define_method(rb_cStringArray, "size", string_array_size, 0);
        rb_define_method(rb_cStringArray, "clear", string_array_clear, 0);
        rb_define_alias(rb_cStringArray, "<<", "push");
        rb_define_method(rb_cStringArray, "map", string_array_map, 0);
        rb_define_method(rb_cStringArray, "map!", string_array_destructive_map, 0);
        rb_define_alias(rb_cStringArray, "each", "map");
        rb_define_method(rb_cStringArray, "each_with_index", string_array_each_with_index, 0);
        rb_define_method(rb_cStringArray, "to_array", string_array_convert_array, 0);
        rb_define_method(rb_cStringArray, "import_array", string_array_import_array, 1);
        rb_define_method(rb_cStringArray, "sum", string_array_sum, 0);
        rb_define_method(rb_cStringArray, "sort", string_array_sort, 0);
    }
}

#endif
