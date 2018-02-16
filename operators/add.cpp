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
        int i;
        int carry = 0;
        int minDigits = (int)fmin(this->digits(), b.digits());
        for (i = 0; i < minDigits; i++) {
            int n = (*this)[i] + b[i] + carry;
            temp.addToFront((int)std::abs(n >= 10 ? n - 10 : n));
            carry = n >= 10 ? 1 : 0;
        }
        temp.addToFront(carry);
        if (i < this->digits()) temp[i] += (*this)[i];
        if (i < b.digits()) temp[i] += b[i];
        i++;
        while (i < this->digits())
            temp.addToFront((*this)[i++]);
        while (i < b.digits())
            temp.addToFront(b[i++]);
        while (temp[--i] == 0)
            temp.value.erase(temp.value.begin());
        return temp;
    }
}
