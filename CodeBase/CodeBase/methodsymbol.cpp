#include "methodsymbol.h"
#include "languageexception.h"
#include "typesymbol.h"
#include "argumentsymbol.h"
#include "node.h"





const TypeSymbol* PositionalMethodSymbol::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	// clear the method nodes argument symbol list
	methodCallNode->argNameToArgumentSymbol.clear();


	/*
	Create argument symbols from the method args
	*/
	std::vector<std::shared_ptr<ArgumentSymbol>> _argumentSymbols;
	for (Expression* expr : methodCallNode->arguments) {
		const TypeSymbol* typesymbol = expr->semanticAnalysis(symboltable);
		_argumentSymbols.push_back(std::make_shared<ArgumentSymbol>(typesymbol, expr));
	}

	// if recieved wrong amount of parameters throw error
	if (parameterSymbols.size() != _argumentSymbols.size()) {
		throw LanguageException("Method " + name + " takes " + std::to_string(parameterSymbols.size()) + " parameters not " + std::to_string(_argumentSymbols.size()) + " parameters", methodCallNode);
	}

	// the input types must be what was expected
	for (int i = 0; i < parameterSymbols.size(); i++) {
		const TypeSymbol* expected = parameterSymbols[i].typesymbol;
		const TypeSymbol* received = _argumentSymbols[i]->type;
		methodCallNode->argNameToArgumentSymbol[parameterSymbols[i].name] = _argumentSymbols[i];


		if (TypeInstances::matchType(expected, received)) {
			continue;
		}

		throw LanguageException("Method " + name + " expected parameter no. " + std::to_string(i) + " to be " + expected->name + " but recieved " + received->name, _argumentSymbols[i]->expression);

	}
	return returnType.typesymbol;

}


std::string PositionalMethodSymbol::getDescription() const {
	std::string description = "";
	for (const ParameterSymbol arg : parameterSymbols) {
		description += arg.getDescription() + "\n";
	}
	return description;
}


std::string PositionalMethodSymbol::getSignature() const {
	std::string output = returnType.typesymbol->name + " " + name + "(";
	for (const ParameterSymbol arg : parameterSymbols) {
		output += arg.toString() + ", ";
	}
	output += ")";
	return output;
}


KeywordMethodSymbol::KeywordMethodSymbol(const std::string& _name, const std::string& _description, const std::vector<ParameterSymbol> _requiredParameterSymbols, const std::vector<OptionalParameterSymbol> _optionalParameterSymbols, const ReturnSymbol _returnType)
	: MethodSymbol(_name, _description, _returnType), requiredParameterSymbols(_requiredParameterSymbols), optionalParameterSymbols(_optionalParameterSymbols) {
	for (OptionalParameterSymbol param : _optionalParameterSymbols) {
		optionalParamsMap.emplace(param.name, param);

	}
}



