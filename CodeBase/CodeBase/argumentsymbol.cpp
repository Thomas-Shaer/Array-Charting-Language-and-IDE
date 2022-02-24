#include "argumentsymbol.h"
#include "typesymbol.h"
#include "node.h"



ArgumentSymbol::ArgumentSymbol(const TypeSymbol* _type, Expression* _expression) : type(_type), expression(_expression) {
	// assign default type null value just so the variant sub type is correct
	expressionValue = _type->nanValue;
	/*
	If constant values are passed, load in their value at compile time.
	*/
	if (expression) {
		if (_type == TypeInstances::GetStringConstantInstance()) {
			std::cout << "1" << std::endl;
			expressionValue = static_cast<StringNode*>(expression)->value;
		}
		if (_type == TypeInstances::GetNumberConstantInstance()) {
			std::cout << "2" << std::endl;

			expressionValue = NullableValueNumber(static_cast<NumberNode*>(expression)->number);
		}
	}
}
