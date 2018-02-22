#include <boost/test/unit_test.hpp>
#include "../../include/BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(operator_division);

BOOST_AUTO_TEST_CASE(large_num) {
    for (BigInteger i = 1; i < BigInteger ("99"); i++)
        for (BigInteger j = 1; j < BigInteger ("99"); j++) {
                //if ((i * j / j) != i)
                    //std::cout << (i * j) << " / " << j << " != " << (i * j / j) << " != " << i << std::endl;
                //else
                    //std::cout << (i * j) << " / " << j << " == " << (i * j / j) << " == " << i << std::endl;
                BOOST_CHECK((i * j / j) == i);
            }
    BOOST_CHECK(BigInteger ("7937478314808") / BigInteger ("8039752") == BigInteger ("987279"));
}

BOOST_AUTO_TEST_SUITE_END();
