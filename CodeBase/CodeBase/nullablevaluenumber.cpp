#include "nullablevaluenumber.h"
#include <string>
#include "jsonsettings.h"


std::string NullableValueNumber::toString() const {
	return this->value ? std::to_string(*this->value) : "null";
}

std::string NullableValueNumber::toFileString() const {
	if (!value) {
		return Settings::settingsFile["defaultNANExportLiteral"].get<std::string>();;
	}
	return std::to_string(*value);
}