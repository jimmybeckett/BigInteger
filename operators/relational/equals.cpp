#include "../../BigInteger.h"

namespace euler {
    bool BigInteger::operator==(const BigInteger& b) const {
        if (this->isNegative != b.isNegative || this->digits() != b.digits())
            return false;
        for (int i = 0; i < this->digits(); i++)
            if (this->value.at(i) != b.value.at(i))
                return false;
        return true;
    }
}
