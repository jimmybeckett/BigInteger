#include "../BigInteger.h"

namespace euler {
    bool BigInteger::operator==(const BigInteger& b) const {
        return (this->isNegative == b.isNegative && this->value == b.value) || (this->digits() == 1 && (*this)[0] == 0 && b.digits() == 1 && b[0] == 0);
    }
}
