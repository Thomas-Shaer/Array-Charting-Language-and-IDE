#pragma once
#include <iostream>
#include <string>
#include "symboltable.h"

const enum class BinaryOperator {PLUS, MINUS, MUL, DIVIDE};


/*
Base node class

*/
class Node {
public:

	/*
	* String representation of AST - must be overloaded
	*/
	virtual std::string toString() const = 0;

	/*
	* Called upon deletion of Node - must be overloaded
	*/
	virtual ~Node() {}

	virtual ExpressionValue evaluate(SymbolTable* symboltable) const = 0;
};

/*
Number node class, represents a number node e.g. 2
*/
class NumberNode : public Node {
public:
	const float number;
	NumberNode(float _number) : number(_number) {}

	virtual std::string toString() const;

	virtual ~NumberNode();

	virtual ExpressionValue evaluate(SymbolTable* symboltable) const;
};

/*
Identifier node class, represents identifier e.g. foo
*/
class IdentifierNode : public Node {
public:
	const std::string name;
	IdentifierNode(std::string _name) : name(_name) {}

	virtual std::string toString() const;
	virtual ~IdentifierNode();

	virtual ExpressionValue evaluate(SymbolTable* symboltable) const;

};

/*
Binary operator node, used for binary operations e.g. 2 + 3
*/
class BinaryOpNode : public Node {
public:
	const Node* left;
	const Node* right;
	const BinaryOperator op;
	BinaryOpNode(Node* _left, BinaryOperator _op, Node* _right) : left(_left), right(_right), op(_op) {}

	virtual std::string toString() const;

	virtual ~BinaryOpNode();
	virtual ExpressionValue evaluate(SymbolTable* symboltable) const;

};


/*
Assign node, used for assign statements, e.g. x = 2 + 3
*/
class AssignNode : public Node {
public:
	const IdentifierNode* lhs;
	const Node* rhs;
	AssignNode(IdentifierNode* _lhs, Node* _rhs) : lhs(_lhs), rhs(_rhs) {}

	virtual std::string toString() const;

	virtual ~AssignNode();

	virtual ExpressionValue evaluate(SymbolTable* symboltable) const;
};