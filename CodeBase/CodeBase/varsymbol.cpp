#include "varsymbol.h"
#include <iostream>
#include "typesymbol.h"
#include "visitors.h"

std::string VarSymbol::toString() {
	std::string output = "<";
	output += name;
	output += ", ";
	output += type->name;
	output += ", ";

	output += boost::apply_visitor(ToString(), value);
	output += ">";

	return output;
}



ExpressionValue VarSymbol::getValue() {
	return value;
}

void VarSymbol::setValue(ExpressionValue _value) {
	// ERORR CHECK HERE MAKE SURE SAME TYPE
	value.swap(_value);
}