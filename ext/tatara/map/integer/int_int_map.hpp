#ifndef INT_INT_MAP_HPP_
#define INT_INT_MAP_HPP_

#include <ruby.h>

constexpr bool int_int_check_key(VALUE key) {
    if (FIXNUM_P(key))
        return true;
    else
        return false;
}

constexpr bool int_int_check_value(VALUE value) {
    if (FIXNUM_P(value))
        return true;
    else
        return false;
}

static VALUE int_int_map_bracket(VALUE self, VALUE key) {
    if (int_int_check_key(key)) {
        return rb_hash_aref(self, key);
    } else {
        rb_raise(rb_eTypeError, "Worng Type Key! %s", rb_obj_classname(key));
        return self;
    }
}

static VALUE int_int_map_bracket_equal(VALUE self, VALUE key, VALUE value) {

    if (!int_int_check_key(key))
        rb_raise(rb_eTypeError, "Worng Type Key! %s", rb_obj_classname(key));

    if (!int_int_check_value(value))
        rb_raise(rb_eTypeError, "Worng Type Value! %s", rb_obj_classname(value));

    rb_hash_aset(self, key, value);

    return value;
}

extern "C" {
    void Init_int_int_map(VALUE mTatara) {

        VALUE rb_cIntIntMap = rb_define_class_under(mTatara, "IntIntMap", rb_cHash);

        rb_define_method(rb_cIntIntMap, "[]", int_int_map_bracket, 1);
        rb_define_method(rb_cIntIntMap, "[]=", int_int_map_bracket_equal, 2);
        rb_define_alias(rb_cIntIntMap, "insert", "[]=");
    }
}

#endif