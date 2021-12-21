#pragma once
#include <iostream>

class TypeSymbol;

/*
A wrapper for a return type in a method symbol.
*/
class ReturnSymbol {
public:

	ReturnSymbol(const TypeSymbol* _typesymbol, const std::string& _description);
	ReturnSymbol(const TypeSymbol* _typesymbol);


	std::string toString() const;
	const TypeSymbol* typesymbol;

private:
	const std::string description;

};