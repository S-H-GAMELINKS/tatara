#ifndef FLOAT_STRING_MAP_HPP_
#define FLOAT_STRING_MAP_HPP_

#include <ruby.h>
#include <unordered_map>
#include <string>

class FloatStringMap {
    std::unordered_map<double, std::string> container;

    public:
        FloatStringMap();
        ~FloatStringMap();
        constexpr std::string bracket(const double key);
        constexpr std::string bracket_equal(const double key, const std::string value);
};

FloatStringMap::FloatStringMap() {}

FloatStringMap::~FloatStringMap() {}

std::string FloatStringMap::bracket(const double key) {
    return this->container[key];
}

std::string FloatStringMap::bracket_equal(const double key, const std::string value) {
    return this->container[key] = value;
}

static FloatStringMap* getFloatStringMap(VALUE self) {
    FloatStringMap *ptr;
    Data_Get_Struct(self, FloatStringMap, ptr);
    return ptr;
}

static void wrap_float_string_map_free(FloatStringMap *ptr) {
    ptr->~FloatStringMap();
    ruby_xfree(ptr);
}

static VALUE wrap_float_string_map_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(FloatStringMap));
    p = new FloatStringMap;
    return Data_Wrap_Struct(klass, NULL, wrap_float_string_map_free, p);
}

static VALUE wrap_float_string_map_init(VALUE self) {
    FloatStringMap *p = getFloatStringMap(self);
    p = new FloatStringMap;
    return Qnil;
}

static VALUE wrap_float_string_map_bracket(VALUE self, VALUE key) {
    const double k = NUM2DBL(key);
    const std::string value = getFloatStringMap(self)->bracket(k);
    VALUE result = rb_str_new(value.c_str(), value.size());
    return result;
}

static VALUE wrap_float_string_map_bracket_equal(VALUE self, VALUE key, VALUE value) {
    const double k = NUM2DBL(key);
    const std::string v = StringValueCStr(value);
    getFloatStringMap(self)->bracket_equal(k, v);
    return value;
}

#endif