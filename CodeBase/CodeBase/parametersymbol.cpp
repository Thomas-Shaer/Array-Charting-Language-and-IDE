#include "parametersymbol.h"
#include "typesymbol.h"
#include "visitors.h"
#include "nullablevaluenumber.h"

ParameterSymbol::ParameterSymbol(const TypeSymbol* _typesymbol, const std::string& _name, const std::string& _description)
	: typesymbol(_typesymbol), name(_name), description(_description) {}


std::string ParameterSymbol::getDescription() const {
	return name + " - " + description;
}

std::string ParameterSymbol::toString() const {
	return typesymbol->name + " " + name;
}


OptionalParameterSymbol::OptionalParameterSymbol(const TypeSymbol* _typesymbol, ExpressionValue _defaultValue, const std::string& _name, const std::string& _description)
	: ParameterSymbol(_typesymbol, _name, _description) , defaultValue(_defaultValue) {}


OptionalParameterSymbol::OptionalParameterSymbol()
	: ParameterSymbol(TypeInstances::GetVoidInstance(), "temp", "temp"), defaultValue(NullableValueNumber()) {}


std::string OptionalParameterSymbol::toString() const {
	return typesymbol->name + " " + name + " = " + boost::apply_visitor(ToString(), defaultValue);
}