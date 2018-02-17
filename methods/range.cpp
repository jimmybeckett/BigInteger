#include "../BigInteger.h"

namespace euler {
    BigInteger BigInteger::range(const int ind1, const int ind2) const {
        BigInteger b;
        for (int i = this->digits() - ind1 - 1; i >= this->digits() - ind2 - 1; i--)
            b.addToBack((*this)[i]);
        return b;
    }
}
