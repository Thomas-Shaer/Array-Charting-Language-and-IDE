#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <string>
#include "CodeBase/argumentsymbol.h"
#include "CodeBase/node.h"
#include "CodeBase/typesymbol.h"

BOOST_AUTO_TEST_SUITE(ARGUMENTSYMBOL)

BOOST_AUTO_TEST_CASE(argument_symbol_literal_value_at_compile_time)
{
    // literal number should have same value as node
    NumberNode* numberNode = new NumberNode(5, yy::SourceLocation());
    ArgumentSymbol argSymbolLitN(TypeInstances::GetNumberConstantInstance(), numberNode);
    BOOST_CHECK(*boost::get<NullableValueNumber>(argSymbolLitN.expressionValue).value == 5);
    delete numberNode;

    // literal string should have same value as node
    StringNode* stringNode = new StringNode("Hello World!", yy::SourceLocation());
    ArgumentSymbol argSymbolLitS(TypeInstances::GetStringConstantInstance(), stringNode);
    BOOST_CHECK(*boost::get<NullableValueString>(argSymbolLitS.expressionValue).value == "Hello World!");
    delete stringNode;
}

BOOST_AUTO_TEST_CASE(argument_symbol_correct_null_value)
{
    IdentifierNode* identifierNode = new IdentifierNode("test", yy::SourceLocation());

    // should have null value
    ArgumentSymbol argSymbolIDB(TypeInstances::GetBooleanInstance(), identifierNode);
    BOOST_CHECK(!boost::get<NullableValueBoolean>(argSymbolIDB.expressionValue).value);

    // should have null value
    ArgumentSymbol argSymbolIDN(TypeInstances::GetNumberInstance(), identifierNode);
    BOOST_CHECK(!boost::get<NullableValueNumber>(argSymbolIDN.expressionValue).value);

    // should have null value
    ArgumentSymbol argSymbolIDS(TypeInstances::GetStringInstance(), identifierNode);
    BOOST_CHECK(!boost::get<NullableValueString>(argSymbolIDS.expressionValue).value);

    delete identifierNode;

}

BOOST_AUTO_TEST_SUITE_END()
