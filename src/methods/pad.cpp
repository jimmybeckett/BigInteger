#include "../../include/BigInteger.h"

namespace euler {
    BigInteger BigInteger::pad(int n) const {
        BigInteger temp (*this);
        while (n-- > 0)
            temp.addToFront(0);
        return temp;
    }
}
