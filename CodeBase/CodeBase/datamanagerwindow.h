#pragma once
#include "imfilebrowser.h"


struct FileBrowserSingletonDataLoader {

	static void init();
	static ImGui::FileBrowser fb;
};

/*
* Window that displays data manager
*/
void ShowDataWindow();
