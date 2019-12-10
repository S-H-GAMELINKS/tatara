#ifndef INT_VECTOR_HPP_
#define INT_VECTOR_HPP_

#include <ruby.h>
#include <vector>

class IntVector {
    std::vector<int> container;

    public:
        IntVector();
        ~IntVector();
        int first();
        int last();
        int bracket(const int index);
        int bracket_equal(const int index, const int var);
        void emplace_back(const int var);
        int size();
        void clear();
        IntVector& push_back_object(const int var);
 };

IntVector::IntVector() {}

IntVector::~IntVector() {}

int IntVector::first() {
    return this->container.front();
}

int IntVector::last() {
    return this->container.back();
}

int IntVector::bracket(const int index) {
    return this->container[index];
}

int IntVector::bracket_equal(const int index, const int var) {
    return this->container[index] = var;
}

void IntVector::emplace_back(const int var) {
    this->container.emplace_back(var);
}

int IntVector::size() {
    return this->container.size();
}

void IntVector::clear() {
    this->container.clear();
}

IntVector &IntVector::push_back_object(const int var) {
    this->container.emplace_back(std::move(var));
    return *this;
}

static IntVector *getIntVector(VALUE self) {
    IntVector *ptr;
    Data_Get_Struct(self, IntVector, ptr);
    return ptr;
}

static void wrap_int_vector_free(IntVector *ptr) {
    ptr->~IntVector();
    ruby_xfree(ptr);
}

static VALUE wrap_int_vector_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(IntVector));
    p = new IntVector;
    return Data_Wrap_Struct(klass, NULL, wrap_int_vector_free, p);
}

static VALUE wrap_int_vector_init(VALUE self) {
    return Qnil;
}

static VALUE wrap_int_vector_first(VALUE self) {
    const int value = getIntVector(self)->first();
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_int_vector_last(VALUE self) {
    const int value = getIntVector(self)->last();
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_int_vector_bracket(VALUE self, VALUE index) {
    const int i = NUM2INT(index);
    const int value = getIntVector(self)->bracket(i);
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_int_vector_bracket_equal(VALUE self, VALUE index, VALUE value) {
    const int i = NUM2INT(index);
    const int v = NUM2INT(value);
    getIntVector(self)->bracket_equal(i, v);
    return value;
}

static VALUE wrap_int_vector_emplace_back(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    getIntVector(self)->emplace_back(v);
    return Qnil;
}

static VALUE wrap_int_vector_size(VALUE self) {
    const int size = getIntVector(self)->size();
    VALUE result = INT2NUM(size);
    return result;
}

static VALUE wrap_int_vector_clear(VALUE self) {
    getIntVector(self)->clear();
    return Qnil;
}

static VALUE wrap_int_vector_push_back_object(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    getIntVector(self)->push_back_object(v);
    return self;
}

#endif
