#pragma once
#include <iostream>
#include <optional>
#include <boost/variant/static_visitor.hpp>


/*
Base class for all values that
can also be a null.
Acts as a wrapper around value of type T
that can be optional.
*/
template<typename T>
class NullableValue {
public:

	// default constructor, value is null
	NullableValue() : value(std::nullopt) {}

	NullableValue(T val) : value(val) {}

	// the value itself. Optional represents whether its null or not.
	std::optional<T> value;

	/*
	Gets value as string.
	For debugging.
	*/
	virtual std::string toString() const = 0;
	
	/*
	Gets value as string.
	Used when writing this value to a CSV file.
	*/
	virtual std::string toFileString() const = 0;
};

