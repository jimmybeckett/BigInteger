#include "../include/BigInteger.h"
#include <iostream>

using namespace euler;

int main() {
    //std::cout << (BigInteger (73997) / BigInteger (2387)) << std::endl;
    //std::cout << (BigInteger (123456789)).pow(500) << std::endl;
    std::cout << (BigInteger (136) / BigInteger (8)) << std::endl;
    std::cout << (BigInteger (316097) / BigInteger (102)) << std::endl;
    std::cout << (BigInteger (316097) % BigInteger (102)) << std::endl;
    return 0;
}
