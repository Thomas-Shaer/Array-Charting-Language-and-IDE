#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "global.h"

class TypeSymbol;

enum class ImportPolicy : unsigned int { COLUMN_WISE, ROW_WISE };

static ImportPolicy StringToImportPolicy(const std::string& name) {
	return name == "column-wise" ? ImportPolicy::COLUMN_WISE : ImportPolicy::ROW_WISE;
}

static std::string ImportPolicyToString(const ImportPolicy ip) {
	return ip == ImportPolicy::COLUMN_WISE ? "column-wise" : "row-wise";
}

class InputData {


public:


	static std::vector<std::shared_ptr<InputData>> LoadInputData(const ImportPolicy importPolicy, std::string name, std::string filename, const std::string& TrueString, const std::string& FalseString, const std::string& NANString);

	std::string name;
	std::string fileName;
	std::string path;

	std::string trueLiteral;
	std::string falseLiteral;
	std::string nanLiteral;

	std::vector<ExpressionValue> data;
	TypeSymbol* type;
	ImportPolicy importPolicy;
	//TypeInstances::

	bool isVariable = false;
	std::string variableName;
};