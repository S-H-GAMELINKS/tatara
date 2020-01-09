#include <string>
#include "vector/vector.hpp"
#include "array/array.hpp"
#include "map/map.hpp"
#include "integer/integer.hpp"
#include "float/float.hpp"
#include "string/string.hpp"

extern "C" {
    void Init_tatara() {
        VALUE mTatara = rb_define_module("Tatara");

        VALUE rb_cInteger = rb_define_class_under(mTatara, "Integer", rb_cObject);

        rb_define_alloc_func(rb_cInteger, wrap_int_alloc);
        rb_define_private_method(rb_cInteger, "initialize", RUBY_METHOD_FUNC(wrap_int_init), 0);
        rb_define_method(rb_cInteger, "value", RUBY_METHOD_FUNC(wrap_int_return_value), 0);
        rb_define_alias(rb_cInteger, "val", "value");
        rb_define_method(rb_cInteger, "value=", RUBY_METHOD_FUNC(wrap_int_assignment), 1);
        rb_define_alias(rb_cInteger, "val=", "value=");
        rb_define_method(rb_cInteger, "value+", RUBY_METHOD_FUNC(wrap_int_plus), 1);
        rb_define_alias(rb_cInteger, "val+", "value+");
        rb_define_method(rb_cInteger, "value+=", RUBY_METHOD_FUNC(wrap_int_plus_equal), 1);
        rb_define_alias(rb_cInteger, "val+=", "value+=");
        rb_define_method(rb_cInteger, "value-", RUBY_METHOD_FUNC(wrap_int_minus), 1);
        rb_define_alias(rb_cInteger, "val-", "value-");
        rb_define_method(rb_cInteger, "value-=", RUBY_METHOD_FUNC(wrap_int_minus_equal), 1);
        rb_define_alias(rb_cInteger, "val-=", "value-=");
        rb_define_method(rb_cInteger, "value/", RUBY_METHOD_FUNC(wrap_int_divided), 1);
        rb_define_alias(rb_cInteger, "val/", "value/");
        rb_define_method(rb_cInteger, "value/=", RUBY_METHOD_FUNC(wrap_int_divided_equal), 1);
        rb_define_alias(rb_cInteger, "val/=", "value/=");
        rb_define_method(rb_cInteger, "value*", RUBY_METHOD_FUNC(wrap_int_multiply), 1);
        rb_define_alias(rb_cInteger, "val*", "value*");
        rb_define_method(rb_cInteger, "value*=", RUBY_METHOD_FUNC(wrap_int_multiply_equal), 1);
        rb_define_alias(rb_cInteger, "val*=", "value*=");
        rb_define_method(rb_cInteger, "value%", RUBY_METHOD_FUNC(wrap_int_mod), 1);
        rb_define_alias(rb_cInteger, "val%", "value%");
        rb_define_method(rb_cInteger, "value%=", RUBY_METHOD_FUNC(wrap_int_mod_equal), 1);
        rb_define_alias(rb_cInteger, "val%=", "value%=");
        rb_define_method(rb_cInteger, "value**", RUBY_METHOD_FUNC(wrap_int_power), 1);
        rb_define_alias(rb_cInteger, "val**", "value**");
        rb_define_method(rb_cInteger, "value**=", RUBY_METHOD_FUNC(wrap_int_power_equal), 1);
        rb_define_alias(rb_cInteger, "val**=", "value**=");
        rb_define_method(rb_cInteger, "increment", RUBY_METHOD_FUNC(wrap_int_increment_value), 0);
        rb_define_alias(rb_cInteger, "inc", "increment");
        rb_define_method(rb_cInteger, "decrement", RUBY_METHOD_FUNC(wrap_int_decrement_value), 0);
        rb_define_alias(rb_cInteger, "dec", "decrement");
        rb_define_method(rb_cInteger, "to_s", RUBY_METHOD_FUNC(wrap_int_to_string), 0);
        rb_define_method(rb_cInteger, "to_f", RUBY_METHOD_FUNC(wrap_int_to_float), 0);
        rb_define_method(rb_cInteger, "clear", RUBY_METHOD_FUNC(wrap_int_clear), 0);
        rb_define_method(rb_cInteger, "value==", RUBY_METHOD_FUNC(wrap_int_equal), 1);
        rb_define_alias(rb_cInteger, "val==", "value==");
        rb_define_alias(rb_cInteger, "equal?", "value==");
        rb_define_method(rb_cInteger, "<<", RUBY_METHOD_FUNC(wrap_int_initialize_object), 1);

        VALUE rb_cFloat = rb_define_class_under(mTatara, "Float", rb_cObject);

        rb_define_alloc_func(rb_cFloat, wrap_float_alloc);
        rb_define_private_method(rb_cFloat, "initialize", RUBY_METHOD_FUNC(wrap_float_init), 0);
        rb_define_method(rb_cFloat, "value", RUBY_METHOD_FUNC(wrap_float_return_value), 0);
        rb_define_alias(rb_cFloat, "val", "value");
        rb_define_method(rb_cFloat, "value=", RUBY_METHOD_FUNC(wrap_float_assignment), 1);
        rb_define_alias(rb_cFloat, "val=", "value=");
        rb_define_method(rb_cFloat, "value+", RUBY_METHOD_FUNC(wrap_float_plus), 1);
        rb_define_alias(rb_cFloat, "val+", "value+");
        rb_define_method(rb_cFloat, "value+=", RUBY_METHOD_FUNC(wrap_float_plus_equal), 1);
        rb_define_alias(rb_cFloat, "val+=", "value+=");
        rb_define_method(rb_cFloat, "value-", RUBY_METHOD_FUNC(wrap_float_minus), 1);
        rb_define_alias(rb_cFloat, "val-", "value-");
        rb_define_method(rb_cFloat, "value-=", RUBY_METHOD_FUNC(wrap_float_minus_equal), 1);
        rb_define_alias(rb_cFloat, "val-=", "value-=");
        rb_define_method(rb_cFloat, "value*", RUBY_METHOD_FUNC(wrap_float_multiply), 1);
        rb_define_alias(rb_cFloat, "val*", "value*");
        rb_define_method(rb_cFloat, "value*=", RUBY_METHOD_FUNC(wrap_float_multiply_equal), 1);
        rb_define_alias(rb_cFloat, "val*=", "value*=");
        rb_define_method(rb_cFloat, "value/", RUBY_METHOD_FUNC(wrap_float_divided), 1);
        rb_define_alias(rb_cFloat, "val/", "value/");
        rb_define_method(rb_cFloat, "value/=", RUBY_METHOD_FUNC(wrap_float_divided_equal), 1);
        rb_define_alias(rb_cFloat, "val/=", "value/=");
        rb_define_method(rb_cFloat, "value**", RUBY_METHOD_FUNC(wrap_float_power), 1);
        rb_define_alias(rb_cFloat, "val**", "value**");
        rb_define_method(rb_cFloat, "value**=", RUBY_METHOD_FUNC(wrap_float_power_equal), 1);
        rb_define_alias(rb_cFloat, "val**=", "value**=");
        rb_define_method(rb_cFloat, "inc", RUBY_METHOD_FUNC(wrap_float_increment_value), 0);
        rb_define_method(rb_cFloat, "dec", RUBY_METHOD_FUNC(wrap_float_decrement_value), 0);
        rb_define_method(rb_cFloat, "to_s", RUBY_METHOD_FUNC(wrap_float_to_string), 0);
        rb_define_method(rb_cFloat, "to_i", RUBY_METHOD_FUNC(wrap_float_to_integer), 0);
        rb_define_method(rb_cFloat, "clear", RUBY_METHOD_FUNC(wrap_float_clear), 0);
        rb_define_method(rb_cFloat, "value==", RUBY_METHOD_FUNC(wrap_float_equal), 1);
        rb_define_alias(rb_cFloat, "val==", "value==");
        rb_define_alias(rb_cFloat, "equal?", "value==");
        rb_define_method(rb_cFloat, "<<", RUBY_METHOD_FUNC(wrap_float_initialize_object), 1);

        // require Tatara::String impl
        Init_string(mTatara);

        // require Tatara::IntVector
        Init_int_vector(mTatara);

        // require Tatara::FloatVector
        Init_float_vector(mTatara);

        // require Tatara::StringVector
        Init_string_vector(mTatara);

        // require Tatara::IntArray
        Init_int_array(mTatara);

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
        rb_define_method(rb_cFloatArray, "map", RUBY_METHOD_FUNC(wrap_float_array_map), 0);
        rb_define_method(rb_cFloatArray, "map!", RUBY_METHOD_FUNC(wrap_float_array_destructive_map), 0);
        rb_define_alias(rb_cFloatArray, "each", "map");
        rb_define_method(rb_cFloatArray, "each_with_index", RUBY_METHOD_FUNC(wrap_float_array_each_with_index), 0);
        rb_define_method(rb_cFloatArray, "to_array", RUBY_METHOD_FUNC(wrap_float_array_convert_array), 0);
        rb_define_method(rb_cFloatArray, "import_array", RUBY_METHOD_FUNC(wrap_float_array_import_array), 1);
        rb_define_method(rb_cFloatArray, "sum", RUBY_METHOD_FUNC(wrap_float_array_sum), 0);
        rb_define_method(rb_cFloatArray, "intersection", RUBY_METHOD_FUNC(wrap_float_array_intersection), 1);
        rb_define_method(rb_cFloatArray, "sort", RUBY_METHOD_FUNC(wrap_float_array_sort), 0);

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
        rb_define_method(rb_cStringArray, "map", RUBY_METHOD_FUNC(wrap_string_array_map), 0);
        rb_define_method(rb_cStringArray, "map!", RUBY_METHOD_FUNC(wrap_string_array_destructive_map), 0);
        rb_define_alias(rb_cStringArray, "each", "map");
        rb_define_method(rb_cStringArray, "each_with_index", RUBY_METHOD_FUNC(wrap_string_array_each_with_index), 0);
        rb_define_method(rb_cStringArray, "to_array", RUBY_METHOD_FUNC(wrap_string_array_convert_array), 0);
        rb_define_method(rb_cStringArray, "import_array", RUBY_METHOD_FUNC(wrap_string_array_import_array), 1);
        rb_define_method(rb_cStringArray, "sum", RUBY_METHOD_FUNC(wrap_string_array_sum), 0);
        rb_define_method(rb_cStringArray, "intersection", RUBY_METHOD_FUNC(wrap_string_array_intersection), 1);
        rb_define_method(rb_cStringArray, "sort", RUBY_METHOD_FUNC(wrap_string_array_sort), 0);
        
        // require Tatara::StringIntMap impl
        Init_string_int_map(mTatara);

        // require Tatara::StringFloatMap impl
        Init_string_float_map(mTatara);

        // require Tatara::StringStringMap impl
        Init_string_string_map(mTatara);

        // require Tatara::IntIntMap impl
        Init_int_int_map(mTatara);

        // require Tatara::IntFloatMap impl
        Init_int_float_map(mTatara);

        // require Tatara::IntString impl
        Init_int_string_map(mTatara);

        // require Tatara::FloatIntMap impl
        Init_float_int_map(mTatara);

        // require Tatara::FloatFloatMap impl
        Init_float_float_map(mTatara);

        // require Tatara::FloatStringMap impl
        Init_float_string_map(mTatara);
    }
}