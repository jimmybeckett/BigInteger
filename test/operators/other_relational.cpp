#include <boost/test/unit_test.hpp>
#include "../../include/BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(operator_other_relational); //All of these are put into one file because they are implemented in terms of the better tested > and ==, and so need less testing

BOOST_AUTO_TEST_CASE(not_equals) {
    BOOST_CHECK(BigInteger (196872) != BigInteger (12552));
    BOOST_CHECK(BigInteger (-11235) != BigInteger (11235));
    BOOST_CHECK(!(BigInteger (5552) != BigInteger (5552)));
}

BOOST_AUTO_TEST_CASE(greater_than_or_equal_to) {
    BOOST_CHECK(BigInteger (54124) >= BigInteger (25225));
    BOOST_CHECK(BigInteger (-9992) >= BigInteger (-998725));
    BOOST_CHECK(BigInteger (8242) >= BigInteger (8242));
    BOOST_CHECK(!(BigInteger (1823) >= BigInteger (2421)));
}

BOOST_AUTO_TEST_CASE(less_than) {
    BOOST_CHECK(BigInteger (525) < BigInteger (72289));
    BOOST_CHECK(!(BigInteger (7282) < BigInteger (7282)));
}

BOOST_AUTO_TEST_CASE(less_than_or_equal_to) {
    BOOST_CHECK(BigInteger (-2592) <= BigInteger (-889));
    BOOST_CHECK(BigInteger (5522) <= BigInteger (5522));
    BOOST_CHECK(!(BigInteger (9455) <= BigInteger (8222)));
}

BOOST_AUTO_TEST_SUITE_END();
