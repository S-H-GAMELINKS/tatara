#ifndef FLOAT_ARRAY_HPP_
#define FLOAT_ARRAY_HPP_

#include <ruby.h>
#include <vector>

class FloatArray {
    std::vector<double> container;

    public:
        FloatArray();
        ~FloatArray();
        double first();
        double last();
        double bracket(const int index);
        double bracket_equal(const int index, const double var);
        void emplace_back(const double var);
        int size();
        void clear();
        FloatArray& push_back_object(const double var);
};

FloatArray::FloatArray() {}

FloatArray::~FloatArray() {}

double FloatArray::first() {
    return this->container.front();
}

double FloatArray::last() {
    return this->container.back();
}

double FloatArray::bracket(const int index) {
    return this->container[index];
}

double FloatArray::bracket_equal(const int index, const double var) {
    return this->container[index] = var;
}

void FloatArray::emplace_back(const double var) {
    this->container.emplace_back(var);
}

int FloatArray::size() {
    return this->container.size();
}

void FloatArray::clear() {
    this->container.clear();
}

FloatArray &FloatArray::push_back_object(const double var) {
    this->container.emplace_back(std::move(var));
    return *this;
}

static FloatArray *getFloatArray(VALUE self) {
    FloatArray *ptr;
    Data_Get_Struct(self, FloatArray, ptr);
    return ptr;
}

static void wrap_float_array_free(FloatArray *ptr) {
    ptr->~FloatArray();
    ruby_xfree(ptr);
}

static VALUE wrap_float_array_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(FloatArray));
    p = new FloatArray;
    return Data_Wrap_Struct(klass, NULL, wrap_float_array_free, p);
}

static VALUE wrap_float_array_init(VALUE self) {
    return Qnil;
}

static VALUE wrap_float_array_first(VALUE self) {
    const double value = getFloatArray(self)->first();
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_array_last(VALUE self) {
    const double value = getFloatArray(self)->last();
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_array_bracket(VALUE self, VALUE index) {
    const int i = NUM2INT(index);
    const double value = getFloatArray(self)->bracket(i);
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_array_bracket_equal(VALUE self, VALUE index, VALUE value) {
    const int i = NUM2INT(index);
    const double v = NUM2DBL(value);
    getFloatArray(self)->bracket_equal(i, v);
    return value;
}

static VALUE wrap_float_array_emplace_back(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    getFloatArray(self)->emplace_back(v);
    return Qnil;
}

static VALUE wrap_float_array_size(VALUE self) {
    const int size = getFloatArray(self)->size();
    VALUE result = INT2NUM(size);
    return result;
}

static VALUE wrap_float_array_clear(VALUE self) {
    getFloatArray(self)->clear();
    return Qnil;
}

static VALUE wrap_float_array_push_back_object(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    getFloatArray(self)->push_back_object(v);
    return self;
}

#endif
