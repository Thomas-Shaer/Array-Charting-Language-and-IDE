#pragma once
#include "nullablevalue.h"


class NullableValueString : public NullableValue<std::string> {

public:

	NullableValueString() : NullableValue() {}
	NullableValueString(std::string _value) : NullableValue(_value) {}

	virtual std::string toString() const;
	virtual std::string toFileString() const;


};