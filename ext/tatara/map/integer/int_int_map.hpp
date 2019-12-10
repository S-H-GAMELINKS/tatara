#ifndef INT_INT_MAP_HPP_
#define INT_INT_MAP_HPP_

#include <ruby.h>
#include <unordered_map>

class IntIntMap {
    std::unordered_map<int, int> container;

    public:
        IntIntMap();
        ~IntIntMap();
        int bracket(const int key);
        int bracket_equal(const int key, const int value);
        IntIntMap& insert_object(const int key, const int value);
};

IntIntMap::IntIntMap() {}

IntIntMap::~IntIntMap() {}

int IntIntMap::bracket(const int key) {
    return this->container[key];
}

int IntIntMap::bracket_equal(const int key, const int value) {
    return this->container[key] = value;
}

IntIntMap& IntIntMap::insert_object(const int key, const int value) {
    this->container[key] = value;
    return *this;
}

static IntIntMap *getIntIntMap(VALUE self) {
    IntIntMap *ptr;
    Data_Get_Struct(self, IntIntMap, ptr);
    return ptr;
}

static void wrap_int_int_map_free(IntIntMap *ptr) {
    ptr->~IntIntMap();
    ruby_xfree(ptr);
}

static VALUE wrap_int_int_map_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(IntIntMap));
    p = new IntIntMap;
    return Data_Wrap_Struct(klass, NULL, wrap_int_int_map_free, p);
}

static VALUE wrap_int_int_map_init(VALUE self) {
    return Qnil;
}

static VALUE wrap_int_int_map_bracket(VALUE self, VALUE key) {
    const int k = NUM2INT(key);
    const int value = getIntIntMap(self)->bracket(k);
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_int_int_map_bracket_equal(VALUE self, VALUE key, VALUE value) {
    const int k = NUM2INT(key);
    const int v = NUM2INT(value);
    getIntIntMap(self)->bracket_equal(k, v);
    return value;
}

static VALUE wrap_int_int_map_insert_object(VALUE self, VALUE key, VALUE value) {
    const int k = NUM2INT(key);
    const int v = NUM2INT(value);
    getIntIntMap(self)->insert_object(k, v);
    return value;
}

#endif