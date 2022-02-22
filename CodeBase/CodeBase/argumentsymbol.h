#pragma once
#include "expressionvalue.h"

class Expression;
class TypeSymbol;


/*
Semantic representation of the users argument passed to a parameter.
Also acts as a container for the runtime value of the argument.
*/
class ArgumentSymbol {

public:

	ArgumentSymbol(const TypeSymbol* _type, Expression* _expression);

	// type of argument
	const TypeSymbol* type;

	// expression node corresponding with the argument e.g. keyword node
	Expression* expression;
	
	/*
	Runtime value passed to the method and updated by the users code.
	*/
	ExpressionValue expressionValue;
private:
	
};