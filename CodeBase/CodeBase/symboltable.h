#pragma once
#include <boost/variant.hpp>
#include <map>

typedef boost::variant<float, bool> ExpressionValue;

/*
* Symbol table stores values of variables e.g.
*	<x, 2>
*	<y, 5>
*	<z, true>
*/
class SymbolTable {
public:

	std::map<std::string, ExpressionValue> values;

	std::string toString();
};