#include "../BigInteger.h"

namespace euler {
    std::string BigInteger::toString() {
        std::string result;
        for (int i : this->value) {
            result += std::to_string(i); 
        }
        return result;
    }
}
