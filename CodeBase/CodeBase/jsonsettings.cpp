#include "jsonsettings.h"
#include <fstream>
#include <chrono>
#include <iostream>

nlohmann::json Settings::settingsFile;
long long Settings::lastSaved = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();

void Settings::saveSettings() {
	std::ofstream o(SAVE_NAME);
	o << Settings::settingsFile << std::endl;
}


void Settings::autoSave() {
	auto timeNow = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
	if ((timeNow - lastSaved) >= saveFrequency) {
		saveSettings();
		lastSaved = timeNow;
		std::cout << "AUtosaved" << std::endl;
	}
}