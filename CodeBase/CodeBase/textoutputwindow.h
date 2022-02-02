#pragma once
#include <iostream>
#include "imfilebrowser.h"
#include "window.h"


class VarSymbol;

class OutputWindow : public Window {

public:

	OutputWindow() : Window("Output Window") {}

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



	static std::vector<std::shared_ptr<VarSymbol>> CODE_OUTPUT_VARIABLES; //Shows all the variables stored on the symbol table


	static void init();
	static ImGui::FileBrowser fb;
	static std::string CODE_OUTPUT; //Text output from the code is displayed here
	static std::string CODE_OUTPUT_RECONSTRUCTION; //Shows how the input code is interpreted
	/*
	Flags to indicate whether tab should be opened or not.
	*/
	static ImGuiTabItemFlags_ outputTabFlags;
	static ImGuiTabItemFlags_ codeReconstructionTabFlags;
	static ImGuiTabItemFlags_ variableTabFlags;

private:



};

