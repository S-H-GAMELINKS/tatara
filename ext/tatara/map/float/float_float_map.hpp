#ifndef FLOAT_FLOAT_MAP_HPP_
#define FLOAT_FLOAT_MAP_HPP_

#include <ruby.h>

bool float_float_check_key(VALUE key) {
    if (TYPE(key) == T_FLOAT)
        return true;
    else
        return false;
}

bool float_float_check_value(VALUE value) {
    if (TYPE(value) == T_FLOAT)
        return true;
    else
        return false;
}

static VALUE float_float_map_bracket(VALUE self, VALUE key) {
    if (float_float_check_key(key)) {
        return rb_hash_aref(self, key);
    } else {
        rb_raise(rb_eTypeError, "Worng Type Key! %s", rb_obj_classname(key));
        return self;
    }
}

static VALUE float_float_map_bracket_equal(VALUE self, VALUE key, VALUE value) {

    if (!float_float_check_key(key))
        rb_raise(rb_eTypeError, "Worng Type Key! %s", rb_obj_classname(key));

    if (!float_float_check_value(value))
        rb_raise(rb_eTypeError, "Worng Type Value! %s", rb_obj_classname(value));

    rb_hash_aset(self, key, value);

    return value;
}

extern "C" {
    void Init_float_float_map(VALUE mTatara) {

        VALUE rb_cFloatFloatMap = rb_define_class_under(mTatara, "FloatFloatMap", rb_cHash);

        rb_define_method(rb_cFloatFloatMap, "[]", float_float_map_bracket, 1);
        rb_define_method(rb_cFloatFloatMap, "[]=", float_float_map_bracket_equal, 2);
        rb_define_alias(rb_cFloatFloatMap, "insert", "[]=");
    }
}

#endif