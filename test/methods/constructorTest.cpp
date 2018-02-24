#include "../../include/BigInteger.h" 
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

using namespace euler;

BOOST_AUTO_TEST_SUITE(constructor);

BOOST_AUTO_TEST_CASE(construct_positive_int) {
    BOOST_CHECK(BigInteger (54321)  == BigInteger (54321));
}

BOOST_AUTO_TEST_CASE(construct_negative_int) {
    BOOST_CHECK(BigInteger (-12345) == BigInteger (-12345));
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
    BOOST_CHECK(BigInteger ("000304") == BigInteger (304));
}

BOOST_AUTO_TEST_CASE(trim_negative) {
    BOOST_CHECK(BigInteger ("-0020020") == BigInteger (-20020));
}

BOOST_AUTO_TEST_CASE(trim_all_zeros) {
    BOOST_CHECK(BigInteger ("00000")  == BigInteger (0));
}

BOOST_AUTO_TEST_CASE(negative_0) {
    BOOST_CHECK(BigInteger ("-0") == BigInteger (0));
}

bool validate_invalid_argument_exception (std::exception const& ex) { return strcmp(ex.what(), "invalid_argument in BigInteger::init()") == 0; }

BOOST_AUTO_TEST_CASE(invalid_argument_exception) {
    BOOST_CHECK_EXCEPTION(BigInteger ("a124"), std::exception, validate_invalid_argument_exception);
}

BOOST_AUTO_TEST_SUITE_END();
