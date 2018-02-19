#include <boost/test/unit_test.hpp>
#include "../../BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(method_range);

BOOST_AUTO_TEST_CASE(positive_range) {
    BOOST_CHECK(BigInteger (1234567).range(2, 5) == 3456);
}

BOOST_AUTO_TEST_CASE(zero_range) {
    BOOST_CHECK(BigInteger (192838).range(1, 1) == 9);
}

BOOST_AUTO_TEST_CASE(negative_range) {
    //should throw exeption, unimplemented
}

BOOST_AUTO_TEST_SUITE_END();
