#include "nullablevaluestring.h"
#include <string>
#include "jsonsettings.h"

std::string NullableValueString::toString() const {
	return this->value ? "\"" + (*this->value) + "\"" : "null";
}

std::string NullableValueString::toFileString() const {
	if (!value) {
		return Settings::settingsFile["defaultNullExportLiteral"].get<std::string>();;
	}
	return *value;
}