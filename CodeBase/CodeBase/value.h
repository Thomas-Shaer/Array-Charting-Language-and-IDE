#pragma once
#include <iostream>
#include <optional>

template<typename T>
class Value {
public:
	Value() : value(std::nullopt) {}
	Value(T val) : value(val) {}
	std::optional<T> value;
	virtual std::string toString() const = 0;
};