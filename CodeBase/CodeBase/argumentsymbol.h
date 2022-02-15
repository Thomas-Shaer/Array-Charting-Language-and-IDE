#pragma once
#include "global.h"

class Expression;
class TypeSymbol;


/*
Representation of the users argument passed to a parameter.
Also acts as a container for the value of the argument.
*/
class ArgumentSymbol {

public:

	ArgumentSymbol(const TypeSymbol* _type, Expression* _expression);

	// type of argument
	const TypeSymbol* type;

	// expression node corresponding with the argument e.g. keyword node
	Expression* expression;
	
	/*
	Value passed to the method and updated by the users code.
	*/
	ExpressionValue expressionValue;
private:
	
};