#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "varsymbol.h"
#include "sourcelocation.h"
#include <map>

class SymbolTable;
class MethodSymbol;
class ArgumentSymbol;

/*
Base node class

*/
class Node {
public:
	Node(yy::SourceLocation csourceLocation);
	
	/*
	* String representation of AST - must be overloaded
	*/
	virtual std::string toString() const = 0;

	/*
	* Called upon deletion of Node - must be overloaded
	*/
	virtual ~Node() {}


	/*
	Source code location of the token(s) that generated this Node.
	*/
	yy::SourceLocation sourceLocation;

	bool semanticExecuted = false;

};

/*
Expression child class of node. 
Interpet/semanticAnalysis visitors will return a value/type.
E.g. numbers, method calls, identifiers
*/
class Expression : public Node {
public:
	Expression(yy::SourceLocation csourceLocation) : Node(csourceLocation) {}

	/*
	Semantic Analyzer visitor abstract method. 
	Performs type checking and returns type of expression.
	Takes a symbol table of current scope as parameter.
	*/
	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) = 0;
	/*
	Interpet visitor abstract method.
	Performs runtime actions. Returns a value computed from expression.
	Takes a tick relating to current index of array data.
	*/
	virtual ExpressionValue interpret(const unsigned int tick) const = 0;


	const TypeSymbol* cachedReturnType;
};

/*
Statement variant of node.
E.g. if statement, block, assign
*/
class Statement : public Node {
public:
	Statement(yy::SourceLocation csourceLocation) : Node(csourceLocation) {}

	/*
	Semantic Analyzer visitor abstract method.
	Performs type checking.
	Takes a symbol table of current scope as parameter.
	*/
	virtual void semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) = 0;

	/*
	Interpet visitor abstract method.
	Performs runtime actions.
	Takes a tick relating to current index of array data.
	*/
	virtual void interpret(const unsigned int tick) const = 0;
};

/*
Expression statement node. 
A statement node wrapper for a expression node.
Motivation: 
Some expressions should also be treated like statements.
E.g. method call
*/
class ExpressionStatementNode : public Statement {
public:


	ExpressionStatementNode(Expression* _expressionNode, yy::SourceLocation csourceLocation) : expressionNode(_expressionNode), Statement(csourceLocation){}

	/*
	Representation of this node as a string
	*/
	virtual std::string toString() const;

	virtual ~ExpressionStatementNode();

	/*
	Semantic Analyzer visitor abstract method.
	Performs type checking.
	Takes a symbol table of current scope as parameter.
	*/
	virtual void semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);

	/*
	Interpet visitor abstract method.
	Performs runtime actions.
	Takes a tick relating to current index of array data.
	*/
	virtual void interpret(const unsigned int tick) const;

private:
	// the expression this node is wrapping
	Expression* expressionNode;

};

/*
Block node class.
Represents a scope i.e. a collection of statements
E.g. if statement block
*/
class BlockNode : public Statement {
public:

	BlockNode(yy::SourceLocation csourceLocation) : Statement(csourceLocation) {}


	/*
	Representation of this node as a string
	*/
	virtual std::string toString() const;

	virtual ~BlockNode();

	/*
	Semantic Analyzer visitor abstract method.
	Performs type checking.
	Takes a symbol table of current scope as parameter.
	*/
	virtual void semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);

	/*
	Interpet visitor abstract method.
	Performs runtime actions.
	Takes a tick relating to current index of array data.
	*/
	virtual void interpret(const unsigned int tick) const;


	// the statements belonging to this block
	std::vector<Statement*> statementNodes;

private:

};


/*
NullableValueNumber node class.
Represents a literal number node e.g. 2
*/
class NumberNode : public Expression {
public:
	NumberNode(float _number, yy::SourceLocation csourceLocation) : number(_number), Expression(csourceLocation) {}

	/*
	Representation of this node as a string
	*/
	virtual std::string toString() const;

	virtual ~NumberNode();

