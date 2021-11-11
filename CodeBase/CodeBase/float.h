#pragma once
#include "value.h"


class Float : public Value {

public:

	Float() : value(-99) {}

	Float(float _value) : value(_value) {}
	float value;

	virtual std::string toString() const;


};