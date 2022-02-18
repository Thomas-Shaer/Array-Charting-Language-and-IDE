#pragma once
#include "window.h"



/*
Window containing additional settings for program
*/
class SettingsWindow : public Window {

public:


	SettingsWindow() : Window("Settings Window") {}

	/*
	Opens the setting window.
	*/
	void ShowWindow();

private:



};

