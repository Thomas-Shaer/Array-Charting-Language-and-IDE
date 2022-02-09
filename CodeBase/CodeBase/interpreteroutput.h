#pragma once
#include <vector>
#include <iostream>
#include "languageexception.h"
#include <optional>

class ChartPlot;

struct InterpreterOutput {
	std::optional<LanguageException> langExcept = std::nullopt;
	//std::vector<std::shared_ptr<ChartPlot>> chartData;
	//std::vector<std::shared_ptr<ChartPlot>> markData;

};