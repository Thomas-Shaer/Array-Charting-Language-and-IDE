#include "methodbucket.h"
#include "languageexception.h"
#include "methodsymbol.h"

std::string OverloadedMethodBucket::toString() const {
	std::string output = "{\n";
	for (MethodSymbol* overload : overloads) {
		output += "	" + overload->toString() + "\n";
	}
	output += "}";
	return output;
}

MethodSymbol* OverloadedMethodBucket::getMethodSymbol(std::vector<DataType> _argumentTypes) const {
	for (MethodSymbol* overload : overloads) {
		try {
			overload->semanticAnaylsis(_argumentTypes);
		}
		catch (LanguageException langexception) {
			continue;
		}
		return overload;
	}
	
	std::string errorOverloads = "No overload matches arguments. Possible overloads are: \n";
	for (MethodSymbol* overload : overloads) {
		errorOverloads += overload->toString() + "\n";
	}
	
	throw LanguageException(errorOverloads);
	return nullptr;
}

std::string SingleMethodBucket::toString() const {
	return methodsymbol->toString();
}

MethodSymbol* SingleMethodBucket::getMethodSymbol(std::vector<DataType> _argumentTypes) const {
	return methodsymbol;
}