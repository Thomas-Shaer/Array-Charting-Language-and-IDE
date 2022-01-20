#include "boolean.h"
#include <string>

char Boolean::TRUEEXPORTSTRING[40] = "true";
char Boolean::TRUEIMPORTSTRING[40] = "true";
char Boolean::FALSEEXPORTSTRING[40] = "false";
char Boolean::FALSEIMPORTSTRING[40] = "false";

std::string Boolean::toString() const {
	return this->value ? (*this->value ? "true" : "false") : "nan";
}


std::string Boolean::toFileString() const {
	if (!value) {
		return NaNHelper::NANEXPORTSTRING;
	}
	return *this->value ? TRUEEXPORTSTRING : FALSEEXPORTSTRING;
}
