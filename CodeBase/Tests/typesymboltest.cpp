#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <string>
#include "CodeBase/typesymbol.h"

BOOST_AUTO_TEST_SUITE(TYPESYMBOL)

BOOST_AUTO_TEST_CASE(match_type_test)
{
    BOOST_CHECK(TypeInstances::matchType(TypeInstances::GetBooleanInstance(), TypeInstances::GetBooleanInstance()));
    BOOST_CHECK(TypeInstances::matchType(TypeInstances::GetNumberConstantInstance(), TypeInstances::GetNumberConstantInstance()));
    BOOST_CHECK(TypeInstances::matchType(TypeInstances::GetNumberInstance(), TypeInstances::GetNumberInstance()));
    BOOST_CHECK(TypeInstances::matchType(TypeInstances::GetStringConstantInstance(), TypeInstances::GetStringConstantInstance()));
    BOOST_CHECK(TypeInstances::matchType(TypeInstances::GetStringInstance(), TypeInstances::GetStringInstance()));
    BOOST_CHECK(TypeInstances::matchType(TypeInstances::GetVoidInstance(), TypeInstances::GetVoidInstance()));

    BOOST_CHECK(TypeInstances::matchType(TypeInstances::GetStringInstance(), TypeInstances::GetStringConstantInstance()));
    BOOST_CHECK(TypeInstances::matchType(TypeInstances::GetNumberInstance(), TypeInstances::GetNumberConstantInstance()));

    BOOST_CHECK(!TypeInstances::matchType(TypeInstances::GetStringConstantInstance(), TypeInstances::GetStringInstance()));
    BOOST_CHECK(!TypeInstances::matchType(TypeInstances::GetNumberConstantInstance(), TypeInstances::GetNumberInstance()));
}


BOOST_AUTO_TEST_SUITE_END()
