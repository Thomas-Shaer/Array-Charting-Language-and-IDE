#pragma once
#include <iostream>
#include <vector>

class InputData;

/*
* Stores all dynamic information used within rendering window
* Also acts as optimisation as stores information such that it doesn't have to be continouly calculated
*/
struct DisplayInformation {
public:
	static std::string PLACEHOLDER_CODE; //Placeholder code for code input box
	static std::string CODE_OUTPUT; //Text output from the code is displayed here
	static std::string CODE_OUTPUT_RECONSTRUCTION; //Shows how the input code is interpreted
	static std::string CODE_OUTPUT_VARIABLES; //Shows all the variables stored on the symbol table
	static std::string CHART_DESCRIPTION;


	static 	std::vector<std::vector<float>> CHART_MARK_DATA;
	
	static 	std::vector<std::shared_ptr<InputData>> LOADED_IN_DATA;

	static 	float MAX_CHART_Y;

	static 	std::vector<std::vector<float>> CHART_LINE_DATA;

};

