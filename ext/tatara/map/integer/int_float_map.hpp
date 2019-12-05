#ifndef INT_FLOAT_MAP_HPP_
#define INT_FLOAT_MAP_HPP_

#include <ruby.h>
#include <unordered_map>

class IntFloatMap {
    std::unordered_map<int, double> container;

    public:
        IntFloatMap();
        ~IntFloatMap();
        double bracket(const int key);
        double bracket_equal(const int key, const double value);
        IntFloatMap&  insert_object(const int key, const double value);
};

IntFloatMap::IntFloatMap() {}

IntFloatMap::~IntFloatMap() {}

double IntFloatMap::bracket(const int key) {
    return this->container[key];
}

double IntFloatMap::bracket_equal(const int key, const double value) {
    return this->container[key] = value;
}

IntFloatMap& IntFloatMap::insert_object(const int key, const double value) {
    this->container[key] = value;
    return *this;
}

static IntFloatMap *getIntFloatMap(VALUE self) {
    IntFloatMap *ptr;
    Data_Get_Struct(self, IntFloatMap, ptr);
    return ptr;
}

static void wrap_int_float_map_free(IntFloatMap *ptr) {
    ptr->~IntFloatMap();
    ruby_xfree(ptr);
}

static VALUE wrap_int_float_map_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(IntFloatMap));
    p = new IntFloatMap;
    return Data_Wrap_Struct(klass, NULL, wrap_int_float_map_free, p);
}

static VALUE wrap_int_float_map_init(VALUE self) {
    IntFloatMap *p = getIntFloatMap(self);
    p = new IntFloatMap;
    return Qnil;
}

static VALUE wrap_int_float_map_bracket(VALUE self, VALUE key) {
    const int k = NUM2INT(key);
    const double value = getIntFloatMap(self)->bracket(k);
    VALUE result = DBL2NUM(value);
    return result;
}

static VALUE wrap_int_float_map_bracket_equal(VALUE self, VALUE key, VALUE value) {
    const int k = NUM2INT(key);
    const double v = NUM2DBL(value);
    getIntFloatMap(self)->bracket_equal(k, v);
    return value;
}

static VALUE wrap_int_float_map_insert_object(VALUE self, VALUE key, VALUE value) {
    const int k = NUM2INT(key);
    const double v = NUM2DBL(value);
    getIntFloatMap(self)->insert_object(k, v);
    return value;
}

#endif