#pragma once
#include <iostream>
#include "global.h"

/*
* Contains logic for evalutating operators, including:
* Semantic requirements e.g. FLOAT + FLOAT
* Interpreter output e.g. 2 + 2 = 4
* Other useful information such as type name as a string.
*/


// forward declare data type

class Operator {
public:
	const DataType type1, type2, returnType; // LHS and RHS type
	const std::string name; // string representation of type
	Operator(const std::string& _name, const DataType _type1, const DataType _type2, const DataType _returnType);

	//result of semantic analysis, LHS, RHS and returning type.
	//Should throw a error if the types do not match those stored in the class.
	DataType semanticAnaylsis(const DataType& _type1, const DataType& _type2) const;

	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const = 0;

};


class PlusOperator : public Operator {
public:
	const std::string name;
	PlusOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class MinusOperator : public Operator {
public:
	const std::string name;
	MinusOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class DivideOperator : public Operator {
public:
	const std::string name;
	DivideOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class MultiplyOperator : public Operator {
public:
	const std::string name;
	MultiplyOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;
};


class LessOperator : public Operator {
public:
	const std::string name;
	LessOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class LessEqualOperator : public Operator {
public:
	const std::string name;
	LessEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class GreaterOperator : public Operator {
public:
	const std::string name;
	GreaterOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class GreaterEqualOperator : public Operator {
public:
	const std::string name;
	GreaterEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;
};

class AndOperator : public Operator {
public:
	const std::string name;
	AndOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class OrOperator : public Operator {
public:
	const std::string name;
	OrOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;
};
