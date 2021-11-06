#pragma once
#include "methodsymbol.h"


// method named "avg" takes two float parameters and returns a float
class  MethodAverage : public MethodSymbol {
public:

	MethodAverage() : MethodSymbol("avg", {DataType::Float, DataType::Float }, DataType::Float) {}

	ExpressionValue interpret(std::vector<ExpressionValue> _argumentValues) const;
};