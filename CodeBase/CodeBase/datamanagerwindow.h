#pragma once
#include "imfilebrowser.h"

class InputData;

struct FileBrowserSingletonDataLoader {

	static void init();
	static ImGui::FileBrowser fb;
};

void loadInData(const std::string& pathName, const std::string& fileName);
void createNewVariable(std::shared_ptr<InputData> data, const std::string& variableName);
void deleteVariable(std::shared_ptr<InputData> data);
void deleteAllVariables();

/*
* Window that displays data manager
*/
void ShowDataWindow();
