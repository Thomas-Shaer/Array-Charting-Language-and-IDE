#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <string>
#include "CodeBase/typesymbol.h"
#include "CodeBase/varsymbol.h"
#include "CodeBase/symboltable.h"

BOOST_AUTO_TEST_SUITE(SYMBOLTABLE)

BOOST_AUTO_TEST_CASE(symbol_table_variable_declared_test)
{
    std::shared_ptr<VarSymbol> varsymbol1 = VarSymbol::createVarSymbol("valid_name", TypeInstances::GetNumberInstance(), { NullableValueNumber(1) });
    std::shared_ptr<SymbolTable> table = std::make_shared<SymbolTable>(std::map<std::string, MethodBucket*>(), std::map<std::string, std::shared_ptr<VarSymbol>>());
    BOOST_CHECK(!table->isVariableDeclared(varsymbol1->name));
    table->declareVariable(varsymbol1);
    BOOST_CHECK(table->isVariableDeclared(varsymbol1->name));

    // access variable from parent scope
    std::shared_ptr<SymbolTable> table2 = std::make_shared<SymbolTable>(table);
    BOOST_CHECK(table2->isVariableDeclared(varsymbol1->name));
    std::shared_ptr<VarSymbol> varsymbol2 = VarSymbol::createVarSymbol("valid_name2", TypeInstances::GetNumberInstance(), { NullableValueNumber(1) });
    // enclosing scope cannot access child variable
    table2->declareVariable(varsymbol2);
    BOOST_CHECK(!table->isVariableDeclared(varsymbol2->name));
    BOOST_CHECK(table2->isVariableDeclared(varsymbol2->name));
}


BOOST_AUTO_TEST_CASE(symbol_table_get_variable_test)
{
    std::shared_ptr<VarSymbol> varsymbol1 = VarSymbol::createVarSymbol("valid_name", TypeInstances::GetNumberInstance(), { NullableValueNumber(1) });
    std::shared_ptr<SymbolTable> table = std::make_shared<SymbolTable>(std::map<std::string, MethodBucket*>(), std::map<std::string, std::shared_ptr<VarSymbol>>());
    table->declareVariable(varsymbol1);
    BOOST_CHECK(table->getVariable(varsymbol1->name) == varsymbol1);

}

BOOST_AUTO_TEST_CASE(symbol_table_variables_to_vector_test)
{
    std::vector<std::shared_ptr<VarSymbol>> initvariables = {
         VarSymbol::createVarSymbol("valid_name", TypeInstances::GetNumberInstance(), { NullableValueNumber(1) }),
         VarSymbol::createVarSymbol("valid_name2", TypeInstances::GetNumberInstance(), { NullableValueNumber(1) })
    };

    std::sort(initvariables.begin(), initvariables.end());

    std::shared_ptr<SymbolTable> table = std::make_shared<SymbolTable>(std::map<std::string, MethodBucket*>(), std::map<std::string, std::shared_ptr<VarSymbol>>());
    
    for (auto var : initvariables) {
        table->declareVariable(var);
    }

    std::vector<std::shared_ptr<VarSymbol>> retrieved = table->variablesToVector(true);
    std::sort(retrieved.begin(), retrieved.end());
    BOOST_CHECK(retrieved == initvariables);

    // enclosing test: only scope variables

    std::shared_ptr<SymbolTable> table2 = std::make_shared<SymbolTable>(table);


    std::vector<std::shared_ptr<VarSymbol>> initvariables2 = {
         VarSymbol::createVarSymbol("valid_name3", TypeInstances::GetNumberInstance(), { NullableValueNumber(1) }),
    };

    for (auto var : initvariables2) {
        table2->declareVariable(var);
    }

    std::vector<std::shared_ptr<VarSymbol>> retrieved2 = table2->variablesToVector(false);
    std::sort(retrieved2.begin(), retrieved2.end());
    BOOST_CHECK(initvariables2 == retrieved2);

    // enclosing test: scope and enclosing variables

    std::vector<std::shared_ptr<VarSymbol>> retrieved3 = table2->variablesToVector(true);
    std::sort(retrieved3.begin(), retrieved3.end());


    std::vector<std::shared_ptr<VarSymbol>> combined = initvariables;
    combined.insert(combined.end(), initvariables2.begin(), initvariables2.end());
    std::sort(combined.begin(), combined.end());
    BOOST_CHECK(combined == retrieved3);




}

BOOST_AUTO_TEST_SUITE_END()
