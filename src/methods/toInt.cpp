#include "../../include/BigInteger.h"
#include <limits>

namespace euler {
    int BigInteger::toInt() const {
        if (this->abs() > BigInteger (std::numeric_limits<int>::max())) {
            //throw exception
        }
        return stoi(this->toString());
    }
}
