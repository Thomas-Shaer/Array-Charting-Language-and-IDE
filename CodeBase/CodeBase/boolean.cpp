#include "boolean.h"
#include <string>
#include "jsonsettings.h"



std::string Boolean::toString() const {
	return this->value ? (*this->value ? "true" : "false") : "nan";
}


std::string Boolean::toFileString() const {
	if (!value) {
		return Settings::settingsFile["defaultNANExportLiteral"].get<std::string>();
	}
	return *this->value ? Settings::settingsFile["defaultTrueExportLiteral"].get<std::string>() : Settings::settingsFile["defaultFalseExportLiteral"].get<std::string>();
}
