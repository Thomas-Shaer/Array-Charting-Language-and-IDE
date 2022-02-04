#pragma once
#include <iostream>
#include "global.h"

class TypeSymbol;

/*
A wrapper for a parameter in a method symbol.
*/
class ParameterSymbol {
public:

	ParameterSymbol(const TypeSymbol* _typesymbol, const std::string& _name, const std::string& _description);


	std::string toString() const;
	std::string getDescription() const;
	const TypeSymbol* typesymbol;
	const std::string name;
private:

	const std::string description;

};



class OptionalParameterSymbol : public ParameterSymbol {
public:

	OptionalParameterSymbol(const TypeSymbol* _typesymbol, ExpressionValue _defaultValue, const std::string& _name, const std::string& _description);
	OptionalParameterSymbol();

	std::string toString() const;
	const ExpressionValue defaultValue;

};