#pragma once
#include <vector>
#include <string>
#include "float.h"

/*
Container for a series to be plotted on the chart.
*/
class ChartPlot {
public:

	ChartPlot(std::string _plotName, std::vector<float> _data) : data(_data), plotName(_plotName) {}

	// create new chart plot i.e. fill vector with amount of ticks
	ChartPlot(std::string _plotName, unsigned int amountTicks);
	
	static std::vector<float> createEmptyVector(unsigned int amountTicks);
	static std::vector<Float> createEmptyVectorNAFloat(unsigned int amountTicks);
	// plot data
	std::vector<float> data;
	
	// plot name (will be displayed as label)
	const std::string plotName;
};