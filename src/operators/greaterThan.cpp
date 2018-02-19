#include "../../include/BigInteger.h"

namespace euler {
    bool BigInteger::operator>(const BigInteger& b) const {
        if (*this == b) 
            return false;
        if (this->isNegative && !b.isNegative) 
            return false;
        if (!this->isNegative && b.isNegative) 
            return true;
        if (this->digits() != b.digits())
            return this->isNegative ? this->digits() < b.digits() : this->digits() > b.digits();
        for (int i = 0; i < this->digits(); i++)
            if ((*this)[i] != b[i])
                return this->isNegative ? (*this)[i] < b[i] : (*this)[i] > b[i];
        return false;
    }
}
