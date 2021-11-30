#pragma once
#include "value.h"


class Float : public Value<float> {

public:

	Float() : Value() {}
	Float(float _value) : Value(_value) {}

	virtual std::string toString() const;

};