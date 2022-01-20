#include "float.h"
#include <string>

std::string Float::toString() const {
	return this->value ? std::to_string(*this->value) : "nan";
}

std::string Float::toFileString() const {
	if (!value) {
		return NaNHelper::NANEXPORTSTRING;
	}
	return std::to_string(*value);
}