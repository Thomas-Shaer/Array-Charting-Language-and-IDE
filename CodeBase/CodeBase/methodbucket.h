#pragma once
#include "global.h"
#include <vector>
#include <map>


/*
Used for classing methods by their type.
*/
enum class METHOD_CAT { OPERATOR, MATHEMATICAL, LOGIC, OUTPUT, STATISTICS, MISC };
static std::map<METHOD_CAT, std::string> METHOD_CAT_TO_STRING{
	{METHOD_CAT::OPERATOR, "Operator"},
	{METHOD_CAT::MATHEMATICAL, "Mathematical"},
	{METHOD_CAT::LOGIC, "Logic"},
	{METHOD_CAT::OUTPUT, "Output"},
	{METHOD_CAT::STATISTICS, "Statistics"},
	{METHOD_CAT::MISC, "Miscellaneous"}
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

	/*
	Used to map the method type categories to the method itself.
	(For front end purposes - documentation window)
	*/
	static std::map<METHOD_CAT, std::vector<MethodBucket*>> methodTypeMappings;

	MethodBucket(const METHOD_CAT _methodType);

	/*
	* Get a method given the argument types
	*/
	virtual MethodSymbol* getMethodSymbol(MethodCallNode* methodcall, std::shared_ptr<SymbolTable> symbolTable) const=0;


	METHOD_CAT methodCat;

	/*
	Used to nicely format the method when drawing onto the GUI
	Usually I want to separate the logic completely from the GUI, but in this 
	case this is the cleanest way to nicely format and draw the information.
	*/
	virtual void renderAsDocumentation() const = 0;
	virtual std::string asDocumentation() const = 0;

	virtual std::string toString() const = 0;

	std::string name;
};


/*
* MethodBucket containing multiple method symbols. Should return one given some input parameters, else throw a error.
* Can only have positional methods. Cannot overload with keywords
*/
class OverloadedMethodBucket : public MethodBucket {
public:

	OverloadedMethodBucket(const std::vector<PositionalMethodSymbol*> _overloads, const METHOD_CAT _methodType) : overloads(_overloads), MethodBucket(_methodType){}

	const std::vector<PositionalMethodSymbol*> overloads;

	virtual MethodSymbol* getMethodSymbol(MethodCallNode* methodcall, std::shared_ptr<SymbolTable> symbolTable) const;

	virtual std::string toString() const;

	virtual void renderAsDocumentation() const;
	virtual std::string asDocumentation() const;


};


/*
* MethodBucket containing only one method. It will always return that method symbol no matter the arguments.
*/
class SingleMethodBucket : public MethodBucket {
public:

	SingleMethodBucket(MethodSymbol* _methodsymbol, const METHOD_CAT _methodType) : methodsymbol(_methodsymbol), MethodBucket(_methodType) {}

	MethodSymbol* methodsymbol;

	virtual MethodSymbol* getMethodSymbol(MethodCallNode* methodcall, std::shared_ptr<SymbolTable> symbolTable) const;

	virtual std::string toString() const;
	virtual void renderAsDocumentation() const;
	virtual std::string asDocumentation() const;

};