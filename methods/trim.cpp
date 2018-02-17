#include "../BigInteger.h"

namespace euler {
    BigInteger BigInteger::trim() {
        int i = this->digits();
        while ((*this)[--i] == 0 && this->digits() > 1)
            this->value.erase(this->value.begin());
        return *this;
    }
}
