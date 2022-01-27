#include "displayinformation.h"
#include "interpretercontext.h"
#include <string>


std::string DisplayInformation::CODE_OUTPUT = "No information to display. Please run some code!";
std::string DisplayInformation::CODE_OUTPUT_RECONSTRUCTION = "No information to display. Please run some code!";
std::string DisplayInformation::PLACEHOLDER_CODE = "plot(tick(), 0)\nmark(tick() > 5 && tick() < 20, tick(), 0)";



std::vector<std::shared_ptr<VarSymbol>> DisplayInformation::CODE_OUTPUT_VARIABLES = {};

//std::vector<std::shared_ptr<ChartPlot>> ChartWindow::getOrCreateChartWindow(0).CHART_LINE_DATA = { };
//std::vector<std::shared_ptr<ChartPlot>> ChartWindow::getOrCreateChartWindow(0).CHART_MARK_DATA = { };

std::vector<std::shared_ptr<InputData>> DisplayInformation::LOADED_IN_DATA = { };

float DisplayInformation::MAX_CHART_Y = 0;
