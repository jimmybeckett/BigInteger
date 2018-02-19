#include <boost/test/unit_test.hpp>
#include "../../BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(operator_addition);

BOOST_AUTO_TEST_CASE(large_num) {
    BOOST_CHECK(BigInteger ("1290910898752125927125") + BigInteger ("19875986310183520") == BigInteger ("1290930774738436110645"));
}

BOOST_AUTO_TEST_CASE(zero) {
    BOOST_CHECK(BigInteger (9879852) + BigInteger (0) == BigInteger (9879852));
    BOOST_CHECK(BigInteger (8824) + BigInteger (-8824) == BigInteger (0));
}

BOOST_AUTO_TEST_CASE(positive_plus_negative) {
    BOOST_CHECK(BigInteger (873923) + BigInteger (-6262) == BigInteger (867661));
    BOOST_CHECK(BigInteger (45624) + BigInteger (-8182262) == BigInteger (-8136638));
}

BOOST_AUTO_TEST_CASE(negative_plus_positive) {
    BOOST_CHECK(BigInteger (-7284) + BigInteger (9875) == BigInteger (2591));
    BOOST_CHECK(BigInteger (-881272) + BigInteger (99812) == BigInteger (-781460));
}

BOOST_AUTO_TEST_CASE(negative_plus_negative) {
    BOOST_CHECK(BigInteger (-12305) + BigInteger (-152072) == BigInteger (-164377));
}

BOOST_AUTO_TEST_SUITE_END();
