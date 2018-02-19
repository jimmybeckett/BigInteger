#include "../BigInteger.h"

namespace euler {
    bool BigInteger::operator==(const BigInteger& b) const {
        return this->isNegative == b.isNegative && this->value == b.value;
    }
}
