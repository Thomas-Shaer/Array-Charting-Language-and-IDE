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
	floattemp->nanValue = Float();
	return floattemp;
}

TypeSymbol* TypeInstances::GetFloatConstantInstance() {
	static TypeSymbol* floatconsttemp = new TypeSymbol("float_constant");
	floatconsttemp->nanValue = Float();
	return floatconsttemp;
}

TypeSymbol* TypeInstances::GetBooleanInstance() {
	static TypeSymbol* boolinstance = new TypeSymbol("boolean");
	boolinstance->nanValue = Boolean();
	return boolinstance;
}



TypeSymbol* TypeInstances::GetStringConstantInstance() {
	static TypeSymbol* string_constant = new TypeSymbol("string_constant");
	string_constant->nanValue = String();
	return string_constant;
}

TypeSymbol* TypeInstances::GetStringInstance() {
	static TypeSymbol* string = new TypeSymbol("string");
	string->nanValue = String();
	return string;
}

TypeSymbol* TypeInstances::GetVoidInstance() {
	static TypeSymbol* voidinstance = new TypeSymbol("void");
	voidinstance->nanValue = String("void");
	return voidinstance;
}