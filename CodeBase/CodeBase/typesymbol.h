#pragma once
#include <iostream>
#include "expressionvalue.h"




/*
Type symbol class.
Used to represent types.
*/
class TypeSymbol {
public:
	const std::string name;
	TypeSymbol(const std::string _name);

	bool operator==(const TypeSymbol& other) {
		return true;
	}

	ExpressionValue nanValue;
};

/*
Singleton for type instances.
*/
struct TypeInstances {
	TypeInstances();

	// Number type
	static TypeSymbol* GetNumberInstance();

	// Constant number type
	static TypeSymbol* GetNumberConstantInstance();

	// Boolean type
	static TypeSymbol* GetBooleanInstance();

	// Void type
	static TypeSymbol* GetVoidInstance();

	// Constant string type
	static TypeSymbol* GetStringConstantInstance();
	
	// String type
	static TypeSymbol* GetStringInstance();

	/*
	Helper functions to determine if two types are compatible.
	Supplies edge cases for constant types.
	*/
	static bool matchType(const TypeSymbol* expected, const TypeSymbol* received);
};

static TypeInstances typeinstances;


