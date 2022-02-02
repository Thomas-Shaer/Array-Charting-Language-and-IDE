#pragma once
#include "TextEditor.h"
#include "imfilebrowser.h"
#include "window.h"

class VarSymbol;

class TextEditorWindow : public Window {

public:


	TextEditorWindow() : Window("Text Editor Window") {}

	/*
	Saves code in text editor to disk.
	Use .al file extension.
	Uses JSON to store additional information.
	*/
	static void saveFile(const std::string& filePath);


	/*
	Loads code from disk and updates the GUI.
	Use .al file extension.
	*/
	static void loadFile(const std::string& filePath);

	/*
	Executes the code through the GUI.
	*/
	static void executeCode(const std::string& code);

	/*
	* Window that allows user to enter and execute code
	*/
	void ShowWindow();

	/*
	Contains all the GUI that requires a one time initalisation for the text editor window.
	*/
	static void initFileBrowserSave();
	static void initFileBrowserOpen();
	static void initTextEditor();
	static ImGui::FileBrowser fbSave;
	static ImGui::FileBrowser fbOpen;
	static TextEditor textEditor;



	static std::string PLACEHOLDER_CODE; //Placeholder code for code input box

private:



};


