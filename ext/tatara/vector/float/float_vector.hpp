#ifndef FLOAT_VECTOR_HPP_
#define FLOAT_VECTOR_HPP_

#include <ruby.h>
#include <vector>

class FloatVector {
    std::vector<double> container;

    public:
        FloatVector();
        ~FloatVector();
        double first();
        double last();
        double bracket(const int index);
        double bracket_equal(const int index, const double var);
        void emplace_back(const double var);
        int size();
        void clear();
        FloatVector& push_back_object(const double var);
 };

FloatVector::FloatVector() {}

FloatVector::~FloatVector() {}

double FloatVector::first() {
    return this->container.front();
}

double FloatVector::last() {
    return this->container.back();
}

double FloatVector::bracket(const int index) {
    return this->container[index];
}

double FloatVector::bracket_equal(const int index, const double var) {
    return this->container[index] = var;
}

void FloatVector::emplace_back(const double var) {
    this->container.emplace_back(var);
}

int FloatVector::size() {
    return this->container.size();
}

void FloatVector::clear() {
    this->container.clear();
}

FloatVector &FloatVector::push_back_object(const double var) {
    this->container.emplace_back(std::move(var));
    return *this;
}

static FloatVector *getFloatVector(VALUE self) {
    FloatVector *ptr;
    Data_Get_Struct(self, FloatVector, ptr);
    return ptr;
}

static void wrap_float_vector_free(FloatVector *ptr) {
    ptr->~FloatVector();
    ruby_xfree(ptr);
}

static VALUE wrap_float_vector_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(FloatVector));
    p = new FloatVector;
    return Data_Wrap_Struct(klass, NULL, wrap_float_vector_free, p);
}

static VALUE wrap_float_vector_init(VALUE self) {
    return Qnil;
}

static VALUE wrap_float_vector_first(VALUE self) {
    const double value = getFloatVector(self)->first();
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_vector_last(VALUE self) {
    const double value = getFloatVector(self)->last();
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_vector_bracket(VALUE self, VALUE index) {
    const int i = NUM2INT(index);
    const double value = getFloatVector(self)->bracket(i);
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_vector_bracket_equal(VALUE self, VALUE index, VALUE value) {
    const int i = NUM2INT(index);
    const double v = NUM2DBL(value);
    getFloatVector(self)->bracket_equal(i, v);
    return value;
}

static VALUE wrap_float_vector_emplace_back(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    getFloatVector(self)->emplace_back(v);
    return Qnil;
}

static VALUE wrap_float_vector_size(VALUE self) {
    const int size = getFloatVector(self)->size();
    VALUE result = INT2NUM(size);
    return result;
}

static VALUE wrap_float_vector_clear(VALUE self) {
    getFloatVector(self)->clear();
    return Qnil;
}

static VALUE wrap_float_vector_push_back_object(VALUE self, VALUE value) {
    const double v = NUM2DBL(value);
    getFloatVector(self)->push_back_object(v);
    return self;
}

#endif
