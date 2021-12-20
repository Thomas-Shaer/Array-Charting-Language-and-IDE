#include "chartplot.h"



// create new chart plot i.e. fill vector with amount of ticks
ChartPlot::ChartPlot(std::string _plotName, unsigned int amountTicks) : plotName(_plotName), data(std::vector<float>(amountTicks)) {
	std::fill(data.begin(), data.end(), std::numeric_limits<float>::quiet_NaN());
}