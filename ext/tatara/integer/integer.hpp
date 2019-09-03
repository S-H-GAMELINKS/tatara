#ifndef INTEGER_H_
#define INTEGER_H_

#include <string>

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
        constexpr int plus_equal(int var);
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

constexpr int Integer::plus_equal(int var) {
    return this->value += var;
}

constexpr int Integer::clear() {
    return this->value = 0;
}

constexpr bool Integer::equal(const int var) {
    return this->value == var;
}

#endif