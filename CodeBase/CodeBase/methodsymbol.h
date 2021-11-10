#pragma once
#include <iostream>
#include "global.h"
#include <vector>

class TypeSymbol;

class MethodSymbol {
public:
	const TypeSymbol* returnType; // return type
	const std::string name; // method name

	const std::vector<TypeSymbol*> argumentTypes; //  type the method takes

	MethodSymbol(const std::string& _name, const std::vector<TypeSymbol*> _argumentTypes, const TypeSymbol* _returnType) : name(_name), argumentTypes(_argumentTypes), returnType(_returnType) {}


	// should take list of types
	const TypeSymbol* semanticAnaylsis(std::vector<const TypeSymbol*> _argumentTypes) const;

	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const = 0;

	std::string toString() const;
};