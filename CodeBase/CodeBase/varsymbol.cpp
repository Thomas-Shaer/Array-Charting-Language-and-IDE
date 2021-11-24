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

	//output += boost::apply_visitor(ToString(), value);
	output += ">";

	return output;
}



ExpressionValue VarSymbol::getValue(const unsigned int i) {
	return value[i];
}

void VarSymbol::setValue(const unsigned int i, ExpressionValue _value) {
	if (value.size() == (i-1)) {
		value[i].swap(_value);
	}
	else {
		value.push_back(_value);
	}
}