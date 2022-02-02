#pragma once
#include "global.h"
#include <vector>
#include <regex>


class TypeSymbol;

/*
* Stores all the necessary information for a variable, including it's type and value
*/

class VarSymbol {
public:
	const std::string name;
	const TypeSymbol* type;
	const bool modifiable;

	// size of buffer if imported
	const unsigned int originalSize;

	/*
	Constructor for variables created outside of the script.
	Verifies name is valid since not achieved through parser.
	Will throw a error if name not valid.
	Returns the new VarSymbol if valid.
	*/
	static std::shared_ptr<VarSymbol> createVarSymbol(const std::string _name, const TypeSymbol* _type, std::vector<ExpressionValue> _value);

	/*
	Constructor for variables created in code.

	FOR SYMMETRY PURPOSE - name is verified by parser anyway.
	Will throw a error if name not valid.
	Returns the new VarSymbol if valid.
	*/
	static std::shared_ptr<VarSymbol> createVarSymbol(const std::string _name, const TypeSymbol* _type);


	/*
	Returns true/false if the name is valid.
	*/
	static bool isValidName(const std::string _name);




	std::string toString();

	ExpressionValue getValue(const unsigned int i);
	void setValue(const unsigned int i, ExpressionValue _value);


	std::vector<ExpressionValue> getValues();
	void setValues(const std::vector<ExpressionValue>& values);

	/*
	Updates the size of the internal buffer array to match max ticks
	*/
	void matchGlobalBufferSize();

	bool exportVariable = false;
	std::string exportName;

	std::vector<ExpressionValue> buffer;


private:


	/*
	Imported code.
	Private because we want the name to be verified first prior to creation of VarSymbol.
	*/
	VarSymbol(const std::string _name, const TypeSymbol* _type, std::vector<ExpressionValue> _value);


	/*
	Constructor for a user defined variables.
	Private for symmetry to imported code constructor.
	The name is verified by the parser anyway.
	*/
	VarSymbol(const std::string _name, const TypeSymbol* _type);

};