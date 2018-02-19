#include "../../include/BigInteger.h"

namespace euler {
    int& BigInteger::operator[](const int index) {
        int& n = this->value.at(index); 
        return n;
    }

    int BigInteger::operator[](const int index) const {
        return this->value.at(index); 
    }
}
