#include "varsymbol.h"
#include <iostream>
#include "typesymbol.h"
#include "visitors.h"
#include "interpretercontext.h"

VarSymbol::VarSymbol(const std::string _name, const TypeSymbol* _type, std::vector<ExpressionValue> _value) : name(_name), type(_type), value(_value) {
	InterpreterContext::ticks = _value.size() >= InterpreterContext::ticks ? _value.size() : InterpreterContext::ticks;
}

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