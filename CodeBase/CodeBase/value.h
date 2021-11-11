#pragma once
#include <iostream>

class Value {
public:
	virtual std::string toString() const = 0;
};