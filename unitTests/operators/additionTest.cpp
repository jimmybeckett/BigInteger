#include <boost/test/unit_test.hpp>
#include "../../BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(operator_addition);

BOOST_AUTO_TEST_CASE(large_num) {
    BOOST_CHECK(BigInteger ("1290910898752125927125") + BigInteger ("19875986310183520") == BigInteger ("1290930774738436110645"));
}

BOOST_AUTO_TEST_SUITE_END();
