#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <string>
#include "CodeBase/nullablevaluestring.h"

BOOST_AUTO_TEST_SUITE(NULLABLEVALUESTRING)

BOOST_AUTO_TEST_CASE(nullable_value_string_to_string_test)
{
    NullableValueString test;
    BOOST_CHECK(test.toString() == "null");
    NullableValueString test2("Hello World!");
    BOOST_CHECK((test2.toString() == "\"Hello World!\""));
}

BOOST_AUTO_TEST_CASE(nullable_value_string_value)
{
    NullableValueString test;
    BOOST_CHECK(!test.value);
    NullableValueString test2("Hello World!");
    BOOST_CHECK(*test2.value == "Hello World!");
}

BOOST_AUTO_TEST_SUITE_END()
