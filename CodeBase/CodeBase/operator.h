#pragma once
#include <iostream>
#include "global.h"

/*
* Contains logic for evalutating operators, including:
* Semantic requirements e.g. FLOAT + FLOAT
* Interpreter output e.g. 2 + 2 = 4
* Other useful information such as type name as a string.
*/


// forward declare data type

class Operator {
public:
	const std::string name; // string representation of type
	Operator(const std::string& _name);
};

