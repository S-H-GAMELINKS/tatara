#include <iostream>
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>

#include "vector/veci.hpp"

using namespace Rice;

extern "C" {
    void Init_tatara() {
        Rice::Module rb_mTatara = define_module("Tatara");

        Data_Type<Veci> rb_cVeci = define_class_under<Veci>(rb_mTatara, "Veci")
            .define_constructor(Constructor<Veci>())
            .define_method("first", &Veci::first)
            .define_method("last", &Veci::last)
            .define_method("[]", &Veci::bracket)
            .define_method("[]=", &Veci::bracket_equal)
            .define_method("emplace_back", &Veci::emplace_back, Arg("var"))
            .define_method("size", &Veci::size)
            .define_method("clear", &Veci::clear);
    }
} 