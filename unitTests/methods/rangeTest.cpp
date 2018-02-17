#include "../unitTests.h"

namespace euler {
    void rangeTest() {
        std::cout << "running range tests" << std::endl;
        BigInteger b1 (123456);
        BigInteger b2 (123);
        assert(b1.range(0, 2) == b2);
        b2.init(234);
        assert(b1.range(1,3) == b2);
        std::cout << "range tests passed" << std::endl;
    }
}
