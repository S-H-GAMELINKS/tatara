#ifndef ANY_H_
#define ANY_H_

#include <ruby.h>

static VALUE any_init(VALUE self) {
    rb_ivar_set(self, rb_intern("value"), Qnil);
    return self;
}

static VALUE any_return_value(VALUE self) {
    return rb_ivar_get(self, rb_intern("value"));
}

static VALUE any_assignment(VALUE self, VALUE value) {
    rb_ivar_set(self, rb_intern("value"), value);
    return value;
}

static VALUE any_plus(VALUE self, VALUE value) {
    VALUE ivar = any_return_value(self);

    if (FIXNUM_P(ivar) && FIXNUM_P(value)) {
        long result = NUM2INT(ivar) + NUM2INT(value);
        return INT2NUM(result);
    } else if (TYPE(ivar) == T_FLOAT && TYPE(ivar) == T_FLOAT) {
        double result = NUM2DBL(ivar) + NUM2DBL(value);
        return DBL2NUM(result);
    } else if (TYPE(ivar) == T_STRING && TYPE(value) == T_STRING) {
        return rb_str_plus(ivar, value);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE any_minus(VALUE self, VALUE value) {
    VALUE ivar = rb_ivar_get(self, rb_intern("value"));

    if (FIXNUM_P(ivar) && FIXNUM_P(value)) {
        long result = NUM2INT(ivar) + NUM2INT(value);
        return INT2NUM(result);
    } else if (TYPE(ivar) == T_FLOAT && TYPE(ivar) == T_FLOAT) {
        double result = NUM2DBL(ivar) + NUM2DBL(value);
        return DBL2NUM(result);
    } else if (TYPE(ivar) == T_STRING && TYPE(value) == T_STRING) {
        rb_raise(rb_eNoMethodError, "No operator minus for String!!");
        return rb_str_plus(ivar, value);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE any_multiply(VALUE self, VALUE value) {
    VALUE ivar = rb_ivar_get(self, rb_intern("value"));

    if (FIXNUM_P(ivar) && FIXNUM_P(value)) {
        long result = NUM2INT(ivar) + NUM2INT(value);
        return INT2NUM(result);
    } else if (TYPE(ivar) == T_FLOAT && TYPE(ivar) == T_FLOAT) {
        double result = NUM2DBL(ivar) + NUM2DBL(value);
        return DBL2NUM(result);
    } else if (TYPE(ivar) == T_STRING && TYPE(value) == T_STRING) {
        rb_raise(rb_eTypeError, "No operator minus for String!!");
        return rb_str_plus(ivar, value);
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE any_divided(VALUE self, VALUE value) {
    VALUE ivar = rb_ivar_get(self, rb_intern("value"));

    if (FIXNUM_P(ivar) && FIXNUM_P(value)) {
        long result = NUM2INT(ivar) / NUM2INT(value);
        return INT2NUM(result);
    } else if (TYPE(ivar) == T_FLOAT && TYPE(ivar) == T_FLOAT) {
        double result = NUM2DBL(ivar) / NUM2DBL(value);
        return DBL2NUM(result);
    } else if (TYPE(ivar) == T_STRING && TYPE(value) == T_STRING) {
        rb_raise(rb_eTypeError, "No operator minus for String!!");
        return Qnil;
    } else {
        return ivar;
    }
}

static VALUE any_mod(VALUE self, VALUE value) {
    VALUE ivar = rb_ivar_get(self, rb_intern("value"));

    if (FIXNUM_P(ivar) && FIXNUM_P(value)) {
        long result = NUM2INT(ivar) % NUM2INT(value);
        return INT2NUM(result);
    } else if (TYPE(ivar) == T_FLOAT && TYPE(ivar) == T_FLOAT) {
        double result = std::fmod(NUM2DBL(ivar), NUM2DBL(value));
        return DBL2NUM(result);
    } else if (TYPE(ivar) == T_STRING && TYPE(value) == T_STRING) {
        rb_raise(rb_eTypeError, "No operator minus for String!!");
        return Qnil;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

static VALUE any_power  (VALUE self, VALUE value) {
    VALUE ivar = rb_ivar_get(self, rb_intern("value"));

    if (FIXNUM_P(ivar) && FIXNUM_P(value)) {
        long result = std::pow(NUM2INT(ivar), NUM2INT(value));
        return INT2NUM(result);
    } else if (TYPE(ivar) == T_FLOAT && TYPE(ivar) == T_FLOAT) {
        double result = std::pow(NUM2DBL(ivar), NUM2DBL(value));
        return DBL2NUM(result);
    } else if (TYPE(ivar) == T_STRING && TYPE(value) == T_STRING) {
        rb_raise(rb_eNoMethodError, "No operator power for String!!");
        return Qnil;
    } else {
        rb_raise(rb_eTypeError, "Worng Type! This Value type is %s !", rb_class_name(value));
        return Qnil;
    }
}

extern "C" {
    inline void Init_any(VALUE mTatara) {
        VALUE rb_cAny = rb_define_class_under(mTatara, "Any", rb_cObject);

        rb_define_private_method(rb_cAny, "initialize", any_init, 0);
        rb_define_method(rb_cAny, "value", any_return_value, 0);
        rb_define_method(rb_cAny, "value=", any_assignment, 1);
        rb_define_method(rb_cAny, "value+", any_plus, 1);
        rb_define_method(rb_cAny, "value-", any_minus, 1);
        rb_define_method(rb_cAny, "value*", any_multiply, 1);
        rb_define_method(rb_cAny, "value/", any_divided, 1);
        rb_define_method(rb_cAny, "value%", any_mod, 1);
        rb_define_method(rb_cAny, "value**", any_power, 1);
    }
}

#endif