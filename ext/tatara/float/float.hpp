#ifndef FLOAT_H_
#define FLOAT_H_

#include <string>
#include <regex>

class Float {
        double value = 0.0;
    public:
        constexpr Float();
        ~Float();
        constexpr double assignment(const double var);
        constexpr double return_value();
        constexpr double increment_value();
        constexpr double decrement_value();
        std::string to_string();
        constexpr int to_integer();
        constexpr double plus(const double var);
        constexpr double plus_equal(const double var);
        constexpr double minus(const double var);
        constexpr double minus_equal(const double var);
        constexpr double multiply(const double var);
        constexpr double multiply_equal(const double var);
        constexpr double divided(const double var);
        constexpr double divided_equal(const double var);
        constexpr double power_equal(const double var);
        constexpr double clear();
        constexpr bool equal(const double var);
};

constexpr Float::Float() {}

Float::~Float() {}

constexpr double Float::assignment(const double var) {
    return this->value = var;
}

constexpr double Float::return_value() {
    return this->value;
}

constexpr double Float::increment_value() {
    return this->value++;
}

constexpr double Float::decrement_value() {
    return this->value--;
}

std::string Float::to_string() {

    std::string null = "";

    std::regex re("0+");

    return std::regex_replace(std::to_string(this->value), re, null);
}

constexpr int Float::to_integer() {
    return static_cast<int>(this->value);
}

constexpr double Float::plus(const double var) {
    return this->value + var;
}

constexpr double Float::plus_equal(const double var) {
    return this->value += var;
}

constexpr double Float::minus(const double var) {
    return this->value - var;
}

constexpr double Float::minus_equal(const double var) {
    return this->value -= var;
}

constexpr double Float::multiply(const double var) {
    return this->value * var;
}

constexpr double Float::multiply_equal(const double var) {
    return this->value *= var;
}

constexpr double Float::divided(const double var) {
    return this->value / var;
}

constexpr double Float::divided_equal(const double var) {
    return this->value /= var;
}

constexpr double Float::power_equal(const double var) {
    return this->value = std::pow(this->value, var);
}

constexpr double Float::clear() {
    return this->value = 0.0;
}

constexpr bool Float::equal(const double var) {
    return this->value == var;
}

#endif