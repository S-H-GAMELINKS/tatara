#ifndef STRING_VECTOR_HPP_
#define STRING_VECTOR_HPP_

#include <ruby.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

class StringVector {
    std::vector<std::string> container;

    public:
        StringVector();
        ~StringVector();
        std::string first();
        std::string last();
        std::string bracket(const int index);
        std::string bracket_equal(const int index, const std::string var);
        void emplace_back(const std::string var);
        int size();
        void clear();
        StringVector& push_back_object(const std::string var);
        std::string sum();
        StringVector& intersection(const StringVector* other);
};

StringVector::StringVector() {}

StringVector::~StringVector() {}

std::string StringVector::first() {
    return this->container.front();
}

std::string StringVector::last() {
    return this->container.back();
}

std::string StringVector::bracket(const int index) {
    return this->container[index];
}

std::string StringVector::bracket_equal(const int index, const std::string var) {
    return this->container[index] = var;
}

void StringVector::emplace_back(const std::string var) {
    this->container.emplace_back(var);
}

int StringVector::size() {
    return this->container.size();
}

void StringVector::clear() {
    this->container.clear();
}

StringVector &StringVector::push_back_object(const std::string var) {
    this->container.emplace_back(std::move(var));
    return *this;
}

std::string StringVector::sum() {
    return std::accumulate(this->container.begin(), this->container.end(), std::string());
}

StringVector& StringVector::intersection(const StringVector* other) {
    std::set_intersection(this->container.begin(), this->container.end(),
                          other->container.begin(), other->container.end(),
                          std::inserter(this->container, this->container.end()));
    return *this;
}

struct WrapStringVector {
    StringVector* instance;
};

static void wrap_string_vector_free(void* ptr) {
    WrapStringVector *p = static_cast<WrapStringVector*>(ptr);
    delete p->instance;
    ruby_xfree(p);
}

static const rb_data_type_t rb_string_vector_type = {
    "StringVector",
    {
        NULL,
        wrap_string_vector_free,
        NULL,
    },
    NULL,
    NULL
};

static StringVector *getStringVector(VALUE self) {
    WrapStringVector *ptr;
    TypedData_Get_Struct(self, WrapStringVector, &rb_string_vector_type, ptr);
    return ptr->instance;
};

static VALUE wrap_string_vector_alloc(VALUE klass) {
    auto ptr = RB_ALLOC(WrapStringVector);
    ptr->instance = new StringVector;
    return TypedData_Wrap_Struct(klass, &rb_string_vector_type, ptr);
}

static VALUE wrap_string_vector_init(VALUE self) {
    return Qnil;
}

static VALUE wrap_string_vector_first(VALUE self) {
    const std::string value = getStringVector(self)->first();
    VALUE result = rb_str_new(value.data(), value.size());
    return result;
}

static VALUE wrap_string_vector_last(VALUE self) {
    const std::string value = getStringVector(self)->last();
    VALUE result = rb_str_new(value.data(), value.size());
    return result;
}

static VALUE wrap_string_vector_bracket(VALUE self, VALUE index) {
    const int i = NUM2INT(index);
    std::string value = "";
    if (getStringVector(self)->size() <= i) {
        rb_raise(rb_eRuntimeError, "Error! Can not get Value!");
    } else {
        value = getStringVector(self)->bracket(i);
    }
    VALUE result = rb_str_new(value.data(), value.size());
    return result;
}

static VALUE wrap_string_vector_bracket_equal(VALUE self, VALUE index, VALUE value) {
    const int i = NUM2INT(index);
    const std::string v = {StringValueCStr(value)};
    if (getStringVector(self)->size() <= i) {
        rb_raise(rb_eRuntimeError, "Error! Can not set Value!");
    } else {
        getStringVector(self)->bracket_equal(i, v);
    }
    return value;
}

static VALUE wrap_string_vector_emplace_back(VALUE self, VALUE value) {
    const std::string v = {StringValueCStr(value)};
    getStringVector(self)->emplace_back(v);
    return Qnil;
}

static VALUE wrap_string_vector_size(VALUE self) {
    const int size = getStringVector(self)->size();
    VALUE result = INT2NUM(size);
    return result;
}

static VALUE wrap_string_vector_clear(VALUE self) {
    getStringVector(self)->clear();
    return Qnil;
}

static VALUE wrap_string_vector_push_back_object(VALUE self, VALUE value) {
    const std::string v = {StringValueCStr(value)};
    getStringVector(self)->push_back_object(v);
    return self;
}

static VALUE wrap_string_vector_map(VALUE self) {

    std::size_t size = getStringVector(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        const std::string v = getStringVector(self)->bracket(i);
        VALUE val = rb_str_new(v.c_str(), v.size());
        rb_ary_push(collection, rb_yield(val));
    }

    return collection;
}

static VALUE wrap_string_vector_destructive_map(VALUE self) {

    std::size_t size = getStringVector(self)->size();

    for(int i = 0; i < size; i++) {
        const std::string v = getStringVector(self)->bracket(i);
        VALUE val = rb_str_new(v.data(), v.size());
        wrap_string_vector_bracket_equal(self, INT2NUM(i), rb_yield(val));
    }

    return self;
}

static VALUE wrap_string_vector_each_with_index(VALUE self) {

    std::size_t size = getStringVector(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        const std::string v = getStringVector(self)->bracket(i);
        VALUE val = rb_str_new(v.data(), v.size());
        VALUE key_value = rb_ary_new2(2);
        rb_ary_push(key_value, val);
        rb_ary_push(key_value, INT2NUM(i));
        rb_ary_push(collection, rb_yield(key_value));
    }

    return collection;
}

static VALUE wrap_string_vector_convert_array(VALUE self) {
    
    std::size_t size = getStringVector(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        const std::string v = getStringVector(self)->bracket(i);
        VALUE val = rb_str_new(v.c_str(), v.size());
        rb_ary_push(collection, val);
    }

    return collection;
}

static VALUE wrap_string_vector_import_array(VALUE self, VALUE ary) {

    std::size_t size = RARRAY_LEN(ary);

    for(int i = 0; i < size; i++) {
        VALUE val = rb_ary_entry(ary, i);
        const std::string v = {StringValueCStr(val)};
        getStringVector(self)->emplace_back(v);
    }

    return self;
}

static VALUE wrap_string_vector_sum(VALUE self) {
    std::string result = getStringVector(self)->sum();
    return rb_str_new(result.c_str(), result.size());
}

static VALUE wrap_string_vector_intersection(VALUE self, VALUE other) {
    VALUE dup = rb_obj_dup(self);
    getStringVector(dup)->intersection(getStringVector(other));
    return dup;   
}

#endif
