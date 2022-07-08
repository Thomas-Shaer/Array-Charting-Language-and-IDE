#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <string>
#include "CodeBase/expressionvalue.h"

BOOST_AUTO_TEST_SUITE(EXPRESSIONVALUE)

BOOST_AUTO_TEST_CASE(expression_value_load_test)
{
    ExpressionValue val = NullableValueString("Hello World!");
    BOOST_CHECK((*boost::get<NullableValueString>(val).value == "Hello World!"));
    ExpressionValue val2 = NullableValueNumber(1.1234);
    BOOST_CHECK((*boost::get<NullableValueNumber>(val2).value == (float)1.1234));
    ExpressionValue val3 = NullableValueBoolean(true);
    BOOST_CHECK((*boost::get<NullableValueBoolean>(val3).value == true));


}

BOOST_AUTO_TEST_SUITE_END()
