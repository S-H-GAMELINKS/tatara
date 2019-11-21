#ifndef FLOAT_INT_MAP_HPP_
#define FLOAT_INT_MAP_HPP_

#include <ruby.h>
#include <unordered_map>

class FloatIntMap {
    std::unordered_map<double, int> container;

public:
    FloatIntMap();
    ~FloatIntMap();
    int bracket(const double key);
    int bracket_equal(const double key, const int value);
};

FloatIntMap::FloatIntMap() {}

FloatIntMap::~FloatIntMap() {}

int FloatIntMap::bracket(const double key) {
    return this->container[key];
}

int FloatIntMap::bracket_equal(const double key, const int value) {
    return this->container[key] = value;
}

static FloatIntMap *getFloatIntMap(VALUE self) {
    FloatIntMap *ptr;
    Data_Get_Struct(self, FloatIntMap, ptr);
    return ptr;
}

static void wrap_float_int_map_free(FloatIntMap *ptr) {
    ptr->~FloatIntMap();
    ruby_xfree(ptr);
}

static VALUE wrap_float_int_map_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(FloatIntMap));
    p = new FloatIntMap;
    return Data_Wrap_Struct(klass, NULL, wrap_float_int_map_free, p);
}

static VALUE wrap_float_int_map_init(VALUE self) {
    FloatIntMap *p = getFloatIntMap(self);
    p = new FloatIntMap;
    return Qnil;
}

static VALUE wrap_float_int_map_bracket(VALUE self, VALUE key) {
    const double k = NUM2DBL(key);
    const int value = getFloatIntMap(self)->bracket(k);
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_float_int_map_bracket_equal(VALUE self, VALUE key, VALUE value) {
    const double k = NUM2DBL(key);
    const int v = NUM2INT(value);
    getFloatIntMap(self)->bracket_equal(k, v);
    return value;
}

#endif