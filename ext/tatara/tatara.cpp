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

        VALUE mTatara = rb_define_module("Tatara");

        VALUE rb_cFloat = rb_define_class_under(mTatara, "Float", rb_cObject);

        rb_define_alloc_func(rb_cFloat, wrap_float_alloc);
        rb_define_private_method(rb_cFloat, "initialize", RUBY_METHOD_FUNC(wrap_float_init), 0);
        rb_define_method(rb_cFloat, "value", RUBY_METHOD_FUNC(wrap_float_return_value), 0);
        rb_define_method(rb_cFloat, "val", RUBY_METHOD_FUNC(wrap_float_return_value), 0);
        rb_define_method(rb_cFloat, "value=", RUBY_METHOD_FUNC(wrap_float_assignment), 1);
        rb_define_method(rb_cFloat, "val=", RUBY_METHOD_FUNC(wrap_float_assignment), 1);
        rb_define_method(rb_cFloat, "value+", RUBY_METHOD_FUNC(wrap_float_plus), 1);
        rb_define_method(rb_cFloat, "val+", RUBY_METHOD_FUNC(wrap_float_plus), 1);
        rb_define_method(rb_cFloat, "value+=", RUBY_METHOD_FUNC(wrap_float_plus_equal), 1);
        rb_define_method(rb_cFloat, "val+=", RUBY_METHOD_FUNC(wrap_float_plus_equal), 1);
        rb_define_method(rb_cFloat, "value-", RUBY_METHOD_FUNC(wrap_float_minus), 1);
        rb_define_method(rb_cFloat, "val-", RUBY_METHOD_FUNC(wrap_float_minus), 1);
        rb_define_method(rb_cFloat, "value-=", RUBY_METHOD_FUNC(wrap_float_minus_equal), 1);
        rb_define_method(rb_cFloat, "val-=", RUBY_METHOD_FUNC(wrap_float_minus_equal), 1);
        rb_define_method(rb_cFloat, "value*", RUBY_METHOD_FUNC(wrap_float_multiply), 1);
        rb_define_method(rb_cFloat, "val*", RUBY_METHOD_FUNC(wrap_float_multiply), 1);
        rb_define_method(rb_cFloat, "value*=", RUBY_METHOD_FUNC(wrap_float_multiply_equal), 1);
        rb_define_method(rb_cFloat, "val*=", RUBY_METHOD_FUNC(wrap_float_multiply_equal), 1);
        rb_define_method(rb_cFloat, "value/", RUBY_METHOD_FUNC(wrap_float_divided), 1);
        rb_define_method(rb_cFloat, "val/", RUBY_METHOD_FUNC(wrap_float_divided), 1);
        rb_define_method(rb_cFloat, "value/=", RUBY_METHOD_FUNC(wrap_float_divided_equal), 1);
        rb_define_method(rb_cFloat, "val/=", RUBY_METHOD_FUNC(wrap_float_divided_equal), 1);
        rb_define_method(rb_cFloat, "value**", RUBY_METHOD_FUNC(wrap_float_power), 1);
        rb_define_method(rb_cFloat, "val**", RUBY_METHOD_FUNC(wrap_float_power), 1);
        rb_define_method(rb_cFloat, "value**=", RUBY_METHOD_FUNC(wrap_float_power_equal), 1);
        rb_define_method(rb_cFloat, "val**=", RUBY_METHOD_FUNC(wrap_float_power_equal), 1);
        rb_define_method(rb_cFloat, "inc", RUBY_METHOD_FUNC(wrap_float_increment_value), 0);
        rb_define_method(rb_cFloat, "dec", RUBY_METHOD_FUNC(wrap_float_decrement_value), 0);
        rb_define_method(rb_cFloat, "to_s", RUBY_METHOD_FUNC(wrap_float_to_string), 0);
        rb_define_method(rb_cFloat, "to_i", RUBY_METHOD_FUNC(wrap_float_to_integer), 0);
        rb_define_method(rb_cFloat, "clear", RUBY_METHOD_FUNC(wrap_float_clear), 0);
        rb_define_method(rb_cFloat, "value==", RUBY_METHOD_FUNC(wrap_float_equal), 1);
        rb_define_method(rb_cFloat, "val==", RUBY_METHOD_FUNC(wrap_float_equal), 1);
        rb_define_method(rb_cFloat, "equal?", RUBY_METHOD_FUNC(wrap_float_equal), 1);
        rb_define_method(rb_cFloat, "<<", RUBY_METHOD_FUNC(wrap_float_initialize_object), 1);

        VALUE rb_cString = rb_define_class_under(mTatara, "String", rb_cObject);

        rb_define_alloc_func(rb_cString, wrap_string_alloc);
        rb_define_private_method(rb_cString, "initialize", RUBY_METHOD_FUNC(wrap_string_init), 0);
        rb_define_method(rb_cString, "value", RUBY_METHOD_FUNC(wrap_string_return_value), 0);
        rb_define_method(rb_cString, "val", RUBY_METHOD_FUNC(wrap_string_return_value), 0);
        rb_define_method(rb_cString, "value=", RUBY_METHOD_FUNC(wrap_string_assignment), 1);
        rb_define_method(rb_cString, "val=", RUBY_METHOD_FUNC(wrap_string_assignment), 1);
        rb_define_method(rb_cString, "value+=", RUBY_METHOD_FUNC(wrap_string_plus_equal), 1);
        rb_define_method(rb_cString, "val+=", RUBY_METHOD_FUNC(wrap_string_plus_equal), 1);
        rb_define_method(rb_cString, "to_i", RUBY_METHOD_FUNC(wrap_string_to_integer), 0);
        rb_define_method(rb_cString, "to_f", RUBY_METHOD_FUNC(wrap_string_to_float), 0);
        rb_define_method(rb_cString, "clear", RUBY_METHOD_FUNC(wrap_string_clear), 0);
        rb_define_method(rb_cString, "value==", RUBY_METHOD_FUNC(wrap_string_equal), 1);
        rb_define_method(rb_cString, "val==", RUBY_METHOD_FUNC(wrap_string_equal), 1);
        rb_define_method(rb_cString, "equal?", RUBY_METHOD_FUNC(wrap_string_equal), 1);
        rb_define_method(rb_cString, "<<", RUBY_METHOD_FUNC(wrap_string_initialize_object), 1);
        rb_define_method(rb_cString, "[]", RUBY_METHOD_FUNC(wrap_string_index_access), 1);
        rb_define_method(rb_cString, "slice", RUBY_METHOD_FUNC(wrap_string_slice), 2);
        rb_define_method(rb_cString, "slice!", RUBY_METHOD_FUNC(wrap_string_destructive_slice), 2);

        VALUE rb_cIntVector = rb_define_class_under(mTatara, "IntVector", rb_cObject);

        rb_define_alloc_func(rb_cIntVector, wrap_int_vector_alloc);
        rb_define_private_method(rb_cIntVector, "initialize", RUBY_METHOD_FUNC(wrap_int_vector_init), 0);
        rb_define_method(rb_cIntVector, "first", RUBY_METHOD_FUNC(wrap_int_vector_first), 0);
        rb_define_method(rb_cIntVector, "last", RUBY_METHOD_FUNC(wrap_int_vector_last), 0);
        rb_define_method(rb_cIntVector, "[]", RUBY_METHOD_FUNC(wrap_int_vector_bracket), 1);
        rb_define_method(rb_cIntVector, "[]=", RUBY_METHOD_FUNC(wrap_int_vector_bracket_equal), 2);
        rb_define_method(rb_cIntVector, "emplace_back", RUBY_METHOD_FUNC(wrap_int_vector_emplace_back), 1);
        rb_define_method(rb_cIntVector, "size", RUBY_METHOD_FUNC(wrap_int_vector_size), 0);
        rb_define_method(rb_cIntVector, "clear", RUBY_METHOD_FUNC(wrap_int_vector_clear), 0);
        rb_define_method(rb_cIntVector, "<<", RUBY_METHOD_FUNC(wrap_int_vector_push_back_object), 1);

        VALUE rb_cFloatVector = rb_define_class_under(mTatara, "FloatVector", rb_cObject);

        rb_define_alloc_func(rb_cFloatVector, wrap_float_vector_alloc);
        rb_define_private_method(rb_cFloatVector, "initialize", RUBY_METHOD_FUNC(wrap_float_vector_init), 0);
        rb_define_method(rb_cFloatVector, "first", RUBY_METHOD_FUNC(wrap_float_vector_first), 0);
        rb_define_method(rb_cFloatVector, "last", RUBY_METHOD_FUNC(wrap_float_vector_last), 0);
        rb_define_method(rb_cFloatVector, "[]", RUBY_METHOD_FUNC(wrap_float_vector_bracket), 1);
        rb_define_method(rb_cFloatVector, "[]=", RUBY_METHOD_FUNC(wrap_float_vector_bracket_equal), 2);
        rb_define_method(rb_cFloatVector, "emplace_back", RUBY_METHOD_FUNC(wrap_float_vector_emplace_back), 1);
        rb_define_method(rb_cFloatVector, "size", RUBY_METHOD_FUNC(wrap_float_vector_size), 0);
        rb_define_method(rb_cFloatVector, "clear", RUBY_METHOD_FUNC(wrap_float_vector_clear), 0);
        rb_define_method(rb_cFloatVector, "<<", RUBY_METHOD_FUNC(wrap_float_vector_push_back_object), 1);

        VALUE rb_cStringVector = rb_define_class_under(mTatara, "StringVector", rb_cObject);

        rb_define_alloc_func(rb_cStringVector, wrap_string_vector_alloc);
        rb_define_private_method(rb_cStringVector, "initialize", RUBY_METHOD_FUNC(wrap_string_vector_init), 0);
        rb_define_method(rb_cStringVector, "first", RUBY_METHOD_FUNC(wrap_string_vector_first), 0);
        rb_define_method(rb_cStringVector, "last", RUBY_METHOD_FUNC(wrap_string_vector_last), 0);
        rb_define_method(rb_cStringVector, "[]", RUBY_METHOD_FUNC(wrap_string_vector_bracket), 1);
        rb_define_method(rb_cStringVector, "[]=", RUBY_METHOD_FUNC(wrap_string_vector_bracket_equal), 2);
        rb_define_method(rb_cStringVector, "emplace_back", RUBY_METHOD_FUNC(wrap_string_vector_emplace_back), 1);
        rb_define_method(rb_cStringVector, "size", RUBY_METHOD_FUNC(wrap_string_vector_size), 0);
        rb_define_method(rb_cStringVector, "clear", RUBY_METHOD_FUNC(wrap_string_vector_clear), 0);
        rb_define_method(rb_cStringVector, "<<", RUBY_METHOD_FUNC(wrap_string_vector_push_back_object), 1);

        VALUE rb_cIntArray = rb_define_class_under(mTatara, "IntArray", rb_cObject);

        rb_define_alloc_func(rb_cIntArray, wrap_int_array_alloc);
        rb_define_private_method(rb_cIntArray, "initialize", RUBY_METHOD_FUNC(wrap_int_array_init), 0);
        rb_define_method(rb_cIntArray, "first", RUBY_METHOD_FUNC(wrap_int_array_first), 0);
        rb_define_method(rb_cIntArray, "last", RUBY_METHOD_FUNC(wrap_int_array_last), 0);
        rb_define_method(rb_cIntArray, "[]", RUBY_METHOD_FUNC(wrap_int_array_bracket), 1);
        rb_define_method(rb_cIntArray, "[]=", RUBY_METHOD_FUNC(wrap_int_array_bracket_equal), 2);
        rb_define_method(rb_cIntArray, "push", RUBY_METHOD_FUNC(wrap_int_array_emplace_back), 1);
        rb_define_method(rb_cIntArray, "size", RUBY_METHOD_FUNC(wrap_int_array_size), 0);
        rb_define_method(rb_cIntArray, "clear", RUBY_METHOD_FUNC(wrap_int_array_clear), 0);
        rb_define_method(rb_cIntArray, "<<", RUBY_METHOD_FUNC(wrap_int_array_push_back_object), 1);

        VALUE rb_cFloatArray = rb_define_class_under(mTatara, "FloatArray", rb_cObject);

        rb_define_alloc_func(rb_cFloatArray, wrap_float_array_alloc);
        rb_define_private_method(rb_cFloatArray, "initialize", RUBY_METHOD_FUNC(wrap_float_array_init), 0);
        rb_define_method(rb_cFloatArray, "first", RUBY_METHOD_FUNC(wrap_float_array_first), 0);
        rb_define_method(rb_cFloatArray, "last", RUBY_METHOD_FUNC(wrap_float_array_last), 0);
        rb_define_method(rb_cFloatArray, "[]", RUBY_METHOD_FUNC(wrap_float_array_bracket), 1);
        rb_define_method(rb_cFloatArray, "[]=", RUBY_METHOD_FUNC(wrap_float_array_bracket_equal), 2);
        rb_define_method(rb_cFloatArray, "push", RUBY_METHOD_FUNC(wrap_float_array_emplace_back), 1);
        rb_define_method(rb_cFloatArray, "size", RUBY_METHOD_FUNC(wrap_float_array_size), 0);
        rb_define_method(rb_cFloatArray, "clear", RUBY_METHOD_FUNC(wrap_float_array_clear), 0);
        rb_define_method(rb_cFloatArray, "<<", RUBY_METHOD_FUNC(wrap_float_array_push_back_object), 1);

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