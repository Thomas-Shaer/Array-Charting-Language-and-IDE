#pragma once
#include "TextEditor.h"
#include "imfilebrowser.h"
#include "window.h"

class VarSymbol;

class TextEditorWindow : public Window {

public:


	TextEditorWindow();

	/*
	Saves code in text editor to disk.
	Use .al file extension.
	Uses JSON to store additional information.
	*/
	void saveFile(const std::string& filePath);


	/*
	Loads code from disk and updates the GUI.
	Use .al file extension.
	*/
	void loadFile(const std::string& filePath);

	/*
	Executes the code through the GUI.
	*/
	void executeCode(const std::string& code);


	/*
	Executes intellisense
	*/
	void executeErrorHighlighting(const std::string& code);

	/*
	* Window that allows user to enter and execute code
	*/
	void ShowWindow();

	/*
	Contains all the GUI that requires a one time initalisation for the text editor window.
	*/
	ImGui::FileBrowser fbSave{ ImGuiFileBrowserFlags_EnterNewFilename };
	ImGui::FileBrowser fbOpen;
	TextEditor textEditor;




	// signal for intellisense triggered by text editor
	static bool codemodifysignal;
	static std::string PLACEHOLDER_CODE; //Placeholder code for code input box

private:



};


