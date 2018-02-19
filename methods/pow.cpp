#include "../BigInteger.h"

namespace euler {
    BigInteger BigInteger::pow(const BigInteger& b) const {
        if (b == 0) 
            return BigInteger (1);
        BigInteger t (*this);
        for (BigInteger i (0); i < b - 1; i++)
            t *= *this;
        return t;
    }
}
