#include "parametersymbol.h"
#include "typesymbol.h"

ParameterSymbol::ParameterSymbol(const TypeSymbol* _typesymbol, const std::string& _name, const std::string& _description)
	: typesymbol(_typesymbol), name(_name), description(_description) {}


std::string ParameterSymbol::getDescription() const {
	return name + " - " + description;
}

std::string ParameterSymbol::toString() const {
	return typesymbol->name + " " + name;
}
