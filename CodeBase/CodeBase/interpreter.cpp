#include "node.h"
#include "symboltable.h"
#include "methodsymbol.h"


void BlockNode::interpret(const unsigned int tick, InterpreterOutput& output) const {
	for (Statement* statement : statementNodes) {
		statement->interpret(tick, output);
	}
}


void ExpressionStatementNode::interpret(const unsigned int tick, InterpreterOutput& output) const {
	expressionNode->interpret(tick, output);
}

ExpressionValue NumberNode::interpret(const unsigned int tick, InterpreterOutput& output) const {
	return (ExpressionValue)Float(number);
}

ExpressionValue BooleanNode::interpret(const unsigned int tick, InterpreterOutput& output) const {
	return (ExpressionValue)Boolean(value);
}


ExpressionValue IdentifierNode::interpret(const unsigned int tick, InterpreterOutput& output) const {
	return varSymbol->getValue(tick);
}


void AssignNode::interpret(const unsigned int tick, InterpreterOutput& output) const {
	ExpressionValue value = rhs->interpret(tick, output);
	varSymbol->setValue(tick, value);
	// need to store value in symbol table at lhs name
}

ExpressionValue MethodCallNode::interpret(const unsigned int tick, InterpreterOutput& output) const {

	std::vector<ExpressionValue> argValues;
	for (Expression* expr : arguments) {
		argValues.push_back(expr->interpret(tick, output));
	}

	return methodsymbol->interpret(tick, argValues, output);
}



void IfStatementNode::interpret(const unsigned int tick, InterpreterOutput& output) const {
	// if condition true execute block code.
	std::optional<bool> conditionResult = boost::get<Boolean>(condition->interpret(tick, output)).value;
	if (conditionResult) {
		if (*conditionResult) {
			block->interpret(tick, output);
		}
	}
}


ExpressionValue TernaryNode::interpret(const unsigned int tick, InterpreterOutput& output) const {
	// if condition true execute block code.
	std::optional<bool> conditionResult = boost::get<Boolean>(condition->interpret(tick, output)).value;
	if (conditionResult) {
		return *conditionResult ? expression1->interpret(tick, output) : expression2->interpret(tick, output);
	}
}