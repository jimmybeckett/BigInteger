#include "../BigInteger.h"

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
        int i;
        int carry = 0;
        for (i = 0; i < this->digits(); i++) {
            int bi = i < b.digits() ? b[i] : 0;
            if ((*this)[i] + carry < bi) {
                temp.addToFront((*this)[i] - bi + carry + 10);
                carry = -1;
            }
            else {
                temp.addToFront((*this)[i] - bi + carry);
                carry = 0;
            }
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
