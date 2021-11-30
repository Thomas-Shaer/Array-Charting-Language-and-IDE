#include "boolean.h"
#include <string>

std::string Boolean::toString() const {
	return this->value ? (*this->value ? "true" : "false") : "nan";
}
