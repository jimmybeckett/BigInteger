#include "../BigInteger.h"

namespace euler {
    std::string BigInteger::toString() const {
        std::string result;
        if (this->isNegative) result += "-";
        for (int i : this->value)
            result += std::to_string(i);
        return result;
    }
}
