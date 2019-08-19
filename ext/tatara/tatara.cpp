#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include "vector/vector.hpp"

using namespace Rice;

extern "C" {
    void Init_tatara() {
        Rice::Module rb_mTatara = define_module("Tatara");

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
            .define_method("emplace_back", &Vector<double>::emplace_back)
            .define_method("size", &Vector<double>::size)
            .define_method("clear", &Vector<double>::clear);
    }
}