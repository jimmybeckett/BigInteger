#include "../../include/BigInteger.h"

namespace euler {
    BigInteger BigInteger::range(const int ind1, const int ind2) const {
        BigInteger b;
        for (int i = ind1; i <= ind2; i++)
            b.addToBack((*this)[i]);
        return b.trim();
    }
}
