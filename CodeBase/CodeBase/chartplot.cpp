#include "chartplot.h"



// create new chart plot i.e. fill vector with amount of ticks
ChartPlot::ChartPlot(std::string _plotName, unsigned int amountTicks) : plotName(_plotName), fdata(std::vector<float>(amountTicks)), vstringdata(std::vector<bool>(amountTicks)), sdata(std::vector<std::string>(amountTicks)) {
	std::fill(fdata.begin(), fdata.end(), std::numeric_limits<float>::quiet_NaN());
	std::fill(sdata.begin(), sdata.end(), "");
	std::fill(vstringdata.begin(), vstringdata.end(), false);
}

