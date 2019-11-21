#ifndef STRING_FLOAT_MAP_HPP_
#define STRING_FLOAT_MAP_HPP_

#include <ruby.h>
#include <unordered_map>

class StringFloatMap {
    std::unordered_map<std::string, double> container;

    public:
        StringFloatMap();
        ~StringFloatMap();
        double bracket(const std::string key);
        double bracket_equal(const std::string key, const double value);
};

StringFloatMap::StringFloatMap() {}

StringFloatMap::~StringFloatMap() {}

double StringFloatMap::bracket(const std::string key) {
    return this->container[key];
}

double StringFloatMap::bracket_equal(const std::string key, const double value) {
    return this->container[key] = value;
}

static StringFloatMap *getStringFloatMap(VALUE self) {
    StringFloatMap *ptr;
    Data_Get_Struct(self, StringFloatMap, ptr);
    return ptr;
}

static void wrap_string_float_map_free(StringFloatMap *ptr) {
    ptr->~StringFloatMap();
    ruby_xfree(ptr);
}

static VALUE wrap_string_float_map_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(StringFloatMap));
    p = new StringFloatMap;
    return Data_Wrap_Struct(klass, NULL, wrap_string_float_map_free, p);
}

static VALUE wrap_string_float_map_init(VALUE self) {
    StringFloatMap *p = getStringFloatMap(self);
    p = new StringFloatMap;
    return Qnil;
}

static VALUE wrap_string_float_map_bracket(VALUE self, VALUE key) {
    const std::string k = {StringValueCStr(key)};
    const double value = getStringFloatMap(self)->bracket(k);
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_string_float_map_bracket_equal(VALUE self, VALUE key, VALUE value) {
    const std::string k = {StringValueCStr(key)};
    const double v = NUM2DBL(value);
    getStringFloatMap(self)->bracket_equal(k, v);
    return value;
}

#endif