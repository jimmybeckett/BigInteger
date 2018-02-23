#include "../../include/BigInteger.h"
#include <math.h>

namespace euler { 
    BigInteger BigInteger::operator%(const BigInteger& other) const {
        if (*this == other || *this == BigInteger (0))
            return BigInteger (0);
        if (other == BigInteger (0))
            return BigInteger (0); //Throw exception
        if (other == BigInteger (2))
            return BigInteger((*this)[this->digits() - 1] % 2);
        BigInteger remainder;
        this->abs().divideAndRemainder(other.abs(), remainder);
        remainder.isNegative = *this < BigInteger (0);
        return remainder;
    }
}
