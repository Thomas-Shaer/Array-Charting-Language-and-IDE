#include "chartplot.h"



// create new chart plot i.e. fill vector with amount of ticks
ChartPlot::ChartPlot(std::string _plotName, unsigned int amountTicks) : plotName(_plotName), data(std::vector<float>(amountTicks)) {
	std::fill(data.begin(), data.end(), std::numeric_limits<float>::quiet_NaN());
}
std::vector<float> ChartPlot::createEmptyVector(unsigned int amountTicks) {
	std::vector<float> newVector(amountTicks);
	std::fill(newVector.begin(), newVector.end(), std::numeric_limits<float>::quiet_NaN());
	return  newVector;
}

std::vector<Float> ChartPlot::createEmptyVectorNAFloat(unsigned int amountTicks) {
	std::vector<Float> newVector(amountTicks);
	std::fill(newVector.begin(), newVector.end(), Float());
	return  newVector;
}