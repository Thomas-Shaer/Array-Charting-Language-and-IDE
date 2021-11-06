#include "methodsymbol.h"
#include "languageexception.h"


DataType MethodSymbol::semanticAnaylsis(std::vector<DataType> _argumentTypes) const {

	// if recieved wrong amount of parameters throw error
	if (argumentTypes.size() != _argumentTypes.size()) {
		throw LanguageException("Method " + name + " takes " + std::to_string(argumentTypes.size()) + "parameters not " + std::to_string(_argumentTypes.size()) + "parameters");
	}	

	// the input types must be what was expected
	for (int i = 0; i < argumentTypes.size(); i++) {
		DataType expected = argumentTypes[i];
		DataType received = _argumentTypes[i];
		if (expected != received) {
			throw LanguageException("Method expected parameter no. " + std::to_string(i) + " to be " + std::to_string((int)expected) + " but recieved " + std::to_string((int)received));
		}
	}
	return returnType;
}


std::string MethodSymbol::toString() const {
	std::string output = std::to_string((int)returnType) + " " + name + "(";
	for (const DataType& arg : argumentTypes) {
		output += std::to_string((int)arg) + ", ";
	}
	output += ")";
	return output;
}
