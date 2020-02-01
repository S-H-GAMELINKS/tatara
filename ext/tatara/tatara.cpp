#include <string>
#include "vector/vector.hpp"
#include "array/array.hpp"
#include "map/map.hpp"
#include "integer/integer.hpp"
#include "float/float.hpp"
#include "string/string.hpp"
#include "any/any.hpp"

extern "C" {
    void Init_tatara() {
        VALUE mTatara = rb_define_module("Tatara");

        // require Tatara::Integer
        Init_integer(mTatara);

        // require Tatara::Float
        Init_float(mTatara);

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

        // require Tatara::FloatArray
        Init_float_array(mTatara);

        // require Tatara::StringArray
        Init_string_array(mTatara);
        
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

        // require Tatara::Any impl
        Init_any(mTatara);
    }
}