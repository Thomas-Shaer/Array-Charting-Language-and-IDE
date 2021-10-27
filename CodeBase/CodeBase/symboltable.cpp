#include "symboltable.h"


std::string SymbolTable::toString() {
	std::string output = "SYMBOL TABLE\n";

	for (const auto& value : values) {
		if (value.second.type() == typeid(float)) {
			output += "<" + value.first + ", " + std::to_string(boost::get<float>(value.second)) + ">\n";
		}
		else {
			output += "<" + value.first + ", " + ((boost::get<bool>(value.second)) == true ? "true" : "false") + ">\n";
		}
	}
	return output;
}