#pragma once
#include <iostream>
#include "global.h"
#include <vector>
#include "interpreteroutput.h"
#include "parametersymbol.h"
#include "returnsymbol.h"
class TypeSymbol;

class MethodSymbol {
public:
	const ReturnSymbol returnType; // return type
	const std::string name; // method name
	const std::string description; //method description

	const std::vector<ParameterSymbol> argumentTypes; //  type the method takes

	MethodSymbol(const std::string& _name, const std::string& _description, const std::vector<ParameterSymbol> _argumentTypes, const ReturnSymbol _returnType) : name(_name), argumentTypes(_argumentTypes), returnType(_returnType), description(_description) {}


	// should take list of types
	virtual const TypeSymbol* semanticAnaylsis(std::vector<const TypeSymbol*> _argumentTypes, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) = 0;

	std::string getSignature() const;
	std::string getDescription() const;

	virtual MethodSymbol* clone() = 0;
};