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
            .define_method("emplace_back", &Veci::emplace_back, Arg("var"))
            .define_method("first", &Veci::first);
    }
} 