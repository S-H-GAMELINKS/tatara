#ifndef STRING_H_
#define STRING_H_

#include <string>

class CppString {
        std::string value = "";
    public:
        CppString();
        ~CppString();
        std::string assignment(const std::string var);
        std::string return_value();
        int to_integer();
        std::string plus_equal(const std::string var);
        std::string clear();
        bool equal(const std::string var);
};

CppString::CppString() {}

CppString::~CppString() {}

std::string CppString::assignment(const std::string var) {
    return this->value = var;
}

std::string CppString::return_value() {
    return this->value;
}

int CppString::to_integer() {
    return std::stoi(this->value);
}

std::string CppString::plus_equal(const std::string var) {
    return this->value += var;
}

std::string CppString::clear() {
    return this->value = "";
}

bool CppString::equal(const std::string var) {
    return this->value == var;
}

#endif
