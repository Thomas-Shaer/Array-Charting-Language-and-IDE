#pragma once
#include "TextEditor.h"
#include "imfilebrowser.h"


struct TextEditorSingleton {

	static void initFileBrowserSave();
	static void initFileBrowserOpen();
	static void initTextEditor();
	static ImGui::FileBrowser fbSave;
	static ImGui::FileBrowser fbOpen;
	static TextEditor textEditor;
};

/*
* Window that allows user to enter and execute code
*/
void ShowEditorWindow();