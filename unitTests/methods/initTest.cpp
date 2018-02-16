#include "../unitTests.h"

namespace euler {
    void initTest() {
        std::cout << "running init tests" << std::endl;
        int n = 0;
        BigInteger b (n); 
        BigInteger t;
        for (int i = 0; i < 10000; i++) {
            b.init(n = std::rand() % 100000 * (std::rand() < RAND_MAX / 2 ? -1 : 1));
            assert(b == n);
            t.init(b);
            assert(b == t);
        }
        std::string str = "";
        for (int i = 0; i < 100; i++) {
            for (int i = 0; i < 10; i++) 
                str += std::to_string(std::rand() % 100000 * (std::rand() < RAND_MAX / 2 ? -1 : 1));
            b.init(str);
            t.init(str);
            assert(b == t);
        }
        std::cout << "init tests passed" << std::endl;
    }
}
