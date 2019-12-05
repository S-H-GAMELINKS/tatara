#ifndef FLOAT_FLOAT_MAP_HPP_
#define FLOAT_FLOAT_MAP_HPP_

#include <ruby.h>
#include <unordered_map>

class FloatFloatMap {
    std::unordered_map<double, double> container;

    public:
        FloatFloatMap();
        ~FloatFloatMap();
        double bracket(const double key);
        double bracket_equal(const double key, const double value);
        FloatFloatMap& insert_object(const double key, const double value);
};

FloatFloatMap::FloatFloatMap() {}

FloatFloatMap::~FloatFloatMap() {}

double FloatFloatMap::bracket(const double key) {
    return this->container[key];
}

double FloatFloatMap::bracket_equal(const double key, const double value) {
    return this->container[key] = value;
}

FloatFloatMap& FloatFloatMap::insert_object(const double key, const double value) {
    this->container[key] = value;
    return *this;
}

static FloatFloatMap *getFloatFloatMap(VALUE self) {
    FloatFloatMap *ptr;
    Data_Get_Struct(self, FloatFloatMap, ptr);
    return ptr;
}

static void wrap_float_float_map_free(FloatFloatMap *ptr) {
    ptr->~FloatFloatMap();
    ruby_xfree(ptr);
}

static VALUE wrap_float_float_map_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(FloatFloatMap));
    p = new FloatFloatMap;
    return Data_Wrap_Struct(klass, NULL, wrap_float_float_map_free, p);
}

static VALUE wrap_float_float_map_init(VALUE self) {
    FloatFloatMap *p = getFloatFloatMap(self);
    p = new FloatFloatMap;
    return Qnil;
}

static VALUE wrap_float_float_map_bracket(VALUE self, VALUE key) {
    const double k = NUM2DBL(key);
    const double value = getFloatFloatMap(self)->bracket(k);
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_float_float_map_bracket_equal(VALUE self, VALUE key, VALUE value) {
    const double k = NUM2DBL(key);
    const double v = NUM2DBL(value);
    getFloatFloatMap(self)->bracket_equal(k, v);
    return value;
}

static VALUE wrap_float_float_map_insert_object(VALUE self, VALUE key, VALUE value) {
    const double k = NUM2DBL(key);
    const double v = NUM2DBL(value);
    getFloatFloatMap(self)->insert_object(k, v);
    return value;
}

#endif