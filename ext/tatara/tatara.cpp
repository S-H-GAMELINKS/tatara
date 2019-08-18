#include <iostream>
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>

#include "vector/veci.hpp"
#include "vector/vecf.hpp"

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

        Data_Type<Vecf> rb_cVecf = define_class_under<Vecf>(rb_mTatara, "Vecf")
            .define_constructor(Constructor<Vecf>())
            .define_method("first", &Vecf::first)
            .define_method("last", &Vecf::last)
            .define_method("[]", &Vecf::bracket)
            .define_method("[]=", &Vecf::bracket_equal);
    }
} 