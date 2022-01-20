#include "varsymbol.h"
#include <iostream>
#include "typesymbol.h"
#include "visitors.h"
#include "interpretercontext.h"

VarSymbol::VarSymbol(const std::string _name, const TypeSymbol* _type, std::vector<ExpressionValue> _value) : name(_name), type(_type), buffer(_value), modifiable(false), exportName(_name), originalSize(_value.size()){
}

VarSymbol::VarSymbol(const std::string _name, const TypeSymbol* _type) : name(_name), type(_type), modifiable(true), exportName(_name), originalSize(0) {
	// for new variables make sure they match the global buffer size
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

	/*
	Add NaNs to match largest series
	*/
	if (buffer.size() < InterpreterContext::ticks) {
		for (int i = buffer.size(); i < InterpreterContext::ticks; i ++) {
			if (type == TypeInstances::GetBooleanInstance()) {
				buffer.push_back(Boolean());
			}
			else if (type == TypeInstances::GetFloatInstance()) {
				buffer.push_back(Float());
			}
		}
	}
	/*
	If too many i.e. a large input variable was removed, reduce all the variables that were previously matched to it's size
	*/
	else if (buffer.size() > InterpreterContext::ticks) {
		while (buffer.size() != InterpreterContext::ticks) {
			buffer.pop_back();
		}
	}
}


std::vector<ExpressionValue> VarSymbol::getValues() {
	return buffer;
}
void VarSymbol::setValues(const std::vector<ExpressionValue>& values) {
	buffer = values;
}