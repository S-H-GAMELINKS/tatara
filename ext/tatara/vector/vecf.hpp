#ifndef VECF_H_
#define VECF_H_

#include <vector>

class Vecf {
    std::vector<double> container;

    public:
        double first();
        double last();
        double bracket(const int index);
        double bracket_equal(const int index, const double var);
        void emplace_back(const double var);
        int size();
};

double Vecf::first() {
    return this->container.front();
}

double Vecf::last() {
    return this->container.back();
}

double Vecf::bracket(const int index) {
    return this->container[index];
}

double Vecf::bracket_equal(const int index, const double var) {
    return this->container[index] = var;
}

void Vecf::emplace_back(const double var) {
    this->container.emplace_back(std::move(var));
}

int Vecf::size() {
    return this->container.size();
}

#endif