#ifndef STRING_H_
#define STRING_H_

#include <ruby.h>
#include <iostream>
#include <string>

class CppString {
        std::string value = "";
    public:
        CppString();
        ~CppString();
        CppString& initialize_object(const std::string var);
        std::string assignment(const std::string var);
        std::string return_value();
        std::string index_access(const int index);
        int to_integer();
        double to_float();
        std::string plus_equal(const std::string var);
        std::string clear();
        bool equal(const std::string var);
        std::string slice(const int start, const int end);
        std::string slice_des(const int start, const int end);
};

CppString::CppString() {}

CppString::~CppString() {}

CppString& CppString::initialize_object(const std::string var) {
    this->value = var;
    return *this;
}

std::string CppString::assignment(const std::string var) {
    return this->value = var;
}

std::string CppString::return_value() {
    return this->value;
}

std::string CppString::index_access(const int index) {
    std::string s{this->value[index]};
    return s;
}

int CppString::to_integer() {
    return std::stoi(this->value);
}

double CppString::to_float() {
    return std::stof(this->value);
}

std::string CppString::plus_equal(const std::string var) {
    return this->value += var;
}

std::string CppString::clear() {
    return this->value = "";
}

bool CppString::equal(const std::string var) {
    return this->value == var;
}

std::string CppString::slice(const int start, const int end) {
    return this->value.substr(start, end);
}

std::string CppString::slice_des(const int start, const int end) {
    this->value = this->value.substr(start, end);
    return this->value;
}

static CppString *getCppString(VALUE self) {
    CppString *ptr;
    Data_Get_Struct(self, CppString, ptr);
    return ptr;
}

static void wrap_string_free(CppString *ptr) {
    ptr->~CppString();
    ruby_xfree(ptr);
}

static VALUE wrap_string_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(CppString));
    p = new CppString;
    return Data_Wrap_Struct(klass, NULL, wrap_string_free, p);
}

static VALUE wrap_string_init(VALUE self) {
    CppString *p = getCppString(self);
    p = new CppString;
    return Qnil;
}

static VALUE wrap_string_return_value(VALUE self) {
    const std::string value = getCppString(self)->return_value();
    VALUE result = rb_str_new(value.c_str(), value.size());
    return result;
}

static VALUE wrap_string_assignment(VALUE self, VALUE value) {
    const std::string v = {StringValueCStr(value)};
    getCppString(self)->assignment(v);
    return value;
}

static VALUE wrap_string_plus_equal(VALUE self, VALUE value) {
    const std::string v = {StringValueCStr(value)};
    const std::string r = getCppString(self)->plus_equal(v);
    VALUE result = rb_str_new(v.c_str(), v.size());
    return result;
}

static VALUE wrap_string_to_integer(VALUE self) {
    try {
        const int value = getCppString(self)->to_integer();
        VALUE result = INT2NUM(value);
        return result;
    } catch (...) {
        std::cout << "Cannot Convert Integer!" << std::endl;
    }
}

static VALUE wrap_string_to_float(VALUE self) {
    try {
        const double value = getCppString(self)->to_float();
        VALUE result = DBL2NUM(value);
        return result;
    } catch (...) {
        std::cout << "Cannot Convert Float!" << std::endl;
    }
}

static VALUE wrap_string_clear(VALUE self) {
    const std::string value = getCppString(self)->clear();
    VALUE result = rb_str_new(value.c_str(), value.size());
    return result;
}

static VALUE wrap_string_equal(VALUE self, VALUE value) {
    const std::string v = {StringValueCStr(value)};
    bool eval = getCppString(self)->equal(v);
    return eval ? Qtrue : Qfalse;
}

static VALUE wrap_string_initialize_object(VALUE self, VALUE value) {
    const std::string v = {StringValueCStr(value)};
    getCppString(self)->initialize_object(v);
    return self;
}

static VALUE wrap_string_index_access(VALUE self, VALUE index) {
    const int i = NUM2INT(index);
    const std::string value = getCppString(self)->index_access(i);
    VALUE result = rb_str_new(value.c_str(), value.size());
    return result;
}

static VALUE wrap_string_slice(VALUE self, VALUE start, VALUE end) {
    const int s = NUM2INT(start);
    const int e = NUM2INT(end);
    const std::string value = getCppString(self)->slice(s, e);
    VALUE result = rb_str_new(value.c_str(), value.size());
    return result;
} 

static VALUE wrap_string_destructive_slice(VALUE self, VALUE start, VALUE end) {
    const int s = NUM2INT(start);
    const int e = NUM2INT(end);
    const std::string value = getCppString(self)->slice_des(s, e);
    VALUE result = rb_str_new(value.c_str(), value.size());
    return result;
} 

#endif
