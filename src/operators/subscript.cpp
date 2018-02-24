#include "../../include/BigInteger.h"

namespace euler {
    int& BigInteger::operator[](const int index) {
        if (index >= this->digits() || index < 0)
            throw std::length_error("length_error in BigInteger::operator[]");
        int& n = this->value.at(index); 
        return n;
    }

    int BigInteger::operator[](const int index) const {
        if (index >= this->digits() || index < 0)
            throw std::length_error("length_error in BigInteger::operator[]");
        return this->value.at(index); 
    }
}
