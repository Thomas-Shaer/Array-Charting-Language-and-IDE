#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <string>
#include "CodeBase/nullablevalueboolean.h"

BOOST_AUTO_TEST_SUITE(NULLABLEVALUEBOOLEAN)

BOOST_AUTO_TEST_CASE(nullable_value_boolean_to_string_test)
{
    NullableValueBoolean test;
    BOOST_CHECK(test.toString() == "null");
    NullableValueBoolean test2(true);
    BOOST_CHECK((test2.toString() == "true"));
}

BOOST_AUTO_TEST_CASE(nullable_value_boolean_value)
{
    NullableValueBoolean test;
    BOOST_CHECK(!test.value);
    NullableValueBoolean test2(false);
    BOOST_CHECK(*test2.value == false);
}

BOOST_AUTO_TEST_SUITE_END()
