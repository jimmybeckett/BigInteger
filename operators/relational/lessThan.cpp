#include "../../BigInteger.h"

namespace euler {
    bool BigInteger::operator<(const BigInteger& b) const {
        return !(*this > b || *this == b);
    }
}
