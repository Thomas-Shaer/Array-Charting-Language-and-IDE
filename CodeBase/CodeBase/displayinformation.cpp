#include "displayinformation.h"
#include "interpretercontext.h"
#include <string>


std::string DisplayInformation::CODE_OUTPUT = "No information to display. Please run some code!";
std::string DisplayInformation::CODE_OUTPUT_RECONSTRUCTION = "No information to display. Please run some code!";
std::string DisplayInformation::CODE_OUTPUT_VARIABLES = "No information to display. Please run some code!";
std::string DisplayInformation::PLACEHOLDER_CODE = "x = 321\ny = 4 + 2\nplot(2)";
std::string DisplayInformation::CHART_DESCRIPTION = "Displaying 1 plot(s) of size " + std::to_string(plotList.size());


std::vector<std::vector<float>> DisplayInformation::CHART_LINE_DATA = { plotList };
std::vector<std::vector<float>> DisplayInformation::CHART_MARK_DATA = { };
