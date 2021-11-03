#pragma once
#include "boolean.h"
#include "float.h"
#include <boost/variant.hpp>

typedef boost::variant<Float, Boolean> ExpressionValue;
enum class DataType { Boolean, Float };

/*
* Stores all the necessary information for a variable, including it's type and value
*/

class VarSymbol {
public:
	const std::string name;
	const DataType type;

	VarSymbol(const std::string _name, const DataType _type) : name(_name), type(_type) {}


	std::string toString();

	ExpressionValue getValue();
	void setValue(ExpressionValue _value);

private:
	ExpressionValue value;

};