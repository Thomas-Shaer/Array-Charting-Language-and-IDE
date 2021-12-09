#pragma once
#include <vector>
#include <string>

class ChartPlot {
public:

	ChartPlot(std::string _plotName, std::vector<float> _data) : data(_data), plotName(_plotName) {}
	const std::vector<float> data;
	const std::string plotName;
};