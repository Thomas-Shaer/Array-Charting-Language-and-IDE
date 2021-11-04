#pragma once
#include "operator.h"


class UnaryOperator : public Operator {
public:
	const DataType type1, returnType; // Type to apply to
	UnaryOperator(const std::string& _name, const DataType _type1, const DataType _returnType);

	//result of semantic analysis, input type and returning type.
	//Should throw a error if the types do not match those stored in the class.
	DataType semanticAnaylsis(const DataType& _type1) const;

	virtual ExpressionValue interpret(ExpressionValue _value1) const = 0;

};



class UnaryPlusOperator : public UnaryOperator {
public:
	const std::string name;
	UnaryPlusOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1) const;

};

class UnaryMinusOperator : public UnaryOperator {
public:
	const std::string name;
	UnaryMinusOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1) const;

};


class UnaryNotOperator : public UnaryOperator {
public:
	const std::string name;
	UnaryNotOperator(const std::string& _name);
	virtual ExpressionValue interpret(ExpressionValue _value1) const;

};

