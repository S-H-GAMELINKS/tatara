#include <iostream>
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>

using namespace Rice;

extern "C" {
    void Init_tatara() {
        Rice::Module rb_mTatara = define_module("Tatara");
    }
} 