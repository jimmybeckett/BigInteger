#include "../unitTests.h"

namespace euler {
    void additionTest() {
        std::cout << "running + tests" << std::endl;
        int n1 = 123321;
        int n2 = 432232;
        BigInteger b1 (n1);
        BigInteger b2 (n2);
        for (int i = 0; i < 1000; i++) {
            b1.init(n1 = (int)(std::rand() % 100000 * (std::rand() < RAND_MAX / 2 ? -1 : 1)));
            b2.init(n2 = (int)(std::rand() % 100000 * (std::rand() < RAND_MAX / 2 ? -1 : 1)));
            assert(b1 + b2 == n1 + n2);
        }
        std::cout << "+ tests passed" << std::endl;
    }
}
