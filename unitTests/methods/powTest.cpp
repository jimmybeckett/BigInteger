#include <boost/test/unit_test.hpp>
#include "../../BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(method_pow);

BOOST_AUTO_TEST_CASE(positive_int) {
    BOOST_CHECK(BigInteger (54).pow(3) == 157464);
}

BOOST_AUTO_TEST_CASE(zero) {
    BOOST_CHECK(BigInteger (87264).pow(0) == 1);
}

BOOST_AUTO_TEST_SUITE_END();
