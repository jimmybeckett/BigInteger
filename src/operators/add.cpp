#include "../../include/BigInteger.h"

namespace euler {
    BigInteger BigInteger::operator+(const BigInteger& b) const {
        if (*this == BigInteger (0)) 
            return b;
        if (b == BigInteger (0)) 
            return *this;
        if (*this < BigInteger (0) && b > BigInteger (0))
            return b - -*this;
        if (*this > BigInteger (0) && b < BigInteger (0))
            return *this - -b;
        if (*this < BigInteger (0) && b < BigInteger (0))
            return -(-*this + -b);
        BigInteger temp;
        int carry = 0;
        int i, j;
        for (i = this->digits() - 1, j = b.digits() - 1; i >= 0 || j >= 0; i--, j--) {
            int n = (i >= 0 ? (*this)[i] : 0) + (j >= 0 ? b[j] : 0) + carry;
            temp.addToFront(n % 10);
            carry = n / 10;
        }
        temp.addToFront(carry);
        return temp.trim();
    }
}
