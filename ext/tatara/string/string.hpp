#ifndef STRING_H_
#define STRING_H_

#include <ruby.h>

static VALUE string_init(VALUE self) {
    rb_iv_set(self, "value", rb_str_new(0, 0));
    return self;
}

static VALUE string_return_value(VALUE self) {
    return rb_iv_get(self, "value");
}

static VALUE string_assignment(VALUE self, VALUE value) {
    if (TYPE(value) == T_STRING) {
        rb_iv_set(self, "value", value);
        return self;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Args type is %s !", rb_class_name(value));
        return self;
    }
}

static VALUE string_plus_equal(VALUE self, VALUE value) {
    if (TYPE(value) == T_STRING) {
        VALUE val = rb_iv_get(self, "value"); 
        rb_iv_set(self, "value", rb_str_plus(val, value));
        return self;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Args type is %s !", rb_class_name(value));
        return self;
    }
}

static VALUE string_to_integer(VALUE self) {
    VALUE str = rb_iv_get(self, "value");
    return rb_str_to_inum(str, 10, 0);
}

static VALUE string_to_float(VALUE self) {
    VALUE str = rb_iv_get(self, "value");
    return DBL2NUM(rb_str_to_dbl(str, 0));
}

static VALUE string_clear(VALUE self) {
    rb_iv_set(self, "value", rb_str_new(0, 0));
    return self;
}

static VALUE string_equal(VALUE self, VALUE value) {
    VALUE val = rb_iv_get(self, "value");
    return rb_str_equal(val, value);
}

static VALUE string_index_access(VALUE self, VALUE index) {
    const int i = NUM2INT(index);
    VALUE val = rb_iv_get(self, "value");
    return rb_str_substr(val, i, 1);
}

static VALUE string_slice(VALUE self, VALUE start, VALUE end) {
    const int s = NUM2INT(start);
    const int e = NUM2INT(end);
    VALUE val = rb_iv_get(self, "value");
    return rb_str_substr(val, s, (e - s));
}

static VALUE string_destructive_slice(VALUE self, VALUE start, VALUE end) {
    const int s = NUM2INT(start);
    const int e = NUM2INT(end);
    VALUE val = rb_iv_get(self, "value");
    VALUE result = rb_str_substr(val, s, (e - s));
    rb_iv_set(self, "value", result);
    return result;
} 

extern "C" {
    void Init_string(VALUE mTatara) {

        VALUE rb_cString = rb_define_class_under(mTatara, "String", rb_cObject);

        rb_define_private_method(rb_cString, "initialize", string_init, 0);
        rb_define_method(rb_cString, "value", string_return_value, 0);
        rb_define_alias(rb_cString, "val", "value");
        rb_define_method(rb_cString, "value=", string_assignment, 1);
        rb_define_alias(rb_cString, "val=", "value=");
        rb_define_method(rb_cString, "value+=", string_plus_equal, 1);
        rb_define_alias(rb_cString, "val+=", "value+=");
        rb_define_method(rb_cString, "to_i", string_to_integer, 0);
        rb_define_method(rb_cString, "to_f", string_to_float, 0);
        rb_define_method(rb_cString, "clear", string_clear, 0);
        rb_define_method(rb_cString, "value==", string_equal, 1);
        rb_define_alias(rb_cString, "val==", "value==");
        rb_define_alias(rb_cString, "equal?", "value==");
        rb_define_alias(rb_cString, "<<", "value=");
        rb_define_method(rb_cString, "[]", string_index_access, 1);
        rb_define_method(rb_cString, "slice", string_slice, 2);
        rb_define_method(rb_cString, "slice!", string_destructive_slice, 2);
    }
}

#endif
