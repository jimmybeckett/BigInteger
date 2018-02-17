#include "../unitTests.h"

namespace euler {
    void pow10Test() {
        int n = 1546;
        BigInteger b (n);
        assert(b.pow10(4) == n * pow(10, 4));
    }
}
