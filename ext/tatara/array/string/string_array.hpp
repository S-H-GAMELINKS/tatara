#ifndef STRING_ARRAY_HPP_
#define STRING_ARRAY_HPP_

#include <ruby.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

class StringArray {
    std::vector<std::string> container;

    public:
        StringArray();
        ~StringArray();
        std::string first();
        std::string last();
        std::string bracket(const int index);
        std::string bracket_equal(const int index, const std::string var);
        void emplace_back(const std::string var);
        int size();
        void clear();
        StringArray& push_back_object(const std::string var);
        std::string sum();
        StringArray& intersection(const StringArray* other);
};

StringArray::StringArray() {}

StringArray::~StringArray() {}

std::string StringArray::first() {
    return this->container.front();
}

std::string StringArray::last() {
    return this->container.back();
}

std::string StringArray::bracket(const int index) {
    return this->container[index];
}

std::string StringArray::bracket_equal(const int index, const std::string var) {
    return this->container[index] = var;
}

void StringArray::emplace_back(const std::string var) {
    this->container.emplace_back(var);
}

int StringArray::size() {
    return this->container.size();
}

void StringArray::clear() {
    this->container.clear();
}

StringArray &StringArray::push_back_object(const std::string var) {
    this->container.emplace_back(std::move(var));
    return *this;
}

std::string StringArray::sum() {
    return std::accumulate(this->container.begin(), this->container.end(), std::string());
}

StringArray& StringArray::intersection(const StringArray* other) {
    std::set_intersection(this->container.begin(), this->container.end(),
                          other->container.begin(), other->container.end(),
                          std::inserter(this->container, this->container.end()));
    return *this;
}

struct WrapStringArray {
    StringArray *instance;
};

static void wrap_string_array_free(void* ptr) {
    WrapStringArray *p = static_cast<WrapStringArray*>(ptr);
    delete p->instance;
    ruby_xfree(p);
}

static const rb_data_type_t rb_string_array_type = {
    "StringArray",
    {
        NULL,
        wrap_string_array_free,
        NULL,
    },
    NULL,
    NULL
};

static StringArray *getStringArray(VALUE self) {
    WrapStringArray *ptr;
    TypedData_Get_Struct(self, WrapStringArray, &rb_string_array_type, ptr);
    return ptr->instance;
}

static VALUE wrap_string_array_alloc(VALUE klass) {
    auto ptr = RB_ALLOC(WrapStringArray);
    ptr->instance = new StringArray;
    return TypedData_Wrap_Struct(klass, &rb_string_array_type, ptr);
}

static VALUE wrap_string_array_init(VALUE self) {
    return Qnil;
}

static VALUE wrap_string_array_first(VALUE self) {
    const std::string value = getStringArray(self)->first();
    VALUE result = rb_str_new(value.data(), value.size());
    return result;
}

static VALUE wrap_string_array_last(VALUE self) {
    const std::string value = getStringArray(self)->last();
    VALUE result = rb_str_new(value.data(), value.size());
    return result;
}

static VALUE wrap_string_array_bracket(VALUE self, VALUE index) {
    const int i = NUM2INT(index);
    std::string value = "";
    if (getStringArray(self)->size() <= i) {
        rb_raise(rb_eRuntimeError, "Error! Can not get Value!");
    } else {
        value = getStringArray(self)->bracket(i);
    }
    VALUE result = rb_str_new(value.data(), value.size());
    return result;
}

static VALUE wrap_string_array_bracket_equal(VALUE self, VALUE index, VALUE value) {
    const int i = NUM2INT(index);
    const std::string v = {StringValueCStr(value)};
    if (getStringArray(self)->size() <= i) {
        rb_raise(rb_eRuntimeError, "Error! Can not set Value!");
    } else {
        getStringArray(self)->bracket_equal(i, v);
    }
    return value;
}

static VALUE wrap_string_array_emplace_back(VALUE self, VALUE value) {
    const std::string v = {StringValueCStr(value)};
    getStringArray(self)->emplace_back(v);
    return Qnil;
}

static VALUE wrap_string_array_size(VALUE self) {
    const int size = getStringArray(self)->size();
    VALUE result = INT2NUM(size);
    return result;
}

static VALUE wrap_string_array_clear(VALUE self) {
    getStringArray(self)->clear();
    return Qnil;
}

static VALUE wrap_string_array_push_back_object(VALUE self, VALUE value) {
    const std::string v = {StringValueCStr(value)};
    getStringArray(self)->push_back_object(v);
    return self;
}

static VALUE wrap_string_array_map(VALUE self) {

    std::size_t size = getStringArray(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        const std::string v = getStringArray(self)->bracket(i);
        VALUE val = rb_str_new(v.c_str(), v.size());
        rb_ary_push(collection, rb_yield(val));
    }

    return collection;
}

static VALUE wrap_string_array_destructive_map(VALUE self) {

    std::size_t size = getStringArray(self)->size();

    for(int i = 0; i < size; i++) {
        const std::string v = getStringArray(self)->bracket(i);
        VALUE val = rb_str_new(v.data(), v.size());
        wrap_string_array_bracket_equal(self, INT2NUM(i), rb_yield(val));
    }

    return self;
}

static VALUE wrap_string_array_each_with_index(VALUE self) {

    std::size_t size = getStringArray(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        const std::string v = getStringArray(self)->bracket(i);
        VALUE val = rb_str_new(v.data(), v.size());
        VALUE key_value = rb_ary_new2(2);
        rb_ary_push(key_value, val);
        rb_ary_push(key_value, INT2NUM(i));
        rb_ary_push(collection, rb_yield(key_value));
    }

    return collection;
}

static VALUE wrap_string_array_convert_array(VALUE self) {
    
    std::size_t size = getStringArray(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        const std::string v = getStringArray(self)->bracket(i);
        VALUE val = rb_str_new(v.c_str(), v.size());
        rb_ary_push(collection, val);
    }

    return collection;
}

static VALUE wrap_string_array_import_array(VALUE self, VALUE ary) {

    std::size_t size = RARRAY_LEN(ary);

    for(int i = 0; i < size; i++) {
        VALUE val = rb_ary_entry(ary, i);
        const std::string v = {StringValueCStr(val)};
        getStringArray(self)->emplace_back(v);
    }

    return self;
}

static VALUE wrap_string_array_sum(VALUE self) {
    std::string result = getStringArray(self)->sum();
    return rb_str_new(result.c_str(), result.size());
}

static VALUE wrap_string_array_intersection(VALUE self, VALUE other) {
    VALUE dup = rb_obj_dup(self);
    getStringArray(dup)->intersection(getStringArray(other));
    return dup;
}

#endif
