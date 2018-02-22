#include "../../include/BigInteger.h"
#include <math.h>

namespace euler { 
    BigInteger BigInteger::divide(const BigInteger& other, BigInteger& remainder) const {
        if (other.digits() == 1) { //simple division algorithm for if divisor is 1 digit
            BigInteger result (0);
            int carry = 0;
            for (int i = 0, temp; i < this->digits(); i++) {
                temp = carry * 10 + (*this)[i];
                result.addToBack(temp / other[0]);
                carry = temp % other[0];
            }
            remainder = carry;
            return result.trim();
        }
        BigInteger f = 10 / (other[0] + 1); //normalization factor
        BigInteger dividend = *this * f;
        BigInteger divisor = other * f;
        remainder = 0;
        BigInteger quotient (0); // quotient
        BigInteger q_est (0); // a digit of q
        for (int j = 0; j <= dividend.digits(); j++) {
                //q_est = fmin((dividend.range(0, 2) / divisor.range(0, 1))[0], 9);
                q_est = 9;
                while (q_est * divisor > remainder)
                    q_est--;
            remainder -= q_est * divisor;
            if (j < dividend.digits()) {
                remainder.addToBack(dividend[j]);
                remainder.trim();
            }
            quotient.addToBack(q_est[0]);
        }
        remainder /= f;
        return quotient.trim();
    }


    BigInteger BigInteger::operator/(const BigInteger& other) const {
        if (*this == BigInteger (0)) //Check if other == 0 and throw exception
            return BigInteger (0); //throw exception
        if (other == *this)
            return 1;
        if (other > *this)
            return 0;
        BigInteger remainder;
        BigInteger ans = this->abs().divide(other.abs(), remainder);
        ans.isNegative = *this < BigInteger (0) != other < BigInteger (0);
        return ans; 
    }

    BigInteger BigInteger::operator%(const BigInteger& other) const {
        if (*this == BigInteger (0)) //Check if other == 0 and throw exception
            return BigInteger (0); //throw exception
        if (other == *this)
            return 1;
        if (other > *this)
            return 0;
        BigInteger remainder;
        this->abs().divide(other.abs(), remainder);
        remainder.isNegative = *this < BigInteger (0) != other < BigInteger (0);
        return remainder;
    }
}
