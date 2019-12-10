#ifndef STRING_ARRAY_HPP_
#define STRING_ARRAY_HPP_

#include <ruby.h>
#include <string>
#include <vector>

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

static StringArray *getStringArray(VALUE self) {
    StringArray *ptr;
    Data_Get_Struct(self, StringArray, ptr);
    return ptr;
}

static void wrap_string_array_free(StringArray *ptr) {
    ptr->~StringArray();
    ruby_xfree(ptr);
}

static VALUE wrap_string_array_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(StringArray));
    p = new StringArray;
    return Data_Wrap_Struct(klass, NULL, wrap_string_array_free, p);
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
    const std::string value = getStringArray(self)->bracket(i);
    VALUE result = rb_str_new(value.data(), value.size());
    return result;
}

static VALUE wrap_string_array_bracket_equal(VALUE self, VALUE index, VALUE value) {
    const int i = NUM2INT(index);
    const std::string v = {StringValueCStr(value)};
    getStringArray(self)->bracket_equal(i, v);
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

#endif
