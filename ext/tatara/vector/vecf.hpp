#ifndef VECF_H_
#define VECF_H_

#include <vector>

class Vecf {
    std::vector<double> container;

    public:
        int first();
};

int Vecf::first() {
    return this->container.front();
}

#endif