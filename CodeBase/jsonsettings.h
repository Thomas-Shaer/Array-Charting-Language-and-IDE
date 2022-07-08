#pragma once
#include <nlohmann/json.hpp>

#define SAVE_NAME "settings.json"

/*
Struct for accessing all 
things related to saveable settings.
*/

struct Settings {
	// last time settings were saved
	static long long lastSaved;

	// how many miliseconds should pass before we save again
	static const int saveFrequency = 5000;

	// the actual json settings file
	static nlohmann::json settingsFile;
	
	/*
	* Saves the JSON object to file
	*/
	static void saveSettings();

	/*
	* Will save the JSON object after saveFrequency amount of time has passed
	*/
	static void autoSave();
};
