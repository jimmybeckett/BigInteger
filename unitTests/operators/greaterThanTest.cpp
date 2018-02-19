#include <boost/test/unit_test.hpp>
#include "../../BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(operator_greater_than);

BOOST_AUTO_TEST_CASE(large_num) {
    BOOST_CHECK(BigInteger (908725) > BigInteger (12552));
}

BOOST_AUTO_TEST_CASE(same_num_digits) {
    BOOST_CHECK(BigInteger (25678) > BigInteger (15679));
}

BOOST_AUTO_TEST_CASE(positive_greater_than_negative) {
    BOOST_CHECK(BigInteger (9272) > BigInteger (-98729872));
}

BOOST_AUTO_TEST_CASE(negative_greater_than_negative) {
    BOOST_CHECK(BigInteger (-727235) > BigInteger (-98728288));
}

BOOST_AUTO_TEST_SUITE_END();
