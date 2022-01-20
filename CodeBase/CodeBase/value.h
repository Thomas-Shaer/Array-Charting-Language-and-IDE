#pragma once
#include <iostream>
#include <optional>


class NaNHelper {
public:
	static char NANEXPORTSTRING[40];
	static char NANIMPORTSTRING[40];
};

template<typename T>
class Value {
public:

	Value() : value(std::nullopt) {}
	Value(T val) : value(val) {}
	std::optional<T> value;
	virtual std::string toString() const = 0;
	virtual std::string toFileString() const = 0;
};