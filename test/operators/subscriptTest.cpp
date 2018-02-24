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

bool validate_length_error_exception (std::exception const& ex) { return strcmp(ex.what(), "length_error in BigInteger::operator[]") == 0; }

BOOST_AUTO_TEST_CASE(length_error_exception) {
    BOOST_CHECK_EXCEPTION((BigInteger (12345))[5], std::exception, validate_length_error_exception);
    BOOST_CHECK_EXCEPTION((BigInteger (12345))[-2], std::exception, validate_length_error_exception);
}
BOOST_AUTO_TEST_SUITE_END();
