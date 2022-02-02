#include "typesymbol.h"


TypeSymbol::TypeSymbol(const std::string _name) : name(_name) {

}


TypeInstances::TypeInstances() {
	GetFloatInstance();
	GetBooleanInstance();
	GetFloatConstantInstance();
	GetVoidInstance();
}

TypeSymbol* TypeInstances::GetFloatInstance() {
	static TypeSymbol* floattemp = new TypeSymbol("float");
	return floattemp;
}

TypeSymbol* TypeInstances::GetFloatConstantInstance() {
	static TypeSymbol* floatconsttemp = new TypeSymbol("float_constant");
	return floatconsttemp;
}

TypeSymbol* TypeInstances::GetBooleanInstance() {
	static TypeSymbol* boolinstance = new TypeSymbol("boolean");
	return boolinstance;
}



TypeSymbol* TypeInstances::GetStringConstantInstance() {
	static TypeSymbol* string_constant = new TypeSymbol("string_constant");
	return string_constant;
}

TypeSymbol* TypeInstances::GetStringInstance() {
	static TypeSymbol* string = new TypeSymbol("string");
	return string;
}

TypeSymbol* TypeInstances::GetVoidInstance() {
	static TypeSymbol* voidinstance = new TypeSymbol("void");
	return voidinstance;
}