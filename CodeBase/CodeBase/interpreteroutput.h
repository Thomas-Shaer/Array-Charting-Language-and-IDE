#pragma once
#include <vector>
#include <iostream>

class ChartPlot;

struct InterpreterOutput {
	const unsigned int amountTicks;
	InterpreterOutput(unsigned int _amountTicks) : amountTicks(_amountTicks) {}
	std::vector<std::string> textOutput;
	std::vector<std::shared_ptr<ChartPlot>> chartData;
	std::vector<std::shared_ptr<ChartPlot>> markData;

};