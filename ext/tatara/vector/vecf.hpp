#ifndef VECF_H_
#define VECF_H_

#include <vector>

class Vecf {
    std::vector<double> container;

    public:
        int first();
        int last();
        double bracket();
        double bracket_equal(const int index, const double var);
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

double Vecf::bracket_equal(const int index, const double var) {
    return this->container[index] = var;
}

#endif