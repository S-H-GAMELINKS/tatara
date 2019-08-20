#ifndef INTEGER_H_
#define INTEGER_H_

class Integer {
    int value;

    public:
        Integer();
        ~Integer();
        int assignment(const int var);
};

Integer::Integer(){}

Integer::~Integer(){}

int Integer::assignment(const int var) {
    return this->value = var;
}

#endif