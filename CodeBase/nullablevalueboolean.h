#pragma once
#include "nullablevalue.h"



/*
The boolean value.
Value will be null or a boolean.
*/
class NullableValueBoolean : public NullableValue<bool> {

public:

	NullableValueBoolean() : NullableValue() {}
	NullableValueBoolean(bool _value) : NullableValue(_value) {}
	
	virtual std::string toString() const;
	virtual std::string toFileString() const;


};