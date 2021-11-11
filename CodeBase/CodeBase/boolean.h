#pragma once
#include "value.h"

class Boolean : public Value {

public:

	Boolean() : value(false) {}

	Boolean(bool _value) : value(_value) {}
	bool value;

	virtual std::string toString() const;

};