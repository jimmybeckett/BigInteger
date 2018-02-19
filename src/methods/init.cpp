#include "../../include/BigInteger.h"

namespace euler {
    void BigInteger::init(const std::string str) {
        this->value.clear();
        this->isNegative = str[0] == '-';
        for (int i = this->isNegative ? 1 : 0; i < str.length(); i++)
            this->addToBack(str[i] - '0');
        this->trim();
    }

    void BigInteger::init(const BigInteger& b) {
        this->value.clear();
        this->isNegative = b.isNegative;
        for (int i = 0; i < b.digits(); i++)
            this->addToBack(b[i]);
    }
}
