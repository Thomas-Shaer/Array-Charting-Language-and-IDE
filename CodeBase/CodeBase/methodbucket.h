#pragma once
#include "global.h"
#include <vector>


class MethodSymbol;
class TypeSymbol;
/*
* Acts as an intermediate container for method symbols.
* It's existance is to support overloaded methods.
* MethodBucket is stored in the symbol table. Given some arguments, the bucket will return a method symbol.
* This allows for us to get a overload from a method.
*/
class MethodBucket {
public:

	/*
	* Get a method given the argument types
	*/
	virtual MethodSymbol* getMethodSymbol(std::vector<const TypeSymbol*> _argumentTypes) const=0;

	virtual std::string toString() const = 0;
};


/*
* MethodBucket containing multiple method symbols. Should return one given some input parameters, else throw a error.
*/
class OverloadedMethodBucket : public MethodBucket {
public:

	OverloadedMethodBucket(const std::vector<MethodSymbol*> _overloads) : overloads(_overloads) {}

	const std::vector<MethodSymbol*> overloads;

	virtual MethodSymbol* getMethodSymbol(std::vector<const TypeSymbol*> _argumentTypes) const;

	virtual std::string toString() const;

};


/*
* MethodBucket containing only one method. It will always return that method symbol no matter the arguments.
*/
class SingleMethodBucket : public MethodBucket {
public:

	SingleMethodBucket(MethodSymbol* _methodsymbol) : methodsymbol(_methodsymbol) {}

	MethodSymbol* methodsymbol;

	virtual MethodSymbol* getMethodSymbol(std::vector<const TypeSymbol*> _argumentTypes) const;

	virtual std::string toString() const;


};