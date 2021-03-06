#ifndef INTEGER_H_
#define INTEGER_H_

#include <ruby.h>
#include <string>
#include <cmath>
#include <iostream>

// Init Tatara::Integer instance
static VALUE int_init(VALUE self) {
    rb_ivar_set(self, rb_intern("value"), INT2NUM(0));
    return self;
}

// Get instance var 
static VALUE int_return_value(VALUE self) {
    return rb_ivar_get(self, rb_intern("value"));
}

// Set instance var
static VALUE int_assignment(VALUE self, VALUE value) {
    if (FIXNUM_P(value) || TYPE(value) == T_FLOAT) {
        rb_ivar_set(self, rb_intern("value"), value);
        return self;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

// Add instance var
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

// Add and Set instance var
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

// Subtract instance var
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

// Subtract and Set instance var
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

// Multiply instance var
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

// Multiply and Set instance var
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

// Mod instance var
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

// Mod and Set instance var
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

// Divide instance var
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

// Divide and Set instance var
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

// Power instance var
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

// Power and Set instance var
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

// Increment instance var
static VALUE int_increment_value(VALUE self) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));
    long result = NUM2INT(val);
    result++;
    rb_ivar_set(self, rb_intern("value"), INT2NUM(result));
    return self;
}

// Decrement instance var
static VALUE int_decrement_value(VALUE self) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));
    long result = NUM2INT(val);
    result--;
    rb_ivar_set(self, rb_intern("value"), INT2NUM(result));
    return self;
}

// Convert to String
static VALUE int_to_string(VALUE self) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));

    std::string result = std::to_string(NUM2INT(val));

    return rb_str_new(result.c_str(), result.size());
}

// Convert to Float
static VALUE int_to_float(VALUE self) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));
    double result = NUM2DBL(val);
    return DBL2NUM(result);
}

// Clear instance var
static VALUE int_clear(VALUE self) {
    rb_ivar_set(self, rb_intern("value"), INT2NUM(0));
    return self;
}

// Check instance var is equal
static VALUE int_equal(VALUE self, VALUE other) {
    VALUE val = rb_ivar_get(self, rb_intern("value"));
    return rb_equal(val, other);
}

// Add Tatara::Integer instance
static VALUE int_object_plus(VALUE self, VALUE other) {
    if(TYPE(other) == TYPE(self)) {
        VALUE dup = rb_obj_dup(self);
        VALUE result = int_plus(self, rb_ivar_get(other, rb_intern("value")));
        rb_ivar_set(dup, rb_intern("value"), result);
        return dup;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(other));
        return Qnil;
    }
}

// Subtract Tatara::Integer instance
static VALUE int_object_minus(VALUE self, VALUE other) {
    if (TYPE(self) == TYPE(other)) {
        VALUE dup = rb_obj_dup(self);
        VALUE result = int_minus(self, rb_ivar_get(other, rb_intern("value")));
        rb_ivar_set(dup, rb_intern("value"), result);
        return dup;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(other));
        return Qnil;
    }
}

// Multiply Tatara::Integer instance
static VALUE int_object_multiply(VALUE self, VALUE other) {
    if (TYPE(self) == TYPE(other)) {
        VALUE dup = rb_obj_dup(self);
        VALUE result = int_multiply(self, rb_ivar_get(other, rb_intern("value")));
        rb_ivar_set(dup, rb_intern("value"), result);
        return dup;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(other));
        return Qnil;
    }
}

// Divide Tatara::Integer instance
static VALUE int_object_divided(VALUE self, VALUE other) {
    if (TYPE(self) == TYPE(other)) {
        VALUE dup = rb_obj_dup(self);
        VALUE result = int_divided(self, rb_ivar_get(other, rb_intern("value")));
        rb_ivar_set(dup, rb_intern("value"), result);
        return dup;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(other));
        return Qnil;
    }
}

// Power Tatara::Integer instance
static VALUE int_object_power(VALUE self, VALUE other) {
    if (TYPE(self) == TYPE(other)) {
        VALUE dup = rb_obj_dup(self);
        VALUE result = int_power(self, rb_ivar_get(other, rb_intern("value")));
        rb_ivar_set(dup, rb_intern("value"), result);
        return dup;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(other));
        return Qnil;
    }
}

// Mod Tatara::Integer instance
static VALUE int_object_mod(VALUE self, VALUE other) {
    if (TYPE(self) == TYPE(other)) {
        VALUE dup = rb_obj_dup(self);
        VALUE result = int_mod(self, rb_ivar_get(other, rb_intern("value")));
        rb_ivar_set(dup, rb_intern("value"), result);
        return dup;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(other));
        return Qnil;
    }
}

extern "C" {
    inline void Init_integer(VALUE mTatara) {
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
        rb_define_method(rb_cInteger, "+", int_object_plus, 1);
        rb_define_method(rb_cInteger, "-", int_object_minus, 1);
        rb_define_method(rb_cInteger, "*", int_object_multiply, 1);
        rb_define_method(rb_cInteger, "/", int_object_divided, 1);
        rb_define_method(rb_cInteger, "**", int_object_power, 1);
        rb_define_method(rb_cInteger, "%", int_object_mod, 1);
    }
}

#endif