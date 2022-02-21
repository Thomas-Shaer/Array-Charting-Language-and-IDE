#pragma once
#include <iostream>
#include "imfilebrowser.h"
#include "window.h"


class VarSymbol;

class OutputWindow : public Window {

public:

	OutputWindow();

	/*
	Snaps to the output tab.
	*/
	static void SnapToOutputTab();

	/*
	Updates and snaps to the variables tab.
	*/
	static void UpdateVariablesTab();

	/*
	* Window which houses all output information
	*/
	void ShowWindow();


	//Shows all the variables stored on the symbol table
	static std::vector<std::shared_ptr<VarSymbol>> CODE_OUTPUT_VARIABLES; 

	//Text output from the code is displayed here
	static std::string CODE_OUTPUT; 

	//Shows how the input code is interpreted
	static std::string CODE_OUTPUT_RECONSTRUCTION; 




private:
	static bool bringToFront;

	/*
	Flags to indicate whether tab should be opened or not.
	*/
	static ImGuiTabItemFlags_ outputTabFlags;
	static ImGuiTabItemFlags_ codeReconstructionTabFlags;
	static ImGuiTabItemFlags_ variableTabFlags;


	ImGui::FileBrowser fb{ ImGuiFileBrowserFlags_EnterNewFilename };


	// exports variable symbols to CSV file column wise
	void exportColumnWise(const std::string& filePath, std::vector<std::shared_ptr<VarSymbol>> variables);

	// exports variable symbols to CSV file row wise
	void exportRowWise(const std::string& filePath, std::vector<std::shared_ptr<VarSymbol>> variables);

};

