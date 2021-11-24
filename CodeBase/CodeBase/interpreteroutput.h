#pragma once
#include <vector>
#include <iostream>

struct InterpreterOutput {
	std::vector<std::string> textOutput;
	std::vector<std::vector<float>> chartData;
	std::vector<std::vector<float>> markData;
	unsigned int maxTicks;

};