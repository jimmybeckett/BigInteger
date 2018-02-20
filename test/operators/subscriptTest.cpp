#include <boost/test/unit_test.hpp>
#include "../../include/BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(operator_subscript);

BOOST_AUTO_TEST_CASE(large_num) {
    BOOST_CHECK(BigInteger ("1234567")[5] == 6);
}

BOOST_AUTO_TEST_CASE(negative) {
    BOOST_CHECK(BigInteger (-8762)[1] == 7);
}

BOOST_AUTO_TEST_SUITE_END();
