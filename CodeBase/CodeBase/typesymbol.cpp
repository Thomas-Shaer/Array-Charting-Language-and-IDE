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
	static TypeSymbol* floattemp = new TypeSymbol("number");
	floattemp->nanValue = NullableValueNumber();
	return floattemp;
}

TypeSymbol* TypeInstances::GetNumberConstantInstance() {
	static TypeSymbol* floatconsttemp = new TypeSymbol("number_constant");
	floatconsttemp->nanValue = NullableValueNumber();
	return floatconsttemp;
}

TypeSymbol* TypeInstances::GetBooleanInstance() {
	static TypeSymbol* boolinstance = new TypeSymbol("boolean");
	boolinstance->nanValue = NullableValueBoolean();
	return boolinstance;
}


TypeSymbol* TypeInstances::GetStringConstantInstance() {
	static TypeSymbol* string_constant = new TypeSymbol("string_constant");
	string_constant->nanValue = NullableValueString();
	return string_constant;
}

TypeSymbol* TypeInstances::GetStringInstance() {
	static TypeSymbol* string = new TypeSymbol("string");
	string->nanValue = NullableValueString();
	return string;
}

TypeSymbol* TypeInstances::GetVoidInstance() {
	static TypeSymbol* voidinstance = new TypeSymbol("void");
	voidinstance->nanValue = NullableValueString("void");
	return voidinstance;
}