#include <boost/test/unit_test.hpp>
#include "../../include/BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(operator_subtraction);

BOOST_AUTO_TEST_CASE(positive_result) {
    BOOST_CHECK(BigInteger ("68726876298176") - BigInteger ("87687621") == BigInteger ("68726788610555"));
}

BOOST_AUTO_TEST_CASE(negative_result) {
    BOOST_CHECK(BigInteger ("7657872212521") - BigInteger ("35678589612598761982") == BigInteger ("-35678581954726549461"));
}

BOOST_AUTO_TEST_CASE(zero) {
    BOOST_CHECK(BigInteger (9879852) - BigInteger (0) == BigInteger (9879852));
}

BOOST_AUTO_TEST_CASE(positive_minus_negative) {
    BOOST_CHECK(BigInteger (789725) - BigInteger (-9872) == BigInteger (799597));
}

BOOST_AUTO_TEST_CASE(negative_minus_positive) {
    BOOST_CHECK(BigInteger (-881272) - BigInteger (99812) == BigInteger (-981084));
}

BOOST_AUTO_TEST_CASE(negative_minus_negative) {
    BOOST_CHECK(BigInteger (-62982) - BigInteger (-987272) == BigInteger (924290));
}

BOOST_AUTO_TEST_SUITE_END();
