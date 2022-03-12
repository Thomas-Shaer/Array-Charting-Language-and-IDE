#pragma once
#include <vector>
#include <string>
#include "nullablevaluenumber.h"

/*
Container for a series to be plotted on the chart.
*/
class ChartPlot {
public:

	ChartPlot(std::string _plotName, std::vector<float> _data) : fdata(_data), plotName(_plotName) {}
	ChartPlot(std::string _plotName, std::vector<std::string> _data) : sdata(_data), plotName(_plotName) { stringMark = true; }

	// create new chart plot i.e. fill vector with amount of ticks
	ChartPlot(std::string _plotName, unsigned int amountTicks);
	
	bool stringMark = false;

	// plot data
	std::vector<float> fdata;
	std::vector<std::string> sdata;
	std::vector<bool> vstringdata;
	
	// plot name (will be displayed as label)
	const std::string plotName;
};