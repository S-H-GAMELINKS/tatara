#ifndef INTEGER_H_
#define INTEGER_H_

#include <ruby.h>
#include <string>
#include <cmath>
#include <iostream>

static VALUE int_init(VALUE self) {
    rb_ivar_set(self, rb_intern("value"), INT2NUM(0));
    return self;
}

static VALUE int_return_value(VALUE self) {
    return rb_ivar_get(self, rb_intern("value"));
}


static VALUE int_assignment(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        rb_ivar_set(self, rb_intern("value"), value);
        return self;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_plus(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        long result = NUM2INT(ivar) + NUM2INT(value);
        return INT2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_plus_equal(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        long result = NUM2INT(ivar) + NUM2INT(value);
        rb_ivar_set(self, rb_intern("value"), INT2NUM(result));
        return INT2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_minus(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        long result = NUM2INT(ivar) - NUM2INT(value);
        return INT2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_minus_equal(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        long result = NUM2INT(ivar) - NUM2INT(value);
        rb_ivar_set(self, rb_intern("value"), INT2NUM(result));
        return INT2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_multiply(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        long result = NUM2INT(ivar) * NUM2INT(value);
        return INT2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_multiply_equal(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        long result = NUM2INT(ivar) * NUM2INT(value);
        rb_ivar_set(self, rb_intern("value"), INT2NUM(result));
        return INT2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_mod(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        long result = NUM2INT(ivar) % NUM2INT(value);
        return INT2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_mod_equal(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        long result = NUM2INT(ivar) % NUM2INT(value);
        rb_ivar_set(self, rb_intern("value"), INT2NUM(result));
        return INT2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_divided(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        long result = NUM2INT(ivar) / NUM2INT(value);
        return INT2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_divided_equal(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        long result = NUM2INT(ivar) / NUM2INT(value);
        rb_ivar_set(self, rb_intern("value"), INT2NUM(result));
        return INT2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_power(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        long result = std::pow(NUM2INT(ivar), NUM2INT(value));
        return INT2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_power_equal(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        VALUE ivar = rb_ivar_get(self, rb_intern("value"));
        long result = std::pow(NUM2INT(ivar), NUM2INT(value));
        rb_ivar_set(self, rb_intern("value"), INT2NUM(result));
        return INT2NUM(result);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE int_increment_value(VALUE self) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));
    long result = NUM2INT(val);
    result++;
    rb_ivar_set(self, rb_intern("value"), INT2NUM(result));
    return self;
}

static VALUE int_decrement_value(VALUE self) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));
    long result = NUM2INT(val);
    result--;
    rb_ivar_set(self, rb_intern("value"), INT2NUM(result));
    return self;
}

static VALUE int_to_string(VALUE self) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));

    std::string result = std::to_string(NUM2INT(val));

    return rb_str_new(result.c_str(), result.size());
}

static VALUE int_to_float(VALUE self) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));
    double result = NUM2DBL(val);
    return DBL2NUM(result);
}

static VALUE int_clear(VALUE self) {
    rb_ivar_set(self, rb_intern("value"), INT2NUM(0));
    return self;
}

static VALUE int_equal(VALUE self, VALUE other) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));
    return rb_equal(val, other);
}

extern "C" {
    void Init_integer(VALUE mTatara) {
        VALUE rb_cInteger = rb_define_class_under(mTatara, "Integer", rb_cObject);

        rb_define_private_method(rb_cInteger, "initialize", int_init, 0);
        rb_define_method(rb_cInteger, "value", int_return_value, 0);
        rb_define_alias(rb_cInteger, "val", "value");
        rb_define_method(rb_cInteger, "value=", int_assignment, 1);
        rb_define_alias(rb_cInteger, "val=", "value=");
        rb_define_method(rb_cInteger, "value+", int_plus, 1);
        rb_define_alias(rb_cInteger, "val+", "value+");
        rb_define_method(rb_cInteger, "value+=", int_plus_equal, 1);
        rb_define_alias(rb_cInteger, "val+=", "value+=");
        rb_define_method(rb_cInteger, "value-", int_minus, 1);
        rb_define_alias(rb_cInteger, "val-", "value-");
        rb_define_method(rb_cInteger, "value-=", int_minus_equal, 1);
        rb_define_alias(rb_cInteger, "val-=", "value-=");
        rb_define_method(rb_cInteger, "value/", int_divided, 1);
        rb_define_alias(rb_cInteger, "val/", "value/");
        rb_define_method(rb_cInteger, "value/=", int_divided_equal, 1);
        rb_define_alias(rb_cInteger, "val/=", "value/=");
        rb_define_method(rb_cInteger, "value*", int_multiply, 1);
        rb_define_alias(rb_cInteger, "val*", "value*");
        rb_define_method(rb_cInteger, "value*=", int_multiply_equal, 1);
        rb_define_alias(rb_cInteger, "val*=", "value*=");
        rb_define_method(rb_cInteger, "value%", int_mod, 1);
        rb_define_alias(rb_cInteger, "val%", "value%");
        rb_define_method(rb_cInteger, "value%=", int_mod_equal, 1);
        rb_define_alias(rb_cInteger, "val%=", "value%=");
        rb_define_method(rb_cInteger, "value**", int_power, 1);
        rb_define_alias(rb_cInteger, "val**", "value**");
        rb_define_method(rb_cInteger, "value**=", int_power_equal, 1);
        rb_define_alias(rb_cInteger, "val**=", "value**=");
        rb_define_method(rb_cInteger, "increment", int_increment_value, 0);
        rb_define_alias(rb_cInteger, "inc", "increment");
        rb_define_method(rb_cInteger, "decrement", int_decrement_value, 0);
        rb_define_alias(rb_cInteger, "dec", "decrement");
        rb_define_method(rb_cInteger, "to_s", int_to_string, 0);
        rb_define_method(rb_cInteger, "to_f", int_to_float, 0);
        rb_define_method(rb_cInteger, "clear", int_clear, 0);
        rb_define_method(rb_cInteger, "value==", int_equal, 1);
        rb_define_alias(rb_cInteger, "val==", "value==");
        rb_define_alias(rb_cInteger, "equal?", "value==");
        rb_define_alias(rb_cInteger, "<<", "value=");
    }
}

#endif