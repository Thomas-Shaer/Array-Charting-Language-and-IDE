#pragma once
#include "nullablevalue.h"


class NullableValueNumber : public NullableValue<float> {

public:

	NullableValueNumber() : NullableValue() {}
	NullableValueNumber(float _value) : NullableValue(_value) {}

	virtual std::string toString() const;
	virtual std::string toFileString() const;


};