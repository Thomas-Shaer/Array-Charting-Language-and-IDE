#include "node.h"
#include "symboltable.h"
#include "methodsymbol.h"


void BlockNode::interpret(SymbolTable* symboltable) const {
	for (Statement* statement : statementNodes) {
		statement->interpret(symboltable);
	}
}

ExpressionValue NumberNode::interpret(SymbolTable* symboltable) const {
	return (ExpressionValue)Float(number);
}

ExpressionValue BooleanNode::interpret(SymbolTable* symboltable) const {
	return (ExpressionValue)Boolean(value);
}


ExpressionValue IdentifierNode::interpret(SymbolTable* symboltable) const {
	return symboltable->getVariable(name)->getValue();
}


void AssignNode::interpret(SymbolTable* symboltable) const {
	ExpressionValue value = rhs->interpret(symboltable);
	symboltable->getVariable(name)->setValue(value);
	// need to store value in symbol table at lhs name
}

ExpressionValue MethodCallNode::interpret(SymbolTable* symboltable) const {

	std::vector<ExpressionValue> argValues;
	for (Expression* expr : arguments) {
		argValues.push_back(expr->interpret(symboltable));
	}

	return methodsymbol->interpret(argValues);
}