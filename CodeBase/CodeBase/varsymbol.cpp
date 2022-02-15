#include "varsymbol.h"
#include <iostream>
#include "typesymbol.h"
#include "visitors.h"
#include "interpretercontext.h"
#include <regex>
#include "dataparseexception.h"


VarSymbol::VarSymbol(const std::string _name, const TypeSymbol* _type, std::vector<ExpressionValue> _value) : name(_name), type(_type), buffer(_value), modifiable(false), exportName(_name), originalSize(_value.size()){
}

VarSymbol::VarSymbol(const std::string _name, const TypeSymbol* _type) : name(_name), type(_type), modifiable(true), exportName(_name), originalSize(0) {
	// for new variables make sure they match the global buffer size
	matchTickSize();
}


std::shared_ptr<VarSymbol> VarSymbol::createVarSymbol(const std::string _name, const TypeSymbol* _type, std::vector<ExpressionValue> _value) {
	if (!std::regex_match(_name, std::regex("[a-zA-Z_][a-zA-Z0-9_]*"))) {
		throw DataParseException("Invalid variable name: " + _name);
	}
	return std::shared_ptr<VarSymbol>(new VarSymbol(_name, _type, _value));
}


std::shared_ptr<VarSymbol> VarSymbol::createVarSymbol(const std::string _name, const TypeSymbol* _type) {
	if (!std::regex_match(_name, std::regex("[a-zA-Z_][a-zA-Z0-9_]*"))) {
		throw DataParseException("Invalid variable name: " + _name);
	}
	return std::shared_ptr<VarSymbol>(new VarSymbol(_name, _type));
}


/*
Returns true/false if the name is valid.
*/
bool VarSymbol::isValidName(const std::string _name) {
	return std::regex_match(_name, std::regex("[a-zA-Z_][a-zA-Z0-9_]*"));
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


void VarSymbol::matchTickSize() {

	/*
	Add NaNs to match largest series
	*/
	if (buffer.size() < InterpreterContext::ticks) {
		for (int i = buffer.size(); i < InterpreterContext::ticks; i ++) {
			if (type == TypeInstances::GetBooleanInstance()) {
				buffer.push_back(NullableValueBoolean());
			}
			else if (type == TypeInstances::GetNumberInstance()) {
				buffer.push_back(NullableValueNumber());
			}
			else if (type == TypeInstances::GetStringInstance()) {
				buffer.push_back(NullableValueString());
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


std::vector<ExpressionValue> VarSymbol::getArrayValues() {
	return buffer;
}
void VarSymbol::setArrayValues(const std::vector<ExpressionValue>& values) {
	buffer = values;
}