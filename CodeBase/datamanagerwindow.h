#pragma once
#include "imfilebrowser.h"
#include "window.h"
class InputSeries;
enum class ImportPolicy : unsigned int;



class DataManagerWindow : public Window {

public:


	DataManagerWindow();


	/*
	Deletes all variables from symbol table.
	*/
	static void deleteAllVariables();

	/*
	Removes a data file.
	*/
	void removeFile(const std::string& fileName);


	/*
	Removes all data files.
	*/
	void removeAllFiles();


	/*
	Converts string into correct format for a variable name.
	*/
	std::string makeVariableName(std::string name);



	/*
	* Window that displays data manager
	*/
	void ShowWindow();



	static 	std::vector<std::shared_ptr<InputSeries>> LOADED_IN_DATA;

private:
	ImGui::FileBrowser fb;

};