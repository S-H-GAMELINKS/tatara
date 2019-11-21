#ifndef STRING_INT_MAP_HPP_
#define STRING_INT_MAP_HPP_

#include <ruby.h>
#include <unordered_map>
#include <string>

class StringIntMap {
    std::unordered_map<std::string, int> container;

    public:
        StringIntMap();
        ~StringIntMap();
        int bracket(const std::string key);
        int bracket_equal(const std::string key, const int value);
};

StringIntMap::StringIntMap() {}

StringIntMap::~StringIntMap() {}

int StringIntMap::bracket(const std::string key) {
    return this->container[key];
}

int StringIntMap::bracket_equal(const std::string key, const int value) {
    return this->container[key] = value;
}

static StringIntMap *getStringIntMap(VALUE self) {
    StringIntMap *ptr;
    Data_Get_Struct(self, StringIntMap, ptr);
    return ptr;
}

static void wrap_string_int_map_free(StringIntMap *ptr) {
    ptr->~StringIntMap();
    ruby_xfree(ptr);
}

static VALUE wrap_string_int_map_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(StringIntMap));
    p = new StringIntMap;
    return Data_Wrap_Struct(klass, NULL, wrap_string_int_map_free, p);
}

static VALUE wrap_string_int_map_init(VALUE self) {
    StringIntMap *p = getStringIntMap(self);
    p = new StringIntMap;
    return Qnil;
}

static VALUE wrap_string_int_map_bracket(VALUE self, VALUE key) {
    const std::string k = {StringValueCStr(key)};
    const int value = getStringIntMap(self)->bracket(k);
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_string_int_map_bracket_equal(VALUE self, VALUE key, VALUE value) {
    const std::string k = {StringValueCStr(key)};
    const int v = NUM2INT(value);
    getStringIntMap(self)->bracket_equal(k, v);
    return value;
}

#endif