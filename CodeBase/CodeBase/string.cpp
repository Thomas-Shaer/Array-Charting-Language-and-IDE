#include "string.h"
#include <string>
#include "jsonsettings.h"

std::string String::toString() const {
	return this->value ? "\"" + (*this->value) + "\"" : "nan";
}

std::string String::toFileString() const {
	if (!value) {
		return Settings::settingsFile["defaultNANExportLiteral"].get<std::string>();;
	}
	return *value;
}