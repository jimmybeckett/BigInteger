#include "../BigInteger.h" 
namespace euler { 
    BigInteger BigInteger::multiply(const BigInteger& other) const {
        if (this->digits() == 1 || other.digits() == 1) { //base case
            BigInteger l (this->digits() > other.digits() ? *this : other);
            BigInteger s (this->digits() <= other.digits() ? *this : other);
            BigInteger t;
            int carry = 0;
            for (int i = 0; i < l.digits(); i++) {
                t.addToFront((l[i] * s[0] + carry) % 10);
                carry = (l[i] * s[0] + carry) / 10;
            }
            if (carry != 0)
                t.addToFront(carry);
            return t.trim();
        }
        int n = fmax(this->digits(), other.digits());
        n += n % 2;
        BigInteger a = this->pad(n - this->digits()).range(0, n / 2 - 1).trim();
        BigInteger b = this->pad(n - this->digits()).range(n / 2, n - 1).trim();
        BigInteger c = other.pad(n - other.digits()).range(0, n / 2 - 1).trim();
        BigInteger d = other.pad(n - other.digits()).range(n / 2, n - 1).trim();
        BigInteger t1 = a * c;
        BigInteger t2 = b * d;
        BigInteger abcd = (a + b) * (c + d);
        BigInteger t3 = abcd - t2 - t1;
        return (t1.pow10(n) + t2 + t3.pow10(n / 2)).trim();
    }

    BigInteger BigInteger::operator*(const BigInteger& other) const { //Karatsuba algorithm implementation
        if (*this == 0 || other == 0)
            return BigInteger (0);
        BigInteger ans = this->abs().multiply(other.abs());
        ans.isNegative = !(*this < 0 == other < 0);
        return ans; 
    }
}
