#pragma once
#include "value.h"




class Boolean : public Value<bool> {

public:

	static char TRUEFILESTRING[40];
	static char FALSEFILESTRING[40];

	Boolean() : Value() {}
	Boolean(bool _value) : Value(_value) {}
	
	virtual std::string toString() const;
	virtual std::string toFileString() const;


};