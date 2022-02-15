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

	// type of parameter
	const TypeSymbol* typesymbol;
	
	// name of parameter
	const std::string name;
private:

	// (FRONT END USE ONLY) description of parameter 
	const std::string description;

};



class OptionalParameterSymbol : public ParameterSymbol {
public:

	OptionalParameterSymbol(const TypeSymbol* _typesymbol, ExpressionValue _defaultValue, const std::string& _name, const std::string& _description);

	/*
	DO NOT USE
	We are forced to provide a default constructor 
	due to how we implement keyword matching in keyword method symbols.
	*/
	OptionalParameterSymbol();

	std::string toString() const;
	const ExpressionValue defaultValue;

};