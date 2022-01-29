#include "float.h"
#include <string>
#include "jsonsettings.h"


std::string Float::toString() const {
	return this->value ? std::to_string(*this->value) : "nan";
}

std::string Float::toFileString() const {
	if (!value) {
		return Settings::settingsFile["defaultNANExportLiteral"].get<std::string>();;
	}
	return std::to_string(*value);
}