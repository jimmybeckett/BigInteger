#include "../../include/BigInteger.h"

namespace euler {
    std::ostream& operator<<(std::ostream& stream, const BigInteger& b) {
        stream << b.toString();
        return stream;
    }
}
