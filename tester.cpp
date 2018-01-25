#include "BigInteger.h"
#include <iostream>

int main() {
    std::string num = "123456";
    euler::BigInteger* b = new euler::BigInteger(num);
    std::cout << "num=" << num << " b=" << b->toString() << std::endl;
    delete b;
    return 0;
}
