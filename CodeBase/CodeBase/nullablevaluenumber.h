#pragma once
#include "nullablevalue.h"



/*
The number value.
Value will be null or a number.
NOTE: Numbers are implemented as floats.
*/
class NullableValueNumber : public NullableValue<float> {

public:

	NullableValueNumber() : NullableValue() {}
	NullableValueNumber(float _value) : NullableValue(_value) {}

	virtual std::string toString() const;
	virtual std::string toFileString() const;


};