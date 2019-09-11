#ifndef ARRAY__TEMPLATE_H_
#define ARRAY__TEMPLATE_H_

#include <vector>

template <class T>
class CppArray {
        std::vector<T> container;
    public:
        CppArray();
        ~CppArray();
};

template <class T>
CppArray<T>::CppArray() {}

template <class T>
CppArray<T>::~CppArray() {}

#endif
