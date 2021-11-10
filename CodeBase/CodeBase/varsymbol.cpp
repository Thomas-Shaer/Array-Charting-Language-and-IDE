#include "varsymbol.h"
#include <iostream>
#include "typesymbol.h"

std::string VarSymbol::toString() {
	std::string output = "<";
	output += name;
	output += ", ";
	output += type->name;
	output += ", ";

	if (type == TypeInstances::GetFloatInstance()) {
		output += std::to_string(boost::get<Float>(value).value) + ">";
	}
	else {
		output += (boost::get<Boolean>(value).value ? "true" : "false");
		output += ">";
	}

	return output;
}



ExpressionValue VarSymbol::getValue() {
	return value;
}

void VarSymbol::setValue(ExpressionValue _value) {
	// ERORR CHECK HERE MAKE SURE SAME TYPE
	value.swap(_value);
}