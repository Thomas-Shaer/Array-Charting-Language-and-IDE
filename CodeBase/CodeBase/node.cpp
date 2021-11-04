
#include "node.h"
#include <map>
#include "operator.h"
#include "bison.tab.h"

// maps the token to a operator class which contains useful logic for evaluating the operator

static const std::map<int, Operator*> TokenToOperator{
	{yy::parser::token::TPLUS, new PlusOperator(token_name(yy::parser::token::TPLUS))},
	{yy::parser::token::TMINUS, new MinusOperator(token_name(yy::parser::token::TMINUS))},
	{yy::parser::token::TMUL, new MultiplyOperator(token_name(yy::parser::token::TMUL))},
	{yy::parser::token::TDIV, new DivideOperator(token_name(yy::parser::token::TDIV))},
	{yy::parser::token::TLESS, new LessOperator(token_name(yy::parser::token::TLESS))},
	{yy::parser::token::TLESSEQUAL, new LessEqualOperator(token_name(yy::parser::token::TLESSEQUAL))},
	{yy::parser::token::TGREATER, new GreaterOperator(token_name(yy::parser::token::TGREATER))},
	{yy::parser::token::TGREATEREQUAL, new GreaterEqualOperator(token_name(yy::parser::token::TGREATEREQUAL))},
	{yy::parser::token::TAND, new AndOperator(token_name(yy::parser::token::TAND))},
	{yy::parser::token::TOR, new OrOperator(token_name(yy::parser::token::TOR))}
};

//std::cout << token_name(yy::parser::token::TPLUS) << std::endl;



BinaryOpNode::BinaryOpNode(Expression* _left, int _op, Expression* _right) : left(_left), right(_right), op(TokenToOperator.at(_op)) {}


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





std::string BinaryOpNode::toString() const {
	return left->toString() + " " + op->name + " " + right->toString();
}

BinaryOpNode::~BinaryOpNode() {
	delete left;
	delete right;
}




std::string AssignNode::toString() const {
	return name + " = " + rhs->toString();
}

AssignNode::~AssignNode() {
	delete rhs;
}
