#include <string>
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include "vector/vector.hpp"
#include "array/array.hpp"
#include "map/map.hpp"
#include "integer/integer.hpp"
#include "float/float.hpp"
#include "string/string.hpp"

using namespace Rice;

extern "C" {
    void Init_tatara() {
        Rice::Module rb_mTatara = define_module("Tatara");

        Data_Type<Integer> rbcInteger = define_class_under<Integer>(rb_mTatara, "Integer")
            .define_constructor(Constructor<Integer>())
            .define_method("value", &Integer::return_value)
            .define_method("val", &Integer::return_value)
            .define_method("value=", &Integer::assignment)
            .define_method("val=", &Integer::assignment)
            .define_method("value+", &Integer::plus)
            .define_method("val+", &Integer::plus)
            .define_method("value+=", &Integer::plus_equal)
            .define_method("val+=", &Integer::plus_equal)
            .define_method("value-", &Integer::minus)
            .define_method("val-", &Integer::minus)
            .define_method("value-=", &Integer::minus_equal)
            .define_method("val-=", &Integer::minus_equal)
            .define_method("value/", &Integer::divided)
            .define_method("val/", &Integer::divided)
            .define_method("value/=", &Integer::divided_equal)
            .define_method("val/=", &Integer::divided_equal)
            .define_method("value*", &Integer::multiply)
            .define_method("val*", &Integer::multiply)
            .define_method("value*=", &Integer::multiply_equal)
            .define_method("val*=", &Integer::multiply_equal)
            .define_method("value%", &Integer::mod)
            .define_method("value%=", &Integer::mod_equal)
            .define_method("value**", &Integer::power)
            .define_method("val**", &Integer::power)
            .define_method("value**=", &Integer::power_equal)
            .define_method("val**=", &Integer::power_equal)
            .define_method("inc", &Integer::increment_value)
            .define_method("increment", &Integer::increment_value)
            .define_method("dec", &Integer::decrement_value)
            .define_method("decrement", &Integer::decrement_value)
            .define_method("to_s", &Integer::to_string)
            .define_method("to_f", &Integer::to_float)
            .define_method("clear", &Integer::clear)
            .define_method("value==", &Integer::equal)
            .define_method("val==", &Integer::equal)
            .define_method("equal?", &Integer::equal)
            .define_method("<<", &Integer::initialize_object);

        Data_Type<Float> rbcFloat = define_class_under<Float>(rb_mTatara, "Float")
            .define_constructor(Constructor<Float>())
            .define_method("value", &Float::return_value)
            .define_method("val", &Float::return_value)
            .define_method("value=", &Float::assignment)
            .define_method("val=", &Float::assignment)
            .define_method("value+", &Float::plus)
            .define_method("val+", &Float::plus)
            .define_method("value+=", &Float::plus_equal)
            .define_method("val+=", &Float::plus_equal)
            .define_method("value-", &Float::minus)
            .define_method("val-", &Float::minus)
            .define_method("value-=", &Float::minus_equal)
            .define_method("val-=", &Float::minus_equal)
            .define_method("value*", &Float::multiply)
            .define_method("val*", &Float::multiply)
            .define_method("value*=", &Float::multiply_equal)
            .define_method("val*=", &Float::multiply_equal)
            .define_method("value/", &Float::divided)
            .define_method("val/", &Float::divided)
            .define_method("value/=", &Float::divided_equal)
            .define_method("val/=", &Float::divided_equal)
            .define_method("value**", &Float::power)
            .define_method("val**", &Float::power)
            .define_method("value**=", &Float::power_equal)
            .define_method("val**=", &Float::power_equal)
            .define_method("inc", &Float::increment_value)
            .define_method("dec", &Float::decrement_value)
            .define_method("to_s", &Float::to_string)
            .define_method("to_i", &Float::to_integer)
            .define_method("clear", &Float::clear)
            .define_method("value==", &Float::equal)
            .define_method("val==", &Float::equal)
            .define_method("equal?", &Float::equal)
            .define_method("<<", &Float::initialize_object);

        Data_Type<CppString> rbcString = define_class_under<CppString>(rb_mTatara, "String")
            .define_constructor(Constructor<CppString>())
            .define_method("value", &CppString::return_value)
            .define_method("val", &CppString::return_value)
            .define_method("value=", &CppString::assignment)
            .define_method("val=", &CppString::assignment)
            .define_method("value+=", &CppString::plus_equal)
            .define_method("val+=", &CppString::plus_equal)
            .define_method("to_i", &CppString::to_integer)
            .define_method("to_f", &CppString::to_float)
            .define_method("clear", &CppString::clear)
            .define_method("value==", &CppString::equal)
            .define_method("val==", &CppString::equal)
            .define_method("equal?", &CppString::equal)
            .define_method("<<", &CppString::initialize_object)
            .define_method("[]", &CppString::index_access)
            .define_method("slice", &CppString::slice)
            .define_method("slice!", &CppString::slice_des);

        Data_Type<Vector<int>> rb_cIntVector = define_class_under<Vector<int>>(rb_mTatara, "IntVector")
            .define_constructor(Constructor<Vector<int>>())
            .define_method("first", &Vector<int>::first)
            .define_method("last", &Vector<int>::last)
            .define_method("[]", &Vector<int>::bracket)
            .define_method("[]=", &Vector<int>::bracket_equal)
            .define_method("emplace_back", &Vector<int>::emplace_back)
            .define_method("size", &Vector<int>::size)
            .define_method("clear", &Vector<int>::clear)
            .define_method("sum", &Vector<int>::sum)
            .define_method("<<", &Vector<int>::push_back_object)
            .define_method("intersection", &Vector<int>::intersection)
            .define_method("sort", &Vector<int>::sort)
            .define_method("sort!", &Vector<int>::destructive_sort)
            .define_method("reverse", &Vector<int>::reverse)
            .define_method("reverse!", &Vector<int>::destructive_reverse);

        Data_Type<Vector<double>> rb_cFloatVector = define_class_under<Vector<double>>(rb_mTatara, "FloatVector")
            .define_constructor(Constructor<Vector<double>>())
            .define_method("first", &Vector<double>::first)
            .define_method("last", &Vector<double>::last)
            .define_method("[]", &Vector<double>::bracket)
            .define_method("[]=", &Vector<double>::bracket_equal)
            .define_method("emplace_back", &Vector<double>::emplace_back)
            .define_method("size", &Vector<double>::size)
            .define_method("clear", &Vector<double>::clear)
            .define_method("sum", &Vector<double>::sum)
            .define_method("<<", &Vector<double>::push_back_object)
            .define_method("intersection", &Vector<double>::intersection)
            .define_method("sort", &Vector<double>::sort)
            .define_method("sort!", &Vector<double>::destructive_sort)
            .define_method("reverse", &Vector<double>::reverse)
            .define_method("reverse!", &Vector<double>::destructive_reverse);

        Data_Type<Vector<std::string>> rb_cStringVector = define_class_under<Vector<std::string>>(rb_mTatara, "StringVector")
            .define_constructor(Constructor<Vector<std::string>>())
            .define_method("first", &Vector<std::string>::first)
            .define_method("last", &Vector<std::string>::last)
            .define_method("[]", &Vector<std::string>::bracket)
            .define_method("[]=", &Vector<std::string>::bracket_equal)
            .define_method("emplace_back", &    Vector<std::string>::emplace_back)
            .define_method("size", &Vector<std::string>::size)
            .define_method("clear", &Vector<std::string>::clear)
            .define_method("sum", &Vector<std::string>::sum)
            .define_method("<<", &Vector<std::string>::push_back_object)
            .define_method("intersection", &Vector<std::string>::intersection)
            .define_method("sort", &Vector<std::string>::sort)
            .define_method("sort!", &Vector<std::string>::destructive_sort)
            .define_method("reverse", &Vector<std::string>::reverse)
            .define_method("reverse!", &Vector<std::string>::destructive_reverse);

        Data_Type<CppArray<int>> rb_cIntArray = define_class_under<CppArray<int>>(rb_mTatara, "IntArray")
            .define_constructor(Constructor<CppArray<int>>())
            .define_method("first", &CppArray<int>::first)
            .define_method("last", &CppArray<int>::last)
            .define_method("[]", &CppArray<int>::bracket)
            .define_method("[]=", &CppArray<int>::bracket_equal)
            .define_method("push", &CppArray<int>::emplace_back)
            .define_method("size", &CppArray<int>::size)
            .define_method("clear", &CppArray<int>::clear)
            .define_method("<<", &CppArray<int>::push_back_object)
            .define_method("intersection", &CppArray<int>::intersection)
            .define_method("sort", &CppArray<int>::sort)
            .define_method("sort!", &CppArray<int>::destructive_sort)
            .define_method("reverse", &CppArray<int>::reverse)
            .define_method("reverse!", &CppArray<int>::destructive_reverse);

        Data_Type<CppArray<double>> rb_cFloatArray = define_class_under<CppArray<double>>(rb_mTatara, "FloatArray")
            .define_constructor(Constructor<CppArray<double>>())
            .define_method("first", &CppArray<double>::first)
            .define_method("last", &CppArray<double>::last)
            .define_method("[]", &CppArray<double>::bracket)
            .define_method("[]=", &CppArray<double>::bracket_equal)
            .define_method("push", &CppArray<double>::emplace_back)
            .define_method("size", &CppArray<double>::size)
            .define_method("clear", &CppArray<double>::clear)
            .define_method("<<", &CppArray<double>::push_back_object)
            .define_method("intersection", &CppArray<double>::intersection)
            .define_method("sort", &CppArray<double>::sort)
            .define_method("sort!", &CppArray<double>::destructive_sort)
            .define_method("reverse", &CppArray<double>::reverse)
            .define_method("reverse!", &CppArray<double>::destructive_reverse);

        VALUE mTatara = rb_define_module("Tatara");

        VALUE rb_cStringArray = rb_define_class_under(mTatara, "StringArray", rb_cObject);

        rb_define_alloc_func(rb_cStringArray, wrap_string_array_alloc);
        rb_define_private_method(rb_cStringArray, "initialize", RUBY_METHOD_FUNC(wrap_string_array_init), 0);
        rb_define_method(rb_cStringArray, "first", RUBY_METHOD_FUNC(wrap_string_array_first), 0);
        rb_define_method(rb_cStringArray, "last", RUBY_METHOD_FUNC(wrap_string_array_last), 0);
        rb_define_method(rb_cStringArray, "[]", RUBY_METHOD_FUNC(wrap_string_array_bracket), 1);
        rb_define_method(rb_cStringArray, "[]=", RUBY_METHOD_FUNC(wrap_string_array_bracket_equal), 2);
        rb_define_method(rb_cStringArray, "push", RUBY_METHOD_FUNC(wrap_string_array_emplace_back), 1);
        rb_define_method(rb_cStringArray, "size", RUBY_METHOD_FUNC(wrap_string_array_size), 0);
        rb_define_method(rb_cStringArray, "clear", RUBY_METHOD_FUNC(wrap_string_array_clear), 0);
        rb_define_method(rb_cStringArray, "<<", RUBY_METHOD_FUNC(wrap_string_array_push_back_object), 1);

        VALUE rb_cStringIntMap = rb_define_class_under(mTatara, "StringIntMap", rb_cObject);

        rb_define_alloc_func(rb_cStringIntMap, wrap_string_int_map_alloc);
        rb_define_private_method(rb_cStringIntMap, "initialize", RUBY_METHOD_FUNC(wrap_string_int_map_init), 0);
        rb_define_method(rb_cStringIntMap, "[]", RUBY_METHOD_FUNC(wrap_string_int_map_bracket), 1);
        rb_define_method(rb_cStringIntMap, "[]=", RUBY_METHOD_FUNC(wrap_string_int_map_bracket_equal), 2);

        VALUE rb_cStringFloatMap = rb_define_class_under(mTatara, "StringFloatMap", rb_cObject);

        rb_define_alloc_func(rb_cStringFloatMap, wrap_string_float_map_alloc);
        rb_define_private_method(rb_cStringFloatMap, "initialize", RUBY_METHOD_FUNC(wrap_string_float_map_init), 0);
        rb_define_method(rb_cStringFloatMap, "[]", RUBY_METHOD_FUNC(wrap_string_float_map_bracket), 1);
        rb_define_method(rb_cStringFloatMap, "[]=", RUBY_METHOD_FUNC(wrap_string_float_map_bracket_equal), 2);

        VALUE rb_cStringStringMap = rb_define_class_under(mTatara, "StringStringMap", rb_cObject);

        rb_define_alloc_func(rb_cStringStringMap, wrap_string_string_map_alloc);
        rb_define_private_method(rb_cStringStringMap, "initialize", RUBY_METHOD_FUNC(wrap_string_string_map_init), 0);
        rb_define_method(rb_cStringStringMap, "[]", RUBY_METHOD_FUNC(wrap_string_string_map_bracket), 1);
        rb_define_method(rb_cStringStringMap, "[]=", RUBY_METHOD_FUNC(wrap_string_string_map_bracket_equal), 2);

        VALUE rb_cIntIntMap = rb_define_class_under(mTatara, "IntIntMap", rb_cObject);

        rb_define_alloc_func(rb_cIntIntMap, wrap_int_int_map_alloc);
        rb_define_private_method(rb_cIntIntMap, "initialize", RUBY_METHOD_FUNC(wrap_int_int_map_init), 0);
        rb_define_method(rb_cIntIntMap, "[]", RUBY_METHOD_FUNC(wrap_int_int_map_bracket), 1);
        rb_define_method(rb_cIntIntMap, "[]=", RUBY_METHOD_FUNC(wrap_int_int_map_bracket_equal), 2);

        VALUE rb_cIntFloatMap = rb_define_class_under(mTatara, "IntFloatMap", rb_cObject);

        rb_define_alloc_func(rb_cIntFloatMap, wrap_int_float_map_alloc);
        rb_define_private_method(rb_cIntFloatMap, "initialize", RUBY_METHOD_FUNC(wrap_int_float_map_init), 0);
        rb_define_method(rb_cIntFloatMap, "[]", RUBY_METHOD_FUNC(wrap_int_float_map_bracket), 1);
        rb_define_method(rb_cIntFloatMap, "[]=", RUBY_METHOD_FUNC(wrap_int_float_map_bracket_equal), 2);

        VALUE rb_cIntStringMap = rb_define_class_under(mTatara, "IntStringMap", rb_cObject);

        rb_define_alloc_func(rb_cIntStringMap, wrap_int_string_map_alloc);
        rb_define_private_method(rb_cIntStringMap, "initialize", RUBY_METHOD_FUNC(wrap_int_string_map_init), 0);
        rb_define_method(rb_cIntStringMap, "[]", RUBY_METHOD_FUNC(wrap_int_string_map_bracket), 1);
        rb_define_method(rb_cIntStringMap, "[]=", RUBY_METHOD_FUNC(wrap_int_string_map_bracket_equal), 2);

        VALUE rb_cFloatIntMap = rb_define_class_under(mTatara, "FloatIntMap", rb_cObject);

        rb_define_alloc_func(rb_cFloatIntMap, wrap_float_int_map_alloc);
        rb_define_private_method(rb_cFloatIntMap, "initialize", RUBY_METHOD_FUNC(wrap_float_int_map_init), 0);
        rb_define_method(rb_cFloatIntMap, "[]", RUBY_METHOD_FUNC(wrap_float_int_map_bracket), 1);
        rb_define_method(rb_cFloatIntMap, "[]=", RUBY_METHOD_FUNC(wrap_float_int_map_bracket_equal), 2);

        VALUE rb_cFloatFloatMap = rb_define_class_under(mTatara, "FloatFloatMap", rb_cObject);

        rb_define_alloc_func(rb_cFloatFloatMap, wrap_float_float_map_alloc);
        rb_define_private_method(rb_cFloatFloatMap, "initialize", RUBY_METHOD_FUNC(wrap_float_float_map_init), 0);
        rb_define_method(rb_cFloatFloatMap, "[]", RUBY_METHOD_FUNC(wrap_float_float_map_bracket), 1);
        rb_define_method(rb_cFloatFloatMap, "[]=", RUBY_METHOD_FUNC(wrap_float_float_map_bracket_equal), 2);

        VALUE rb_cFloatStringMap = rb_define_class_under(mTatara, "FloatStringMap", rb_cObject);

        rb_define_alloc_func(rb_cFloatStringMap, wrap_float_string_map_alloc);
        rb_define_private_method(rb_cFloatStringMap, "initialize", RUBY_METHOD_FUNC(wrap_float_string_map_init), 0);
        rb_define_method(rb_cFloatStringMap, "[]", RUBY_METHOD_FUNC(wrap_float_string_map_bracket), 1);
        rb_define_method(rb_cFloatStringMap, "[]=", RUBY_METHOD_FUNC(wrap_float_string_map_bracket_equal), 2);
    }
}