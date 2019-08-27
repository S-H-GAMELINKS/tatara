#ifndef STRING_H_
#define STRING_H_

#include <string>

class CppString {
        std::string value;
    public:
        CppString();
        ~CppString();
        std::string assignment(const std::string var);
        std::string return_value();
        int to_integer();
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

#endif
