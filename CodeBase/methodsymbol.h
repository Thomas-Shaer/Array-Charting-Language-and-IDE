#pragma once
#include <iostream>
#include "expressionvalue.h"
#include <vector>

#include "parametersymbol.h"
#include "returnsymbol.h"
#include <map>
class TypeSymbol;
class ArgumentSymbol;
class MethodCallNode;
class SymbolTable;

/*
Base class for all built-in methods.

Stored on the method symbol table.

Contains all information related to a built-in method including:
Return types, name, description, semantic and interpreter actions.
*/
class MethodSymbol {
public:
	// return type
	const ReturnSymbol returnType; 
	// method name
	const std::string name; 
	//method description
	const std::string description; 


	MethodSymbol(const std::string& _name, const std::string& _description, const ReturnSymbol _returnType) : name(_name), returnType(_returnType), description(_description) {}


	// should take list of types
	virtual const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) = 0;
	virtual ExpressionValue interpret(const unsigned int tick) = 0;

	virtual std::string getSignature() const = 0;
	virtual std::string getDescription() const = 0;

	virtual MethodSymbol* clone() = 0;
};


/*
Method symbol where we match arguments to parameters via position.
I.e. Positional Parameters
E.g. test(a, b, c)
*/
class PositionalMethodSymbol : public MethodSymbol {
public:

	//  method parameters
	const std::vector<ParameterSymbol> parameterSymbols;


	PositionalMethodSymbol(const std::string& _name, const std::string& _description, const std::vector<ParameterSymbol> _parameterSymbols, const ReturnSymbol _returnType) 
		: MethodSymbol(_name, _description, _returnType), parameterSymbols(_parameterSymbols) {}

	// should take list of types
	virtual const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual std::string getSignature() const;
	virtual std::string getDescription() const;
};


/*
Method symbol where we match arguments to parameters via position AND
optionally pass in optional parameters via keyword or positional.
I.e. Keyword/named Parameters.
sE.g. test(a, b, c, d = 2, e = 5)


NOTE
In our language, optional parameters can only be at the end of the method.
I.e. test(a, b, c = 2, d) is not allowed
This is also enforced by the parser which forbids non-keyword arguments after 
a keyword argument is first supplied.
Required paramters cannot be supplied by keyword.
*/
class KeywordMethodSymbol : public MethodSymbol {
public:

	// "leading" required parameters: can only be passed in via positional arguments
	const std::vector<ParameterSymbol> requiredParameterSymbols; 
	
	// optional parameters: can be passed in via positional + keyword arguments
	const std::vector<OptionalParameterSymbol> optionalParameterSymbols; 


	KeywordMethodSymbol(const std::string& _name, const std::string& _description,
		const std::vector<ParameterSymbol> _requiredParameterSymbols, const std::vector<OptionalParameterSymbol> _optionalParameterSymbols, const ReturnSymbol _returnType);

	virtual const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual std::string getSignature() const;
	virtual std::string getDescription() const;

private:
	// helper map for matching keyword strings to parameters
	std::map<std::string, OptionalParameterSymbol> optionalParamsMap;

};