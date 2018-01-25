#include "../BigInteger.h"

namespace euler {
    BigInteger::BigInteger(int num) {
        while (num > 9) {
            this->value.push_back(num / 10);
            num %= 10;
        }
        this->value.push_back(num);
    }
            
    BigInteger::BigInteger(long num) {
        while (num > 9) {
            this->value.push_back(num / 10);
            num %= 10;
        }
        this->value.push_back(num);
    }
            
    BigInteger::BigInteger(std::string str) {
        for (int i = 0; i < str.length(); i++)
            this->value.push_back(str[i] - '0');
    }

    BigInteger::BigInteger(BigInteger& b) {
        
    }
}
