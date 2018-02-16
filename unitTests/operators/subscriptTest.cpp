#include "../unitTests.h"
#include <string>

namespace euler {
    void subscriptTest() {
        std::cout << "running [] operator tests" << std::endl;
        std::string str = "123456";
        BigInteger* b = new BigInteger(str);
        for (int i = 0; i < str.length(); i++)
            assert(str[str.length() - i - 1] - '0' == (*b)[i]);
        delete b;
        std::cout << "[] tests passed" << std::endl;
    }
}
