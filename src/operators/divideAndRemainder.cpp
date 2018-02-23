#include "../../include/BigInteger.h"
#include <math.h>

namespace euler { 
    BigInteger BigInteger::divideAndRemainder(const BigInteger& other, BigInteger& remainder) const {
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
                q_est = max(BigInteger (dividend.range(0, 2).toInt() / divisor.range(0, 1).toInt()), BigInteger (9));
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
}
