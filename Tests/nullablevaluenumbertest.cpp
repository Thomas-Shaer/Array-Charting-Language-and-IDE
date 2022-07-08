#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <string>
#include "CodeBase/nullablevaluenumber.h"

BOOST_AUTO_TEST_SUITE(NULLABLEVALUENUMBER)

BOOST_AUTO_TEST_CASE(nullable_value_number_to_string_test)
{
    NullableValueNumber test;
    BOOST_CHECK(test.toString() == "null");
    NullableValueNumber test2(1.1234);
    BOOST_CHECK((test2.toString() == std::to_string(float(1.1234))));
}

BOOST_AUTO_TEST_CASE(nullable_value_number_value)
{
    NullableValueNumber test;
    BOOST_CHECK(!test.value);
    NullableValueNumber test2(1.1234);
    BOOST_CHECK(*test2.value == float(1.1234));
}

BOOST_AUTO_TEST_SUITE_END()
