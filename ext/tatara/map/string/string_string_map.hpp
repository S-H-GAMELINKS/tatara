#ifndef STRING_STRING_MAP_HPP_
#define STRING_STRING_MAP_HPP_

#include <ruby.h>
#include <unordered_map>
#include <string>

class StringStringMap {
    std::unordered_map<std::string, std::string> container;

    public:
        StringStringMap();
        ~StringStringMap();
        std::string bracket(const std::string key);
        std::string bracket_equal(const std::string key, const std::string value);
};

StringStringMap::StringStringMap() {}

StringStringMap::~StringStringMap() {}

std::string StringStringMap::bracket(const std::string key) {
    return this->container[key];
}

std::string StringStringMap::bracket_equal(const std::string key, const std::string value) {
    return this->container[key] = value;
}

static StringStringMap *getStringStringMap(VALUE self) {
    StringStringMap *ptr;
    Data_Get_Struct(self, StringStringMap, ptr);
    return ptr;
}

static void wrap_string_string_map_free(StringStringMap *ptr) {
    ptr->~StringStringMap();
    ruby_xfree(ptr);
}

static VALUE wrap_string_string_map_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(StringStringMap));
    p = new StringStringMap;
    return Data_Wrap_Struct(klass, NULL, wrap_string_string_map_free, p);
}

static VALUE wrap_string_string_map_init(VALUE self) {
    StringStringMap *p = getStringStringMap(self);
    p = new StringStringMap;
    return Qnil;
}

static VALUE wrap_string_string_map_bracket(VALUE self, VALUE key) {
    const std::string k = {StringValueCStr(key)};
    const std::string value = getStringStringMap(self)->bracket(k);
    VALUE result = rb_str_new(value.c_str(), value.size());
    return result;
}

static VALUE wrap_string_string_map_bracket_equal(VALUE self, VALUE key, VALUE value) {
    const std::string k = {StringValueCStr(key)};
    const std::string v = {StringValueCStr(value)};
    getStringStringMap(self)->bracket_equal(k, v);
    return value;
}

#endif