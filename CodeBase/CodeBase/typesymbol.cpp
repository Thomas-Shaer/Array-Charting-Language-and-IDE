#include "typesymbol.h"


TypeSymbol::TypeSymbol(const std::string _name) : name(_name) {

}


TypeInstances::TypeInstances() {
	GetFloatInstance();
	GetBooleanInstance();
}

TypeSymbol*& TypeInstances::GetFloatInstance() {
	static TypeSymbol* floattemp = new TypeSymbol("float");
	return floattemp;
}


TypeSymbol*& TypeInstances::GetBooleanInstance() {
	static TypeSymbol* boolinstance = new TypeSymbol("boolean");
	return boolinstance;
}

TypeSymbol*& TypeInstances::GetVoidInstance() {
	static TypeSymbol* voidinstance = new TypeSymbol("void");
	return voidinstance;
}