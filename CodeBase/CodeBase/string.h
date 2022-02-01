#pragma once
#include "value.h"


class String : public Value<std::string> {

public:

	String() : Value() {}
	String(std::string _value) : Value(_value) {}

	virtual std::string toString() const;
	virtual std::string toFileString() const;


};