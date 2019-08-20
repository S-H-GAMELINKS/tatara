#ifndef INTEGER_H_
#define INTEGER_H_

class Integer {
    int value;

    public:
        Integer();
        ~Integer();
        int assignment(const int var);
        int return_value();
        int increment_value();
};

Integer::Integer(){}

Integer::~Integer(){}

int Integer::assignment(const int var) {
    return this->value = var;
}

int Integer::return_value() {
    return this->value;
}

int Integer::increment_value() {
    return this->value++;
}

#endif