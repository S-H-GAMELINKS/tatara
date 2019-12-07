#ifndef FLOAT_H_
#define FLOAT_H_

#include <ruby.h>
#include <string>
#include <regex>

class Float {
        double value = 0.0;
    public:
        constexpr Float();
        ~Float();
        constexpr Float& initialize_object(const double var);
        constexpr double assignment(const double var);
        constexpr double return_value();
        constexpr double increment_value();
        constexpr double decrement_value();
        std::string to_string();
        constexpr int to_integer();
        constexpr double plus(const double var);
        constexpr double plus_equal(const double var);
        constexpr double minus(const double var);
        constexpr double minus_equal(const double var);
        constexpr double multiply(const double var);
        constexpr double multiply_equal(const double var);
        constexpr double divided(const double var);
        constexpr double divided_equal(const double var);
        constexpr double power(const double var);
        constexpr double power_equal(const double var);
        constexpr double clear();
        constexpr bool equal(const double var);
};

constexpr Float::Float() {}

Float::~Float() {}

constexpr Float& Float::initialize_object(const double var) {
    this->value = var;
    return *this;
}

constexpr double Float::assignment(const double var) {
    return this->value = var;
}

constexpr double Float::return_value() {
    return this->value;
}

constexpr double Float::increment_value() {
    return this->value++;
}

constexpr double Float::decrement_value() {
    return this->value--;
}

std::string Float::to_string() {

    std::string null = "";

    std::regex re("0+");

    return std::regex_replace(std::to_string(this->value), re, null);
}

constexpr int Float::to_integer() {
    return static_cast<int>(this->value);
}

constexpr double Float::plus(const double var) {
    return this->value + var;
}

constexpr double Float::plus_equal(const double var) {
    return this->value += var;
}

constexpr double Float::minus(const double var) {
    return this->value - var;
}

constexpr double Float::minus_equal(const double var) {
    return this->value -= var;
}

constexpr double Float::multiply(const double var) {
    return this->value * var;
}

constexpr double Float::multiply_equal(const double var) {
    return this->value *= var;
}

constexpr double Float::divided(const double var) {
    return this->value / var;
}

constexpr double Float::divided_equal(const double var) {
    return this->value /= var;
}

constexpr double Float::power(const double var) {
    return std::pow(this->value, var);
}

constexpr double Float::power_equal(const double var) {
    return this->value = std::pow(this->value, var);
}

constexpr double Float::clear() {
    return this->value = 0.0;
}

constexpr bool Float::equal(const double var) {
    return this->value == var;
}

struct WrapFloat {
    Float* float_instance;
};

static Float *getFloat(VALUE self) {
    WrapFloat *ptr;
    Data_Get_Struct(self, WrapFloat, ptr);
    return ptr->float_instance;
}

static void wrap_float_free(WrapFloat *ptr) {
    delete ptr->float_instance;
    ruby_xfree(ptr);
}

static VALUE wrap_float_alloc(VALUE klass) {
    auto wrap_float = RB_ALLOC(WrapFloat);
    wrap_float->float_instance = new Float;
    return Data_Wrap_Struct(klass, NULL, wrap_float_free, wrap_float);
}

static VALUE wrap_float_init(VALUE self) {
    Float *p = getFloat(self);
    p = new Float;
    return Qnil;
}

static VALUE wrap_float_return_value(VALUE self) {
    const double value = getFloat(self)->return_value();
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_assignment(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    getFloat(self)->assignment(v);
    return value;
}

static VALUE wrap_float_plus(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    const double r = getFloat(self)->plus(v);
    VALUE result = DBL2NUM(r);
    return result;
}

static VALUE wrap_float_plus_equal(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    const double r = getFloat(self)->plus_equal(v);
    VALUE result = DBL2NUM(r);
    return result;
}

static VALUE wrap_float_minus(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    const double r = getFloat(self)->minus(v);
    VALUE result = DBL2NUM(r);
    return result;
}

static VALUE wrap_float_minus_equal(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    const double r = getFloat(self)->minus_equal(v);
    VALUE result = DBL2NUM(r);
    return result;
}

static VALUE wrap_float_multiply(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    const double r = getFloat(self)->multiply(v);
    VALUE result = DBL2NUM(r);
    return result;
}

static VALUE wrap_float_multiply_equal(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    const double r = getFloat(self)->multiply_equal(v);
    VALUE result = DBL2NUM(r);
    return result;
}

static VALUE wrap_float_divided(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    const double r = getFloat(self)->divided(v);
    VALUE result = DBL2NUM(r);
    return result;
}

static VALUE wrap_float_divided_equal(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    const double r = getFloat(self)->divided_equal(v);
    VALUE result = DBL2NUM(r);
    return result;
}

static VALUE wrap_float_power(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    const double r = getFloat(self)->power(v);
    VALUE result = DBL2NUM(r);
    return result;
}

static VALUE wrap_float_power_equal(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    const double r = getFloat(self)->power_equal(v);
    VALUE result = DBL2NUM(r);
    return result;
}

static VALUE wrap_float_increment_value(VALUE self) {
    const double value = getFloat(self)->increment_value();
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_decrement_value(VALUE self) {
    const double value = getFloat(self)->decrement_value();
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_to_string(VALUE self) {
    const std::string value = getFloat(self)->to_string();
    VALUE result = rb_str_new(value.c_str(), value.size());
    return result;
}

static VALUE wrap_float_to_integer(VALUE self) {
    const int value = getFloat(self)->to_integer();
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_float_clear(VALUE self) {
    const double value = getFloat(self)->clear();
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_equal(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    bool eval = getFloat(self)->equal(v);
    return eval ? Qtrue : Qfalse;
}

static VALUE wrap_float_initialize_object(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    getFloat(self)->initialize_object(v);
    return self;
}

#endif