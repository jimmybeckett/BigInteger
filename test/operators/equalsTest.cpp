#include <boost/test/unit_test.hpp>
#include "../../include/BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(operator_equality);

BOOST_AUTO_TEST_CASE(large_num) {
    BOOST_CHECK(BigInteger (87621672) == BigInteger (87621672));
    BOOST_CHECK(!(BigInteger (87621672) == BigInteger (87621671)));
}

BOOST_AUTO_TEST_CASE(negative) {
    BOOST_CHECK(!(BigInteger (1234) == BigInteger (-1234)));
}

BOOST_AUTO_TEST_CASE(zero) {
    BOOST_CHECK(BigInteger (156) + BigInteger (-156) == BigInteger (0));
    BOOST_CHECK(BigInteger (-0) == BigInteger (0));
    BOOST_CHECK(BigInteger (-0) == BigInteger (-0));
}

BOOST_AUTO_TEST_SUITE_END();
