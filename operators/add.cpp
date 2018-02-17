#include "../BigInteger.h"

namespace euler {
    BigInteger BigInteger::operator+(const BigInteger& b) const {
        if (*this == 0) 
            return b;
        if (b == 0) 
            return *this;
        if (*this < 0 && b > 0)
            return b - -*this;
        if (*this > 0 && b < 0)
            return *this - -b;
        if (*this < 0 && b < 0)
            return -(-*this + -b);
        BigInteger temp;
        int i = 0;
        int carry = 0;
        int minDigits = (int)fmin(this->digits(), b.digits());
        for (i = 0; i < minDigits; i++) {
            int n = (*this)[i] + b[i] + carry;
            temp.addToFront(n >= 10 ? n - 10 : n);
            carry = n >= 10 ? 1 : 0;
        }
        for (; i < this->digits(); i++) {
            int n = (*this)[i] + carry;
            temp.addToFront(n >= 10 ? n - 10 : n);
            carry = n >= 10 ? 1 : 0;
        }
        for (; i < b.digits(); i++) {
            int n = b[i] + carry;
            temp.addToFront(n >= 10 ? n - 10 : n);
            carry = n >= 10 ? 1 : 0;
        }
        temp.addToFront(carry);
        return temp.trim();
    }
}
