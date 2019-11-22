#ifndef FLOAT_VECTOR_HPP_
#define FLOAT_VECTOR_HPP_

#include <ruby.h>
#include <vector>

class FloatString {
    std::vector<double> container;

    public:
        FloatString();
        ~FloatString();
        double first();
        double last();
        double bracket(const int index);
        double bracket_equal(const int index, const double var);
        void emplace_back(const double var);
        int size();
        void clear();
        FloatString& push_back_object(const double var);
 };

FloatString::FloatString() {}

FloatString::~FloatString() {}

double FloatString::first() {
    return this->container.front();
}

double FloatString::last() {
    return this->container.back();
}

double FloatString::bracket(const int index) {
    return this->container[index];
}

double FloatString::bracket_equal(const int index, const double var) {
    return this->container[index] = var;
}

void FloatString::emplace_back(const double var) {
    this->container.emplace_back(var);
}

int FloatString::size() {
    return this->container.size();
}

void FloatString::clear() {
    this->container.clear();
}

FloatString &FloatString::push_back_object(const double var) {
    this->container.emplace_back(std::move(var));
    return *this;
}

static FloatString *getFloatString(VALUE self) {
    FloatString *ptr;
    Data_Get_Struct(self, FloatString, ptr);
    return ptr;
}

static void wrap_float_vector_free(FloatString *ptr) {
    ptr->~FloatString();
    ruby_xfree(ptr);
}

static VALUE wrap_float_vector_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(FloatString));
    p = new FloatString;
    return Data_Wrap_Struct(klass, NULL, wrap_float_vector_free, p);
}

static VALUE wrap_float_vector_init(VALUE self) {
    FloatString *p = getFloatString(self);
    p = new FloatString;
    return Qnil;
}

static VALUE wrap_float_vector_first(VALUE self) {
    const double value = getFloatString(self)->first();
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_vector_last(VALUE self) {
    const double value = getFloatString(self)->last();
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_vector_bracket(VALUE self, VALUE index) {
    const int i = NUM2INT(index);
    const double value = getFloatString(self)->bracket(i);
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_vector_bracket_equal(VALUE self, VALUE index, VALUE value) {
    const int i = NUM2INT(index);
    const double v = NUM2DBL(value);
    getFloatString(self)->bracket_equal(i, v);
    return value;
}

static VALUE wrap_float_vector_emplace_back(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    getFloatString(self)->emplace_back(v);
    return Qnil;
}

static VALUE wrap_float_vector_size(VALUE self) {
    const int size = getFloatString(self)->size();
    VALUE result = INT2NUM(size);
    return result;
}

static VALUE wrap_float_vector_clear(VALUE self) {
    getFloatString(self)->clear();
    return Qnil;
}

static VALUE wrap_float_vector_push_back_object(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    getFloatString(self)->push_back_object(v);
    return self;
}

#endif
