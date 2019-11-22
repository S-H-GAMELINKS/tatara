#ifndef INT_ARRAY_HPP_
#define INT_ARRAY_HPP_

#include <ruby.h>
#include <algorithm>
#include <iterator>
#include <vector>

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
        IntArray intersection(const IntArray array);
        IntArray sort();
        IntArray& destructive_sort();
        IntArray reverse();
        IntArray& destructive_reverse();
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

IntArray IntArray::intersection(const IntArray array) {

    std::vector<int> result;

    std::set_intersection(
        this->container.begin(), this->container.end(),
        array.container.begin(), array.container.end(),
        std::inserter(result, result.end()));

    IntArray object;

    object.container = std::move(result);

    return object;
}

IntArray IntArray::sort() {
    IntArray object;
    object.container = this->container;
    std::sort(object.container.begin(), object.container.end());
    return object;
}

IntArray& IntArray::destructive_sort() {
    std::sort(this->container.begin(), this->container.end());
    return *this;
}

IntArray IntArray::reverse() {
    IntArray object;
    object.container = this->container;
    std::reverse(object.container.begin(), object.container.end());
    return object;
}

IntArray& IntArray::destructive_reverse() {
    std::reverse(this->container.begin(), this->container.end());
    return *this;
}

static IntArray *getIntArray(VALUE self) {
    IntArray *ptr;
    Data_Get_Struct(self, IntArray, ptr);
    return ptr;
}

static void wrap_int_array_free(IntArray *ptr) {
    ptr->~IntArray();
    ruby_xfree(ptr);
}

static VALUE wrap_int_array_alloc(VALUE klass) {
    void *p = ruby_xmalloc(sizeof(IntArray));
    p = new IntArray;
    return Data_Wrap_Struct(klass, NULL, wrap_int_array_free, p);
}

static VALUE wrap_int_array_init(VALUE self) {
    IntArray *p = getIntArray(self);
    p = new IntArray;
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

#endif