	/*
	Semantic Analyzer visitor abstract method.
	Performs type checking and returns type of expression.
	Takes a symbol table of current scope as parameter.
	*/
	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);

	/*
	Interpet visitor abstract method.
	Performs runtime actions. Returns a value computed from expression.
	Takes a tick relating to current index of array data.
	*/
	virtual ExpressionValue interpret(const unsigned int tick) const;

	// the number this node represents
	const float number;
private:


};


/*
NullableValueBoolean node class
Represents a literal boolean e.g. true/false
*/
class BooleanNode : public Expression {
public:
	BooleanNode(bool _value, yy::SourceLocation csourceLocation) : value(_value), Expression(csourceLocation) {}

	/*
	Representation of this node as a string
	*/
	virtual std::string toString() const;

	virtual ~BooleanNode();

	/*
	Semantic Analyzer visitor abstract method.
	Performs type checking and returns type of expression.
	Takes a symbol table of current scope as parameter.
	*/
	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);

	/*
	Interpet visitor abstract method.
	Performs runtime actions. Returns a value computed from expression.
	Takes a tick relating to current index of array data.
	*/
	virtual ExpressionValue interpret(const unsigned int tick) const;

private:
	// the bool value this node represents
	const bool value;
};


/*
String node class
Represents a literal string node e.g. "Hello World"
*/
class StringNode : public Expression {
public:
	StringNode(std::string _value, yy::SourceLocation csourceLocation) : value(_value), Expression(csourceLocation) {}

	/*
	Representation of this node as a string
	*/
	virtual std::string toString() const;

	virtual ~StringNode();

	/*
	Semantic Analyzer visitor abstract method.
	Performs type checking and returns type of expression.
	Takes a symbol table of current scope as parameter.
	*/
	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);

	/*
	Interpet visitor abstract method.
	Performs runtime actions. Returns a value computed from expression.
	Takes a tick relating to current index of array data.
	*/
	virtual ExpressionValue interpret(const unsigned int tick) const;


	// the string this node represents
	const std::string value;
private:
};

/*
Identifier node class.
Represents variable identifier e.g. foo
*/
class IdentifierNode : public Expression {
public:
	IdentifierNode(std::string _name, yy::SourceLocation csourceLocation) : name(_name), Expression(csourceLocation) {}

	/*
	Representation of this node as a string
	*/
	virtual std::string toString() const;
	virtual ~IdentifierNode();

	/*
	Semantic Analyzer visitor abstract method.
	Performs type checking and returns type of expression.
	Takes a symbol table of current scope as parameter.
	*/
	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);

	/*
	Interpet visitor abstract method.
	Performs runtime actions. Returns a value computed from expression.
	Takes a tick relating to current index of array data.
	*/
	virtual ExpressionValue interpret(const unsigned int tick) const;

private:
	/*
	Pointer to VarSymbol this identifier maps to.
	(Value is stored within it)
	Acts as optimisation so a var lookup doesn't
	have to performed every tick in interpeter.
	Set in the semantic phase.
	*/
	std::shared_ptr<VarSymbol> varSymbol;
	// name of variable
	const std::string name;
};


/*
Keyword node class.
Represents parameter keyword e.g. plot(level=2)
									   ^^^^^^^
*/
class KeywordNode : public Expression {
public:

	KeywordNode(std::string _name, Expression* _rhs, yy::SourceLocation csourceLocation) : name(_name), rhs(_rhs), Expression(csourceLocation) {}

	/*
	Representation of this node as a string
	*/
	virtual std::string toString() const;
	virtual ~KeywordNode();

	/*
	Semantic Analyzer visitor abstract method.
	Performs type checking and returns type of expression.
	Takes a symbol table of current scope as parameter.
	*/
	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);

	/*
	Interpet visitor abstract method.
	Performs runtime actions. Returns a value computed from expression.
	Takes a tick relating to current index of array data.
	*/
	virtual ExpressionValue interpret(const unsigned int tick) const;

	// name of this parameter
	const std::string name;

	// value of the argument
	Expression* rhs;
private:
};


/*
Assign node.
Used for assign statements, e.g. x = 2 + 3
*/
class AssignNode : public Statement {
public:

	AssignNode(std::string _name, Expression* _rhs, yy::SourceLocation csourceLocation) : name(_name), rhs(_rhs), Statement(csourceLocation) {
	}

