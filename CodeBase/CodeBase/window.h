#pragma once
#include <iostream>
#include <vector>

class Window {
public:

	static std::vector<Window*> windows;



	Window(const std::string _name);
	virtual void ShowWindow() = 0;

	void deleteWindow();

	/*
	Creates/deletes windows stored in toCreate/toDelete.
	We do this so we can modify the windows vector at a safe time
	i.e. when we are not looping through it.
	*/
	static void manageNewWindows();


	std::string name;
	std::string saveJSONName;
	bool saveStatus = false;
	bool show = true;
	bool windowTab = false;
private:
	static std::vector<Window*> toCreate;
	static std::vector<Window*> toDelete;

};