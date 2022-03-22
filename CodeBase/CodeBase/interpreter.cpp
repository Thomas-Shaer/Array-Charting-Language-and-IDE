#include "node.h"
#include "symboltable.h"
#include "methodsymbol.h"
#include "argumentsymbol.h"

void BlockNode::interpret(const unsigned int tick) {
	for (Statement* statement : statementNodes) {
		statement->interpret(tick);
	}
}


void ExpressionStatementNode::interpret(const unsigned int tick) {
	expressionNode->interpret(tick);
}

ExpressionValue NumberNode::interpret(const unsigned int tick) {
	return (ExpressionValue)NullableValueNumber(number);
}

ExpressionValue BooleanNode::interpret(const unsigned int tick) {
	return (ExpressionValue)NullableValueBoolean(value);
}


ExpressionValue StringNode::interpret(const unsigned int tick) {
	return (ExpressionValue)NullableValueString(value);
}


ExpressionValue IdentifierNode::interpret(const unsigned int tick) {
	return varSymbol->getValue(tick);
}



void AssignNode::interpret(const unsigned int tick) {
	ExpressionValue value = rhs->interpret(tick);
	varSymbol->setValue(tick, value);
	// need to store value in symbol table at lhs name
}

void AssignOnceNode::interpret(const unsigned int tick) {
	if (!executed) {
		AssignNode::interpret(tick);
		executed = true;
	}
}

ExpressionValue MethodCallNode::interpret(const unsigned int tick) {


	for (auto item : expressionToArgList) {
		std::shared_ptr<ArgumentSymbol> arg = item.second;
		Expression* expr = arg->expression;
		/*
		Only execute if the ArgumentSymbol has a expression node,
		and therefore is a argument we provided (optional args)
		*/
		if (expr) {
			arg->expressionValue = expr->interpret(tick);
		}
	}


	return methodsymbol->interpret(tick);
}


ExpressionValue KeywordNode::interpret(const unsigned int tick) {
	return rhs->interpret(tick);
}



void IfStatementNode::interpret(const unsigned int tick) {
	// if condition true execute block code.
	std::optional<bool> conditionResult = boost::get<NullableValueBoolean>(condition->interpret(tick)).value;
	if (conditionResult) {
		if (*conditionResult) {
			block->interpret(tick);
		}
	}
}


ExpressionValue TernaryNode::interpret(const unsigned int tick) {
	// if condition true execute block code.
	std::optional<bool> conditionResult = boost::get<NullableValueBoolean>(condition->interpret(tick)).value;
	if (conditionResult) {
		return *conditionResult ? expression1->interpret(tick) : expression2->interpret(tick);
	}
}