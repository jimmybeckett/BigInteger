#include "../BigInteger.h"

int euler::BigInteger::digits() const {
    return this->value.size();
}
