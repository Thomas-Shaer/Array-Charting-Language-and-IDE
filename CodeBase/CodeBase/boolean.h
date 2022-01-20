#pragma once
#include "value.h"




class Boolean : public Value<bool> {

public:

	static char TRUEEXPORTSTRING[40];
	static char TRUEIMPORTSTRING[40];
	static char FALSEEXPORTSTRING[40];
	static char FALSEIMPORTSTRING[40];

	Boolean() : Value() {}
	Boolean(bool _value) : Value(_value) {}
	
	virtual std::string toString() const;
	virtual std::string toFileString() const;


};