#include "../BigInteger.h"

namespace euler {
    BigInteger BigInteger::trim() {
        while (this->digits() > 1 && (*this)[0] == 0)
            this->value.erase(this->value.begin());
        return *this;
    }
}
