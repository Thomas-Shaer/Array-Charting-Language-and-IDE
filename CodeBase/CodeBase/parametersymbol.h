#pragma once
#include <iostream>

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

private:

	const std::string name;
	const std::string description;

};