#pragma once
#include "methodsymbol.h"
#include "typesymbol.h"

// method named "avg" takes two float parameters and returns a float
class  MethodAverage : public MethodSymbol {
public:

	MethodAverage() : MethodSymbol("avg", {TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetFloatInstance()) {}

	ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;
};


class UnaryPlusOperator : public MethodSymbol {
public:
	const std::string name;
	UnaryPlusOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;

};

class UnaryMinusOperator : public MethodSymbol {
public:
	const std::string name;
	UnaryMinusOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;

};


class UnaryNotOperator : public MethodSymbol {
public:
	UnaryNotOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;

};


class BinaryPlusOperator : public MethodSymbol {
public:
	BinaryPlusOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;

};

class BinaryMinusOperator : public MethodSymbol {
public:
	BinaryMinusOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;

};

class BinaryDivideOperator : public MethodSymbol {
public:
	BinaryDivideOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;

};

class BinaryMultiplyOperator : public MethodSymbol {
public:
	BinaryMultiplyOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;
};


class BinaryLessOperator : public MethodSymbol {
public:
	BinaryLessOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;

};

class BinaryLessEqualOperator : public MethodSymbol {
public:
	BinaryLessEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;

};

class BinaryGreaterOperator : public MethodSymbol {
public:
	BinaryGreaterOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;

};

class BinaryGreaterEqualOperator : public MethodSymbol {
public:
	BinaryGreaterEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;
};

class BinaryAndOperator : public MethodSymbol {
public:
	BinaryAndOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;

};

class BinaryOrOperator : public MethodSymbol {
public:
	BinaryOrOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;
};

class BinaryBooleanEqualOperator : public MethodSymbol {
public:
	BinaryBooleanEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;
};

class BinaryFloatEqualOperator : public MethodSymbol {
public:
	BinaryFloatEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;
};

class BinaryBooleanNotEqualOperator : public MethodSymbol {
public:
	BinaryBooleanNotEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;
};

class BinaryFloatNotEqualOperator : public MethodSymbol {
public:
	BinaryFloatNotEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;
};