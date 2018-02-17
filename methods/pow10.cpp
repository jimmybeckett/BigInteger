#include "../BigInteger.h"

namespace euler {
    BigInteger BigInteger::pow10(int pow) const {
        BigInteger t (*this);
        while (pow-- > 0)
            t.addToBack(0);
        return t;
    }
}
