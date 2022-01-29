#include "window.h"

std::vector<Window*> Window::windows = {};


Window::Window(const std::string _name, bool recordAsMainWindow) : name(_name) {

	if (recordAsMainWindow) {
		windows.push_back(this);
	}

}
