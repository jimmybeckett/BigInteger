#include <boost/test/unit_test.hpp>
#include "../../include/BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(method_toInt);

BOOST_AUTO_TEST_CASE(num) {
    BOOST_CHECK(BigInteger (14798).toInt() == 14798);
}

BOOST_AUTO_TEST_CASE(negative) {
    BOOST_CHECK(BigInteger (-90859).toInt() == -90859);
}

BOOST_AUTO_TEST_SUITE_END();
