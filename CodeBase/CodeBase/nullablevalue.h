#pragma once
#include <iostream>
#include <optional>


template<typename T>
class NullableValue {
public:

	NullableValue() : value(std::nullopt) {}
	NullableValue(T val) : value(val) {}
	std::optional<T> value;
	virtual std::string toString() const = 0;
	virtual std::string toFileString() const = 0;
};