


#include "symboltable.h"
#include "varsymbol.h"
#include "methodsymbol.h"
#include "methodimplementations.h"
#include "methodbucket.h"

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
class ExpressionStatementNode;
class IfStatementNode;
class TernaryNode;

#include "bison.tab.h"


std::shared_ptr<SymbolTable> SymbolTable::GLOBAL_SYMBOL_TABLE = std::make_shared<SymbolTable>(

	// methods declarations
	std::map<std::string, MethodBucket*>({
	{"average", new SingleMethodBucket(new MethodAverage())},
	{"plot", new SingleMethodBucket(new Plot())},
	{"tick", new SingleMethodBucket(new GetTick())},
	{"mark", new SingleMethodBucket(new Mark())},

	{"nan_f", new SingleMethodBucket(new FloatNAN())},
	{"nan_b", new SingleMethodBucket(new BooleanNAN())},



	{"operator" + token_name(yy::parser::token::TPLUS), new OverloadedMethodBucket(
		{new UnaryPlusOperator("operator" + token_name(yy::parser::token::TPLUS)),
		 new BinaryPlusOperator("operator" + token_name(yy::parser::token::TPLUS))
		}
	)},
	{"operator" + token_name(yy::parser::token::TMINUS), new OverloadedMethodBucket(
		{new UnaryMinusOperator("operator" + token_name(yy::parser::token::TMINUS)),
		 new BinaryMinusOperator("operator" + token_name(yy::parser::token::TMINUS))
		}
	)},
	{"operator" + token_name(yy::parser::token::TEQUAL), new OverloadedMethodBucket(
		{new BinaryFloatEqualOperator("operator" + token_name(yy::parser::token::TEQUAL)),
		 new BinaryBooleanEqualOperator("operator" + token_name(yy::parser::token::TEQUAL))
		}
	)},
	{"operator" + token_name(yy::parser::token::TNOTEQUAL), new OverloadedMethodBucket(
		{new BinaryFloatNotEqualOperator("operator" + token_name(yy::parser::token::TNOTEQUAL)),
		 new BinaryBooleanNotEqualOperator("operator" + token_name(yy::parser::token::TNOTEQUAL))
		}
	)},
	{"operator" + token_name(yy::parser::token::TNOT), new SingleMethodBucket(new UnaryNotOperator("operator" + token_name(yy::parser::token::TNOT)))},
	{"operator" + token_name(yy::parser::token::TMUL), new SingleMethodBucket(new BinaryMultiplyOperator("operator" + token_name(yy::parser::token::TMUL)))},
	{"operator" + token_name(yy::parser::token::TDIV), new SingleMethodBucket(new BinaryDivideOperator("operator" + token_name(yy::parser::token::TDIV)))},
	{"operator" + token_name(yy::parser::token::TLESS), new SingleMethodBucket(new BinaryLessOperator("operator" + token_name(yy::parser::token::TLESS)))},
	{"operator" + token_name(yy::parser::token::TLESSEQUAL), new SingleMethodBucket(new BinaryLessEqualOperator("operator" + token_name(yy::parser::token::TLESSEQUAL)))},
	{"operator" + token_name(yy::parser::token::TGREATER), new SingleMethodBucket(new BinaryGreaterOperator("operator" + token_name(yy::parser::token::TGREATER)))},
	{"operator" + token_name(yy::parser::token::TGREATEREQUAL), new SingleMethodBucket(new BinaryGreaterEqualOperator("operator" + token_name(yy::parser::token::TGREATEREQUAL)))},
	{"operator" + token_name(yy::parser::token::TAND), new SingleMethodBucket(new BinaryAndOperator("operator" + token_name(yy::parser::token::TAND)))},
	{"operator" + token_name(yy::parser::token::TOR), new SingleMethodBucket(new BinaryOrOperator("operator" + token_name(yy::parser::token::TOR)))},

	}),
	

	// variables declarations
	std::map<std::string, std::shared_ptr<VarSymbol>>({})
	);



SymbolTable::SymbolTable(std::shared_ptr<SymbolTable> _enclosingSymbolTable) 
	: enclosingSymbolTable(_enclosingSymbolTable) {}

SymbolTable::SymbolTable(std::map<std::string, MethodBucket*> _methodTable,
	std::map<std::string, std::shared_ptr<VarSymbol>> _variableTable)
	: methodTable(_methodTable), variableTable(_variableTable) {}

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

std::string SymbolTable::variablesToString(bool _enclosing) {
	std::string output = "";
	for (const auto& value : variableTable) {
		output += value.second->toString() + "\n";
	}
	if (_enclosing) {
		if (enclosingSymbolTable) {
			output += "######\n";
			output += enclosingSymbolTable->variablesToString(_enclosing);
		}
	}
	return output;
}


bool SymbolTable::isVariableDeclared(const std::string& name) {
	if (variableTable.find(name) != variableTable.end()) {
		return true;
	}
	else {
		if (enclosingSymbolTable) {
			return enclosingSymbolTable->isVariableDeclared(name);
		}
	}

	return false;
}

bool SymbolTable::isMethodDeclared(const std::string& name) {

	if (methodTable.find(name) != methodTable.end()) {
		return true;
	}
	else {
		if (enclosingSymbolTable) {
			return enclosingSymbolTable->isMethodDeclared(name);
		}
	}

	return false;
}

std::shared_ptr<VarSymbol> SymbolTable::getVariable(const std::string& name) {
	if (variableTable.find(name) != variableTable.end()) {
		return variableTable.find(name)->second;
	}
	else {
		if (enclosingSymbolTable) {
			return enclosingSymbolTable->getVariable(name);
		}
	}
	return nullptr;
}


MethodBucket* SymbolTable::getMethod(const std::string& name) {



	if (methodTable.find(name) != methodTable.end()) {
		return methodTable.find(name)->second;
	}
	else {
		if (enclosingSymbolTable) {
			return enclosingSymbolTable->getMethod(name);
		}
	}
	return nullptr;
}

void SymbolTable::declareVariable(std::shared_ptr<VarSymbol> varsymbol) {
	variableTable[varsymbol->name] = varsymbol;
}
