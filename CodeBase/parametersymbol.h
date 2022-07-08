#pragma once
#include <iostream>
#include "expressionvalue.h"

class TypeSymbol;

/*
Semantic representation of a parameter in a method symbol.
*/
class ParameterSymbol {
public:

	ParameterSymbol(const TypeSymbol* _typesymbol, const std::string& _name, const std::string& _description);


	std::string toString() const;

	// gets the description of the parameter as a string
	std::string getDescription() const;

	// type of parameter
	const TypeSymbol* typesymbol;
	
	// name of parameter
	const std::string name;
private:

	// (FRONT END USE ONLY) description of parameter 
	const std::string description;

};


/*
Semantic representation of a optional parameter in a method symbol.
The key difference is that it contains a default value.
In the case the user does not supply the optional parameter,
that value is passed to the generated ArgumentSymbol.

*/
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

	// default value for situation where user does not give this parameter
	const ExpressionValue defaultValue;

};