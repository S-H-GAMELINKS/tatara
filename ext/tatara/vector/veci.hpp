#ifndef VECI_H_
#define VECI_H_

#include <iostream>
#include <vector>

class Veci {
    std::vector<int> container;

    public:
        int first();
        int last();
        int bracket(const int index);
        void emplace_back(const int var);
};

int Veci::first() {
    return *this->container.begin();;
}

int Veci::last() {
    return this->container.back();;
}

int Veci::bracket(const int index) {
    return this->container[index];
}

void Veci::emplace_back(const int var) {
    this->container.emplace_back(std::move(var));
}

#endif