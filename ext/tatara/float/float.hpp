#ifndef FLOAT_H_
#define FLOAT_H_

#include <ruby.h>
#include <cmath>
#include <string>
#include <regex>

static VALUE float_init(VALUE self) {
    rb_ivar_set(self, rb_intern("value"), DBL2NUM(0.0));
    return self;
}

static VALUE float_return_value(VALUE self) {
    return rb_ivar_get(self, rb_intern("value"));
}

static VALUE float_assignment(VALUE self, VALUE value) {
    if (TYPE(value) == T_FLOAT) {
        rb_ivar_set(self, rb_intern("value"), value);
        return self;
    } else if (FIXNUM_P(value)) {
        double val = NUM2DBL(value);
        rb_ivar_set(self, rb_intern("value"), DBL2NUM(val));
        return self;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE float_plus(VALUE self, VALUE value) {
    if (TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) + NUM2DBL(value);
        return DBL2NUM(result);
    } else if (FIXNUM_P(value)) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) + NUM2DBL(value);
        return DBL2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE float_plus_equal(VALUE self, VALUE value) {
    if (TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) + NUM2DBL(value);
        rb_ivar_set(self, rb_intern("value"), DBL2NUM(result));
        return DBL2NUM(result);
    } else if (FIXNUM_P(value)) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) + NUM2DBL(value);
        rb_ivar_set(self, rb_intern("value"), DBL2NUM(result));
        return DBL2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE float_minus(VALUE self, VALUE value) {
    if (TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) - NUM2DBL(value);
        return DBL2NUM(result);
    } else if (FIXNUM_P(value)) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) - NUM2DBL(value);
        return DBL2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE float_minus_equal(VALUE self, VALUE value) {
    if (TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) - NUM2DBL(value);
        rb_ivar_set(self, rb_intern("value"), DBL2NUM(result));
        return DBL2NUM(result);
    } else if (FIXNUM_P(value)) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) - NUM2DBL(value);
        rb_ivar_set(self, rb_intern("value"), DBL2NUM(result));
        return DBL2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE float_multiply(VALUE self, VALUE value) {
    if (TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) * NUM2DBL(value);
        return DBL2NUM(result);
    } else if (FIXNUM_P(value)) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) * NUM2DBL(value);
        return DBL2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE float_multiply_equal(VALUE self, VALUE value) {
    if (TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) * NUM2DBL(value);
        rb_ivar_set(self, rb_intern("value"), DBL2NUM(result));
        return DBL2NUM(result);
    } else if (FIXNUM_P(value)) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) * NUM2DBL(value);
        rb_ivar_set(self, rb_intern("value"), DBL2NUM(result));
        return DBL2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE float_divided(VALUE self, VALUE value) {
    if (TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) / NUM2DBL(value);
        return DBL2NUM(result);
    } else if (FIXNUM_P(value)) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) / NUM2DBL(value);
        return DBL2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE float_divided_equal(VALUE self, VALUE value) {
    if (TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) / NUM2DBL(value);
        rb_ivar_set(self, rb_intern("value"), DBL2NUM(result));
        return DBL2NUM(result);
    } else if (FIXNUM_P(value)) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = NUM2DBL(ivar) / NUM2DBL(value);
        rb_ivar_set(self, rb_intern("value"), DBL2NUM(result));
        return DBL2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE float_power(VALUE self, VALUE value) {
    if (TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = std::pow(NUM2DBL(ivar), NUM2DBL(value));
        return DBL2NUM(result);
    } else if (FIXNUM_P(value)) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = std::pow(NUM2DBL(ivar), NUM2DBL(value));
        return DBL2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE float_power_equal(VALUE self, VALUE value) {
    if (TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = std::pow(NUM2DBL(ivar), NUM2DBL(value));
        rb_ivar_set(self, rb_intern("value"), DBL2NUM(result));
        return DBL2NUM(result);
    } else if (FIXNUM_P(value)) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        double result = std::pow(NUM2DBL(ivar), NUM2DBL(value));
        rb_ivar_set(self, rb_intern("value"), DBL2NUM(result));
        return DBL2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE float_increment_value(VALUE self) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));
    double result = NUM2DBL(val);
    result++;
    rb_ivar_set(self, rb_intern("value"), DBL2NUM(result));
    return self;
}

