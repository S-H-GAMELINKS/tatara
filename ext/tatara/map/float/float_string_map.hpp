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
        std::string bracket(const double key);
        std::string bracket_equal(const double key, const std::string value);
        FloatStringMap& insert_object(const double key, const std::string value);
};

FloatStringMap::FloatStringMap() {}

FloatStringMap::~FloatStringMap() {}

std::string FloatStringMap::bracket(const double key) {
    return this->container[key];
}

std::string FloatStringMap::bracket_equal(const double key, const std::string value) {
    return this->container[key] = value;
}

FloatStringMap& FloatStringMap::insert_object(const double key, const std::string value) {
    this->container[key] = value;
    return *this;
}

struct WrapFloatStringMap {
    FloatStringMap *instance;
};

static void wrap_float_string_map_free(void* ptr) {
    WrapFloatStringMap *p = static_cast<WrapFloatStringMap*>(ptr);
    delete p->instance;
    ruby_xfree(p);
}

static const rb_data_type_t rb_float_string_map_type = {
    "FloatStringMap",
    {
        NULL,
        wrap_float_string_map_free,
        NULL,
    },
    NULL,
    NULL
};

static FloatStringMap* getFloatStringMap(VALUE self) {
    WrapFloatStringMap *ptr;
    TypedData_Get_Struct(self, WrapFloatStringMap, &rb_float_string_map_type, ptr);
    return ptr->instance;
}

static VALUE wrap_float_string_map_alloc(VALUE klass) {
    auto ptr = RB_ALLOC(WrapFloatStringMap);
    ptr->instance = new FloatStringMap;
    return TypedData_Wrap_Struct(klass, &rb_float_string_map_type, ptr);
}

static VALUE wrap_float_string_map_init(VALUE self) {
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

static VALUE wrap_float_string_map_insert_object(VALUE self, VALUE key, VALUE value) {
    const double k = NUM2DBL(key);
    const std::string v = {StringValueCStr(value)};
    getFloatStringMap(self)->insert_object(k, v);
    return value;
}

#endif