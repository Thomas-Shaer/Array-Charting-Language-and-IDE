#include "node.h"
#include "symboltable.h"
#include "languageexception.h"
#include "methodsymbol.h"
#include "methodbucket.h"

void BlockNode::semanticAnalysis(SymbolTable* symboltable) {
	for (Statement* statement : statementNodes) {
		statement->semanticAnalysis(symboltable);
	}
}

DataType NumberNode::semanticAnalysis(SymbolTable* symboltable) {
	return DataType::Float;
}

DataType BooleanNode::semanticAnalysis(SymbolTable* symboltable) {
	return DataType::Boolean;
}



DataType IdentifierNode::semanticAnalysis(SymbolTable* symboltable) {
	// need to return item in symbol table
	if (symboltable->isVariableDeclared(name)) {
		return symboltable->getVariable(name)->type;
	}
	throw LanguageException("No variable called " + name);
}


void AssignNode::semanticAnalysis(SymbolTable* symboltable) {
	DataType rhsType = rhs->semanticAnalysis(symboltable);

	// variable already declared therefore right side type should be same as left side type
	if (symboltable->isVariableDeclared(name)) {
		if (symboltable->getVariable(name)->type != rhsType) {
			throw LanguageException("RHS type does not match LHS");
		}
	}
	// variable not declared register new variable
	else {
		symboltable->declareVariable(std::make_shared<VarSymbol>(name, rhsType));
	}
	// need to store value in symbol table at lhs name
}

DataType MethodCallNode::semanticAnalysis(SymbolTable* symboltable) {

	// check to see if method exists first
	if (!symboltable->isMethodDeclared(name)) {
		throw LanguageException("No method called " + name);
	}

	std::vector<DataType> argTypes;
	for (Expression* expr : arguments) {
		argTypes.push_back(expr->semanticAnalysis(symboltable));
	}

	this->methodsymbol = symboltable->getMethod(name)->getMethodSymbol(argTypes);
	return methodsymbol->semanticAnaylsis(argTypes);
}