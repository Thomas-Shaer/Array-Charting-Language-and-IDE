#include "window.h"

std::vector<Window*> Window::windows = {};
std::vector<Window*> Window::toCreate = {};
std::vector<Window*> Window::toDelete = {};

Window::Window(const std::string _name) : name(_name) {

	toCreate.push_back(this);

}


void Window::deleteWindow() {
	toDelete.push_back(this);
}



void Window::manageNewWindows() {

	for (Window* wind : toCreate) {
		windows.push_back(wind);
	}
	for (Window* wind : toDelete) {
		windows.erase(std::remove(windows.begin(), windows.end(), wind), windows.end());
		delete wind;

	}
	toCreate.clear();
	toDelete.clear();
}