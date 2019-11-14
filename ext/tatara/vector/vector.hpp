#ifndef VEC_TEMPLATE_H_
#define VEC_TEMPLATE_H_

#include <algorithm>
#include <iterator>
#include <vector>

template <class T>
class Vector {
    std::vector<T> container;

    public:
        constexpr Vector();
        ~Vector();
        constexpr T first();
        constexpr T last();
        constexpr T bracket(const int index);
        constexpr T bracket_equal(const int index, const T var);
        constexpr void emplace_back(const T var);
        constexpr int size();
        constexpr void clear();
        T sum();
        constexpr Vector<T>& push_back_object(const T var);
        constexpr Vector<T> duplicate(const Vector<T> vec);
        constexpr Vector<T>& sort();
};

template <class T>
constexpr Vector<T>::Vector() {}

template <class T>
Vector<T>::~Vector() {}

template <class T>
constexpr T Vector<T>::first() {
    return this->container.front();
}

template <class T>
constexpr T Vector<T>::last() {
    return this->container.back();
}

template <class T>
constexpr T Vector<T>::bracket(const int index) {
    return this->container[index];
}

template <class T>
constexpr T Vector<T>::bracket_equal(const int index, const T var) {
    return this->container[index] = var;
}

template <class T>
constexpr void Vector<T>::emplace_back(const T var) {
    this->container.emplace_back(std::move(var));
}

template <class T>
constexpr int Vector<T>::size() {
    return this->container.size();
}

template <class T>
constexpr void Vector<T>::clear() {
    this->container.clear();
}

template <class T>
T Vector<T>::sum() {
    T sum;

    for (auto&& c : this->container)
        sum += c;

    return sum;
}

template <class T>
constexpr Vector<T>& Vector<T>::push_back_object(const T var) {
    this->container.emplace_back(std::move(var));
    return *this;
}

template <class T>
constexpr Vector<T> Vector<T>::duplicate(const Vector<T> vec) {

    std::vector<T> result;

    std::set_intersection(
        this->container.begin(), this->container.end(),
        vec.container.begin(), vec.container.end(),
        std::inserter(result, result.end())
    );

    Vector<T> object;

    object.container = std::move(result);

    return object;
}

template <class T>
constexpr Vector<T>& Vector<T>::sort() {
    std::sort(this->container.begin(), this->container.end());
    return *this;
}

#endif