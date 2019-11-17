#ifndef ARRAY__TEMPLATE_H_
#define ARRAY__TEMPLATE_H_

#include <algorithm>
#include <iterator>
#include <vector>

template <class T>
class CppArray {
        std::vector<T> container;
    public:
        constexpr CppArray();
        ~CppArray();
        constexpr T first();
        constexpr T last();
        constexpr T bracket(const int index);
        constexpr T bracket_equal(const int index, const T var);
        constexpr void emplace_back(const T var);
        constexpr int size();
        constexpr void clear();
        constexpr CppArray<T>& push_back_object(const T var);
        constexpr CppArray<T> duplicate(const CppArray<T> array);
        constexpr CppArray<T> sort();
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
constexpr T CppArray<T>::last(){
    return this->container.back();
}

template <class T>
constexpr T CppArray<T>::bracket(const int index) {
    return this->container[index];
}

template <class T>
constexpr T CppArray<T>::bracket_equal(const int index, const T var) {
    return this->container[index] = var;
}

template <class T>
constexpr void CppArray<T>::emplace_back(const T var) {
    this->container.emplace_back(var);
}

template <class T>
constexpr int CppArray<T>::size() {
    return this->container.size();
}

template <class T>
constexpr void CppArray<T>::clear() {
    this->container.clear();
}

template <class T>
constexpr CppArray<T>& CppArray<T>::push_back_object(const T var) {
    this->container.emplace_back(std::move(var));
    return *this;
}

template <class T>
constexpr CppArray<T> CppArray<T>::duplicate(const CppArray<T> array) {

    std::vector<T> result;

    std::set_intersection(
        this->container.begin(), this->container.end(),
        array.container.begin(), array.container.end(),
        std::inserter(result, result.end())
    );

    CppArray<T> object;

    object.container = std::move(result);

    return object;
}

template <class T>
constexpr CppArray<T> CppArray<T>::sort() {
    CppArray<T> object;
    object.container = this->container;
    std::sort(object.container.begin(), object.container.end());
    return object;
}

#endif
