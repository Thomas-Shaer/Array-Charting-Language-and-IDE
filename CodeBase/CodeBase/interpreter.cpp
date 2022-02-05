#include "node.h"
#include "symboltable.h"
#include "methodsymbol.h"
#include "argumentsymbol.h"

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


ExpressionValue StringNode::interpret(const unsigned int tick, InterpreterOutput& output) const {
	return (ExpressionValue)String(value);
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


	for (auto item : expressionToArgList) {
		std::shared_ptr<ArgumentSymbol> arg = item.second;
		Expression* expr = arg->expression;
		/*
		Only execute if the ArgumentSymbol has a expression node,
		and therefore is a argument we provided (optional args)
		*/
		if (expr) {
			arg->expressionValue = expr->interpret(tick, output);
		}
	}


	return methodsymbol->interpret(tick, output);
}


ExpressionValue KeywordNode::interpret(const unsigned int tick, InterpreterOutput& output) const {
	return rhs->interpret(tick, output);
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