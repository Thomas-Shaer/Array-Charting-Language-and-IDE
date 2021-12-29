#pragma once
#include <iostream>
#include "imfilebrowser.h"


struct TextOutputWindow {

	static void init();
	static ImGui::FileBrowser fb;
};

/*
Snaps to the output tab.
*/
void SnapToOutputTab();

/*
Updates and snaps to the variables tab.
*/
void UpdateVariablesTab();

/*
* Window which houses all output information
*/
void ShowTextOutputWindow();