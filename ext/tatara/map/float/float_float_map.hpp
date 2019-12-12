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

struct WrapFloatFloatMap {
    FloatFloatMap *instance;
};

static FloatFloatMap *getFloatFloatMap(VALUE self) {
    WrapFloatFloatMap *ptr;
    Data_Get_Struct(self, WrapFloatFloatMap, ptr);
    return ptr->instance;
}

static void wrap_float_float_map_free(WrapFloatFloatMap *ptr) {
    delete ptr->instance;
    ruby_xfree(ptr);
}

static VALUE wrap_float_float_map_alloc(VALUE klass) {
    auto ptr = RB_ALLOC(WrapFloatFloatMap);
    ptr->instance = new FloatFloatMap;
    return Data_Wrap_Struct(klass, NULL, wrap_float_float_map_free, ptr);
}

static VALUE wrap_float_float_map_init(VALUE self) {
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