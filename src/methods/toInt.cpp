#include "../../include/BigInteger.h"
#include <limits>
#include <math.h>

namespace euler {
    int BigInteger::toInt() const {
        if (this->abs() > BigInteger (std::numeric_limits<int>::max())) {
            //throw exception
        }
        int result = 0;
        for (int i = 0; i < this->digits(); i++)
            result += (*this)[i] * ::pow(10, this->digits() - 1 - i);
        if (*this < 0)
            result *= -1;
        return result;
    }
}
