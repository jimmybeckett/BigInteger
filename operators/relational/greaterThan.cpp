#include "../../BigInteger.h"

    bool euler::BigInteger::operator>(const BigInteger& b) const {
        if (this->digits() != b.digits()) 
            return this->digits() > b.digits();
        for (int i = 0; i < this->digits(); i++)
            if (this->digits() != b.digits())
                return this->digits() > b.digits();
        return false;
    }
