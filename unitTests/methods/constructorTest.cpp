#include <boost/test/unit_test.hpp>
#include "../../BigInteger.h"
#include <boost/test/output_test_stream.hpp>

using namespace euler;

BOOST_AUTO_TEST_SUITE(constructor);

BOOST_AUTO_TEST_CASE(construct_positive_int) {
    BOOST_CHECK(BigInteger (54321)  == 54321);
}

BOOST_AUTO_TEST_CASE(construct_negative_int) {
    BOOST_CHECK(BigInteger (-12345) == -12345);
}

BOOST_AUTO_TEST_CASE(construct_postive_string) {
    BOOST_CHECK(BigInteger ("653290873988655678883093619305836176201") == BigInteger ("653290873988655678883093619305836176201"));
}

BOOST_AUTO_TEST_CASE(construct_negative_string) {
    BOOST_CHECK(BigInteger ("-98736983509287136022078") == BigInteger ("-98736983509287136022078"));
}

BOOST_AUTO_TEST_CASE(construct_positive_BigInteger) {
    BigInteger b1 (979863);
    BigInteger b2 (b1);
    BOOST_CHECK(b1 == b2);
}

BOOST_AUTO_TEST_CASE(construct_negative_BigInteger) {
    BigInteger b1 (-9800734);
    BigInteger b2 (b1);
    BOOST_CHECK(b1 == b2);
}

BOOST_AUTO_TEST_CASE(trim_positive) {
    BOOST_CHECK(BigInteger ("000304") == 304);
}

BOOST_AUTO_TEST_CASE(trim_negative) {
    BOOST_CHECK(BigInteger ("-0020020") == -20020);
}

BOOST_AUTO_TEST_CASE(trim_all_zeros) {
    BOOST_CHECK(BigInteger ("00000")  == 0);
}

BOOST_AUTO_TEST_SUITE_END();