const TypeSymbol* KeywordMethodSymbol::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	// clear the method nodes argument symbol list
	methodCallNode->argNameToArgumentSymbol.clear();

	/*
	Create argument symbols from the method args
	*/
	std::vector<std::shared_ptr<ArgumentSymbol>> positionalSymbols;
	std::map<std::string, std::shared_ptr<ArgumentSymbol>> keywordSymbols;
	for (Expression* expr : methodCallNode->arguments) {

		KeywordNode* keyword;
		if ((keyword = dynamic_cast<KeywordNode*>(expr))) {
			// Convenient place to make sure same keyword argument not supplied twice
			if (keywordSymbols.find(keyword->name) != keywordSymbols.end()) {
				throw LanguageException("Already specified keyword argument " + keyword->name, keyword);
			}
			// register keyword argument
			const TypeSymbol* typesymbol = expr->semanticAnalysis(symboltable);
			keywordSymbols[keyword->name] = std::make_shared<ArgumentSymbol>(typesymbol, keyword->rhs);
			continue;
		}
		// register non keyword argument
		const TypeSymbol* typesymbol = expr->semanticAnalysis(symboltable);
		positionalSymbols.push_back(std::make_shared<ArgumentSymbol>(typesymbol, expr));
	}

	/*
	Bounds checking
	*/

	// must supply at least the amount of required params
	if (positionalSymbols.size() < requiredParameterSymbols.size()) {
		throw LanguageException("Method " + name + " takes at least " + std::to_string(requiredParameterSymbols.size()) + " non optional parameters not " + std::to_string(positionalSymbols.size()) + " non optional parameters", methodCallNode);
	}

	// must not provide more arguments then required + optional parameters
	if (positionalSymbols.size() > (requiredParameterSymbols.size() + optionalParameterSymbols.size())) {
		throw LanguageException("Method " + name + " takes at most " + std::to_string(requiredParameterSymbols.size() + optionalParameterSymbols.size()) + " parameters not " + std::to_string(positionalSymbols.size()) + " parameters", methodCallNode);
	}


	/*
	Matching
	*/

	// first we match the positional args
	for (int i = 0; i < positionalSymbols.size(); i++) {
		const TypeSymbol* expected;
		std::string expectedName;
		// if we have satisifed all required params, start eating away at optional ones
		if (i > requiredParameterSymbols.size() - 1) {
			auto optionalParamSymbol = optionalParameterSymbols[i - requiredParameterSymbols.size()];
			expected = optionalParamSymbol.typesymbol;
			expectedName = optionalParamSymbol.name;
			// remove from the params map
			optionalParamsMap.erase(optionalParamSymbol.name);

		}
		else {
			expected = requiredParameterSymbols[i].typesymbol;
			expectedName = requiredParameterSymbols[i].name;

		}
		std::shared_ptr<ArgumentSymbol> received = positionalSymbols[i];
		methodCallNode->argNameToArgumentSymbol[expectedName] = received;



		if (TypeInstances::matchType(expected, received->type)) {
			continue;
		}

		throw LanguageException("Method " + name + " expected parameter no. " + std::to_string(i) + " to be " + expectedName + " but recieved " + received->type->name, received->expression);
	}

	// Then we match the keyword args
	for (auto item : keywordSymbols) {
		std::shared_ptr<ArgumentSymbol> received = item.second;
		std::string name = item.first;
		

		// if keyword arg not specified throw error
		if (optionalParamsMap.find(name) == optionalParamsMap.end()) {
			throw LanguageException("No keyword argument with name " + name, received->expression);
		}

		ParameterSymbol expected = optionalParamsMap[name];
		// erase that arg
		optionalParamsMap.erase(name);


		methodCallNode->argNameToArgumentSymbol[expected.name] = received;

		if (TypeInstances::matchType(expected.typesymbol, received->type)) {
			continue;
		}

		throw LanguageException("Method " + name + " expected parameter " + name + " to be " + expected.typesymbol->name + " but recieved " + received->type->name, received->expression);

	}
	// The optional arguments not supplied by the user will now be registered as a argument with their default value
	for (auto& item : optionalParamsMap) {
		/*
		Gives argument symbol the default value of the parameter symbol
		*/
		std::shared_ptr<ArgumentSymbol> defaultArgument = std::make_shared<ArgumentSymbol>(item.second.typesymbol, nullptr);
		// give argument symbol default parameter value
		defaultArgument->expressionValue = item.second.defaultValue;
		methodCallNode->argNameToArgumentSymbol[item.first] = defaultArgument;
	}

	return returnType.typesymbol;

}




std::string KeywordMethodSymbol::getDescription() const {
	std::string description = "";
	for (const ParameterSymbol arg : requiredParameterSymbols) {
		description += arg.getDescription() + "\n";
	}
	for (const OptionalParameterSymbol arg : optionalParameterSymbols) {
		description += arg.getDescription() + "\n";
	}
	return description;
}


std::string KeywordMethodSymbol::getSignature() const {
	std::string output = returnType.typesymbol->name + " " + name + "(";
	for (const ParameterSymbol arg : requiredParameterSymbols) {
		output += arg.toString() + ", ";
	}
	for (const OptionalParameterSymbol arg : optionalParameterSymbols) {
		output += arg.toString() + ", ";
	}
	output += ")";
	return output;
}
