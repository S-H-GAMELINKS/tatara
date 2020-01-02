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
        StringIntMap &insert_object(const std::string key, const int value);
};

StringIntMap::StringIntMap() {}

StringIntMap::~StringIntMap() {}

int StringIntMap::bracket(const std::string key) {
    return this->container[key];
}

int StringIntMap::bracket_equal(const std::string key, const int value) {
    return this->container[key] = value;
}

StringIntMap &StringIntMap::insert_object(const std::string key, const int value) {
    this->container[key] = value;
    return *this;
}

struct WrapStringIntMap {
    StringIntMap *instance;
};

static void wrap_string_int_map_free(void* ptr) {
    WrapStringIntMap *p = static_cast<WrapStringIntMap*>(ptr);
    delete p->instance;
    ruby_xfree(p);
}

static const rb_data_type_t rb_string_int_map_type = {
    "StringIntMap",
    {
        NULL,
        wrap_string_int_map_free,
        NULL,
    },
    NULL,
    NULL
};

static StringIntMap *getStringIntMap(VALUE self) {
    WrapStringIntMap *ptr;
    TypedData_Get_Struct(self, WrapStringIntMap, &rb_string_int_map_type, ptr);
    return ptr->instance;
}

static VALUE wrap_string_int_map_alloc(VALUE klass) {
    auto ptr = RB_ALLOC(WrapStringIntMap);
    ptr->instance = new StringIntMap;
    return TypedData_Wrap_Struct(klass, &rb_string_int_map_type, ptr);
}

static VALUE wrap_string_int_map_init(VALUE self) {
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

static VALUE wrap_string_int_map_insert_object(VALUE self, VALUE key, VALUE value) {
    const std::string k = {StringValueCStr(key)};
    const int v = NUM2INT(value);
    getStringIntMap(self)->insert_object(k, v);
    return value;
}

#endif