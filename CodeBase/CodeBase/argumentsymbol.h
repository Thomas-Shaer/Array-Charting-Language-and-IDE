#pragma once
#include "global.h"

class Expression;
class TypeSymbol;


class ArgumentSymbol {

public:


	ArgumentSymbol(const TypeSymbol* _type, Expression* _expression);


	const TypeSymbol* type;
	Expression* expression;
	
	ExpressionValue expressionValue;


private:
	
};