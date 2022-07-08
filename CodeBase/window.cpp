#include "window.h"
#include "jsonsettings.h"

std::vector<Window*> Window::windows = {};
std::vector<Window*> Window::toCreate = {};
std::vector<Window*> Window::toDelete = {};

Window::Window(const std::string _name) : name(_name) {
	saveJSONName = "isOpen" + _name;
	// remove spaces from save name
	saveJSONName.erase(std::remove(saveJSONName.begin(), saveJSONName.end(), ' '), saveJSONName.end());

	toCreate.push_back(this);
	// load save status
	if (Settings::settingsFile.contains(saveJSONName)) {
		show = Settings::settingsFile[saveJSONName].get<bool>();
	}
}


void Window::deleteWindow() {
	toDelete.push_back(this);
}



void Window::manageNewWindows() {

	for (Window* wind : toCreate) {
		windows.push_back(wind);
	}
	toCreate.clear();
	for (Window* wind : toDelete) {
		windows.erase(std::remove(windows.begin(), windows.end(), wind), windows.end());
		delete wind;

	}
	toDelete.clear();
}