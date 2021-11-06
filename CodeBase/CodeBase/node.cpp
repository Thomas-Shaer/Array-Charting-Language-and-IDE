
#include "node.h"
#include <map>
#include "binaryoperator.h"
#include "unaryoperator.h"
#include "bison.tab.h"

// maps the token to a binary operator object which contains useful logic for evaluating the operator and operands

static const std::map<int, BinaryOperator*> TokenToBinaryOperator{
	{yy::parser::token::TPLUS, new BinaryPlusOperator(token_name(yy::parser::token::TPLUS))},
	{yy::parser::token::TMINUS, new BinaryMinusOperator(token_name(yy::parser::token::TMINUS))},
	{yy::parser::token::TMUL, new BinaryMultiplyOperator(token_name(yy::parser::token::TMUL))},
	{yy::parser::token::TDIV, new BinaryDivideOperator(token_name(yy::parser::token::TDIV))},
	{yy::parser::token::TLESS, new BinaryLessOperator(token_name(yy::parser::token::TLESS))},
	{yy::parser::token::TLESSEQUAL, new BinaryLessEqualOperator(token_name(yy::parser::token::TLESSEQUAL))},
	{yy::parser::token::TGREATER, new BinaryGreaterOperator(token_name(yy::parser::token::TGREATER))},
	{yy::parser::token::TGREATEREQUAL, new BinaryGreaterEqualOperator(token_name(yy::parser::token::TGREATEREQUAL))},
	{yy::parser::token::TAND, new BinaryAndOperator(token_name(yy::parser::token::TAND))},
	{yy::parser::token::TOR, new BinaryOrOperator(token_name(yy::parser::token::TOR))}
};


// maps the token to a unary operator object which contains useful logic for evaluating the operator and operands

static const std::map<int, UnaryOperator*> TokenToUnaryOperator{
	{yy::parser::token::TPLUS, new UnaryPlusOperator(token_name(yy::parser::token::TPLUS))},
	{yy::parser::token::TMINUS, new UnaryMinusOperator(token_name(yy::parser::token::TMINUS))},
	{yy::parser::token::TNOT, new UnaryNotOperator(token_name(yy::parser::token::TNOT))},
};






std::string BlockNode::toString() const {
	std::string block;

	for (Statement* statement : statementNodes) {
		block += statement->toString() + "\n";
	}


	return block;
}




BlockNode::~BlockNode() {
	for (Statement* statement : statementNodes) {
		delete statement;
	}
}



std::string NumberNode::toString() const {
	return std::to_string(number);
}


NumberNode::~NumberNode() {}


std::string BooleanNode::toString() const {
	return value ? "true" : "false";
}

BooleanNode::~BooleanNode() {}


std::string IdentifierNode::toString() const {
	return name;
}

IdentifierNode::~IdentifierNode() {}



BinaryOpNode::BinaryOpNode(Expression* _left, int _op, Expression* _right) : left(_left), right(_right), op(TokenToBinaryOperator.at(_op)) {}


std::string BinaryOpNode::toString() const {
	return left->toString() + " " + op->name + " " + right->toString();
}

BinaryOpNode::~BinaryOpNode() {
	delete left;
	delete right;
}


UnaryOpNode::UnaryOpNode(int _op, Expression* _expression) : expression(_expression), op(TokenToUnaryOperator.at(_op)) {}

std::string UnaryOpNode::toString() const {
	return op->name + " " + expression->toString();
}

UnaryOpNode::~UnaryOpNode() {
	delete expression;
}



std::string AssignNode::toString() const {
	return name + " = " + rhs->toString();
}

AssignNode::~AssignNode() {
	delete rhs;
}



std::string MethodCallNode::toString() const {
	std::string output = name + "(";
	for (const Expression* argument : arguments) {
		output += argument->toString() + ", ";
	}
	output += ")";
	return output;
}

MethodCallNode::~MethodCallNode() {
	for (const Expression* argument : arguments) {
		delete argument;
	}
}
