#include <boost/test/unit_test.hpp>
#include "../../include/BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(operator_division);

BOOST_AUTO_TEST_CASE(large_num) {
    BOOST_CHECK(BigInteger ("7937478314808") / BigInteger ("8039752") == BigInteger ("987279"));
}

BOOST_AUTO_TEST_CASE(division_with_remainder) {
    BOOST_CHECK(BigInteger ("876501091125215") / BigInteger ("91786501127") == BigInteger ("9549"));
}

BOOST_AUTO_TEST_CASE(zero) {
    BOOST_CHECK(BigInteger (0) / BigInteger ("129872") == BigInteger (0));
    //check division by zero throws exception
}

BOOST_AUTO_TEST_CASE(negative_divided_positive) {
    BOOST_CHECK(BigInteger ("-19182605978215") / BigInteger ("18762182712") == BigInteger ("-1022"));
}

BOOST_AUTO_TEST_CASE(postive_divided_negative) {
    BOOST_CHECK(BigInteger ("8712350978253") / BigInteger ("-1876128976") == BigInteger ("-4643"));
}

BOOST_AUTO_TEST_CASE(negative_divided_negative) {
    BOOST_CHECK(BigInteger ("-12091870125125") / BigInteger ("-89627356135") == BigInteger (134)); 
}

BOOST_AUTO_TEST_SUITE_END();
