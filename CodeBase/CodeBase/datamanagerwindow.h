#pragma once
#include "imfilebrowser.h"

class InputData;
enum class ImportPolicy : unsigned int;

struct FileBrowserSingletonDataLoader {

	static void init();
	static ImGui::FileBrowser fb;
};

/*
Registers date file and also parses and loads in the various data columns.
*/
void loadInData(const ImportPolicy importPolicy, const std::string& pathName, const std::string& fileName, const std::string& TrueString, const std::string& FalseString, const std::string& NANString);

/*
Creates and registers new variable on symbol table.
*/
void createNewVariable(std::shared_ptr<InputData> data, const std::string& variableName);

/*
Deletes variable from symbol table.
*/
void deleteVariable(std::shared_ptr<InputData> data);

/*
Deletes all variables from symbol table.
*/
void deleteAllVariables();

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
void ShowDataWindow();
