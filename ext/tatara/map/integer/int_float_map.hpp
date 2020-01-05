#ifndef INT_FLOAT_MAP_HPP_
#define INT_FLOAT_MAP_HPP_

#include <ruby.h>

constexpr bool int_float_check_key(VALUE key) {
    if (FIXNUM_P(key))
        return true;
    else
        return false;
}

bool int_float_check_value(VALUE value) {
    if (TYPE(value) == T_FLOAT)
        return true;
    else
        return false;
}

static VALUE int_float_map_bracket(VALUE self, VALUE key) {
    if (int_float_check_key(key)) {
        return rb_hash_aref(self, key);
    } else {
        rb_raise(rb_eTypeError, "Worng Type Key! %s", rb_obj_classname(key));
        return self;
    }
}

static VALUE int_float_map_bracket_equal(VALUE self, VALUE key, VALUE value) {

    if (!int_float_check_key(key))
        rb_raise(rb_eTypeError, "Worng Type Key! %s", rb_obj_classname(key));

    if (!int_float_check_value(value))
        rb_raise(rb_eTypeError, "Worng Type Value! %s", rb_obj_classname(key));

    rb_hash_aset(self, key, value);

    return value;
}

extern "C" {
    void Init_int_float_map(VALUE mTatara) {

        VALUE rb_cIntFloatMap = rb_define_class_under(mTatara, "IntFloatMap", rb_cHash);

        rb_define_method(rb_cIntFloatMap, "[]", int_float_map_bracket, 1);
        rb_define_method(rb_cIntFloatMap, "[]=", int_float_map_bracket_equal, 2);
        rb_define_alias(rb_cIntFloatMap, "insert", "[]=");
    }
}

#endif