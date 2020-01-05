#ifndef INT_VECTOR_HPP_
#define INT_VECTOR_HPP_

#include <ruby.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>

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
        int sum();
        IntVector& intersection(const IntVector* other);
        void sort();
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

int IntVector::sum() {
    return std::accumulate(this->container.begin(), this->container.end(), 0);
}

IntVector& IntVector::intersection(const IntVector* other) {
    std::set_intersection(this->container.begin(), this->container.end(),
                          other->container.begin(), other->container.end(),
                          std::inserter(this->container, this->container.end()));
    return *this;
}

void IntVector::sort() {
    std::sort(this->container.begin(), this->container.end());
}

struct WrapIntVector {
    IntVector *instance;
};

static void wrap_int_vector_free(void* ptr) {
    WrapIntVector *p = static_cast<WrapIntVector*>(ptr);
    delete p->instance;
    ruby_xfree(p);
}

static const rb_data_type_t rb_int_vector_type = {
    "IntVector",
    {
        NULL,
        wrap_int_vector_free,
        NULL,
    },
    NULL,
    NULL
};

static IntVector *getIntVector(VALUE self) {
    WrapIntVector *ptr;
    TypedData_Get_Struct(self, WrapIntVector, &rb_int_vector_type, ptr);
    return ptr->instance;
}

static VALUE wrap_int_vector_alloc(VALUE klass) {
    auto ptr = RB_ALLOC(WrapIntVector);
    ptr->instance = new IntVector;
    return TypedData_Wrap_Struct(klass, &rb_int_vector_type, ptr);
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
    int value = 0;
    if (getIntVector(self)->size() <= i) {
        rb_raise(rb_eRuntimeError, "Error! Can not get Value!");
    } else {
        value = getIntVector(self)->bracket(i);
    }
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_int_vector_bracket_equal(VALUE self, VALUE index, VALUE value) {
    const int i = NUM2INT(index);
    const int v = NUM2INT(value);
    if (getIntVector(self)->size() <= i) {
        rb_raise(rb_eRuntimeError, "Error! Can not set Value!");
    } else {
        getIntVector(self)->bracket_equal(i, v);
    }
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

static VALUE wrap_int_vector_map(VALUE self) {

    std::size_t size = getIntVector(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = INT2NUM(getIntVector(self)->bracket(i));
        rb_ary_push(collection, rb_yield(val));
    }

    return collection;
}

static VALUE wrap_int_vector_destructive_map(VALUE self) {

    std::size_t size = getIntVector(self)->size();

    for(int i = 0; i < size; i++) {
        const int v = getIntVector(self)->bracket(i);
        VALUE val = INT2NUM(v);
        wrap_int_vector_bracket_equal(self, INT2NUM(i), rb_yield(val));
    }

    return self;
}

static VALUE wrap_int_vector_each_with_index(VALUE self) {

    std::size_t size = getIntVector(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = INT2NUM(getIntVector(self)->bracket(i));
        VALUE key_value = rb_ary_new2(2);
        rb_ary_push(key_value, val);
        rb_ary_push(key_value, INT2NUM(i));
        rb_ary_push(collection, rb_yield(key_value));
    }

    return collection;
}

static VALUE wrap_int_vector_convert_array(VALUE self) {

    std::size_t size = getIntVector(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = INT2NUM(getIntVector(self)->bracket(i));
        rb_ary_push(collection, val);
    }

    return collection;
}

static VALUE wrap_int_vector_import_array(VALUE self, VALUE ary) {

    std::size_t size = RARRAY_LEN(ary);

    for(int i = 0; i < size; i++) {
        VALUE val = rb_ary_entry(ary, i);
        getIntVector(self)->emplace_back(NUM2INT(val));
    }

    return self;
}

static VALUE wrap_int_vector_sum(VALUE self) {
    int result = getIntVector(self)->sum();
    return INT2NUM(result);
}

static VALUE wrap_int_vector_intersection(VALUE self, VALUE other) {
    VALUE dup = rb_obj_dup(self);
    getIntVector(dup)->intersection(getIntVector(other));
    return dup;   
}

static VALUE wrap_int_vector_sort(VALUE self) {
    VALUE dup = rb_obj_dup(self);
    VALUE result = wrap_int_vector_convert_array(self);
    dup = wrap_int_vector_import_array(dup, result);
    getIntVector(dup)->sort();
    return dup;
}

#endif
