


#include "symboltable.h"
#include "varsymbol.h"
#include "methodsymbol.h"
#include "methodimplementations.h"

// have to forward declare for whatever reason to keep bison include happy
class NumberNode;
class BooleanNode;
class Expression;
class Statement;
class Node;
class BinaryOpNode;
class BlockNode;
class AssignNode;
class IdentifierNode;
class MethodCallNode;
#include "bison.tab.h"


std::map<std::string, MethodSymbol*> SymbolTable::methodTable{
	{"average", new MethodAverage()},
	{"unary_operator" + token_name(yy::parser::token::TPLUS), new UnaryPlusOperator("unary_operator" + token_name(yy::parser::token::TPLUS))},
	{"unary_operator" + token_name(yy::parser::token::TMINUS), new UnaryMinusOperator("unary_operator" + token_name(yy::parser::token::TMINUS))},
	{"unary_operator" + token_name(yy::parser::token::TNOT), new UnaryNotOperator("unary_operator" + token_name(yy::parser::token::TNOT))},

	{"binary_operator" + token_name(yy::parser::token::TPLUS), new BinaryPlusOperator("binary_operator" + token_name(yy::parser::token::TPLUS))},
	{"binary_operator" + token_name(yy::parser::token::TMINUS), new BinaryMinusOperator("binary_operator" + token_name(yy::parser::token::TMINUS))},
	{"binary_operator" + token_name(yy::parser::token::TMUL), new BinaryMultiplyOperator("binary_operator" + token_name(yy::parser::token::TMUL))},
	{"binary_operator" + token_name(yy::parser::token::TDIV), new BinaryDivideOperator("binary_operator" + token_name(yy::parser::token::TDIV))},
	{"binary_operator" + token_name(yy::parser::token::TLESS), new BinaryLessOperator("binary_operator" + token_name(yy::parser::token::TLESS))},
	{"binary_operator" + token_name(yy::parser::token::TLESSEQUAL), new BinaryLessEqualOperator("binary_operator" + token_name(yy::parser::token::TLESSEQUAL))},
	{"binary_operator" + token_name(yy::parser::token::TGREATER), new BinaryGreaterOperator("binary_operator" + token_name(yy::parser::token::TGREATER))},
	{"binary_operator" + token_name(yy::parser::token::TGREATEREQUAL), new BinaryGreaterEqualOperator("binary_operator" + token_name(yy::parser::token::TGREATEREQUAL))},
	{"binary_operator" + token_name(yy::parser::token::TAND), new BinaryAndOperator("binary_operator" + token_name(yy::parser::token::TAND))},
	{"binary_operator" + token_name(yy::parser::token::TOR), new BinaryOrOperator("binary_operator" + token_name(yy::parser::token::TOR))},

};

SymbolTable::SymbolTable() {}

std::string SymbolTable::toString() {
	std::string output = "SYMBOL TABLE\nVariables:\n";

	for (const auto& value : variableTable) {
		output += value.second->toString() + "\n";
	}

	output += "Methods:\n";

	for (const auto& value : methodTable) {
		output += value.second->toString() + "\n";
	}

	return output;
}

bool SymbolTable::isVariableDeclared(const std::string& name) {
	return variableTable.find(name) != variableTable.end();
}

bool SymbolTable::isMethodDeclared(const std::string& name) {
	return methodTable.find(name) != methodTable.end();
}

std::shared_ptr<VarSymbol> SymbolTable::getVariable(const std::string& name) {
	return variableTable[name];
}


MethodSymbol* SymbolTable::getMethod(const std::string& name) {
	return methodTable[name];
}

void SymbolTable::declareVariable(std::shared_ptr<VarSymbol> varsymbol) {
	variableTable[varsymbol->name] = varsymbol;
}
