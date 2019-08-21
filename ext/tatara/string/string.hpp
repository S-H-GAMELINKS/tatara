#ifndef STRING_H_
#define STRING_H_

#include <string>

class CppString {
        std::string value;
    public:
        CppString();
        ~CppString();
        std::string assignment(const std::string var);
};

CppString::CppString() {}

CppString::~CppString() {}

std::string CppString::assignment(const std::string var) {
    return this->value = var;
}

#endif
