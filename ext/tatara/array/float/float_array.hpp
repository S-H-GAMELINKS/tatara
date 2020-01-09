#ifndef FLOAT_ARRAY_HPP_
#define FLOAT_ARRAY_HPP_

#include <ruby.h>
#include <vector>
#include <algorithm>
#include <iterator>

static VALUE float_array_init(VALUE self) {
    return self;
}

static VALUE float_array_first(VALUE self) {
    return rb_ary_entry(self, 0);
}

static VALUE float_array_last(VALUE self) {
    const long length = RARRAY_LEN(self);
    if (length == 0) return Qnil;
    return rb_ary_entry(self, length - 1);
}

static VALUE float_array_bracket(VALUE self, VALUE index) {
    return rb_ary_entry(self, NUM2LONG(index));
}

static VALUE float_array_bracket_equal(VALUE self, VALUE index, VALUE value) {
    if (TYPE(value) == T_FLOAT) {
        long i = NUM2LONG(index);
        rb_ary_store(self, i, value);
        return value;
    }else if (FIXNUM_P(value)) {
        double val = NUM2DBL(value);
        long i = NUM2LONG(index);
        rb_ary_store(self, i, DBL2NUM(val));
        return self;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE float_array_push(VALUE self, VALUE value) {
    if (TYPE(value) == T_FLOAT) {
        rb_ary_push(self, value);
        return self;
    } else if (FIXNUM_P(value)) {
        double val = NUM2DBL(value);
        rb_ary_push(self, DBL2NUM(val));
        return self;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE float_array_size(VALUE self) {
    return LONG2NUM(RARRAY_LEN(self));
}

static VALUE float_array_clear(VALUE self) {
    rb_ary_clear(self);
    return self;
}

static VALUE float_array_map(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    VALUE collection = rb_obj_dup(self);

    for(int i = 0; i < size; i++) {
        VALUE val = float_array_bracket(self, INT2NUM(i));
        float_array_bracket_equal(collection, INT2NUM(i), rb_yield(val));
    }

    return collection;
}

static VALUE float_array_destructive_map(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    for(int i = 0; i < size; i++) {
        VALUE val = float_array_bracket(self, INT2NUM(i));
        float_array_bracket_equal(self, INT2NUM(i), rb_yield(val));
    }

    return self;
}

static VALUE float_array_each_with_index(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    VALUE collection = rb_obj_dup(self);

    for(int i = 0; i < size; i++) {
        VALUE val = float_array_bracket(self, INT2NUM(i));
        VALUE key_value = rb_ary_new2(2);
        rb_ary_push(key_value, val);
        rb_ary_push(key_value, INT2NUM(i));
        rb_ary_push(collection, rb_yield(key_value));
    }

    return collection;
}

static VALUE float_array_convert_array(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = float_array_bracket(self, INT2NUM(i));
        rb_ary_push(collection, val);
    }

    return collection;
}

static VALUE float_array_import_array(VALUE self, VALUE ary) {

    std::size_t size = RARRAY_LEN(ary);

    for(int i = 0; i < size; i++) {
        VALUE val = rb_ary_entry(ary, i);
        float_array_push(self, val);
    }

    return self;
}

static VALUE float_array_sum(VALUE self) {

    std::size_t size = RARRAY_LEN(self);

    double result = 0.0;

    for (int i = 0; i < size; i++) {
        VALUE val = float_array_bracket(self, INT2NUM(i));
        result += NUM2DBL(val);
    }
    
    return DBL2NUM(result);
}

static VALUE float_array_sort(VALUE self) {
    return rb_ary_sort(self);
}

extern "C" {
    void Init_float_array(VALUE mTatara) {
        VALUE rb_cFloatArray = rb_define_class_under(mTatara, "FloatArray", rb_cArray);

        rb_define_private_method(rb_cFloatArray, "initialize", float_array_init, 0);
        rb_define_method(rb_cFloatArray, "first", float_array_first, 0);
        rb_define_method(rb_cFloatArray, "last", float_array_last, 0);
        rb_define_method(rb_cFloatArray, "[]", float_array_bracket, 1);
        rb_define_method(rb_cFloatArray, "[]=", float_array_bracket_equal, 2);
        rb_define_method(rb_cFloatArray, "push", float_array_push, 1);
        rb_define_method(rb_cFloatArray, "size", float_array_size, 0);
        rb_define_method(rb_cFloatArray, "clear", float_array_clear, 0);
        rb_define_alias(rb_cFloatArray, "<<", "push");
        rb_define_method(rb_cFloatArray, "map", float_array_map, 0);
        rb_define_method(rb_cFloatArray, "map!", float_array_destructive_map, 0);
        rb_define_alias(rb_cFloatArray, "each", "map");
        rb_define_method(rb_cFloatArray, "each_with_index", float_array_each_with_index, 0);
        rb_define_method(rb_cFloatArray, "to_array", float_array_convert_array, 0);
        rb_define_method(rb_cFloatArray, "import_array", float_array_import_array, 1);
        rb_define_method(rb_cFloatArray, "sum", float_array_sum, 0);
        rb_define_method(rb_cFloatArray, "sort", float_array_sort, 0);
    }
}

#endif