	/*
	Representation of this node as a string
	*/
	virtual std::string toString() const;

	virtual ~AssignNode();

	/*
	Semantic Analyzer visitor abstract method.
	Performs type checking.
	Takes a symbol table of current scope as parameter.
	*/
	virtual void semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);

	/*
	Interpet visitor abstract method.
	Performs runtime actions.
	Takes a tick relating to current index of array data.
	*/
	virtual void interpret(const unsigned int tick) const;

private:
	/*
	Pointer to VarSymbol this assign maps to.
	(Value is stored within it)
	Acts as optimisation so a var lookup doesn't
	have to performed every tick in interpeter.
	Set in the semantic phase.
	*/
	std::shared_ptr<VarSymbol> varSymbol;

	// name of this variable
	const std::string name;

	// rhs expression of assign operator
	Expression* rhs;
};


/*
Method call node.
e.g. average(2, 3)
*/
class MethodCallNode : public Expression {
public:

	MethodCallNode(std::string _name, std::vector<Expression*> _arguments, yy::SourceLocation csourceLocation) : name(_name), arguments(_arguments), Expression(csourceLocation) {
	}

	/*
	Representation of this node as a string
	*/
	virtual std::string toString() const;

	virtual ~MethodCallNode();

	/*
	Semantic Analyzer visitor abstract method.
	Performs type checking and returns type of expression.
	Takes a symbol table of current scope as parameter.
	*/
	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);

	/*
	Interpet visitor abstract method.
	Performs runtime actions. Returns a value computed from expression.
	Takes a tick relating to current index of array data.
	*/
	virtual ExpressionValue interpret(const unsigned int tick) const;

	std::map<std::string, std::shared_ptr<ArgumentSymbol>> expressionToArgList;


	const std::vector<Expression*> arguments;
private:

	/*
	Pointer to MethodSymbol this methodcall maps to.
	(Semantic + Interpeter logic stored within it)
	Acts as optimisation so a method lookup doesn't
	have to performed every tick in interpeter.
	Set in the semantic phase.
	*/
	MethodSymbol* methodsymbol;

	// name of the method
	const std::string name;
};


/*
If statement node.
If true executes block
*/
class IfStatementNode : public Statement {
public:

	IfStatementNode(Expression* _condition, BlockNode* _block, yy::SourceLocation csourceLocation) : condition(_condition), block(_block), Statement(csourceLocation){}


	/*
	Representation of this node as a string
	*/
	virtual std::string toString() const;

	virtual ~IfStatementNode();

	/*
	Semantic Analyzer visitor abstract method.
	Performs type checking.
	Takes a symbol table of current scope as parameter.
	*/
	virtual void semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);

	/*
	Interpet visitor abstract method.
	Performs runtime actions.
	Takes a tick relating to current index of array data.
	*/
	virtual void interpret(const unsigned int tick) const;

private:
	// condition expression of the if statement
	Expression* condition;

	// block of code that is executed
	BlockNode* block;
};


/*
Ternary node.
E.g. x > 3 ? 12 : 17
*/
class TernaryNode : public Expression {
public:

	TernaryNode(Expression* _condition, Expression* _expression1, Expression* _expression2, yy::SourceLocation csourceLocation)
		: condition(_condition), expression1(_expression1), expression2(_expression2), Expression(csourceLocation) {
	}

	/*
	Representation of this node as a string
	*/
	virtual std::string toString() const;

	virtual ~TernaryNode();

	/*
	Semantic Analyzer visitor abstract method.
	Performs type checking and returns type of expression.
	Takes a symbol table of current scope as parameter.
	*/
	virtual const TypeSymbol* semanticAnalysis(std::shared_ptr<SymbolTable> symboltable);

	/*
	Interpet visitor abstract method.
	Performs runtime actions. Returns a value computed from expression.
	Takes a tick relating to current index of array data.
	*/
	virtual ExpressionValue interpret(const unsigned int tick) const;

private:
	// condition of ternary expression
	Expression* condition;
	// expression that is computed + returned if condition true
	Expression* expression1;
	// expression that is computed + returned if condition false
	Expression* expression2;

};