#pragma once
#include <iostream>
#include <vector>
#include <string>

class InputData {


public:


	static std::vector<std::shared_ptr<InputData>> LoadInputData(std::string name, std::string filename);

	std::string name;
	std::string fileName;
	std::vector<float> data;

	bool isVariable = false;
	std::string variableName;

	std::string toString() {
		std::string output = name + " : ";

		for (auto d : data) {
			output += std::to_string(d) + ", ";
		}

		return output;
	}

};