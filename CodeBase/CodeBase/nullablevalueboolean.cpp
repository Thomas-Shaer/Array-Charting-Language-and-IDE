#include "nullablevalueboolean.h"
#include <string>
#include "jsonsettings.h"



std::string NullableValueBoolean::toString() const {
	return this->value ? (*this->value ? "true" : "false") : "nan";
}


std::string NullableValueBoolean::toFileString() const {
	if (!value) {
		return Settings::settingsFile["defaultNANExportLiteral"].get<std::string>();
	}
	return *this->value ? Settings::settingsFile["defaultTrueExportLiteral"].get<std::string>() : Settings::settingsFile["defaultFalseExportLiteral"].get<std::string>();
}
