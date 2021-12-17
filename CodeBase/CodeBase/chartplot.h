#pragma once
#include <vector>
#include <string>

class ChartPlot {
public:

	ChartPlot(std::string _plotName, std::vector<float> _data) : data(_data), plotName(_plotName) {}

	// create new chart plot i.e. fill vector with amount of ticks
	ChartPlot(std::string _plotName, unsigned int amountTicks);
	std::vector<float> data;
	const std::string plotName;
};