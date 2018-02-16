#include "BigInteger.h"

namespace euler {
    void BigInteger::init(const int num) {
        this->init(std::to_string(num));
    }

    void BigInteger::init(const std::string str) {
        this->value.clear();
        this->isNegative = str[0] == '-';
        for (int i = this->isNegative ? 1 : 0; i < str.length(); i++)
            this->value.push_back(str[i] - '0');
    }

    void BigInteger::init(const BigInteger& b) {
        this->value.clear();
        this->isNegative = b.isNegative;
        for (int i = b.digits() - 1; i >= 0; i--)
            this->value.push_back(b[i]);
    }
}
