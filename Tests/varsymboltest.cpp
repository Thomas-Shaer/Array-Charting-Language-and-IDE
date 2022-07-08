#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <string>
#include "CodeBase/varsymbol.h"
#include "CodeBase/typesymbol.h"
#include "CodeBase/dataparseexception.h"

BOOST_AUTO_TEST_SUITE(VARSYMBOL)

BOOST_AUTO_TEST_CASE(varsymbol_creation_test)
{
    BOOST_CHECK(VarSymbol::createVarSymbol("valid_name", TypeInstances::GetNumberInstance()));
    BOOST_CHECK(VarSymbol::createVarSymbol("valid_name", TypeInstances::GetNumberInstance(), {}));

    BOOST_CHECK_THROW(VarSymbol::createVarSymbol("b a d  n a m e", TypeInstances::GetNumberInstance()), DataParseException);
    BOOST_CHECK_THROW(VarSymbol::createVarSymbol("b a d  n a m e", TypeInstances::GetNumberInstance(), {}), DataParseException);

}

BOOST_AUTO_TEST_CASE(varsymbol_valid_name_test)
{
    BOOST_CHECK(VarSymbol::isValidName("valid_name"));
    BOOST_CHECK(!VarSymbol::isValidName("b a d  n a m e"));
}

BOOST_AUTO_TEST_CASE(varsymbol_get_value_test)
{
    std::shared_ptr<VarSymbol> symbol = VarSymbol::createVarSymbol("valid_name", TypeInstances::GetNumberInstance(), { NullableValueNumber(1) });
    BOOST_CHECK(*boost::get<NullableValueNumber>(symbol->getValue(0)).value == 1);

    std::shared_ptr<VarSymbol> symbol2 = VarSymbol::createVarSymbol("valid_name", TypeInstances::GetNumberInstance(), { NullableValueNumber(1), NullableValueNumber(12) });
    BOOST_CHECK(*boost::get<NullableValueNumber>(symbol2->getValue(1)).value == 12);
}

BOOST_AUTO_TEST_CASE(varsymbol_set_value_test)
{
    std::shared_ptr<VarSymbol> symbol = VarSymbol::createVarSymbol("valid_name", TypeInstances::GetNumberInstance(), { NullableValueNumber(1) });
    symbol->setValue(0, NullableValueNumber(10));
    BOOST_CHECK(*boost::get<NullableValueNumber>(symbol->getValue(0)).value == 10);

    std::shared_ptr<VarSymbol> symbol2 = VarSymbol::createVarSymbol("valid_name", TypeInstances::GetNumberInstance(), { NullableValueNumber(1), NullableValueNumber(12) });
    symbol2->setValue(1, NullableValueNumber(20));
    BOOST_CHECK(*boost::get<NullableValueNumber>(symbol2->getValue(1)).value == 20);
}

BOOST_AUTO_TEST_CASE(varsymbol_set_array_size)
{
    std::shared_ptr<VarSymbol> symbol = VarSymbol::createVarSymbol("valid_name", TypeInstances::GetNumberInstance(), { NullableValueNumber(1) });
    BOOST_CHECK_NO_THROW(symbol->getValue(0));
    BOOST_CHECK_THROW(symbol->getValue(1), std::out_of_range);
    symbol->setArraySize(100);
    BOOST_CHECK_NO_THROW(symbol->getValue(1));
    BOOST_CHECK_NO_THROW(symbol->getValue(99));
    BOOST_CHECK_THROW(symbol->getValue(100), std::out_of_range);
    symbol->setArraySize(1);
    BOOST_CHECK_THROW(symbol->getValue(1), std::out_of_range);
    BOOST_CHECK_THROW(symbol->getValue(99), std::out_of_range);
    BOOST_CHECK_NO_THROW(symbol->getValue(0));



 
}




BOOST_AUTO_TEST_SUITE_END()
