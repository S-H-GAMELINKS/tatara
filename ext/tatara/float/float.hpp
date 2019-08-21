#ifndef FLOAT_H_
#define FLOAT_H_

class Float {
        double value;
    public:
        Float();
        ~Float();
        double assignment(const double var);
        double return_value();
        double increment_value();
        double decrement_value();
};

Float::Float(){}

Float::~Float(){}

double Float::assignment(const double var) {
    return this->value = var;
}

double Float::return_value() {
    return this->value;
}

double Float::increment_value() {
    return this->value++;
}

double Float::decrement_value() {
    return this->value--;
}

#endif