#ifndef FLOAT_ARRAY_HPP_
#define FLOAT_ARRAY_HPP_

#include <ruby.h>
#include <vector>
#include <algorithm>
#include <iterator>

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
        double sum();
        FloatArray& intersection(const FloatArray* other);
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

double FloatArray::sum() {
    return std::accumulate(this->container.begin(), this->container.end(), 0.0);
}

FloatArray& FloatArray::intersection(const FloatArray* other) {
    std::set_intersection(this->container.begin(), this->container.end(),
                          other->container.begin(), other->container.end(),
                          std::inserter(this->container, this->container.end()));
    return *this;
}

struct WrapFloatArray {
    FloatArray *instance;
};

static void wrap_float_array_free(void* ptr) {
    WrapFloatArray *p = static_cast<WrapFloatArray*>(ptr);
    delete p->instance;
    ruby_xfree(p);
}

static const rb_data_type_t rb_float_array_type = {
    "FloatArray",
    {
        NULL,
        wrap_float_array_free,
        NULL,
    },
    NULL,
    NULL
};

static FloatArray *getFloatArray(VALUE self) {
    WrapFloatArray *ptr;
    TypedData_Get_Struct(self, WrapFloatArray, &rb_float_array_type, ptr);
    return ptr->instance;
}

static VALUE wrap_float_array_alloc(VALUE klass) {
    auto ptr= RB_ALLOC(WrapFloatArray);
    ptr->instance = new FloatArray;
    return TypedData_Wrap_Struct(klass, &rb_float_array_type, ptr);
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

static VALUE wrap_float_array_map(VALUE self) {

    std::size_t size = getFloatArray(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = DBL2NUM(getFloatArray(self)->bracket(i));
        rb_ary_push(collection, rb_yield(val));
    }

    return collection;
}

static VALUE wrap_float_array_destructive_map(VALUE self) {

    std::size_t size = getFloatArray(self)->size();

    for(int i = 0; i < size; i++) {
        VALUE val = DBL2NUM(getFloatArray(self)->bracket(i));
        wrap_float_array_bracket_equal(self, INT2NUM(i), rb_yield(val));
    }

    return self;
}

static VALUE wrap_float_array_each_with_index(VALUE self) {

    std::size_t size = getFloatArray(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = DBL2NUM(getFloatArray(self)->bracket(i));
        VALUE key_value = rb_ary_new2(2);
        rb_ary_push(key_value, val);
        rb_ary_push(key_value, INT2NUM(i));
        rb_ary_push(collection, rb_yield(key_value));
    }

    return collection;
}

static VALUE wrap_float_array_convert_array(VALUE self) {
    
    std::size_t size = getFloatArray(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = DBL2NUM(getFloatArray(self)->bracket(i));
        rb_ary_push(collection, val);
    }

    return collection;
}

static VALUE wrap_float_array_import_array(VALUE self, VALUE ary) {

    std::size_t size = RARRAY_LEN(ary);

    for(int i = 0; i < size; i++) {
        VALUE val = rb_ary_entry(ary, i);
        getFloatArray(self)->emplace_back(NUM2DBL(val));
    }

    return self;
}

static VALUE wrap_float_array_sum(VALUE self) {
    double result = getFloatArray(self)->sum();
    return DBL2NUM(result);
}

static VALUE wrap_float_array_intersection(VALUE self, VALUE other) {
    VALUE dup = rb_obj_dup(self);
    getFloatArray(dup)->intersection(getFloatArray(other));
    return dup;
}

#endif
