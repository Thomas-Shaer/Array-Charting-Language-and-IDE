#include "nullablevaluestring.h"
#include <string>
#include "jsonsettings.h"

std::string NullableValueString::toString() const {
	return this->value ? "\"" + (*this->value) + "\"" : "nan";
}

std::string NullableValueString::toFileString() const {
	if (!value) {
		return Settings::settingsFile["defaultNANExportLiteral"].get<std::string>();;
	}
	return *value;
}