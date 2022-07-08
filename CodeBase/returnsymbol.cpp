#include "returnsymbol.h"
#include "typesymbol.h"

ReturnSymbol::ReturnSymbol(const TypeSymbol* _typesymbol, const std::string& _description)
	: typesymbol(_typesymbol), description(_description) {}

ReturnSymbol::ReturnSymbol(const TypeSymbol* _typesymbol)
	: typesymbol(_typesymbol), description("") {}



std::string ReturnSymbol::toString() const {
	return description == "" ? "Returns " + typesymbol->name : "Returns " + typesymbol->name + " - " + description;
}
