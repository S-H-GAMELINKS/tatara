#ifndef STRING_H_
#define STRING_H_

#include <string>

class CppString {
        std::string value = "";
    public:
        CppString();
        ~CppString();
        CppString& initialize_object(const std::string var);
        std::string assignment(const std::string var);
        std::string return_value();
        std::string index_access(const int index);
        int to_integer();
        std::string plus_equal(const std::string var);
        std::string clear();
        bool equal(const std::string var);
        std::string slice(const int start, const int end);
        std::string slice_des(const int start, const int end);
};

CppString::CppString() {}

CppString::~CppString() {}

CppString& CppString::initialize_object(const std::string var) {
    this->value = var;
    return *this;
}

std::string CppString::assignment(const std::string var) {
    return this->value = var;
}

std::string CppString::return_value() {
    return this->value;
}

std::string CppString::index_access(const int index) {
    std::string s{this->value[index]};
    return s;
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

std::string CppString::slice(const int start, const int end) {
    return this->value.substr(start, end);
}

std::string CppString::slice_des(const int start, const int end) {
    this->value = this->value.substr(start, end);
    return this->value;
}

#endif
