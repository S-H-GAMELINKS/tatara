#ifndef VEC_TEMPLATE_H_
#define VEC_TEMPLATE_H_

#include <vector>

template <class T>
class Vector {
    std::vector<T> container;

    public:
        Vector();
        T first();
        T last();
        T bracket(const int index);
        T bracket_equal(const int index, const T var);
        void emplace_back(const T var);
        int size();
        void clear();
};

template <class T>
Vector<T>::Vector() {}

template <class T>
T Vector<T>::first() {
    return this->container.front();
}

template <class T>
T Vector<T>::last() {
    return this->container.back();
}

template <class T>
T Vector<T>::bracket(const int index) {
    return this->container[index];
}

template <class T>
T Vector<T>::bracket_equal(const int index, const T var) {
    return this->container[index] = var;
}

template <class T>
void Vector<T>::emplace_back(const T var) {
    this->container.emplace_back(std::move(var));
}

template <class T>
int Vector<T>::size() {
    return this->container.size();
}

template <class T>
void Vector<T>::clear() {
    this->container.clear();
}

#endif