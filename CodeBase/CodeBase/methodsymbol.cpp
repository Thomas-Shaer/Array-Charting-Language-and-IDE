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
		const TypeSymbol* expected = argumentTypes[i].typesymbol;
		const TypeSymbol* received = _argumentTypes[i];
		if (expected != received) {
			throw LanguageException("Method " + name + " expected parameter no. " + std::to_string(i) + " to be " + expected->name + " but recieved " + received->name);
		}
	}
	return returnType.typesymbol;
}

std::string MethodSymbol::getDescription() const {
	std::string description = "";
	for (const ParameterSymbol arg : argumentTypes) {
		description += arg.getDescription();
	}
	return description;
}


std::string MethodSymbol::getSignature() const {
	std::string output = returnType.typesymbol->name + " " + name + "(";
	for (const ParameterSymbol arg : argumentTypes) {
		output += arg.toString() + ", ";
	}
	output += ")";
	return output;
}
