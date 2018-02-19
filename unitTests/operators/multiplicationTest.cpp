#include <boost/test/unit_test.hpp>
#include "../../BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(operator_multiplication);

BOOST_AUTO_TEST_CASE(large_num) {
    BOOST_CHECK(BigInteger ("98127698672987218927982255") * BigInteger ("6275202852012258") == BigInteger ("615771214574128860906756106511010466481790"));
}

BOOST_AUTO_TEST_CASE(zero) {
    BOOST_CHECK(BigInteger (528225) * BigInteger (0) == BigInteger (0));
}

BOOST_AUTO_TEST_SUITE_END();
