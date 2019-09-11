#ifndef ARRAY__TEMPLATE_H_
#define ARRAY__TEMPLATE_H_

#include <vector>

template <class T>
class CppArray {
        std::vector<T> container;
    public:
        constexpr CppArray();
        ~CppArray();
        constexpr T first();
        constexpr void emplace_back(const T value);
};

template <class T>
constexpr CppArray<T>::CppArray() {}

template <class T>
CppArray<T>::~CppArray() {}

template <class T>
constexpr T CppArray<T>::first() {
    return this->container.front();
}

template <class T>
constexpr void CppArray<T>::emplace_back(const T value) {
    this->container.emplace_back(value);
}

#endif
