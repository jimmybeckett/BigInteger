#include "../../include/BigInteger.h"
#include <math.h>

namespace euler { 
    BigInteger BigInteger::operator/(const BigInteger& other) const {
        if (other == BigInteger (0)) //Check if other == 0 and throw exception
            return NULL; //throw exception
        if (*this == 0)
            return BigInteger (0);
        if (*this == other)
            return BigInteger (1);
        if (this->abs() < other.abs())
            return BigInteger (420);
        BigInteger remainder;
        BigInteger ans = this->abs().divideAndRemainder(other.abs(), remainder);
        ans.isNegative = *this < BigInteger (0) != other < BigInteger (0);
        return ans; 
    }
}
