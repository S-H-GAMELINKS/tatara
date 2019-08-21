#ifndef FLOAT_H_
#define FLOAT_H_

class Float {
        double value;
    public:
        Float();
        ~Float();
        double assignment(const double var);
};

Float::Float(){}

Float::~Float(){}

double Float::assignment(const double var) {
    return this->value = var;
}

#endif