#include "methodsymbol.h"
#include "languageexception.h"
#include "typesymbol.h"
#include "argumentsymbol.h"


const TypeSymbol* MethodSymbol::semanticAnaylsis(std::vector<std::shared_ptr<ArgumentSymbol>> _argumentSymbols, InterpreterOutput& output) {

	// if recieved wrong amount of parameters throw error
	if (argumentTypes.size() != _argumentSymbols.size()) {
		throw LanguageException("Method " + name + " takes " + std::to_string(argumentTypes.size()) + " parameters not " + std::to_string(_argumentSymbols.size()) + " parameters");
	}	

	// the input types must be what was expected
	for (int i = 0; i < argumentTypes.size(); i++) {
		const TypeSymbol* expected = argumentTypes[i].typesymbol;
		const TypeSymbol* received = _argumentSymbols[i]->type;

		// a parameter expecting a float can receive a constant_float
		if (expected == TypeInstances::GetFloatInstance() && received == TypeInstances::GetFloatConstantInstance()) {
			continue;
		}
		if (expected == TypeInstances::GetStringInstance() && received == TypeInstances::GetStringConstantInstance()) {
			continue;
		}
		// else types have to be the same
		else if (expected == received) {
			continue;
		}

		throw LanguageException("Method " + name + " expected parameter no. " + std::to_string(i) + " to be " + expected->name + " but recieved " + received->name);

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
