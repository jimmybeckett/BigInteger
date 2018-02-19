#include "../BigInteger.h"
#include "math.h"

namespace euler {
    BigInteger BigInteger::operator-(const BigInteger& b) const {
        if (*this == 0) 
            return b;
        if (b == 0) 
            return *this;
        if (*this == b) 
            return 0;
        if (*this < 0 && b > 0)
            return -(-*this + b);
        if (*this < 0 && b < 0)
            return -b - -*this;
        if (*this > 0 && b < 0)
            return *this + -b;
        if (this->abs() < b.abs())
            return -(b.abs() - this->abs());
        BigInteger temp;
        int i, j;
        int carry = 0;
        for (i = this->digits() - 1, j = b.digits() - 1; i >= 0 && j >= 0; i--, j--) {
            int n = (*this)[i] - b[j] + carry;
            temp.addToFront(n < 0 ? n + 10 : n);
            carry = n < 0 ? -1 : 0;
        }
        for (; i >= 0; i--) {
            int n = (*this)[i] + carry;
            temp.addToFront(std::abs(n));
            carry = n < 0;
        }
        for (; j >= 0; j--) {
            int n = b[j] + carry;
            temp.addToFront(std::abs(n));
            carry = n < 0;
        }
        return temp.trim();
    }
}
