#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "varsymbol.h"
#include "interpreteroutput.h"
#include <map>

class SymbolTable;
class BinaryOperator;
class UnaryOperator;
class MethodSymbol;
class ArgumentSymbol;

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
	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) = 0;
	virtual ExpressionValue interpret(const unsigned int tick) const = 0;
};

/*
* Statement variant of node.
*/
class Statement : public Node {
public:
	virtual void semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) = 0;
	virtual void interpret(const unsigned int tick) const = 0;
};

/*
Expression statment node, acts as a statement wrapper for a expression. Allows
to parse things such as a method call outside a assign context.
*/
class ExpressionStatementNode : public Statement {
public:

	Expression* expressionNode;

	ExpressionStatementNode(Expression* _expressionNode) : expressionNode(_expressionNode) {}

	virtual std::string toString() const;

	virtual ~ExpressionStatementNode();

	virtual void semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);
	virtual void interpret(const unsigned int tick) const;
};

/*
Block node class, represents a scope i.e. a collection of statements
*/
class BlockNode : public Statement {
public:

	std::vector<Statement*> statementNodes;

	virtual std::string toString() const;

	virtual ~BlockNode();

	virtual void semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);
	virtual void interpret(const unsigned int tick) const;
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

	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);
	virtual ExpressionValue interpret(const unsigned int tick) const;
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

	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);
	virtual ExpressionValue interpret(const unsigned int tick) const;
};


/*
String node class, represents a number node e.g. 2
*/
class StringNode : public Expression {
public:
	const std::string value;
	StringNode(std::string _value) : value(_value) {}

	virtual std::string toString() const;

	virtual ~StringNode();

	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);
	virtual ExpressionValue interpret(const unsigned int tick) const;
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

	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);
	virtual ExpressionValue interpret(const unsigned int tick) const;

private:
	// set in the semantic phase
	std::shared_ptr<VarSymbol> varSymbol;

};


/*
Keyword node class, represents parameter keyword e.g. plot(level=2)
*/
class KeywordNode : public Expression {
public:
	const std::string name;
	Expression* rhs;
	KeywordNode(std::string _name, Expression* _rhs) : name(_name), rhs(_rhs) {}

	virtual std::string toString() const;
	virtual ~KeywordNode();

	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);
	virtual ExpressionValue interpret(const unsigned int tick) const;
};


/*
Assign node, used for assign statements, e.g. x = 2 + 3
*/
class AssignNode : public Statement {
public:
	const std::string name;
	Expression* rhs;
	AssignNode(std::string _name, Expression* _rhs) : name(_name), rhs(_rhs) {}

	virtual std::string toString() const;

	virtual ~AssignNode();

	virtual void semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);
	virtual void interpret(const unsigned int tick) const;

private:
	// set in the semantic phase
	std::shared_ptr<VarSymbol> varSymbol;
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

	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);
	virtual ExpressionValue interpret(const unsigned int tick) const;

	std::map<std::string, std::shared_ptr<ArgumentSymbol>> expressionToArgList;

private:
	MethodSymbol* methodsymbol;

};


/*
If statement node
*/
class IfStatementNode : public Statement {
public:
	Expression* condition;
	BlockNode* block;
	IfStatementNode(Expression* _condition, BlockNode* _block) : condition(_condition), block(_block) {}

	virtual std::string toString() const;

	virtual ~IfStatementNode();

	virtual void semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);
	virtual void interpret(const unsigned int tick) const;

};


/*
Ternary node
*/
class TernaryNode : public Expression {
public:
	Expression* condition;
	Expression* expression1;
	Expression* expression2;
	TernaryNode(Expression* _condition, Expression* _expression1, Expression* _expression2) 
		: condition(_condition), expression1(_expression1), expression2(_expression2) {}

	virtual std::string toString() const;

	virtual ~TernaryNode();

	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);
	virtual ExpressionValue interpret(const unsigned int tick) const;

};