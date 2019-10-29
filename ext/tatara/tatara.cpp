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
            .define_method("[]", &Integer::initialize_object);

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
            .define_method("value==", &Float::equal);

        Data_Type<CppString> rbcString = define_class_under<CppString>(rb_mTatara, "String")
            .define_constructor(Constructor<CppString>())
            .define_method("value", &CppString::return_value)
            .define_method("val", &CppString::return_value)
            .define_method("value=", &CppString::assignment)
            .define_method("val=", &CppString::assignment)
            .define_method("value+=", &CppString::plus_equal)
            .define_method("val+=", &CppString::plus_equal)
            .define_method("to_i", &CppString::to_integer)
            .define_method("clear", &CppString::clear)
            .define_method("value==", &CppString::equal)
            .define_method("val==", &CppString::equal)
            .define_method("[]", &CppString::initialize_object);

        Data_Type<Vector<int>> rb_cIntVector = define_class_under<Vector<int>>(rb_mTatara, "IntVector")
            .define_constructor(Constructor<Vector<int>>())
            .define_method("first", &Vector<int>::first)
            .define_method("last", &Vector<int>::last)
            .define_method("[]", &Vector<int>::bracket)
            .define_method("[]=", &Vector<int>::bracket_equal)
            .define_method("emplace_back", &Vector<int>::emplace_back)
            .define_method("size", &Vector<int>::size)
            .define_method("clear", &Vector<int>::clear)
            .define_method("sum", &Vector<int>::sum);

        Data_Type<Vector<double>> rb_cFloatVector = define_class_under<Vector<double>>(rb_mTatara, "FloatVector")
            .define_constructor(Constructor<Vector<double>>())
            .define_method("first", &Vector<double>::first)
            .define_method("last", &Vector<double>::last)
            .define_method("[]", &Vector<double>::bracket)
            .define_method("[]=", &Vector<double>::bracket_equal)
            .define_method("emplace_back", &Vector<double>::emplace_back)
            .define_method("size", &Vector<double>::size)
            .define_method("clear", &Vector<double>::clear)
            .define_method("sum", &Vector<double>::sum);

        Data_Type<Vector<std::string>> rb_cStringVector = define_class_under<Vector<std::string>>(rb_mTatara, "StringVector")
            .define_constructor(Constructor<Vector<std::string>>())
            .define_method("first", &Vector<std::string>::first)
            .define_method("last", &Vector<std::string>::last)
            .define_method("[]", &Vector<std::string>::bracket)
            .define_method("[]=", &Vector<std::string>::bracket_equal)
            .define_method("emplace_back", &    Vector<std::string>::emplace_back)
            .define_method("size", &Vector<std::string>::size)
            .define_method("clear", &Vector<std::string>::clear)
            .define_method("sum", &Vector<std::string>::sum);

        Data_Type<CppArray<int>> rb_cIntArray = define_class_under<CppArray<int>>(rb_mTatara, "IntArray")
            .define_constructor(Constructor<CppArray<int>>())
            .define_method("first", &CppArray<int>::first)
            .define_method("last", &CppArray<int>::last)
            .define_method("[]", &CppArray<int>::bracket)
            .define_method("[]=", &CppArray<int>::bracket_equal)
            .define_method("push", &CppArray<int>::emplace_back)
            .define_method("size", &CppArray<int>::size)
            .define_method("clear", &CppArray<int>::clear);

        Data_Type<CppArray<double>> rb_cFloatArray = define_class_under<CppArray<double>>(rb_mTatara, "FloatArray")
            .define_constructor(Constructor<CppArray<double>>())
            .define_method("first", &CppArray<double>::first)
            .define_method("last", &CppArray<double>::last)
            .define_method("[]", &CppArray<double>::bracket)
            .define_method("[]=", &CppArray<double>::bracket_equal)
            .define_method("push", &CppArray<double>::emplace_back)
            .define_method("size", &CppArray<double>::size)
            .define_method("clear", &CppArray<double>::clear);

        Data_Type<CppArray<std::string>> rb_cStringArray = define_class_under<CppArray<std::string>>(rb_mTatara, "StringArray")
            .define_constructor(Constructor<CppArray<std::string>>())
            .define_method("first", &CppArray<std::string>::first)
            .define_method("last", &CppArray<std::string>::last)
            .define_method("[]", &CppArray<std::string>::bracket)
            .define_method("[]=", &CppArray<std::string>::bracket_equal)            
            .define_method("push", &CppArray<std::string>::emplace_back)
            .define_method("size", &CppArray<std::string>::size)
            .define_method("clear", &CppArray<std::string>::clear);

        Data_Type<Map<std::string, int>> rb_cStringIntMap = define_class_under<Map<std::string, int>>(rb_mTatara, "StringIntMap")
            .define_constructor(Constructor<Map<std::string, int>>())
            .define_method("[]", &Map<std::string, int>::bracket)
            .define_method("[]=", &Map<std::string, int>::bracket_equal);

        Data_Type<Map<std::string, double>> rb_cStringFloatMap = define_class_under<Map<std::string, double>>(rb_mTatara, "StringFloatMap")
            .define_constructor(Constructor<Map<std::string, double>>())
            .define_method("[]", &Map<std::string, double>::bracket)
            .define_method("[]=", &Map<std::string, double>::bracket_equal);

        Data_Type<Map<std::string, std::string>> rb_cStringStringMap = define_class_under<Map<std::string, std::string>>(rb_mTatara, "StringStringMap")
            .define_constructor(Constructor<Map<std::string, std::string>>())
            .define_method("[]", &Map<std::string, std::string>::bracket)
            .define_method("[]=", &Map<std::string, std::string>::bracket_equal);

        Data_Type<Map<int, int>> rb_cIntIntMap = define_class_under<Map<int, int>>(rb_mTatara, "IntIntMap")
            .define_constructor(Constructor<Map<int, int>>())
            .define_method("[]", &Map<int, int>::bracket)
            .define_method("[]=", &Map<int, int>::bracket_equal);
    }
}