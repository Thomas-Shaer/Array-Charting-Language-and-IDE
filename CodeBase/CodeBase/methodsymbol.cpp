#include "methodsymbol.h"
#include "languageexception.h"
#include "typesymbol.h"
#include "argumentsymbol.h"
#include "node.h"


bool matchType(const TypeSymbol* expected, const TypeSymbol* received) {
	if (expected == TypeInstances::GetFloatInstance() && received == TypeInstances::GetFloatConstantInstance()) {
		return true;
	}
	if (expected == TypeInstances::GetStringInstance() && received == TypeInstances::GetStringConstantInstance()) {
		return true;
	}
	// else types have to be the same
	else if (expected == received) {
		return true;
	}
	return false;
}



const TypeSymbol* PositionalMethodSymbol::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	methodCallNode->expressionToArgList.clear();
	std::vector<std::shared_ptr<ArgumentSymbol>> _argumentSymbols;
	for (Expression* expr : methodCallNode->arguments) {
		_argumentSymbols.push_back(std::make_shared<ArgumentSymbol>(expr->semanticAnalysis(symboltable, output), expr));
	}

	// if recieved wrong amount of parameters throw error
	if (parameterSymbols.size() != _argumentSymbols.size()) {
		throw LanguageException("Method " + name + " takes " + std::to_string(parameterSymbols.size()) + " parameters not " + std::to_string(_argumentSymbols.size()) + " parameters");
	}

	// the input types must be what was expected
	for (int i = 0; i < parameterSymbols.size(); i++) {
		const TypeSymbol* expected = parameterSymbols[i].typesymbol;
		const TypeSymbol* received = _argumentSymbols[i]->type;
		methodCallNode->expressionToArgList[parameterSymbols[i].name] = _argumentSymbols[i];


		if (matchType(expected, received)) {
			continue;
		}

		throw LanguageException("Method " + name + " expected parameter no. " + std::to_string(i) + " to be " + expected->name + " but recieved " + received->name);

	}
	return returnType.typesymbol;

}


std::string PositionalMethodSymbol::getDescription() const {
	std::string description = "";
	for (const ParameterSymbol arg : parameterSymbols) {
		description += arg.getDescription();
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



const TypeSymbol* KeywordMethodSymbol::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	methodCallNode->expressionToArgList.clear();
	std::vector<std::shared_ptr<ArgumentSymbol>> positionalSymbols;
	std::map<std::string, std::shared_ptr<ArgumentSymbol>> keywordSymbols;
	for (Expression* expr : methodCallNode->arguments) {
		//std::shared_ptr<ArgumentSymbol> argSymbol = std::make_shared<ArgumentSymbol>(expr->semanticAnalysis(symboltable, output), expr);

		KeywordNode* keyword;
		if ((keyword = dynamic_cast<KeywordNode*>(expr))) {
			if (keywordSymbols.find(keyword->name) != keywordSymbols.end()) {
				throw LanguageException("Already specified keyword argument " + keyword->name);
			}
			keywordSymbols[keyword->name] = std::make_shared<ArgumentSymbol>(expr->semanticAnalysis(symboltable, output), keyword->rhs);
			continue;
		}
		positionalSymbols.push_back(std::make_shared<ArgumentSymbol>(expr->semanticAnalysis(symboltable, output), expr));
	}

	// (must do bound checking for positional arguments)

	// must supply at least the amount of non optional params
	if (positionalSymbols.size() < requiredParameterSymbols.size()) {
		throw LanguageException("Method " + name + " takes at least " + std::to_string(requiredParameterSymbols.size()) + " non optional parameters not " + std::to_string(positionalSymbols.size()) + " non optional parameters");
	}

	// must supply at least the amount of non optional params
	if (positionalSymbols.size() > (requiredParameterSymbols.size() + optionalParameterSymbols.size())) {
		throw LanguageException("Method " + name + " takes at most " + std::to_string(requiredParameterSymbols.size() + optionalParameterSymbols.size()) + " parameters not " + std::to_string(positionalSymbols.size()) + " parameters");
	}



	// first we match the positional args
	for (int i = 0; i < positionalSymbols.size(); i++) {
		const TypeSymbol* expected;
		std::string expectedName;
		// if we have satisifed all required params, start eating away at optional ones
		if (i > requiredParameterSymbols.size() - 1) {
			std::cout << "what fuck" << std::endl;
			std::cout << i - requiredParameterSymbols.size() << std::endl;
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
		std::cout << expectedName << std::endl;
		methodCallNode->expressionToArgList[expectedName] = received;



		if (matchType(expected, received->type)) {
			continue;
		}

		throw LanguageException("Method " + name + " expected parameter no. " + std::to_string(i) + " to be " + expectedName + " but recieved " + received->type->name);
	}

	// Then we match the keyword args
	for (auto item : keywordSymbols) {
		std::shared_ptr<ArgumentSymbol> received = item.second;
		std::string name = item.first;
		

		// if keyword arg not specified throw error
		if (optionalParamsMap.find(name) == optionalParamsMap.end()) {
			throw LanguageException("No keyword argument with name " + name);
		}

		ParameterSymbol expected = optionalParamsMap[name];
		// erase that arg
		optionalParamsMap.erase(name);


		methodCallNode->expressionToArgList[expected.name] = received;

		if (matchType(expected.typesymbol, received->type)) {
			continue;
		}

		throw LanguageException("Method " + name + " expected parameter " + name + " to be " + expected.typesymbol->name + " but recieved " + received->type->name);

	}
	// rest of keyword args just declare them

	for (auto& item : optionalParamsMap) {
		/*
		Gives argument symbol the default value of the parameter symbol
		*/
		std::shared_ptr<ArgumentSymbol> defaultArgument = std::make_shared<ArgumentSymbol>(item.second.typesymbol, nullptr);
		defaultArgument->expressionValue = item.second.defaultValue;
		methodCallNode->expressionToArgList[item.first] = defaultArgument;
	}

	return returnType.typesymbol;

}




std::string KeywordMethodSymbol::getDescription() const {
	std::string description = "";
	for (const ParameterSymbol arg : requiredParameterSymbols) {
		description += arg.getDescription();
	}
	for (const OptionalParameterSymbol arg : optionalParameterSymbols) {
		description += arg.getDescription();
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
