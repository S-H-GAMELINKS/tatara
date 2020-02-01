#ifndef ANY_H_
#define ANY_H_

#include <ruby.h>

static VALUE any_init(VALUE self) {
    rb_ivar_set(self, rb_intern("value"), Qnil);
    return self;
}

static VALUE any_return_value(VALUE) {
    return rb_ivar_get(self, rb_intern("value"));
}

extern "C" {
    inline void Init_any(VALUE mTatara) {
        VALUE rb_cAny = rb_define_class_under(mTatara, "Any", rb_cObject);

        rb_define_private_method(rb_cAny, "initialize", any_init, 0);
        rb_define_method(rb_cAny, "value", any_return_value, 0);
    }
}

#endif