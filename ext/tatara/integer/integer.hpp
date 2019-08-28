#ifndef INTEGER_H_
#define INTEGER_H_

#include <string>

class Integer {
    int value;

    public:
        Integer();
        ~Integer();
        int assignment(const int var);
        int return_value();
        int increment_value();
        int decrement_value();
        std::string to_string();
        int clear();
};

Integer::Integer(){}

Integer::~Integer(){}

int Integer::assignment(const int var) {
    return this->value = var;
}

int Integer::return_value() {
    return this->value;
}

int Integer::increment_value() {
    return this->value++;
}

int Integer::decrement_value() {
    return this->value--;
}

std::string Integer::to_string() {
    return std::to_string(this->value);
}

int Integer::clear() {
    return this->value = 0;
}

#endif