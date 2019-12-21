#ifndef INT_ARRAY_HPP_
#define INT_ARRAY_HPP_

#include <ruby.h>
#include <vector>
#include <iostream>

class IntArray {
    std::vector<int> container;

    public:
        IntArray();
        ~IntArray();
        int first();
        int last();
        int bracket(const int index);
        int bracket_equal(const int index, const int var);
        void emplace_back(const int var);
        int size();
        void clear();
        IntArray& push_back_object(const int var);
 };

IntArray::IntArray() {}

IntArray::~IntArray() {}

int IntArray::first() {
    return this->container.front();
}

int IntArray::last() {
    return this->container.back();
}

int IntArray::bracket(const int index) {
    return this->container[index];
}

int IntArray::bracket_equal(const int index, const int var) {
    return this->container[index] = var;
}

void IntArray::emplace_back(const int var) {
    this->container.emplace_back(var);
}

int IntArray::size() {
    return this->container.size();
}

void IntArray::clear() {
    this->container.clear();
}

IntArray &IntArray::push_back_object(const int var) {
    this->container.emplace_back(std::move(var));
    return *this;
}

struct WrapIntArray {
    IntArray *instance;
};

static void wrap_int_array_free(void* ptr) {
    WrapIntArray *p = static_cast<WrapIntArray*>(ptr);
    delete p->instance;
    ruby_xfree(p);
}

static const rb_data_type_t rb_int_array_type = {
    "IntArray",
    {
        NULL,
        wrap_int_array_free,
        NULL,
    },
    NULL,
    NULL
};

static IntArray *getIntArray(VALUE self) {
    WrapIntArray *ptr;
    TypedData_Get_Struct(self, WrapIntArray, &rb_int_array_type, ptr);
    return ptr->instance;
}

static VALUE wrap_int_array_alloc(VALUE klass) {
    auto ptr = RB_ALLOC(WrapIntArray);
    ptr->instance = new IntArray;
    return TypedData_Wrap_Struct(klass, &rb_int_array_type, ptr);
}

static VALUE wrap_int_array_init(VALUE self) {
    return Qnil;
}

static VALUE wrap_int_array_first(VALUE self) {
    const int value = getIntArray(self)->first();
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_int_array_last(VALUE self) {
    const int value = getIntArray(self)->last();
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_int_array_bracket(VALUE self, VALUE index) {
    const int i = NUM2INT(index);
    const int value = getIntArray(self)->bracket(i);
    VALUE result = INT2NUM(value);
    return result;
}

static VALUE wrap_int_array_bracket_equal(VALUE self, VALUE index, VALUE value) {
    const int i = NUM2INT(index);
    const int v = NUM2INT(value);
    getIntArray(self)->bracket_equal(i, v);
    return value;
}

static VALUE wrap_int_array_emplace_back(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    getIntArray(self)->emplace_back(v);
    return Qnil;
}

static VALUE wrap_int_array_size(VALUE self) {
    const int size = getIntArray(self)->size();
    VALUE result = INT2NUM(size);
    return result;
}

static VALUE wrap_int_array_clear(VALUE self) {
    getIntArray(self)->clear();
    return Qnil;
}

static VALUE wrap_int_array_push_back_object(VALUE self, VALUE value) {
    const int v = NUM2INT(value);
    getIntArray(self)->push_back_object(v);
    return self;
}

static VALUE
rb_ary_length(VALUE ary)
{
    long len = RARRAY_LEN(ary);
    return LONG2NUM(len);
}

static VALUE ary_enum_length(VALUE ary, VALUE args, VALUE eobj)
{
    return rb_ary_length(ary);
}

static VALUE wrap_int_array_map(VALUE self) {

    std::size_t size = getIntArray(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = INT2NUM(getIntArray(self)->bracket(i));
        rb_ary_push(collection, rb_yield(val));
    }

    return collection;
}

static VALUE wrap_int_array_destructive_map(VALUE self) {

    std::size_t size = getIntArray(self)->size();

    for(int i = 0; i < size; i++) {
        VALUE val = INT2NUM(getIntArray(self)->bracket(i));
        wrap_int_array_bracket_equal(self, INT2NUM(i), rb_yield(val));
    }

    return self;
}

static VALUE wrap_int_array_each_with_index(VALUE self) {

    std::size_t size = getIntArray(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = INT2NUM(getIntArray(self)->bracket(i));
        VALUE key_value = rb_ary_new2(2);
        rb_ary_push(key_value, val);
        rb_ary_push(key_value, INT2NUM(i));
        rb_ary_push(collection, rb_yield(key_value));
    }

    return collection;
}

static VALUE wrap_int_array_convert_array(VALUE self) {

    std::size_t size = getIntArray(self)->size();

    VALUE collection = rb_ary_new2(size);

    for(int i = 0; i < size; i++) {
        VALUE val = INT2NUM(getIntArray(self)->bracket(i));
        rb_ary_push(collection, val);
    }

    return collection;
}

#endif
