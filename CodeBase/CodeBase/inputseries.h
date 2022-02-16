#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "global.h"

class TypeSymbol;

enum class ImportPolicy : unsigned int { COLUMN_WISE, ROW_WISE };


/*
Intermediate storage for loaded in data visualised by the Data Manager Window.
Contains the data itself, file origins, how to parse it (col/row wise and boolean/null literal names)
*/

class InputSeries {

public:

	/*
	Converts string to import policy enum.
	*/
	static ImportPolicy StringToImportPolicy(const std::string& name);
	/*
	Converts import policy enum to string.
	*/
	static std::string ImportPolicyToString(const ImportPolicy ip);


	InputSeries(const std::string& _name, const std::string& _fileName, const std::string& _path, 
			  const std::string& _trueLiteral, const std::string& _falseLiteral, const std::string& _nanLiteral,
			  std::vector<ExpressionValue> _data, TypeSymbol* _type, ImportPolicy _importPolicy) 
		: name(_name), fileName(_fileName), path(_path), trueLiteral(_trueLiteral), falseLiteral(_falseLiteral), nanLiteral(_nanLiteral),
		  data(_data), type(_type), importPolicy(_importPolicy) {}

	/*
	Creates InputSeries vector from fileName
	*/
	static void LoadInputData(const ImportPolicy importPolicy, std::string name, std::string filename, const std::string& TrueString, const std::string& FalseString, const std::string& NANString);


	/*
	Creates and registers new variable on symbol table.
	*/
	void createNewVariable(const std::string& variableName);

	/*
	Deletes variable from symbol table.
	*/
	void deleteVariable();

	/*
	Renames a variable
	*/
	void renameVariable(const std::string& variableName);



	std::string name;
	std::string fileName;
	std::string path;

	std::string trueLiteral;
	std::string falseLiteral;
	std::string nanLiteral;

	std::vector<ExpressionValue> data;
	TypeSymbol* type;
	ImportPolicy importPolicy;

	bool isVariable = false;
	std::string variableName;


private:
    /*
	Returns a ExpressionValue vector and TypeSymbol given a vector of strings.
	Will throw a DataParseException if the parsed strings are incompatible
	*/
	static std::pair<std::vector<ExpressionValue>, TypeSymbol*> parse(std::vector<std::string> rawValues, const std::string& TrueString, const std::string& FalseString, const std::string& NANString);
};