#ifndef INT_STRING_MAP_HPP_
#define INT_STRING_MAP_HPP_

#include <ruby.h>
#include <unordered_map>
#include <string>

class IntStringMap {
    std::unordered_map<int, std::string> container;

    public:
        IntStringMap();
        ~IntStringMap();
        std::string bracket(const int key);
        std::string bracket_equal(const int key, const std::string value);
        IntStringMap& insert_object(const int key, const std::string value);
};

IntStringMap::IntStringMap() {}

IntStringMap::~IntStringMap() {}

std::string IntStringMap::bracket(const int key) {
    return this->container[key];
}

std::string IntStringMap::bracket_equal(const int key, const std::string value) {
    return this->container[key] = value;
}

IntStringMap& IntStringMap::insert_object(const int key, const std::string value) {
    this->container[key] = value;
    return *this;
}

struct WrapIntStringMap {
    IntStringMap *instance;
};

static IntStringMap *getIntStringMap(VALUE self) {
    WrapIntStringMap *ptr;
    Data_Get_Struct(self, WrapIntStringMap, ptr);
    return ptr->instance;
}

static void wrap_int_string_map_free(WrapIntStringMap *ptr) {
    delete ptr->instance;
    ruby_xfree(ptr);
}

static VALUE wrap_int_string_map_alloc(VALUE klass) {
    auto ptr = RB_ALLOC(WrapIntStringMap);
    ptr->instance = new IntStringMap;
    return Data_Wrap_Struct(klass, NULL, wrap_int_string_map_free, ptr);
}

static VALUE wrap_int_string_map_init(VALUE self) {
    return Qnil;
}

static VALUE wrap_int_string_map_bracket(VALUE self, VALUE key) {
    const int k = NUM2INT(key);
    const std::string value = getIntStringMap(self)->bracket(k);
    VALUE result = rb_str_new(value.c_str(), value.size());
    return result;
}

static VALUE wrap_int_string_map_bracket_equal(VALUE self, VALUE key, VALUE value) {
    const int k = NUM2INT(key);
    const std::string v = {StringValueCStr(value)};
    getIntStringMap(self)->bracket_equal(k, v);
    return value;
}

static VALUE wrap_int_string_map_insert_object(VALUE self, VALUE key, VALUE value) {
    const int k = NUM2INT(key);
    const std::string v = {StringValueCStr(value)};
    getIntStringMap(self)->insert_object(k, v);
    return value;
}

#endif