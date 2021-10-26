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

	std::string toString() {
		std::string output;

		for (const auto& value : values){
			if (value.second.type() == typeid(float)) {
				output += "<" + value.first + ", " + std::to_string(boost::get<float>(value.second)) + ">";
			}
			else {
				output += "<" + value.first + ", " + ((boost::get<bool>(value.second)) == true ? "true" : "false") + ">";
			}
		}
		return output;
	}
};