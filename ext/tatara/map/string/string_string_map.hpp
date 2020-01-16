#ifndef STRING_STRING_MAP_HPP_
#define STRING_STRING_MAP_HPP_

#include <ruby.h>

bool string_string_check_key(VALUE key) {
    if (TYPE(key) == T_STRING)
        return true;
    else
        return false;
}

bool string_string_check_value(VALUE value) {
    if (TYPE(value) == T_STRING)
        return true;
    else
        return false;
}

static VALUE string_string_map_bracket(VALUE self, VALUE key) {
    if (string_string_check_key(key)) {
        return rb_hash_aref(self, key);
    } else {
        rb_raise(rb_eTypeError, "Worng Type Key! %s", rb_obj_classname(key));
        return self;
    }
}

static VALUE string_string_map_bracket_equal(VALUE self, VALUE key, VALUE value) {

    if (!string_string_check_key(key))
        rb_raise(rb_eTypeError, "Worng Type Key! %s", rb_obj_classname(key));

    if (!string_string_check_value(value))
        rb_raise(rb_eTypeError, "Worng Type Value! %s", rb_obj_classname(value));

    rb_hash_aset(self, key, value);

    return value;
}

extern "C" {
    inline void Init_string_string_map(VALUE mTatara) {

        VALUE rb_cStringStringMap = rb_define_class_under(mTatara, "StringStringMap", rb_cHash);

        rb_define_method(rb_cStringStringMap, "[]", string_string_map_bracket, 1);
        rb_define_method(rb_cStringStringMap, "[]=", string_string_map_bracket_equal, 2);
        rb_define_alias(rb_cStringStringMap, "insert", "[]=");
    }
}

#endif