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

struct WrapFloatVector {
    FloatVector* instance;
};

static void wrap_float_vector_free(void* ptr) {
    WrapFloatVector *p = static_cast<WrapFloatVector*>(ptr);
    delete p->instance;
    ruby_xfree(p);
}

static const rb_data_type_t rb_float_vector_type = {
    "FloatVector",
    {
        NULL,
        wrap_float_vector_free,
        NULL,
    },
    NULL,
    NULL
};

static FloatVector *getFloatVector(VALUE self) {
    WrapFloatVector *ptr;
    TypedData_Get_Struct(self, WrapFloatVector, &rb_float_vector_type, ptr);
    return ptr->instance;
}

static VALUE wrap_float_vector_alloc(VALUE klass) {
    auto ptr = RB_ALLOC(WrapFloatVector);
    ptr->instance = new FloatVector;
    return TypedData_Wrap_Struct(klass, &rb_float_vector_type, ptr);
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

static VALUE wrap_float_vector_map(VALUE self) {

    std::size_t size = getFloatVector(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = DBL2NUM(getFloatVector(self)->bracket(i));
        rb_ary_push(collection, rb_yield(val));
    }

    return collection;
}

static VALUE wrap_float_vector_destructive_map(VALUE self) {

    std::size_t size = getFloatVector(self)->size();

    for(int i = 0; i < size; i++) {
        const double v = getFloatVector(self)->bracket(i);
        VALUE val = DBL2NUM(v);
        wrap_float_vector_bracket_equal(self, INT2NUM(i), rb_yield(val));
    }

    return self;
}

static VALUE wrap_float_vector_each_with_index(VALUE self) {

    std::size_t size = getFloatVector(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = DBL2NUM(getFloatVector(self)->bracket(i));
        VALUE key_value = rb_ary_new2(2);
        rb_ary_push(key_value, val);
        rb_ary_push(key_value, INT2NUM(i));
        rb_ary_push(collection, rb_yield(key_value));
    }

    return collection;
}

#endif
