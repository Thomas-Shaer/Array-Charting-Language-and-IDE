#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <string>
#include "CodeBase/parametersymbol.h"
#include "CodeBase/typesymbol.h"

BOOST_AUTO_TEST_SUITE(PARAMETERSYMBOL)

BOOST_AUTO_TEST_CASE(parametersymbol_to_string_test)
{
    BOOST_CHECK(ParameterSymbol(TypeInstances::GetBooleanInstance(), "test", "Description").toString() == "boolean test");
    BOOST_CHECK(ParameterSymbol(TypeInstances::GetNumberInstance(), "test", "Description").toString() == "number test");
    BOOST_CHECK(ParameterSymbol(TypeInstances::GetStringInstance(), "test", "Description").toString() == "string test");
    BOOST_CHECK(ParameterSymbol(TypeInstances::GetStringConstantInstance(), "test", "Description").toString() == "string_constant test");
    BOOST_CHECK(ParameterSymbol(TypeInstances::GetNumberConstantInstance(), "test", "Description").toString() == "number_constant test");

}



BOOST_AUTO_TEST_CASE(optional_parametersymbol_to_string_test)
{
    BOOST_CHECK(OptionalParameterSymbol(TypeInstances::GetBooleanInstance(), NullableValueBoolean(true), "test", "Description").toString() == "boolean test = true");
    BOOST_CHECK(OptionalParameterSymbol(TypeInstances::GetNumberInstance(), NullableValueNumber(float(1.123)), "test", "Description").toString() == ("number test = " + std::to_string((float)1.123)));
    BOOST_CHECK(OptionalParameterSymbol(TypeInstances::GetStringInstance(), NullableValueString("Hello World!"), "test", "Description").toString() == "string test = \"Hello World!\"");
    BOOST_CHECK(OptionalParameterSymbol(TypeInstances::GetStringConstantInstance(), NullableValueString("Hello World!"), "test", "Description").toString() == "string_constant test = \"Hello World!\"");
    BOOST_CHECK(OptionalParameterSymbol(TypeInstances::GetNumberConstantInstance(), NullableValueNumber(float(1.123)), "test", "Description").toString() == "number_constant test = " + std::to_string((float)1.123));

    BOOST_CHECK(OptionalParameterSymbol(TypeInstances::GetBooleanInstance(), NullableValueBoolean(), "test", "Description").toString() == "boolean test = null");
    BOOST_CHECK(OptionalParameterSymbol(TypeInstances::GetNumberInstance(), NullableValueNumber(), "test", "Description").toString() == ("number test = null"));
    BOOST_CHECK(OptionalParameterSymbol(TypeInstances::GetStringInstance(), NullableValueString(), "test", "Description").toString() == "string test = null");
    BOOST_CHECK(OptionalParameterSymbol(TypeInstances::GetStringConstantInstance(), NullableValueString(), "test", "Description").toString() == "string_constant test = null");
    BOOST_CHECK(OptionalParameterSymbol(TypeInstances::GetNumberConstantInstance(), NullableValueNumber(), "test", "Description").toString() == "number_constant test = null");

}

BOOST_AUTO_TEST_SUITE_END()
