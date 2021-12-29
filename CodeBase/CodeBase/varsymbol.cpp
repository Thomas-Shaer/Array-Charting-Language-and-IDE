#include "varsymbol.h"
#include <iostream>
#include "typesymbol.h"
#include "visitors.h"
#include "interpretercontext.h"

VarSymbol::VarSymbol(const std::string _name, const TypeSymbol* _type, std::vector<ExpressionValue> _value) : name(_name), type(_type), buffer(_value), modifiable(false), exportName(_name) {
	InterpreterContext::ticks = _value.size() >= InterpreterContext::ticks ? _value.size() : InterpreterContext::ticks;
}

VarSymbol::VarSymbol(const std::string _name, const TypeSymbol* _type) : name(_name), type(_type), modifiable(true), exportName(_name) {
	matchGlobalBufferSize();
}

std::string VarSymbol::toString() {
	std::string output = "<";
	output += name;
	output += ", ";
	output += type->name;
	output += ", ";

	output += ">";

	return output;
}



ExpressionValue VarSymbol::getValue(const unsigned int i) {
	return buffer[i];
}

void VarSymbol::setValue(const unsigned int i, ExpressionValue _value) {
	buffer[i].swap(_value);
}


void VarSymbol::matchGlobalBufferSize() {
	if (buffer.size() < InterpreterContext::ticks) {
		buffer = std::vector<ExpressionValue>(InterpreterContext::ticks);
		if (type == TypeInstances::GetBooleanInstance()) {
			std::fill(buffer.begin(), buffer.end(), Boolean());
		}
		else if (type == TypeInstances::GetFloatInstance()) {
			std::fill(buffer.begin(), buffer.end(), Float());
		}
	}
}


std::vector<ExpressionValue> VarSymbol::getValues() {
	return buffer;
}
void VarSymbol::setValues(const std::vector<ExpressionValue>& values) {
	buffer = values;
}