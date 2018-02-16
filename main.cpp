#include "BigInteger.h"
#include "unitTests/unitTests.h"
#include <iostream>

int main() {
    using namespace euler;
    std::cout << "running unit tests" << std::endl;
    initTest();
    equalsTest(); 
    greaterThanTest();
    subscriptTest();
    additionTest();
    std::cout << "all unit tests passed" << std::endl;
    return 0;
}
