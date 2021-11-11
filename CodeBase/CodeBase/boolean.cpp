#include "boolean.h"
#include <string>

std::string Boolean::toString() const {
	return value ? "true" : "false";
}
