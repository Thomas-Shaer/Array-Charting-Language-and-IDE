#pragma once
#include "global.h"
#include <vector>
#include <map>


/*
Used for classing methods by their type.
*/
const enum METHOD_TYPE { OPERATOR, MATHEMATICAL, LOGIC, OUTPUT, STATISTICS, MISC };
static std::map<METHOD_TYPE, std::string> METHOD_TYPE_TO_STRING{
	{METHOD_TYPE::OPERATOR, "Operator"},
	{METHOD_TYPE::MATHEMATICAL, "Mathematical"},
	{METHOD_TYPE::LOGIC, "Logic"},
	{METHOD_TYPE::OUTPUT, "Output"},
	{METHOD_TYPE::STATISTICS, "Statistics"},
	{METHOD_TYPE::MISC, "Miscellaneous"}
};

class MethodSymbol;
class PositionalMethodSymbol;
class TypeSymbol;
class ArgumentSymbol;
class MethodCallNode;
class SymbolTable;

/*
* Acts as an intermediate container for method symbols.
* It's existance is to support overloaded methods.
* MethodBucket is stored in the symbol table. Given some arguments, the bucket will return a method symbol.
* This allows for us to get a overload from a method.
*/
class MethodBucket {
public:


	static std::map<METHOD_TYPE, std::vector<MethodBucket*>> methodTypeMappings;

	MethodBucket(const METHOD_TYPE _methodType);

	/*
	* Get a method given the argument types
	*/
	virtual MethodSymbol* getMethodSymbol(MethodCallNode* methodcall, std::shared_ptr<SymbolTable> symbolTable) const=0;


	METHOD_TYPE methodType;

	/*
	Used to nicely format the method when drawing onto the GUI
	Usually I want to separate the logic completely from the GUI, but in this 
	case this is the cleanest way to nicely format and draw the information.
	*/
	virtual void renderAsDocumentation() const = 0;

	virtual std::string toString() const = 0;

	std::string name;
};


/*
* MethodBucket containing multiple method symbols. Should return one given some input parameters, else throw a error.
* Can only have positional methods. Cannot overload with keywords
*/
class OverloadedMethodBucket : public MethodBucket {
public:

	OverloadedMethodBucket(const std::vector<PositionalMethodSymbol*> _overloads, const METHOD_TYPE _methodType) : overloads(_overloads), MethodBucket(_methodType){}

	const std::vector<PositionalMethodSymbol*> overloads;

	virtual MethodSymbol* getMethodSymbol(MethodCallNode* methodcall, std::shared_ptr<SymbolTable> symbolTable) const;

	virtual std::string toString() const;

	virtual void renderAsDocumentation() const;
	

};


/*
* MethodBucket containing only one method. It will always return that method symbol no matter the arguments.
*/
class SingleMethodBucket : public MethodBucket {
public:

	SingleMethodBucket(MethodSymbol* _methodsymbol, const METHOD_TYPE _methodType) : methodsymbol(_methodsymbol), MethodBucket(_methodType) {}

	MethodSymbol* methodsymbol;

	virtual MethodSymbol* getMethodSymbol(MethodCallNode* methodcall, std::shared_ptr<SymbolTable> symbolTable) const;

	virtual std::string toString() const;
	virtual void renderAsDocumentation() const;


};