#ifndef INTEGER_H_
#define INTEGER_H_

#include <ruby.h>
#include <string>
#include <cmath>
#include <iostream>

class Integer {
    int value = 0;

    public:
        constexpr Integer();
        ~Integer();
        constexpr Integer& initialize_object(const int var);
        constexpr int assignment(const int var);
        constexpr int return_value();
        constexpr int increment_value();
        constexpr int decrement_value();
        std::string to_string();
        constexpr double to_float();
        constexpr int plus(int var);
        constexpr int plus_equal(int var);
        constexpr int minus(int var);
        constexpr int minus_equal(int var);
        constexpr int divided(int var);
        constexpr int divided_equal(int var);
        constexpr int multiply(int var);
        constexpr int multiply_equal(int var);
        constexpr int mod(int var);
        constexpr int mod_equal(int var);
        constexpr int power(int var);
        constexpr int power_equal(int var);
        constexpr int clear();
        constexpr bool equal(const int var);
};

constexpr Integer::Integer() {}

Integer::~Integer() {}

constexpr Integer& Integer::initialize_object(const int var) {
    this->value = var;
    return *this;
}

constexpr int Integer::assignment(const int var) {
    return this->value = var;
}

constexpr int Integer::return_value() {
    return this->value;
}

constexpr int Integer::increment_value() {
    return this->value++;
}

constexpr int Integer::decrement_value() {
    return this->value--;
}

std::string Integer::to_string() {
    return std::to_string(this->value);
}

constexpr double Integer::to_float() {
    return static_cast<double>(this->value);
}

constexpr int Integer::plus(int var) {
    return this->value + var;
}

constexpr int Integer::plus_equal(int var) {
    return this->value += var;
}

constexpr int Integer::minus(int var) {
    return this->value - var;
}

constexpr int Integer::minus_equal(int var) {
    return this->value -= var;
}

constexpr int Integer::divided(int var) {
    return this->value / var;
}

constexpr int Integer::divided_equal(int var) {
    return this->value /= var;
}

constexpr int Integer::multiply(int var) {
    return this->value * var;
}

constexpr int Integer::multiply_equal(int var) {
    return this->value *= var;
}

constexpr int Integer::mod(int var) {
    return this->value % var;
}

constexpr int Integer::mod_equal(int var) {
    return this->value %= var;
}

constexpr int Integer::power(int var) {
    return std::pow(this->value, var);
}

constexpr int Integer::power_equal(int var) {
    return this->value = std::pow(this->value, var);
}

constexpr int Integer::clear() {
    return this->value = 0;
}

constexpr bool Integer::equal(const int var) {
    return this->value == var;
}

struct WrapInteger {
    Integer* instance;
};

static void wrap_int_free(void *ptr) {
    WrapInteger* p = static_cast<WrapInteger*>(ptr);
    delete p->instance;
    ruby_xfree(p);
}

static const rb_data_type_t rb_int_type = {
    "Integer",
    {
        NULL,
        wrap_int_free,
        NULL,
    },
    NULL,
    NULL
};

static Integer *getInteger(VALUE self) {
    WrapInteger *ptr;
    TypedData_Get_Struct(self, WrapInteger, &rb_int_type, ptr);
    return ptr->instance;
}

static VALUE wrap_int_alloc(VALUE klass) {
    auto ptr = RB_ALLOC(WrapInteger);
    ptr->instance = new Integer;
    return TypedData_Wrap_Struct(klass, &rb_int_type, ptr);
}

static VALUE wrap_int_init(VALUE self) {
    return Qnil;
}


static VALUE wrap_int_return_value(VALUE self) {
    const int value = getInteger(self)->return_value();
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_int_assignment(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    const int r = getInteger(self)->assignment(v);
    VALUE result = INT2NUM(r);
    return result;
}

static VALUE wrap_int_plus(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    const int r = getInteger(self)->plus(v);
    VALUE result = INT2NUM(r);
    return result;
}

static VALUE wrap_int_plus_equal(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    const int r = getInteger(self)->plus_equal(v);
    VALUE result = INT2NUM(r);
    return result;
}

static VALUE wrap_int_minus(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    const int r = getInteger(self)->minus(v);
    VALUE result = INT2NUM(r);
    return result;
}

static VALUE wrap_int_minus_equal(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    const int r = getInteger(self)->minus_equal(v);
    VALUE result = INT2NUM(r);
    return result;
}

static VALUE wrap_int_divided(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    const int r = getInteger(self)->divided(v);
    VALUE result = INT2NUM(r);
    return result;
}

static VALUE wrap_int_divided_equal(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    const int r = getInteger(self)->divided_equal(v);
    VALUE result = INT2NUM(r);
    return result;
}

static VALUE wrap_int_multiply(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    const int r = getInteger(self)->multiply(v);
    VALUE result = INT2NUM(r);
    return result;
}

static VALUE wrap_int_multiply_equal(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    const int r = getInteger(self)->multiply_equal(v);
    VALUE result = INT2NUM(r);
    return result;
}

static VALUE wrap_int_mod(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    const int r = getInteger(self)->mod(v);
    VALUE result = INT2NUM(r);
    return result;
}

static VALUE wrap_int_mod_equal(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    const int r = getInteger(self)->mod_equal(v);
    VALUE result = INT2NUM(r);
    return result;
}

static VALUE wrap_int_power(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    const int r = getInteger(self)->power(v);
    VALUE result = INT2NUM(r);
    return result;
}

static VALUE wrap_int_power_equal(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    const int r = getInteger(self)->power_equal(v);
    VALUE result = INT2NUM(r);
    return result;
}

static VALUE wrap_int_increment_value(VALUE self) {
    const int value = getInteger(self)->increment_value();
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_int_decrement_value(VALUE self) {
    const int value = getInteger(self)->decrement_value();
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_int_to_string(VALUE self) {
    const std::string value = getInteger(self)->to_string();
    VALUE result = rb_str_new(value.c_str(), value.size());
    return result;
}

static VALUE wrap_int_to_float(VALUE self) {
    const double value = getInteger(self)->to_float();
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_int_clear(VALUE self) {
    const int value = getInteger(self)->clear();
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_int_equal(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    bool eval = getInteger(self)->equal(v);
    return eval ? Qtrue : Qfalse;
}

static VALUE wrap_int_initialize_object(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    getInteger(self)->initialize_object(v);
    return self;
}

#endif