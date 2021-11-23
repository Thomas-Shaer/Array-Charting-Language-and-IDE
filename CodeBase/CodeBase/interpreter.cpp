#include "node.h"
#include "symboltable.h"
#include "methodsymbol.h"


void BlockNode::interpret(SymbolTable* symboltable, std::vector<std::string>& output) const {
	for (Statement* statement : statementNodes) {
		statement->interpret(symboltable, output);
	}
}


void ExpressionStatementNode::interpret(SymbolTable* symboltable, std::vector<std::string>& output) const {
	expressionNode->interpret(symboltable, output);
}

ExpressionValue NumberNode::interpret(SymbolTable* symboltable, std::vector<std::string>& output) const {
	return (ExpressionValue)Float(number);
}

ExpressionValue BooleanNode::interpret(SymbolTable* symboltable, std::vector<std::string>& output) const {
	return (ExpressionValue)Boolean(value);
}


ExpressionValue IdentifierNode::interpret(SymbolTable* symboltable, std::vector<std::string>& output) const {
	return symboltable->getVariable(name)->getValue();
}


void AssignNode::interpret(SymbolTable* symboltable, std::vector<std::string>& output) const {
	ExpressionValue value = rhs->interpret(symboltable, output);
	symboltable->getVariable(name)->setValue(value);
	// need to store value in symbol table at lhs name
}

ExpressionValue MethodCallNode::interpret(SymbolTable* symboltable, std::vector<std::string>& output) const {

	std::vector<ExpressionValue> argValues;
	for (Expression* expr : arguments) {
		argValues.push_back(expr->interpret(symboltable, output));
	}

	return methodsymbol->interpret(argValues, output);
}