#pragma once
#include <iostream>
#include <vector>

class Window {
public:

	static std::vector<Window*> windows;


	Window(const std::string _name, bool recordAsMainWindow);
	virtual void ShowWindow() = 0;


	std::string name;
	bool show = true;
private:

};