static VALUE float_decrement_value(VALUE self) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));
    double result = NUM2DBL(val);
    result--;
    rb_ivar_set(self, rb_intern("value"), DBL2NUM(result));
    return self;
}

static VALUE float_to_string(VALUE self) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));

    std::string null = "";

    std::regex re("0+");

    std::string result = std::regex_replace(std::to_string(NUM2DBL(val)), re, null);

    return rb_str_new(result.c_str(), result.size());
}

static VALUE float_to_integer(VALUE self) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));
    long result = NUM2LONG(val);
    return LONG2NUM(result);
}

static VALUE float_clear(VALUE self) {
    rb_ivar_set(self, rb_intern("value"), DBL2NUM(0.0));
    return self;
}

static VALUE float_equal(VALUE self, VALUE other) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));
    return rb_equal(val, other);
}

extern "C" {
    void Init_float(VALUE mTatara) {
        VALUE rb_cFloat = rb_define_class_under(mTatara, "Float", rb_cObject);

        rb_define_private_method(rb_cFloat, "initialize", float_init, 0);
        rb_define_method(rb_cFloat, "value", float_return_value, 0);
        rb_define_alias(rb_cFloat, "val", "value");
        rb_define_method(rb_cFloat, "value=", float_assignment, 1);
        rb_define_alias(rb_cFloat, "val=", "value=");
        rb_define_method(rb_cFloat, "value+", float_plus, 1);
        rb_define_alias(rb_cFloat, "val+", "value+");
        rb_define_method(rb_cFloat, "value+=", float_plus_equal, 1);
        rb_define_alias(rb_cFloat, "val+=", "value+=");
        rb_define_method(rb_cFloat, "value-", float_minus, 1);
        rb_define_alias(rb_cFloat, "val-", "value-");
        rb_define_method(rb_cFloat, "value-=", float_minus_equal, 1);
        rb_define_alias(rb_cFloat, "val-=", "value-=");
        rb_define_method(rb_cFloat, "value*", float_multiply, 1);
        rb_define_alias(rb_cFloat, "val*", "value*");
        rb_define_method(rb_cFloat, "value*=", float_multiply_equal, 1);
        rb_define_alias(rb_cFloat, "val*=", "value*=");
        rb_define_method(rb_cFloat, "value/", float_divided, 1);
        rb_define_alias(rb_cFloat, "val/", "value/");
        rb_define_method(rb_cFloat, "value/=", float_divided_equal, 1);
        rb_define_alias(rb_cFloat, "val/=", "value/=");
        rb_define_method(rb_cFloat, "value**", float_power, 1);
        rb_define_alias(rb_cFloat, "val**", "value**");
        rb_define_method(rb_cFloat, "value**=", float_power_equal, 1);
        rb_define_alias(rb_cFloat, "val**=", "value**=");
        rb_define_method(rb_cFloat, "inc", float_increment_value, 0);
        rb_define_method(rb_cFloat, "dec", float_decrement_value, 0);
        rb_define_method(rb_cFloat, "to_s", float_to_string, 0);
        rb_define_method(rb_cFloat, "to_i", float_to_integer, 0);
        rb_define_method(rb_cFloat, "clear", float_clear, 0);
        rb_define_method(rb_cFloat, "value==", float_equal, 1);
        rb_define_alias(rb_cFloat, "val==", "value==");
        rb_define_alias(rb_cFloat, "equal?", "value==");
        rb_define_alias(rb_cFloat, "<<", "value=");
    }
}

#endif