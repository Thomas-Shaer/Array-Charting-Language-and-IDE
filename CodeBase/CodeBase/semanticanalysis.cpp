#include "node.h"
#include "symboltable.h"
#include "languageexception.h"
#include "methodsymbol.h"
#include "methodbucket.h"
#include "typesymbol.h"

void BlockNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	for (Statement* statement : statementNodes) {
		statement->semanticAnalysis(symboltable, output);
	}
}

const TypeSymbol* NumberNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	return TypeInstances::GetFloatInstance();
}

const TypeSymbol* BooleanNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	return TypeInstances::GetBooleanInstance();
}



const TypeSymbol* IdentifierNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	// need to return item in symbol table
	if (symboltable->isVariableDeclared(name)) {
		varSymbol = symboltable->getVariable(name);
		return varSymbol->type;
	}
	throw LanguageException("No variable called " + name);
}



void ExpressionStatementNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	expressionNode->semanticAnalysis(symboltable, output);
}


void AssignNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	const TypeSymbol* rhsType = rhs->semanticAnalysis(symboltable, output);

	// x = void
	if (rhsType == TypeInstances::GetVoidInstance()) {
		throw LanguageException("Void is not a assignable type.");
	}

	// variable already declared therefore right side type should be same as left side type
	if (symboltable->isVariableDeclared(name)) {
		varSymbol = symboltable->getVariable(name);

		if (varSymbol->type != rhsType) {
			throw LanguageException("RHS type does not match LHS");
		}
	}
	// variable not declared register new variable
	else {
		varSymbol = std::make_shared<VarSymbol>(name, rhsType);

		symboltable->declareVariable(varSymbol);
	}
	// need to store value in symbol table at lhs name
}

const TypeSymbol* MethodCallNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {

	// check to see if method exists first
	if (!symboltable->isMethodDeclared(name)) {
		throw LanguageException("No method called " + name);
	}

	std::vector<const TypeSymbol*> argTypes;
	for (Expression* expr : arguments) {
		argTypes.push_back(expr->semanticAnalysis(symboltable, output));
	}

	this->methodsymbol = symboltable->getMethod(name)->getMethodSymbol(argTypes)->clone();
	return methodsymbol->semanticAnaylsis(argTypes, output);
}

void IfStatementNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	if (condition->semanticAnalysis(symboltable, output) != TypeInstances::GetBooleanInstance()) {
		throw LanguageException("If statement condition must be a boolean.");
	}
	// create new symbol table
	std::shared_ptr<SymbolTable> ifStatementSymbolTable = std::make_shared<SymbolTable>(symboltable);
	block->semanticAnalysis(ifStatementSymbolTable, output);
}