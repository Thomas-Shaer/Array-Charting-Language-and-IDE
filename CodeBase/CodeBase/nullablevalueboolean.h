#pragma once
#include "nullablevalue.h"




class NullableValueBoolean : public NullableValue<bool> {

public:

	NullableValueBoolean() : NullableValue() {}
	NullableValueBoolean(bool _value) : NullableValue(_value) {}
	
	virtual std::string toString() const;
	virtual std::string toFileString() const;


};