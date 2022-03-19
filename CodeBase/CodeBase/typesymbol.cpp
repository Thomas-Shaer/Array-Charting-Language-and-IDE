#include "typesymbol.h"


TypeSymbol::TypeSymbol(const std::string _name) : name(_name) {

}


TypeInstances::TypeInstances() {
	GetNumberInstance();
	GetBooleanInstance();
	GetNumberConstantInstance();
	GetStringInstance();
	GetStringConstantInstance();
	GetVoidInstance();
}

TypeSymbol* TypeInstances::GetNumberInstance() {
	static TypeSymbol* numbertemp = new TypeSymbol("number");
	numbertemp->nullValue = NullableValueNumber();
	return numbertemp;
}

TypeSymbol* TypeInstances::GetNumberConstantInstance() {
	static TypeSymbol* numberconsttemp = new TypeSymbol("number_constant");
	numberconsttemp->nullValue = NullableValueNumber();
	return numberconsttemp;
}

TypeSymbol* TypeInstances::GetBooleanInstance() {
	static TypeSymbol* boolinstance = new TypeSymbol("boolean");
	boolinstance->nullValue = NullableValueBoolean();
	return boolinstance;
}


TypeSymbol* TypeInstances::GetStringConstantInstance() {
	static TypeSymbol* string_constant = new TypeSymbol("string_constant");
	string_constant->nullValue = NullableValueString();
	return string_constant;
}

TypeSymbol* TypeInstances::GetStringInstance() {
	static TypeSymbol* string = new TypeSymbol("string");
	string->nullValue = NullableValueString();
	return string;
}

TypeSymbol* TypeInstances::GetVoidInstance() {
	static TypeSymbol* voidinstance = new TypeSymbol("void");
	voidinstance->nullValue = NullableValueString("void");
	return voidinstance;
}

bool TypeInstances::matchType(const TypeSymbol* expected, const TypeSymbol* received) {
	if (expected == TypeInstances::GetNumberInstance() && received == TypeInstances::GetNumberConstantInstance()) {
		return true;
	}
	if (expected == TypeInstances::GetStringInstance() && received == TypeInstances::GetStringConstantInstance()) {
		return true;
	}
	// else types have to be the same
	return expected == received;
}