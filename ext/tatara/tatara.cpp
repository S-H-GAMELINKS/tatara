#include <string>
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include "vector/vector.hpp"
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
            .define_method("value=", &Integer::assignment, Arg("var"))
            .define_method("value+=", &Integer::plus_equal, Arg("var"))
            .define_method("inc", &Integer::increment_value)
            .define_method("dec", &Integer::decrement_value)
            .define_method("to_s", &Integer::to_string)
            .define_method("clear", &Integer::clear)
            .define_method("value==", &Integer::equal, Arg("var"));

        Data_Type<Float> rbcFloat = define_class_under<Float>(rb_mTatara, "Float")
            .define_constructor(Constructor<Float>())
            .define_method("value", &Float::return_value)
            .define_method("value=", &Float::assignment, Arg("var"))
            .define_method("value+=", &Float::plus_equal, Arg("var"))
            .define_method("inc", &Float::increment_value)
            .define_method("dec", &Float::decrement_value)
            .define_method("to_s", &Float::to_string)
            .define_method("to_i", &Float::to_integer)
            .define_method("clear", &Float::clear);

        Data_Type<CppString> rbcString = define_class_under<CppString>(rb_mTatara, "String")
            .define_constructor(Constructor<CppString>())
            .define_method("value", &CppString::return_value)
            .define_method("value=", &CppString::assignment, Arg("var"))
            .define_method("value+=", &CppString::plus_equal, Arg("var"))
            .define_method("to_i", &CppString::to_integer)
            .define_method("clear", &CppString::clear);

        Data_Type<Vector<int>> rb_cVeci = define_class_under<Vector<int>>(rb_mTatara, "Veci")
            .define_constructor(Constructor<Vector<int>>())
            .define_method("first", &Vector<int>::first)
            .define_method("last", &Vector<int>::last)
            .define_method("[]", &Vector<int>::bracket)
            .define_method("[]=", &Vector<int>::bracket_equal)
            .define_method("emplace_back", &Vector<int>::emplace_back, Arg("var"))
            .define_method("size", &Vector<int>::size)
            .define_method("clear", &Vector<int>::clear);

        Data_Type<Vector<double>> rb_cVecf = define_class_under<Vector<double>>(rb_mTatara, "Vecf")
            .define_constructor(Constructor<Vector<double>>())
            .define_method("first", &Vector<double>::first)
            .define_method("last", &Vector<double>::last)
            .define_method("[]", &Vector<double>::bracket)
            .define_method("[]=", &Vector<double>::bracket_equal)
            .define_method("emplace_back", &Vector<double>::emplace_back, Arg("var"))
            .define_method("size", &Vector<double>::size)
            .define_method("clear", &Vector<double>::clear);

        Data_Type<Vector<std::string>> rb_cVecs = define_class_under<Vector<std::string>>(rb_mTatara, "Vecs")
            .define_constructor(Constructor<Vector<std::string>>())
            .define_method("first", &Vector<std::string>::first)
            .define_method("last", &Vector<std::string>::last)
            .define_method("[]", &Vector<std::string>::bracket)
            .define_method("[]=", &Vector<std::string>::bracket_equal)
            .define_method("emplace_back", &Vector<std::string>::emplace_back, Arg("var"))
            .define_method("size", &Vector<std::string>::size)
            .define_method("clear", &Vector<std::string>::clear);
    }
}