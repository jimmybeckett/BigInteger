#include <boost/test/unit_test.hpp>
#include "../../include/BigInteger.h"

using namespace euler;

BOOST_AUTO_TEST_SUITE(method_pow);

BOOST_AUTO_TEST_CASE(large) {
    BOOST_CHECK(BigInteger (1272).pow(BigInteger (125)) == BigInteger ("11505060692779076349559969772489064051663614580201013943631437221901242316333027637745723844954585979560188042142579082208332146956387098522668185301526382465229278731835517486245974070584440656795907224694418493792324789361110870456823331751341728741989878159437738410720064390940134577917732681357420697304430394021858762839909657949919654325324066760527299700269133206854901864366866432"));
}; //That's pretty big

BOOST_AUTO_TEST_CASE(negative_result) {
    BOOST_CHECK(BigInteger (-19).pow(BigInteger (5)) == BigInteger (-2476099));
}

BOOST_AUTO_TEST_CASE(positive_result) {
    BOOST_CHECK(BigInteger (-15).pow(BigInteger (4)) == BigInteger (50625));
}

BOOST_AUTO_TEST_CASE(zero) {
    BOOST_CHECK(BigInteger (87264).pow(0) == 1);
}

BOOST_AUTO_TEST_SUITE_END();
