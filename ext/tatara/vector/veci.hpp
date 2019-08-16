#ifndef VECI_H_
#define VECI_H_

#include <iostream>
#include <vector>

class Veci {
    std::vector<int> container;

    public:
        int first();
        void emplace_back(const int var);
};

int Veci::first() {
    return *this->container.begin();;
}

void Veci::emplace_back(const int var) {
    this->container.emplace_back(std::move(var));
}

#endif