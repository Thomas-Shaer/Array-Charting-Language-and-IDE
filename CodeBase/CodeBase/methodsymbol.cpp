#include "methodsymbol.h"
#include "languageexception.h"
#include "typesymbol.h"


const TypeSymbol* MethodSymbol::semanticAnaylsis(std::vector<const TypeSymbol*> _argumentTypes) const {

	// if recieved wrong amount of parameters throw error
	if (argumentTypes.size() != _argumentTypes.size()) {
		throw LanguageException("Method " + name + " takes " + std::to_string(argumentTypes.size()) + " parameters not " + std::to_string(_argumentTypes.size()) + " parameters");
	}	

	// the input types must be what was expected
	for (int i = 0; i < argumentTypes.size(); i++) {
		const TypeSymbol* expected = argumentTypes[i];
		const TypeSymbol* received = _argumentTypes[i];
		if (expected != received) {
			throw LanguageException("Method " + name + " expected parameter no. " + std::to_string(i) + " to be " + expected->name + " but recieved " + received->name);
		}
	}
	return returnType;
}


std::string MethodSymbol::toString() const {
	std::string output = returnType->name + " " + name + "(";
	for (const TypeSymbol* arg : argumentTypes) {
		output += arg->name + ", ";
	}
	output += ")";
	return output;
}
