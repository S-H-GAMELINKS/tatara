#include <iostream>
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>

using namespace Rice;

class Tatara {
    public:
        Tatara();
};

Tatara::Tatara() { std::cout << "Hello Tatara!" << std::endl; }

extern "C" {
    void Init_test() {
        Data_Type<Tatara> rb_cTatara = define_class<Tatara>("Tatara")
            .define_constructor(Constructor<Tatara>());
    }
} 