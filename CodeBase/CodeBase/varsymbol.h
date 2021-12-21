#pragma once
#include "global.h"
#include <vector>


class TypeSymbol;

/*
* Stores all the necessary information for a variable, including it's type and value
*/

class VarSymbol {
public:
	const std::string name;
	const TypeSymbol* type;

	VarSymbol(const std::string _name, const TypeSymbol* _type);
	VarSymbol(const std::string _name, const TypeSymbol* _type, std::vector<ExpressionValue> _value);


	std::string toString();

	ExpressionValue getValue(const unsigned int i);
	void setValue(const unsigned int i, ExpressionValue _value);


	std::vector<ExpressionValue> getValues();
	void setValues(const std::vector<ExpressionValue>& values);

	/*
	Updates the size of the internal buffer array to match max ticks
	*/
	void matchGlobalBufferSize();

private:
	std::vector<ExpressionValue> buffer;

};