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
};

IntStringMap::IntStringMap() {}

IntStringMap::~IntStringMap() {}

std::string IntStringMap::bracket(const int key) {
    return this->container[key];
}

std::string IntStringMap::bracket_equal(const int key, const std::string value) {
    return this->container[key] = value;
}

static IntStringMap *getIntStringMap(VALUE self) {
    IntStringMap *ptr;
    Data_Get_Struct(self, IntStringMap, ptr);
    return ptr;
}

static void wrap_int_string_map_free(IntStringMap *ptr) {
    ptr->~IntStringMap();
    ruby_xfree(ptr);
}

static VALUE wrap_int_string_map_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(IntStringMap));
    p = new IntStringMap;
    return Data_Wrap_Struct(klass, NULL, wrap_int_string_map_free, p);
}

static VALUE wrap_int_string_map_init(VALUE self) {
    IntStringMap *p = getIntStringMap(self);
    p = new IntStringMap;
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

#endif