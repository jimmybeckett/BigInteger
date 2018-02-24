#include <boost/test/unit_test.hpp>
#include "../../include/BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(method_toString);

BOOST_AUTO_TEST_CASE(large_num) {
    BOOST_CHECK(BigInteger ("8160928111").toString() == "8160928111");
}

BOOST_AUTO_TEST_CASE(negative) {
    BOOST_CHECK(BigInteger ("-298721").toString() == "-298721");
}

BOOST_AUTO_TEST_SUITE_END();
