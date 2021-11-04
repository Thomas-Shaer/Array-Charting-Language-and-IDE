#pragma once
#include "operator.h"
#include <iostream>
#include "global.h"

/*
* Contains logic for evalutating operators, including:
* Semantic requirements e.g. FLOAT + FLOAT
* Interpreter output e.g. 2 + 2 = 4
* Other useful information such as type name as a string.
*/


// forward declare data type

class BinaryOperator : public Operator {
public:
	const DataType type1, type2, returnType; // LHS and RHS type
	BinaryOperator(const std::string& _name, const DataType _type1, const DataType _type2, const DataType _returnType);

	//result of semantic analysis, LHS, RHS and returning type.
	//Should throw a error if the types do not match those stored in the class.
	DataType semanticAnaylsis(const DataType& _type1, const DataType& _type2) const;

	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const = 0;

};


class BinaryPlusOperator : public BinaryOperator {
public:
	const std::string name;
	BinaryPlusOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class BinaryMinusOperator : public BinaryOperator {
public:
	const std::string name;
	BinaryMinusOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class BinaryDivideOperator : public BinaryOperator {
public:
	const std::string name;
	BinaryDivideOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class BinaryMultiplyOperator : public BinaryOperator {
public:
	const std::string name;
	BinaryMultiplyOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;
};


class BinaryLessOperator : public BinaryOperator {
public:
	const std::string name;
	BinaryLessOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class BinaryLessEqualOperator : public BinaryOperator {
public:
	const std::string name;
	BinaryLessEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class BinaryGreaterOperator : public BinaryOperator {
public:
	const std::string name;
	BinaryGreaterOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class BinaryGreaterEqualOperator : public BinaryOperator {
public:
	const std::string name;
	BinaryGreaterEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;
};

class BinaryAndOperator : public BinaryOperator {
public:
	const std::string name;
	BinaryAndOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;

};

class BinaryOrOperator : public BinaryOperator {
public:
	const std::string name;
	BinaryOrOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1, ExpressionValue _value2) const;
};
