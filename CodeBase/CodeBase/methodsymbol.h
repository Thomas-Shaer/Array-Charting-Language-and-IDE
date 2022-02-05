#pragma once
#include <iostream>
#include "global.h"
#include <vector>
#include "interpreteroutput.h"
#include "parametersymbol.h"
#include "returnsymbol.h"
#include <map>
class TypeSymbol;
class ArgumentSymbol;
class MethodCallNode;
class SymbolTable;

/*
Contains all information related to a method.
Stored on the method symbol table.
*/
class MethodSymbol {
public:
	const ReturnSymbol returnType; // return type
	const std::string name; // method name
	const std::string description; //method description


	MethodSymbol(const std::string& _name, const std::string& _description, const ReturnSymbol _returnType) : name(_name), returnType(_returnType), description(_description) {}


	// should take list of types
	virtual const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) = 0;
	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output) = 0;

	virtual std::string getSignature() const = 0;
	virtual std::string getDescription() const = 0;

	virtual MethodSymbol* clone() = 0;
};


/*
Method symbol where we match parameters via positional arguments.
*/
class PositionalMethodSymbol : public MethodSymbol {
public:

	const std::vector<ParameterSymbol> parameterSymbols; //  type the method takes


	PositionalMethodSymbol(const std::string& _name, const std::string& _description, const std::vector<ParameterSymbol> _parameterSymbols, const ReturnSymbol _returnType) 
		: MethodSymbol(_name, _description, _returnType), parameterSymbols(_parameterSymbols) {}

	// should take list of types
	virtual const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual std::string getSignature() const;
	virtual std::string getDescription() const;
};


/*
Method symbol where we match parameters via positional arguments + keyword arguments.
*/
class KeywordMethodSymbol : public MethodSymbol {
public:

	const std::vector<ParameterSymbol> requiredParameterSymbols; //  type the method takes
	const std::vector<OptionalParameterSymbol> optionalParameterSymbols; //  type the method takes
	std::map<std::string, OptionalParameterSymbol> optionalParamsMap;


	KeywordMethodSymbol(const std::string& _name, const std::string& _description,
		const std::vector<ParameterSymbol> _requiredParameterSymbols, const std::vector<OptionalParameterSymbol> _optionalParameterSymbols, const ReturnSymbol _returnType);

	// should take list of types
	virtual const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual std::string getSignature() const;
	virtual std::string getDescription() const;
};