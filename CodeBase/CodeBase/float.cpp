#include "float.h"
#include <string>

std::string Float::toString() const {
	return std::to_string(value);
}