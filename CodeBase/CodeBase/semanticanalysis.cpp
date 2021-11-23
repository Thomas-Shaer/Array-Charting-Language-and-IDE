#include "node.h"
#include "symboltable.h"
#include "languageexception.h"
#include "methodsymbol.h"
#include "methodbucket.h"
#include "typesymbol.h"

void BlockNode::semanticAnalysis(SymbolTable* symboltable, std::vector<std::string>& output) {
	for (Statement* statement : statementNodes) {
		statement->semanticAnalysis(symboltable, output);
	}
}

const TypeSymbol* NumberNode::semanticAnalysis(SymbolTable* symboltable, std::vector<std::string>& output) {
	return TypeInstances::GetFloatInstance();
}

const TypeSymbol* BooleanNode::semanticAnalysis(SymbolTable* symboltable, std::vector<std::string>& output) {
	return TypeInstances::GetBooleanInstance();
}



const TypeSymbol* IdentifierNode::semanticAnalysis(SymbolTable* symboltable, std::vector<std::string>& output) {
	// need to return item in symbol table
	if (symboltable->isVariableDeclared(name)) {
		return symboltable->getVariable(name)->type;
	}
	throw LanguageException("No variable called " + name);
}



void ExpressionStatementNode::semanticAnalysis(SymbolTable* symboltable, std::vector<std::string>& output) {
	expressionNode->semanticAnalysis(symboltable, output);
}


void AssignNode::semanticAnalysis(SymbolTable* symboltable, std::vector<std::string>& output) {
	const TypeSymbol* rhsType = rhs->semanticAnalysis(symboltable, output);

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

const TypeSymbol* MethodCallNode::semanticAnalysis(SymbolTable* symboltable, std::vector<std::string>& output) {

	// check to see if method exists first
	if (!symboltable->isMethodDeclared(name)) {
		throw LanguageException("No method called " + name);
	}

	std::vector<const TypeSymbol*> argTypes;
	for (Expression* expr : arguments) {
		argTypes.push_back(expr->semanticAnalysis(symboltable, output));
	}

	this->methodsymbol = symboltable->getMethod(name)->getMethodSymbol(argTypes);
	return methodsymbol->semanticAnaylsis(argTypes);
}