#pragma once
#include <iostream>

class TypeSymbol {
public:
	const std::string name;
	TypeSymbol(const std::string _name);

	bool operator==(const TypeSymbol& other) {
		return true;
	}


};

struct TypeInstances {
	TypeInstances();
	static TypeSymbol* GetFloatInstance();
	static TypeSymbol* GetFloatConstantInstance();
	static TypeSymbol* GetBooleanInstance();
	static TypeSymbol* GetVoidInstance();
	static TypeSymbol* GetStringConstantInstance();
	static TypeSymbol* GetStringInstance();
};

static TypeInstances typeinstances;


