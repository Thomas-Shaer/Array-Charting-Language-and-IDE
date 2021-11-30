#include "float.h"
#include <string>

std::string Float::toString() const {
	return this->value ? std::to_string(*this->value) : "nan";
}