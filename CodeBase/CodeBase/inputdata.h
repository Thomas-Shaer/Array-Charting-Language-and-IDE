#pragma once
#include <iostream>
#include <vector>
#include <string>

class InputData {

public:
	std::string name;
	std::vector<float> data;

	std::string toString() {
		std::string output = name + " : ";

		for (auto d : data) {
			output += std::to_string(d) + ", ";
		}

		return output;
	}

};