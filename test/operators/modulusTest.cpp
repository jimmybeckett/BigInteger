#include <boost/test/unit_test.hpp>
#include "../../include/BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(operator_modulus);

BOOST_AUTO_TEST_CASE(large_num) {
    BOOST_TEST(BigInteger ("97128650891273") % BigInteger ("187261225") == BigInteger ("185969498"));
}

BOOST_AUTO_TEST_CASE(small_mod_large) {
    BOOST_TEST(BigInteger (122) % BigInteger (98231) == BigInteger (122));
}

BOOST_AUTO_TEST_CASE(negative_mod_postive) {
    BOOST_TEST(BigInteger (-99218725) % BigInteger (25125) == BigInteger (-100));
}

BOOST_AUTO_TEST_CASE(positive_mod_negative) {
    BOOST_TEST(BigInteger (1151) % BigInteger (-882) == BigInteger (269));
}

BOOST_AUTO_TEST_CASE(negative_mod_negative) {
    BOOST_TEST(BigInteger (-127192) % BigInteger (-12925) == BigInteger (-10867));
}

BOOST_AUTO_TEST_SUITE_END();
