#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "expressionvalue.h"

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


	// parsed name of series (determined by column/row header)
	std::string name;
	// file name e.g. data.csv
	std::string fileName;
	// path to file e.g. C\\Users\\Tom\\data.csv
	std::string path;

	// how a true literal should be parsed for this data when reading from CSV
	std::string trueLiteral;
	// how a false literal should be parsed for this data when reading from CSV
	std::string falseLiteral;
	// how a null literal should be parsed for this data when reading from CSV
	std::string nanLiteral;

	// temporary storage of series data
	std::vector<ExpressionValue> data;

	// type of this series
	TypeSymbol* type;

	// import policy (parse instruction): column-wise or row-wise
	ImportPolicy importPolicy;

	// flag indicating if a variable has been made out of this series
	bool isVariable = false;
	// name of variable if this series has been turned into a variable
	std::string variableName;


private:
    /*
	Returns a ExpressionValue vector and TypeSymbol given a vector of strings.
	Will throw a DataParseException if the parsed strings are incompatible
	*/
	static std::pair<std::vector<ExpressionValue>, TypeSymbol*> parse(std::vector<std::string> rawValues, const std::string& TrueString, const std::string& FalseString, const std::string& NANString);
};