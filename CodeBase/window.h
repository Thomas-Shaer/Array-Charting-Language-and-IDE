#pragma once
#include <iostream>
#include <vector>

/*
Window base class.
Allows for easy access and management of window objects.
E.g. ChartWindow, DataManagerWindow
*/
class Window {
public:

	// contains record of ALL windows. Window constructor automatically registers it in here.
	static std::vector<Window*> windows;



	Window(const std::string _name);
	virtual void ShowWindow() = 0;

	// registers this window in toDelete. Will be safely deleted
	void deleteWindow();

	/*
	Creates/deletes windows stored in toCreate/toDelete.
	We do this so we can modify the windows vector at a safe time
	i.e. when we are not looping through it.
	*/
	static void manageNewWindows();


	// name of window
	std::string name;
	// json is open save name for this window
	std::string saveJSONName;
	// if true will save status of open/closed for this window
	bool saveOpenStatus = false;
	// render this window or not
	bool show = true;
	// add this window to main viewport menubar tab
	bool windowTab = false;
private:
	// temporarily store windows to be safely created
	static std::vector<Window*> toCreate;
	// temporarily store windows to be safely deleted
	static std::vector<Window*> toDelete;


};