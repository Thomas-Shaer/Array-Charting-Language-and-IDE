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

	// type of the return
	const TypeSymbol* typesymbol;

private:

	// (FRONT END USE ONLY) description of return type
	const std::string description;

};