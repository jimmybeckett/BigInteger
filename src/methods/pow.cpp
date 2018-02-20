#include "../../include/BigInteger.h"

namespace euler {
    BigInteger BigInteger::pow(const int n) const { //Exponentiation by squaring
        if (n == 0) 
            return BigInteger (1);
        if (n == 1)
            return BigInteger (*this);
        if (n % 2 == 0) 
            return ((*this) * (*this)).pow(n / 2);
        return (*this) * ((*this) * (*this)).pow((n - 1) / 2);
    }
}
