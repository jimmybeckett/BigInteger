#include "../../include/BigInteger.h"
#include <string>

namespace euler {
    std::string BigInteger::toString() const {
        std::string result = "";
        if (this->isNegative) 
            result += "-";
        for (int i = 0; i < this->digits(); i++)
            result += std::to_string((*this)[i]);
        return result;
    }
}
