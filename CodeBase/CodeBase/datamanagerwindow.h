#pragma once
#include "imfilebrowser.h"
#include "window.h"
class InputData;
enum class ImportPolicy : unsigned int;



class DataManagerWindow : public Window {

public:


	DataManagerWindow() : Window("Data Manager Window", true) {}


	/*
	* Window that shows documentation for the language.
	*/
	/*
Registers date file and also parses and loads in the various data columns.
*/
	static void loadInData(const ImportPolicy importPolicy, const std::string& pathName, const std::string& fileName, const std::string& TrueString, const std::string& FalseString, const std::string& NANString);

	/*
	Creates and registers new variable on symbol table.
	*/
	static void createNewVariable(std::shared_ptr<InputData> data, const std::string& variableName);

	/*
	Deletes variable from symbol table.
	*/
	static void deleteVariable(std::shared_ptr<InputData> data);

	/*
	Renames a variable
	*/
	static void renameVariable(std::shared_ptr<InputData> data, const std::string& variableName);


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


	static void init();
	static ImGui::FileBrowser fb;


	static 	std::vector<std::shared_ptr<InputData>> LOADED_IN_DATA;

private:



};