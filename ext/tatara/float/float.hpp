#ifndef FLOAT_H_
#define FLOAT_H_

#include <string>
#include <regex>

class Float {
        double value;
    public:
        Float();
        ~Float();
        double assignment(const double var);
        double return_value();
        double increment_value();
        double decrement_value();
        std::string to_string();
        int to_integer();
        double plus_equal(const double var);
};

Float::Float(){}

Float::~Float(){}

double Float::assignment(const double var) {
    return this->value = var;
}

double Float::return_value() {
    return this->value;
}

double Float::increment_value() {
    return this->value++;
}

double Float::decrement_value() {
    return this->value--;
}

std::string Float::to_string() {

    std::string null = "";

    std::regex re("0+");

    return std::regex_replace(std::to_string(this->value), re, null);
}

int Float::to_integer() {
    return static_cast<int>(this->value);
}

double Float::plus_equal(const double var) {

    this->value += var;

    std::string null = "";

    std::regex re("0+");

    return this->value = static_cast<double>(std::regex_replace(std::to_string(this->value), re, null));
}

#endif