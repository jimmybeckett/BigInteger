#include "../unitTests.h"

namespace euler {
    void equalsTest() {
        std::cout << "running == tests" << std::endl;
        int n = 123456;
        BigInteger b1 (n);
        BigInteger b2 (n);
        for (int i = 0; i < 10000; i++) {
            n = std::rand() % 100000 * (std::rand() < RAND_MAX / 2 ? -1 : 1);
            b1.init(n);
            b2.init(n);
            assert(b1 == b2);
        }
        std::cout << "== tests passed" << std::endl;
    }
}
