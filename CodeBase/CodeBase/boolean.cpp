#include "boolean.h"
#include <string>

char Boolean::TRUEFILESTRING[40] = "true";
char Boolean::FALSEFILESTRING[40] = "false";

std::string Boolean::toString() const {
	return this->value ? (*this->value ? "true" : "false") : "nan";
}


std::string Boolean::toFileString() const {
	if (!value) {
		return NaNHelper::NANFILESTRING;
	}
	return *this->value ? TRUEFILESTRING : FALSEFILESTRING;
}
