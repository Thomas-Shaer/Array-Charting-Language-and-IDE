#include "displayinformation.h"
#include "interpretercontext.h"
#include <string>


std::string DisplayInformation::CODE_OUTPUT = "No information to display. Please run some code!";
std::string DisplayInformation::CODE_OUTPUT_RECONSTRUCTION = "No information to display. Please run some code!";
std::string DisplayInformation::CODE_OUTPUT_VARIABLES = "No information to display. Please run some code!";
std::string DisplayInformation::PLACEHOLDER_CODE = "plot(tick())\nmark(tick() > 5 && tick() < 20, tick())";
std::string DisplayInformation::CHART_DESCRIPTION = "Displaying 1 plot(s) of size " + std::to_string(plotList.size());


std::vector<std::vector<float>> DisplayInformation::CHART_LINE_DATA = { plotList };
std::vector<std::vector<float>> DisplayInformation::CHART_MARK_DATA = { };

std::vector<std::shared_ptr<InputData>> DisplayInformation::LOADED_IN_DATA = { };

float DisplayInformation::MAX_CHART_Y = 0;
