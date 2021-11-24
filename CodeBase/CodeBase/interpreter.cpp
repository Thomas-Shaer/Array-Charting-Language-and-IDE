#include "node.h"
#include "symboltable.h"
#include "methodsymbol.h"


void BlockNode::interpret(const unsigned int tick, SymbolTable* symboltable, InterpreterOutput& output) const {
	for (Statement* statement : statementNodes) {
		statement->interpret(tick, symboltable, output);
	}
}


void ExpressionStatementNode::interpret(const unsigned int tick, SymbolTable* symboltable, InterpreterOutput& output) const {
	expressionNode->interpret(tick, symboltable, output);
}

ExpressionValue NumberNode::interpret(const unsigned int tick, SymbolTable* symboltable, InterpreterOutput& output) const {
	return (ExpressionValue)Float(number);
}

ExpressionValue BooleanNode::interpret(const unsigned int tick, SymbolTable* symboltable, InterpreterOutput& output) const {
	return (ExpressionValue)Boolean(value);
}


ExpressionValue IdentifierNode::interpret(const unsigned int tick, SymbolTable* symboltable, InterpreterOutput& output) const {
	return symboltable->getVariable(name)->getValue(tick);
}


void AssignNode::interpret(const unsigned int tick, SymbolTable* symboltable, InterpreterOutput& output) const {
	ExpressionValue value = rhs->interpret(tick, symboltable, output);
	symboltable->getVariable(name)->setValue(tick, value);
	// need to store value in symbol table at lhs name
}

ExpressionValue MethodCallNode::interpret(const unsigned int tick, SymbolTable* symboltable, InterpreterOutput& output) const {

	std::vector<ExpressionValue> argValues;
	for (Expression* expr : arguments) {
		argValues.push_back(expr->interpret(tick, symboltable, output));
	}

	return methodsymbol->interpret(tick, argValues, output);
}