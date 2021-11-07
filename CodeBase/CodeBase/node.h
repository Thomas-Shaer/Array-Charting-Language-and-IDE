#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "varsymbol.h"

class SymbolTable;
class BinaryOperator;
class UnaryOperator;

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

};

/*
* Expression variant of node. Evaluate function will return something.
*/
class Expression : public Node {
public:
	virtual DataType semanticAnalysis(SymbolTable* symboltable) const = 0;
	virtual ExpressionValue interpret(SymbolTable* symboltable) const = 0;
};

/*
* Statement variant of node.
*/
class Statement : public Node {
public:
	virtual void semanticAnalysis(SymbolTable* symboltable) const = 0;
	virtual void interpret(SymbolTable* symboltable) const = 0;
};

/*
Block node class, represents a scope i.e. a collection of statements
*/
class BlockNode : public Statement {
public:

	std::vector<Statement*> statementNodes;

	virtual std::string toString() const;

	virtual ~BlockNode();

	virtual void semanticAnalysis(SymbolTable* symboltable) const;
	virtual void interpret(SymbolTable* symboltable) const;
};


/*
Number node class, represents a number node e.g. 2
*/
class NumberNode : public Expression {
public:
	const float number;
	NumberNode(float _number) : number(_number) {}

	virtual std::string toString() const;

	virtual ~NumberNode();

	virtual DataType semanticAnalysis(SymbolTable* symboltable) const;
	virtual ExpressionValue interpret(SymbolTable* symboltable) const;
};


/*
Number node class, represents a number node e.g. 2
*/
class BooleanNode : public Expression {
public:
	const bool value;
	BooleanNode(bool _value) : value(_value) {}

	virtual std::string toString() const;

	virtual ~BooleanNode();

	virtual DataType semanticAnalysis(SymbolTable* symboltable) const;
	virtual ExpressionValue interpret(SymbolTable* symboltable) const;
};

/*
Identifier node class, represents identifier e.g. foo
*/
class IdentifierNode : public Expression {
public:
	const std::string name;
	IdentifierNode(std::string _name) : name(_name) {}

	virtual std::string toString() const;
	virtual ~IdentifierNode();

	virtual DataType semanticAnalysis(SymbolTable* symboltable) const;
	virtual ExpressionValue interpret(SymbolTable* symboltable) const;

};


/*
Assign node, used for assign statements, e.g. x = 2 + 3
*/
class AssignNode : public Statement {
public:
	const std::string name;
	const Expression* rhs;
	AssignNode(std::string _name, Expression* _rhs) : name(_name), rhs(_rhs) {}

	virtual std::string toString() const;

	virtual ~AssignNode();

	virtual void semanticAnalysis(SymbolTable* symboltable) const;
	virtual void interpret(SymbolTable* symboltable) const;
};


/*
Method call node, e.g. average(2, 3)
*/
class MethodCallNode : public Expression {
public:
	const std::string name;
	const std::vector<Expression*> arguments;
	MethodCallNode(std::string _name, std::vector<Expression*> _arguments) : name(_name), arguments(_arguments) {}

	virtual std::string toString() const;

	virtual ~MethodCallNode();

	virtual DataType semanticAnalysis(SymbolTable* symboltable) const;
	virtual ExpressionValue interpret(SymbolTable* symboltable) const;
};