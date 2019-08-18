#ifndef VECF_H_
#define VECF_H_

#include <vector>

class Vecf {
    std::vector<double> container;

    public:
        int first();
        int last();
        double bracket();
};

int Vecf::first() {
    return this->container.front();
}

int Vecf::last() {
    return this->container.back();
}

double Vecf::bracket(const int index) {
    return this->container[index];
}

#endif