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

struct WrapIntFloatMap {
    IntFloatMap *instance;
};

static void wrap_int_float_map_free(void* ptr) {
    WrapIntFloatMap *p = static_cast<WrapIntFloatMap*>(ptr);
    delete p->instance;
    ruby_xfree(p);
}

static const rb_data_type_t rb_int_float_map_type = {
    "IntFloatMap",
    {
        NULL,
        wrap_int_float_map_free,
        NULL,
    },
    NULL,
    NULL
};

static IntFloatMap *getIntFloatMap(VALUE self) {
    WrapIntFloatMap *ptr;
    TypedData_Get_Struct(self, WrapIntFloatMap, &rb_int_float_map_type, ptr);
    return ptr->instance;
}

static VALUE wrap_int_float_map_alloc(VALUE klass) {
    auto ptr = RB_ALLOC(WrapIntFloatMap);
    ptr->instance = new IntFloatMap;
    return TypedData_Wrap_Struct(klass, &rb_int_float_map_type, ptr);
}

static VALUE wrap_int_float_map_init(VALUE self) {
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