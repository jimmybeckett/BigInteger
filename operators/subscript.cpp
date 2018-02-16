#include "../BigInteger.h"

namespace euler {
    int& BigInteger::operator[](const int index) {
        int& n = this->value.at(this->digits() - index - 1); 
        return n;
    }

    int BigInteger::operator[](const int index) const {
        return this->value.at(this->digits() - index - 1); 
    }
}
