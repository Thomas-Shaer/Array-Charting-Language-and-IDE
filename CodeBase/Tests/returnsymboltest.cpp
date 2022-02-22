#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <string>
#include "CodeBase/returnsymbol.h"
#include "CodeBase/typesymbol.h"

BOOST_AUTO_TEST_SUITE(RETURNSYMBOL)

BOOST_AUTO_TEST_CASE(return_symbol_construct_test)
{

    BOOST_CHECK(ReturnSymbol(TypeInstances::GetBooleanInstance()).typesymbol == TypeInstances::GetBooleanInstance());
    BOOST_CHECK(ReturnSymbol(TypeInstances::GetNumberInstance()).typesymbol == TypeInstances::GetNumberInstance());
    BOOST_CHECK(ReturnSymbol(TypeInstances::GetStringInstance()).typesymbol == TypeInstances::GetStringInstance());
}


BOOST_AUTO_TEST_SUITE_END()
