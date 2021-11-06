#pragma once
#include <iostream>
#include "global.h"
#include <vector>

class MethodSymbol {
public:
	const DataType returnType; // return type
	const std::string name; // method name

	const std::vector<DataType> argumentTypes; //  type the method takes

	MethodSymbol(const std::string& _name, const std::vector<DataType> _argumentTypes, const DataType _returnType) : name(_name), argumentTypes(_argumentTypes), returnType(_returnType) {}


	// should take list of types
	DataType semanticAnaylsis(std::vector<DataType> _argumentTypes) const;

	virtual ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const = 0;

	std::string toString() const;
};