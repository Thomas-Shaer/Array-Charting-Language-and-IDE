#pragma once
#include "value.h"

class Boolean : public Value<bool> {

public:

	Boolean() : Value() {}
	Boolean(bool _value) : Value(_value) {}
	
	virtual std::string toString() const;



};