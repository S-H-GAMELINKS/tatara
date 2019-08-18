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
        int bracket_equal(const int index, const int var);
        void emplace_back(const int var);
        int size();
        void clear();
};

int Veci::first() {
    return this->container.front();
}

int Veci::last() {
    return this->container.back();
}

int Veci::bracket(const int index) {
    return this->container[index];
}

int Veci::bracket_equal(const int index, const int var) {
    return this->container[index] = var;
}

void Veci::emplace_back(const int var) {
    this->container.emplace_back(std::move(var));
}

int Veci::size() {
    return this->container.size();
}

void Veci::clear() {
    this->container.clear();
}

#endif