#ifndef INTEGER_H_
#define INTEGER_H_

#include <string>
#include <cmath>

class Integer {
    int value = 0;

    public:
        constexpr Integer();
        ~Integer();
        constexpr int assignment(const int var);
        constexpr int return_value();
        constexpr int increment_value();
        constexpr int decrement_value();
        std::string to_string();
        constexpr int plus(int var);
        constexpr int plus_equal(int var);
        constexpr int minus(int var);
        constexpr int minus_equal(int var);
        constexpr int divided(int var);
        constexpr int divided_equal(int var);
        constexpr int multiply(int var);
        constexpr int multiply_equal(int var);
        constexpr int power_equal(int var);
        constexpr int clear();
        constexpr bool equal(const int var);
};

constexpr Integer::Integer() {}

Integer::~Integer(){}

constexpr int Integer::assignment(const int var) {
    return this->value = var;
}

constexpr int Integer::return_value() {
    return this->value;
}

constexpr int Integer::increment_value() {
    return this->value++;
}

constexpr int Integer::decrement_value() {
    return this->value--;
}

std::string Integer::to_string() {
    return std::to_string(this->value);
}

constexpr int Integer::plus(int var) {
    return this->value + var;
}

constexpr int Integer::plus_equal(int var) {
    return this->value += var;
}

constexpr int Integer::minus(int var) {
    return this->value - var;
}

constexpr int Integer::minus_equal(int var) {
    return this->value -= var;
}

constexpr int Integer::divided(int var) {
    return this->value / var;
}

constexpr int Integer::divided_equal(int var) {
    return this->value /= var;
}

constexpr int Integer::multiply(int var) {
    return this->value * var;
}

constexpr int Integer::multiply_equal(int var) {
    return this->value *= var;
}

constexpr int Integer::power_equal(int var) {
    return this->value = std::pow(this->value, var);
}

constexpr int Integer::clear() {
    return this->value = 0;
}

constexpr bool Integer::equal(const int var) {
    return this->value == var;
}

#endif