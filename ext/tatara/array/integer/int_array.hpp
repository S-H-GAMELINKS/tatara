#ifndef INT_ARRAY_HPP_
#define INT_ARRAY_HPP_

#include <ruby.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

static VALUE int_array_init(VALUE self) {
    return self;
}

static VALUE int_array_first(VALUE self) {
    return rb_ary_entry(self, 0);
}

static VALUE int_array_last(VALUE self) {
    const long length = RARRAY_LEN(self);
    if (length == 0) return Qnil;
    return rb_ary_entry(self, length - 1);
}

static VALUE int_array_bracket(VALUE self, VALUE index) {
    return rb_ary_entry(self, NUM2LONG(index));
}

static VALUE int_array_bracket_equal(VALUE self, VALUE index, VALUE value) {
    if (FIXNUM_P(value)) {
        long i = NUM2LONG(index);
        rb_ary_store(self, i, value);
        return value;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_array_push(VALUE self, VALUE value) {
    if (FIXNUM_P(value)) {
        rb_ary_push(self, value);
        return self;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_array_size(VALUE self) {
    return LONG2NUM(RARRAY_LEN(self));
}

static VALUE int_array_clear(VALUE self) {
    rb_ary_clear(self);
    return self;
}

static VALUE int_array_map(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    VALUE collection = rb_obj_dup(self);

    for(int i = 0; i < size; i++) {
        VALUE val = int_array_bracket(self, INT2NUM(i));
        int_array_bracket_equal(collection, INT2NUM(i), rb_yield(val));
    }

    return collection;
}

static VALUE int_array_destructive_map(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    for(int i = 0; i < size; i++) {
        VALUE val = int_array_bracket(self, INT2NUM(i));
        int_array_bracket_equal(self, INT2NUM(i), rb_yield(val));
    }

    return self;
}

static VALUE int_array_each_with_index(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    VALUE collection = rb_obj_dup(self);

    for(int i = 0; i < size; i++) {
        VALUE val = int_array_bracket(self, INT2NUM(i));
        VALUE key_value = rb_ary_new2(2);
        rb_ary_push(key_value, val);
        rb_ary_push(key_value, INT2NUM(i));
        rb_ary_push(collection, rb_yield(key_value));
    }

    return collection;
}

static VALUE int_array_convert_array(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = int_array_bracket(self, INT2NUM(i));
        rb_ary_push(collection, val);
    }

    return collection;
}

static VALUE int_array_import_array(VALUE self, VALUE ary) {

    std::size_t size = RARRAY_LEN(ary);

    for(int i = 0; i < size; i++) {
        VALUE val = rb_ary_entry(ary, i);
        int_array_push(self, val);
    }

    return self;
}

static VALUE int_array_sum(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    long result = 0;

    for (int i = 0; i < size; i++) {
        VALUE val = int_array_bracket(self, INT2NUM(i));
        result += NUM2LONG(val);
    }
    
    return LONG2NUM(result);
}

static VALUE int_array_sort(VALUE self) {
    return rb_ary_sort(self);
}

extern "C" {
    inline void Init_int_array(VALUE mTatara) {
        VALUE rb_cIntArray = rb_define_class_under(mTatara, "IntArray", rb_cArray);

        rb_define_private_method(rb_cIntArray, "initialize", int_array_init, 0);
        rb_define_method(rb_cIntArray, "first", int_array_first, 0);
        rb_define_method(rb_cIntArray, "last", int_array_last, 0);
        rb_define_method(rb_cIntArray, "[]", int_array_bracket, 1);
        rb_define_method(rb_cIntArray, "[]=", int_array_bracket_equal, 2);
        rb_define_method(rb_cIntArray, "push", int_array_push, 1);
        rb_define_method(rb_cIntArray, "size", int_array_size, 0);
        rb_define_method(rb_cIntArray, "clear", int_array_clear, 0);
        rb_define_alias(rb_cIntArray, "<<", "push");
        rb_define_method(rb_cIntArray, "map", int_array_map, 0);
        rb_define_method(rb_cIntArray, "map!", int_array_destructive_map, 0);
        rb_define_alias(rb_cIntArray, "each", "map");
        rb_define_method(rb_cIntArray, "each_with_index", int_array_each_with_index, 0);
        rb_define_method(rb_cIntArray, "to_array", int_array_convert_array, 0);
        rb_define_method(rb_cIntArray, "import_array", int_array_import_array, 1);
        rb_define_method(rb_cIntArray, "sum", int_array_sum, 0);
        rb_define_method(rb_cIntArray, "sort", int_array_sort, 0);
    }
}

#endif
