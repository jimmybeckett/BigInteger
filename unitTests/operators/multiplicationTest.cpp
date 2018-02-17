#include "../unitTests.h"

namespace euler {
    void multiplicationTest() {
        std::cout << "running * tests" << std::endl;
        int n1;
        int n2;
        BigInteger b1 (3329);
        BigInteger b2 (9080);
        for (int i = 0; i < 1000; i++) {
            b1.init(n1 = (int)(std::rand() % 10000 * (std::rand() < RAND_MAX / 2 ? -1 : 1)));
            b2.init(n2 = (int)(std::rand() % 10000 * (std::rand() < RAND_MAX / 2 ? -1 : 1)));
            assert(b1 * b2 == n1 * n2);
        }
        std::cout << "* tests passed" << std::endl;
    }
}
