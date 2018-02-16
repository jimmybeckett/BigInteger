#include "../BigInteger.h"

namespace euler {
    bool BigInteger::operator>(const BigInteger& b) const {
        if (this->isNegative && !b.isNegative) return false;
        if (!this->isNegative && b.isNegative) return true;
        if (this->digits() != b.digits())
            return this->isNegative ? this->digits() < b.digits() : this->digits() > b.digits();
        for (int i = this->digits() - 1; i >= 0; i--)
            if ((*this)[i] != b[i])
                return this->isNegative ? (*this)[i] < b[i] : (*this)[i] > b[i];
        return false;
    }
}
