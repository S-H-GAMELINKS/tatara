#ifndef STRING_STRING_MAP_HPP_
#define STRING_STRING_MAP_HPP_

#include <ruby.h>
#include <unordered_map>
#include <string>

class StringStringMap {
    std::unordered_map<std::string, std::string> container;

    public:
        StringStringMap();
        ~StringStringMap();
        std::string bracket(const std::string key);
        std::string bracket_equal(const std::string key, const std::string value);
        StringStringMap& insert_object(const std::string key, const std::string value);
};

StringStringMap::StringStringMap() {}

StringStringMap::~StringStringMap() {}

std::string StringStringMap::bracket(const std::string key) {
    return this->container[key];
}

std::string StringStringMap::bracket_equal(const std::string key, const std::string value) {
    return this->container[key] = value;
}

StringStringMap& StringStringMap::insert_object(const std::string key, const std::string value) {
    this->container[key] = value;
    return *this;
}

struct WrapStringStringMap {
    StringStringMap *instance;
};

static void wrap_string_string_map_free(void* ptr) {
    WrapStringStringMap *p = static_cast<WrapStringStringMap*>(ptr);
    delete p->instance;
    ruby_xfree(p);
}

static const rb_data_type_t rb_string_string_map_type = {
    "StringStringMap",
    {
        NULL,
        wrap_string_string_map_free,
        NULL,
    },
    NULL,
    NULL
};

static StringStringMap *getStringStringMap(VALUE self) {
    WrapStringStringMap *ptr;
    TypedData_Get_Struct(self, WrapStringStringMap, &rb_string_string_map_type, ptr);
    return ptr->instance;
}

static VALUE wrap_string_string_map_alloc(VALUE klass) {
    auto ptr = RB_ALLOC(WrapStringStringMap);
    ptr->instance = new StringStringMap;
    return TypedData_Wrap_Struct(klass, &rb_string_string_map_type, ptr);
}

static VALUE wrap_string_string_map_init(VALUE self) {
    return Qnil;
}

static VALUE wrap_string_string_map_bracket(VALUE self, VALUE key) {
    const std::string k = {StringValueCStr(key)};
    const std::string value = getStringStringMap(self)->bracket(k);
    VALUE result = rb_str_new(value.c_str(), value.size());
    return result;
}

static VALUE wrap_string_string_map_bracket_equal(VALUE self, VALUE key, VALUE value) {
    const std::string k = {StringValueCStr(key)};
    const std::string v = {StringValueCStr(value)};
    getStringStringMap(self)->bracket_equal(k, v);
    return value;
}

static VALUE wrap_string_string_map_insert_object(VALUE self, VALUE key, VALUE value) {
    const std::string k = {StringValueCStr(key)};
    const std::string v = {StringValueCStr(value)};
    getStringStringMap(self)->insert_object(k, v);
    return value;
}

#endif