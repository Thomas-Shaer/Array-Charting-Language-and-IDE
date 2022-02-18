#pragma once
#include "nullablevalue.h"


/*
The string value.
Value will be null or a string.
*/
class NullableValueString : public NullableValue<std::string> {

public:

	NullableValueString() : NullableValue() {}
	NullableValueString(std::string _value) : NullableValue(_value) {}

	virtual std::string toString() const;
	virtual std::string toFileString() const;


};