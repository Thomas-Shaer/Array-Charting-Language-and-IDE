#include "methodimplementations.h"
#include "typesymbol.h"
#include "visitors.h"
#include "interpretercontext.h"
#include "chartplot.h"
#include <numbers>
#include "languageexception.h"
#include <numeric>
#include <random>
#include "argumentsymbol.h"
#include "chartwindow.h"
#include "node.h"


MethodAverage::MethodAverage() : PositionalMethodSymbol("avg",
	"Returns the average of two numbers.",
	{

		ParameterSymbol(TypeInstances::GetNumberInstance(), "value1", "Argument 1 for average."),
ParameterSymbol(TypeInstances::GetNumberInstance(), "value2", "Argument 2 for average.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The average")) {}

const TypeSymbol* MethodAverage::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value1 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value1"]->expressionValue);
	value2 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value2"]->expressionValue);
	return returnType;
}


ExpressionValue MethodAverage::interpret(const unsigned int tick) {

	// if any argument is a NAN return NAN
	if (!value1->value || !value2->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber((*value1->value + *value2->value) / 2);
}


UnaryPlusOperator::UnaryPlusOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Propagates a expression.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "expr", "The expression to progate.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the propogation")) {}


const TypeSymbol* UnaryPlusOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["expr"]->expressionValue);
	return returnType;
}

ExpressionValue UnaryPlusOperator::interpret(const unsigned int tick) {
	// if arg is nan return a nan
	if (!value->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber(+*value->value);
}



UnaryMinusOperator::UnaryMinusOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Negates a expression.",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "expr", "The expression to negate.")

	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the negation")) {}


const TypeSymbol* UnaryMinusOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["expr"]->expressionValue);

	return returnType;


}

ExpressionValue UnaryMinusOperator::interpret(const unsigned int tick) {
	// if arg is nan return a nan
	if (!value->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber(-*value->value);
}

UnaryNotOperator::UnaryNotOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Negates a boolean expression.",
	{
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "expr", "The expression to negate.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the boolean negation")) {}


const TypeSymbol* UnaryNotOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["expr"]->expressionValue);
	return returnType;

}

ExpressionValue UnaryNotOperator::interpret(const unsigned int tick) {
	// if arg is nan return a nan
	if (!value->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(!*value->value);
}


BinaryPlusOperator::BinaryPlusOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Adds together two numbers.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the addition operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the addition operation.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the addition")) {}


const TypeSymbol* BinaryPlusOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;

}

ExpressionValue BinaryPlusOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber(*lhsValue->value + *rhsValue->value);
}

BinaryMinusOperator::BinaryMinusOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Minuses two numbers.",
	{

	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the minus operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the minus operation.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the negation")) {}


const TypeSymbol* BinaryMinusOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

ExpressionValue BinaryMinusOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber(*lhsValue->value - *rhsValue->value);
}

BinaryDivideOperator::BinaryDivideOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Divides two numbers.",
	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the division operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the division operation.")

	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the division")) {}


const TypeSymbol* BinaryDivideOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

ExpressionValue BinaryDivideOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber(*lhsValue->value / *rhsValue->value);
}

BinaryMultiplyOperator::BinaryMultiplyOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Multiplies two numbers.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the multiply operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the multiply operation.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the multiplication")) {}


const TypeSymbol* BinaryMultiplyOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}


ExpressionValue BinaryMultiplyOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber(*lhsValue->value * *rhsValue->value);
}




BinaryPowOperator::BinaryPowOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Raises number by power of another.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the power operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the power operation.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the power operator")) {}


const TypeSymbol* BinaryPowOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

ExpressionValue BinaryPowOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber(std::powf(*lhsValue->value, *rhsValue->value));
}



BinaryModOperator::BinaryModOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Applies modulus operator to number",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the modulus operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the modulus operation.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the modulus operator")) {}


const TypeSymbol* BinaryModOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

ExpressionValue BinaryModOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber(std::fmod(*lhsValue->value, *rhsValue->value));
}





BinaryLessOperator::BinaryLessOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs less than operator on two numbers.",
	{

	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the less than operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the less than operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the less then operation")) {}


const TypeSymbol* BinaryLessOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

ExpressionValue BinaryLessOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value < *rhsValue->value);
}

BinaryLessEqualOperator::BinaryLessEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs less than or equal operator on two numbers.",

	{

	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the less than or equal operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the less than or equal operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the less then or equal operation")) {}


const TypeSymbol* BinaryLessEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

ExpressionValue BinaryLessEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value <= *rhsValue->value);
}


BinaryGreaterOperator::BinaryGreaterOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs greater than operator on two numbers.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the greater than operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the greater than operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the greater then operation")) {}


const TypeSymbol* BinaryGreaterOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

ExpressionValue BinaryGreaterOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value > *rhsValue->value);
}

BinaryGreaterEqualOperator::BinaryGreaterEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,

	"Performs greater than or equal operator on two numbers.",
	{

	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the greater than or equal operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the greater than or equal operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the greater then or equal operation")) {}

const TypeSymbol* BinaryGreaterEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

ExpressionValue BinaryGreaterEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value >= *rhsValue->value);
}


BinaryAndOperator::BinaryAndOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs and operator on two booleans.",

	{

	ParameterSymbol(TypeInstances::GetBooleanInstance(), "lhs", "The left hand side of the and operation."),
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "rhs", "The rhs hand side of the and operation.")


	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of and operation")) {}


const TypeSymbol* BinaryAndOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

ExpressionValue BinaryAndOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value && *rhsValue->value);
}


BinaryOrOperator::BinaryOrOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs or operator on two booleans.",
	{
		ParameterSymbol(TypeInstances::GetBooleanInstance(), "lhs", "The left hand side of the or operation."),
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "rhs", "The rhs hand side of the or operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the or operation")) {}

const TypeSymbol* BinaryOrOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}


ExpressionValue BinaryOrOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value || *rhsValue->value);
}


BinaryBooleanEqualOperator::BinaryBooleanEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs equal operator on two booleans.",
	{
			ParameterSymbol(TypeInstances::GetBooleanInstance(), "lhs", "The left hand side of the equal operation."),
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "rhs", "The rhs hand side of the equal operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands equal")) {}


const TypeSymbol* BinaryBooleanEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

ExpressionValue BinaryBooleanEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value == *rhsValue->value);
}

BinaryFloatEqualOperator::BinaryFloatEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs equal operator on two floats.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the equal operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the equal operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands equal")) {}


const TypeSymbol* BinaryFloatEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

ExpressionValue BinaryFloatEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value == *rhsValue->value);
}


BinaryBooleanNotEqualOperator::BinaryBooleanNotEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs not equal operator on two booleans.",

	{
			ParameterSymbol(TypeInstances::GetBooleanInstance(), "lhs", "The left hand side of the not equal operation."),
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "rhs", "The rhs hand side of the not equal operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands not equal")) {}


const TypeSymbol* BinaryBooleanNotEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

ExpressionValue BinaryBooleanNotEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value != *rhsValue->value);
}

BinaryFloatNotEqualOperator::BinaryFloatNotEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,

	"Performs not equal operator on two floats.",

	{

				ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the not equal operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the not equal operation.")
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands not equal")) {}


const TypeSymbol* BinaryFloatNotEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

ExpressionValue BinaryFloatNotEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value != *rhsValue->value);
}



GetTick::GetTick() : PositionalMethodSymbol("tick",
	"Gets the current tick.",
	{ }, ReturnSymbol(TypeInstances::GetNumberInstance(), "The current tick")) {}


const TypeSymbol* GetTick::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}

ExpressionValue GetTick::interpret(const unsigned int tick) {
	return NullableValueNumber(tick);
}



Plot::Plot() : KeywordMethodSymbol("plot",
	"Plots a series of values onto the chart",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value that will be plotted at the current tick"),

	},
	{
	OptionalParameterSymbol(TypeInstances::GetStringConstantInstance(), NullableValueString(""), "name", "The name of the plot"),
	OptionalParameterSymbol(TypeInstances::GetStringConstantInstance(), NullableValueString(DEFAULT_CHART_WINDOW_ID), "chart_id", "The id of the chart to plot too.")

	}

	, ReturnSymbol(TypeInstances::GetVoidInstance())) {}



const TypeSymbol* Plot::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {

	const TypeSymbol* returnType = KeywordMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	lineName = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["name"]->expressionValue);
	chartId = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["chart_id"]->expressionValue);


	if (!InterpreterContext::isIntellisense) {
		std::shared_ptr<ChartPlot> newData = std::make_shared<ChartPlot>(*lineName->value, InterpreterContext::ticks);
		ChartWindow::getOrCreateChartWindow(*chartId->value)->CHART_LINE_DATA.push_back(newData);
		std::shared_ptr<ChartPlot> first = ChartWindow::getOrCreateChartWindow(*chartId->value)->CHART_LINE_DATA.back(); //returns reference, not iterator, to the first object in the vector so you had only to write the data type in the generic of your vector, i.e. myObject, and not all the iterator stuff and the vector again and :: of course
		plotdata = first;
	}
	return returnType;

}


ExpressionValue Plot::interpret(const unsigned int tick) {


	// if nan return a nan value else extract the correct value
	float pushBackValue = value->value ? *value->value : std::numeric_limits<double>::quiet_NaN();
	plotdata->data[tick] = pushBackValue;

	return NullableValueBoolean(true);
}



Mark::Mark() : KeywordMethodSymbol("mark",
	"Conditionally marks points on the chart when a condition is true.",

	{
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "when", "Mark the current tick or not"),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to mark if marking this tick"),
	},
	{
	OptionalParameterSymbol(TypeInstances::GetStringConstantInstance(), NullableValueString(""), "name", "The name of the plot"),
	OptionalParameterSymbol(TypeInstances::GetStringConstantInstance(), NullableValueString(DEFAULT_CHART_WINDOW_ID), "chart_id", "The id of the chart to plot too.")
	},
	ReturnSymbol(TypeInstances::GetVoidInstance())) {}




const TypeSymbol* Mark::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = KeywordMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	when = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["when"]->expressionValue);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	lineName = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["name"]->expressionValue);
	chartId = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["chart_id"]->expressionValue);


	if (!InterpreterContext::isIntellisense) {
		std::shared_ptr<ChartPlot> newData = std::make_shared<ChartPlot>(*lineName->value, InterpreterContext::ticks);

		ChartWindow::getOrCreateChartWindow(*chartId->value)->CHART_MARK_DATA.push_back(newData);
		std::shared_ptr<ChartPlot> first = ChartWindow::getOrCreateChartWindow(*chartId->value)->CHART_MARK_DATA.back(); //returns reference, not iterator, to the first object in the vector so you had only to write the data type in the generic of your vector, i.e. myObject, and not all the iterator stuff and the vector again and :: of course
		plotdata = first;
	}
	
	return returnType;
}

ExpressionValue Mark::interpret(const unsigned int tick) {
	//if not nan
	if (when->value) {

		// if positive
		if (*when->value) {

			float pushBackValue = value->value ? *value->value : std::numeric_limits<double>::quiet_NaN();
			plotdata->data[tick] = (pushBackValue);
		}
		else {
			plotdata->data[tick] = (std::numeric_limits<double>::quiet_NaN());
		}
	}
	else {
		plotdata->data[tick] = (std::numeric_limits<double>::quiet_NaN());
	}

	return NullableValueBoolean(true);
}



ValueWhen::ValueWhen() : PositionalMethodSymbol("valuewhen",
	"Stores and returns a value that only changes when the condition is true.",

	{
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "when", "When to update the current value."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to update it with.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The value last time the condition was true")) {}


const TypeSymbol* ValueWhen::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	when = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["when"]->expressionValue);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

ExpressionValue ValueWhen::interpret(const unsigned int tick) {
	if (when->value) {
		if (when->value) {
			currentValue = *value;
		}
	}

	return currentValue;
}






FloatNAN::FloatNAN() : PositionalMethodSymbol("nan_f",
	"Get a float NAN.",

	{ }, ReturnSymbol(TypeInstances::GetNumberInstance(), "NAN value")) {}

const TypeSymbol* FloatNAN::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}


ExpressionValue FloatNAN::interpret(const unsigned int tick) {
	return NullableValueNumber();
}


BooleanNAN::BooleanNAN() : PositionalMethodSymbol("nan_b",
	"Get a boolean NAN.",
	{ }, ReturnSymbol(TypeInstances::GetBooleanInstance(), "NAN value")) {}

const TypeSymbol* BooleanNAN::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}

ExpressionValue BooleanNAN::interpret(const unsigned int tick) {
	return NullableValueBoolean();
}


StringNAN::StringNAN() : PositionalMethodSymbol("nan_s",
	"Get a string NAN.",
	{ }, ReturnSymbol(TypeInstances::GetStringInstance(), "NullableValueString value")) {}

const TypeSymbol* StringNAN::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}

ExpressionValue StringNAN::interpret(const unsigned int tick) {
	return NullableValueString();
}



Minimum::Minimum() : PositionalMethodSymbol("min",
	"Returns the smallest value that has ever been passed to it.",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "Next potentially minimum value.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The maximum value.")) {}


const TypeSymbol* Minimum::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}



ExpressionValue Minimum::interpret(const unsigned int tick) {
	if (value->value) {
		if (*value->value < *value->value) {
			minimumValue = *value;
		}
	}

	return minimumValue;
}



MinimumBars::MinimumBars() : PositionalMethodSymbol("min",
	"Returns the smallest value that has ever been passed to it in the last bars_back bars",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "Next potentially minimum value."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "bars_back", "Next potentially minimum value.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The minimum value.")) {}


const TypeSymbol* MinimumBars::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["bars_back"]->expressionValue);
	barsBackNode = methodCallNode->expressionToArgList["bars_back"]->expression;
	return returnType;
}


ExpressionValue MinimumBars::interpret(const unsigned int tick) {
	if (bars_back->value) {
		int lookback = (int)*bars_back->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", moving minimum function must use positive non zero amount.", barsBackNode);
		}

		if (value->value) {
			buffer.push_back(*value->value);

			if (buffer.size() < lookback) {
				return NullableValueNumber();
			}

			float min = *std::min_element(buffer.begin(), buffer.end());

			buffer.pop_front();
			return NullableValueNumber(min);
		}
	}

	return NullableValueNumber();
}





Maximum::Maximum() : PositionalMethodSymbol("max",
	"Returns the max value that has ever been passed to it.",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "Next potentially maximum value.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The minimum value.")) {}


const TypeSymbol* Maximum::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

ExpressionValue Maximum::interpret(const unsigned int tick) {
	if (value->value) {
		if (*value->value > *value->value) {
			maximumValue = value;
		}
	}

	return maximumValue;
}



MaximumBars::MaximumBars() : PositionalMethodSymbol("max",
	"Returns the largest value that has ever been passed to it in the last bars_back bars",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "Next potentially maximum value."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "bars_back", "Next potentially maximum value.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The maximum value.")) {}


const TypeSymbol* MaximumBars::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["bars_back"]->expressionValue);
	barsBackNode = methodCallNode->expressionToArgList["bars_back"]->expression;

	return returnType;
}


ExpressionValue MaximumBars::interpret(const unsigned int tick) {
	if (bars_back->value) {
		int lookback = (int)*bars_back->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", moving maximum function must use positive non zero amount.", barsBackNode);
		}

		if (value->value) {
			buffer.push_back(*value->value);

			if (buffer.size() < lookback) {
				return NullableValueNumber();
			}

			float min = *std::max_element(buffer.begin(), buffer.end());

			buffer.pop_front();
			return NullableValueNumber(min);
		}
	}

	return NullableValueNumber();
}






Sum::Sum() : PositionalMethodSymbol("sum",
	"Returns the sum of the values passed to it so far",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "Add this to sum/")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The total sum.")) {}


const TypeSymbol* Sum::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

ExpressionValue Sum::interpret(const unsigned int tick) {
	if (value->value) {
		sum += *value->value;
	}

	return NullableValueNumber(sum);
}



SumBars::SumBars() : PositionalMethodSymbol("sum",
	"Returns the sum of the last bars_back bars",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "Current value"),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "bars_back", "Sum of bars back bars.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The sum.")) {}


const TypeSymbol* SumBars::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["bars_back"]->expressionValue);
	barsBackNode = methodCallNode->expressionToArgList["bars_back"]->expression;

	return returnType;
}


ExpressionValue SumBars::interpret(const unsigned int tick) {
	if (bars_back->value) {
		int lookback = (int)*bars_back->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", moving sum function must use positive non zero amount.", barsBackNode);
		}

		if (value->value) {
			buffer.push_back(*value->value);

			if (buffer.size() < lookback) {
				return NullableValueNumber();
			}

			float min = std::accumulate(buffer.begin(), buffer.end(), 0);

			buffer.pop_front();
			return NullableValueNumber(min);
		}
	}

	return NullableValueNumber();
}








Mean::Mean() : PositionalMethodSymbol("mean",
	"Returns the mean of values passed to it so far. (Doesn't take na values into account).",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to add to the mean calculation. (Will ignore NAs)")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The mean value so far.")) {}


const TypeSymbol* Mean::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}


ExpressionValue Mean::interpret(const unsigned int tick) {
	if (value->value) {
		amountSoFar++;
		sum += *value->value;
	}

	return NullableValueNumber(sum / amountSoFar);
}


GetPi::GetPi() : PositionalMethodSymbol("pi",
	"Gets the PI constant.",

	{
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The PI constant")) {}

const TypeSymbol* GetPi::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}


ExpressionValue GetPi::interpret(const unsigned int tick) {
	return NullableValueNumber(std::numbers::pi_v<float>);
}


GetE::GetE() : PositionalMethodSymbol("e",
	"Gets the E constant.",

	{
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The E constant")) {}


const TypeSymbol* GetE::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}


ExpressionValue GetE::interpret(const unsigned int tick) {
	return NullableValueNumber(std::numbers::e);
}


Round::Round() : PositionalMethodSymbol("round",
	"Rounds to nearest int. Returns NA if NA passed.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to round")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The rounded value")) {}


const TypeSymbol* Round::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

ExpressionValue Round::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueNumber(std::round(*value->value));
	}

	return NullableValueNumber();
}




Floor::Floor() : PositionalMethodSymbol("floor",
	"Floors value",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to floor")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The floored value")) {}


const TypeSymbol* Floor::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

ExpressionValue Floor::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueNumber(std::floor(*value->value));
	}

	return NullableValueNumber();
}



Ceil::Ceil() : PositionalMethodSymbol("ceil",
	"Ceils value",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to ceil")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The ceiled value")) {}


const TypeSymbol* Ceil::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

ExpressionValue Ceil::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueNumber(std::ceil(*value->value));
	}

	return NullableValueNumber();
}



FloatMax::FloatMax() : PositionalMethodSymbol("floatmax",
	"The max float value",

	{
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The largest possible float value")) {}

const TypeSymbol* FloatMax::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}


ExpressionValue FloatMax::interpret(const unsigned int tick) {

	return NullableValueNumber((std::numeric_limits<float>::max)());
}


FloatMin::FloatMin() : PositionalMethodSymbol("floatmin",
	"The minimum float value",

	{
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The smallest possible float value")) {}


const TypeSymbol* FloatMin::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}

ExpressionValue FloatMin::interpret(const unsigned int tick) {

	return NullableValueNumber((std::numeric_limits<float>::min)());
}



Count::Count() : PositionalMethodSymbol("count",
	"The amount of times a condition has been true.",

	{
		ParameterSymbol(TypeInstances::GetBooleanInstance(), "condition", "The condition to count.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The amount of times that condition has been true.")) {}


const TypeSymbol* Count::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["condition"]->expressionValue);
	return returnType;
}


ExpressionValue Count::interpret(const unsigned int tick) {

	if (value->value) {
		if (*value->value) {
			count++;
		}
	}

	return NullableValueNumber(count);
}


FloatCast::FloatCast() : PositionalMethodSymbol("float",
	"Casts value to a float.",

	{
		ParameterSymbol(TypeInstances::GetBooleanInstance(), "value", "The value to convert")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The value as a float.")) {}


const TypeSymbol* FloatCast::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

ExpressionValue FloatCast::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueNumber(*value->value);
	}

	return NullableValueNumber();
}



BooleanCast::BooleanCast() : PositionalMethodSymbol("boolean",
	"Casts value to a boolea.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to convert")
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "The value as a boolean.")) {}


const TypeSymbol* BooleanCast::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

ExpressionValue BooleanCast::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueBoolean(*value->value);
	}

	return NullableValueBoolean();
}




Absolute::Absolute() : PositionalMethodSymbol("abs",
	"Returns the abs of a value.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to abs.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The value as a abs.")) {}


const TypeSymbol* Absolute::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}


ExpressionValue Absolute::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueNumber(std::abs(*value->value));
	}

	return NullableValueNumber();
}




LogE::LogE() : PositionalMethodSymbol("log",
	"Returns the natural base-e log of a number. Can throw a run time error if <= 0.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to log. Has to be positive non-zero value.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The logged value")) {}


const TypeSymbol* LogE::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	valueNode = methodCallNode->expressionToArgList["value"]->expression;
	return returnType;
}

ExpressionValue LogE::interpret(const unsigned int tick) {

	if (value->value) {
		if (*value->value <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", log function must use positive non zero value.", valueNode);
		}
		return NullableValueNumber(std::log(*value->value));
	}

	return NullableValueNumber();
}



LogBase::LogBase() : PositionalMethodSymbol("log",
	"Returns the log of a number given a base. Can throw a run time error if <= 0.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to log. Has to be positive non-zero value."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "base", "The base of the log. Has to be positive non-zero value.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The logged value.")) {}


const TypeSymbol* LogBase::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	base = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["base"]->expressionValue);
	valueNode = methodCallNode->expressionToArgList["value"]->expression;
	baseNode = methodCallNode->expressionToArgList["base"]->expression;

	return returnType;
}

ExpressionValue LogBase::interpret(const unsigned int tick) {

	if (value->value) {
		if (*value->value <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", log function must use positive non zero value.", valueNode);
		}
	}
	if (base->value) {
		if (*base->value <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", log function must use positive non zero base.", baseNode);
		}
		return NullableValueNumber(log(*value->value) / log(*base->value));
	}

	return NullableValueNumber();
}



SquareRoot::SquareRoot() : PositionalMethodSymbol("sqrt",
	"Returns the square root of a number. ",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to root. Must be a positive number."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The rooted value.")) {}


const TypeSymbol* SquareRoot::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	valueNode = methodCallNode->expressionToArgList["value"]->expression;
	return returnType;
}

ExpressionValue SquareRoot::interpret(const unsigned int tick) {

	if (value->value) {
		if (*value->value < 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", log function must use positive zero value.", valueNode);
		}

		return NullableValueNumber(std::sqrt(*value->value));
	}

	return NullableValueNumber();
}



LCM::LCM() : PositionalMethodSymbol("lcm",
	"Returns the lowest common multiple of two numbers. Note: converts both numbers to ints.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value1", "The LCM value 1."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value2", "The LCM value 2."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The LCM.")) {}


const TypeSymbol* LCM::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value1 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value1"]->expressionValue);
	value2 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value2"]->expressionValue);
	return returnType;
}

ExpressionValue LCM::interpret(const unsigned int tick) {

	if (value1->value && value2->value) {

		return NullableValueNumber(std::lcm((int)*value1->value, (int)*value2->value));
	}

	return NullableValueNumber();
}



GCD::GCD() : PositionalMethodSymbol("gcd",
	"Returns the greatest common divider of two numbers. Note: converts both numbers to ints.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value1", "The GCD value 1."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value2", "The GCD value 2."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The GCD.")) {}


const TypeSymbol* GCD::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value1 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value1"]->expressionValue);
	value2 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value2"]->expressionValue);
	return returnType;
}

ExpressionValue GCD::interpret(const unsigned int tick) {

	if (value1->value && value2->value) {

		return NullableValueNumber(std::gcd((int)*value1->value, (int)*value2->value));
	}

	return NullableValueNumber();
}



Variance::Variance() : PositionalMethodSymbol("variance",
	"Returns the variance of a value.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "amount", "Amount values must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The variance of the data.")) {}


const TypeSymbol* Variance::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	amount = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["amount"]->expressionValue);
	amountNode = methodCallNode->expressionToArgList["amount"]->expression;

	return returnType;
}

ExpressionValue Variance::interpret(const unsigned int tick) {
	if (amount->value) {
		int lookback = (int)*amount->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", variance function must use positive non zero amount.", amountNode);
		}

		if (value->value) {
			buffer.push_back(*value->value);

			if (buffer.size() < lookback) {
				return NullableValueNumber();
			}

			float sum = std::accumulate(buffer.begin(), buffer.end(), 0);
			float mean = sum / buffer.size();

			float variance = 0;
			for (int i = buffer.size() - 1; i >= 0; i--) {
				variance += std::pow(buffer[i] - mean, 2);
			}
			variance = variance / buffer.size();
			buffer.pop_front();
			return NullableValueNumber(variance);
		}
	}

	return NullableValueNumber();
}




STD::STD() : PositionalMethodSymbol("std",
	"Returns the std of a value.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "amount", "Amount values must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The std of the data.")) {}

const TypeSymbol* STD::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	amount = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["amount"]->expressionValue);
	amountNode = methodCallNode->expressionToArgList["amount"]->expression;

	return returnType;
}


ExpressionValue STD::interpret(const unsigned int tick) {


	if (amount->value) {
		int lookback = (int)*amount->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", variance function must use positive non zero amount.", amountNode);
		}

		if (value->value) {
			buffer.push_back(*value->value);

			if (buffer.size() < lookback) {
				return NullableValueNumber();
			}

			float sum = std::accumulate(buffer.begin(), buffer.end(), 0);
			float mean = sum / buffer.size();

			float variance = 0;
			for (int i = buffer.size() - 1; i >= 0; i--) {
				variance += std::pow(buffer[i] - mean, 2);
			}
			variance = variance / buffer.size();
			buffer.pop_front();
			return NullableValueNumber(std::sqrt(variance));
		}
	}

	return NullableValueNumber();
}




MA::MA() : PositionalMethodSymbol("ma",
	"Returns the moving average of a value.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "amount", "Amount values must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The moving average of the data.")) {}


const TypeSymbol* MA::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	amount = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["amount"]->expressionValue);
	amountNode = methodCallNode->expressionToArgList["amount"]->expression;

	return returnType;
}

ExpressionValue MA::interpret(const unsigned int tick) {
	if (amount->value) {
		int lookback = (int)*amount->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", moving average function must use positive non zero amount.", amountNode);
		}

		if (value->value) {
			buffer.push_back(*value->value);

			if (buffer.size() < lookback) {
				return NullableValueNumber();
			}

			float sum = std::accumulate(buffer.begin(), buffer.end(), 0);
			float mean = sum / buffer.size();

			buffer.pop_front();
			return NullableValueNumber(mean);
		}
	}

	return NullableValueNumber();
}




IsNANF::IsNANF() : PositionalMethodSymbol("isnan",
	"Returns true if float value is NAN",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to test"),
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Whether the value is NAN or not")) {}


const TypeSymbol* IsNANF::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}


ExpressionValue IsNANF::interpret(const unsigned int tick) {
	return NullableValueBoolean((bool)!value->value);
}


IsNANB::IsNANB() : PositionalMethodSymbol("isnan",
	"Returns true if boolean value is NAN",

	{
		ParameterSymbol(TypeInstances::GetBooleanInstance(), "value", "The value to test"),
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Whether the value is NAN or not")) {}


const TypeSymbol* IsNANB::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

ExpressionValue IsNANB::interpret(const unsigned int tick) {
	return NullableValueBoolean((bool)!value->value);
}




IsNANS::IsNANS() : PositionalMethodSymbol("isnan",
	"Returns true if string value is NAN",

	{
		ParameterSymbol(TypeInstances::GetStringInstance(), "value", "The value to test"),
	}, ReturnSymbol(TypeInstances::GetStringInstance(), "Whether the value is NAN or not")) {}


const TypeSymbol* IsNANS::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

ExpressionValue IsNANS::interpret(const unsigned int tick) {
	return NullableValueBoolean((bool)!value->value);
}





Random::Random() : PositionalMethodSymbol("random",
	"Returns random value between the two ranges",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "minvalue", "The minimum range (will be casted to int)."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "maxvalue", "The maximum range (will be casted to int)."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The random number in the range.")) {}


const TypeSymbol* Random::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	minvalue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["minvalue"]->expressionValue);
	maxvalue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["maxvalue"]->expressionValue);
	return returnType;
}

ExpressionValue Random::interpret(const unsigned int tick) {
	if (!minvalue->value) {
		return NullableValueNumber();
	}
	if (!maxvalue->value) {
		return NullableValueNumber();
	}

	std::random_device seeder;
	std::mt19937 engine(seeder());
	std::uniform_int_distribution<int> dist((int)*minvalue->value, (int)*maxvalue->value);
	int compGuess = dist(engine);

	return NullableValueNumber(compGuess);
}



Falling::Falling() : PositionalMethodSymbol("falling",
	"Returns true if data has been dropping for n bars in a row.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "amount", "Amount bars must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "True or false if it has been falling for n bars in a row.")) {}


const TypeSymbol* Falling::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	amount = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["amount"]->expressionValue);
	amountNode = methodCallNode->expressionToArgList["amount"]->expression;

	return returnType;
}

ExpressionValue Falling::interpret(const unsigned int tick) {
	if (amount->value) {
		int lookback = (int)*amount->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", falling function must use positive non zero amount.", amountNode);
		}

		if (value->value) {
			float newVal = *value->value;
			if (newVal < currentMin) {
				inRow++;
			}
			else {
				inRow = 0;
			}
			currentMin = newVal;

			if (inRow >= lookback) {
				return NullableValueBoolean(true);
			}
			return NullableValueBoolean(false);
		}
	}

	return NullableValueBoolean();
}



Rising::Rising() : PositionalMethodSymbol("rising",
	"Returns true if data has been rising for n bars in a row.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "amount", "Amount bars must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "True or false if it has been rising for n bars in a row.")) {}


const TypeSymbol* Rising::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	amount = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["amount"]->expressionValue);
	amountNode = methodCallNode->expressionToArgList["amount"]->expression;

	return returnType;
}

ExpressionValue Rising::interpret(const unsigned int tick) {
	if (amount->value) {
		int lookback = (int)*amount->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", rising function must use positive non zero amount.", amountNode);
		}

		if (value->value) {
			float newVal = *value->value;
			if (newVal > currentMax) {
				inRow++;
			}
			else {
				inRow = 0;
			}
			currentMax = newVal;

			if (inRow >= lookback) {
				return NullableValueBoolean(true);
			}
			return NullableValueBoolean(false);
		}
	}

	return NullableValueBoolean();
}



Cosine::Cosine() : PositionalMethodSymbol("cos",
	"Returns the cosine of x radians. If NAN supplied, will return NAN.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The consine of the parameter input.")) {}

const TypeSymbol* Cosine::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["radians"]->expressionValue);
	return returnType;
}


ExpressionValue Cosine::interpret(const unsigned int tick) {
	if (radians->value) {
		return NullableValueNumber(std::cos(*radians->value));
	}

	return NullableValueNumber();
}



Tangent::Tangent() : PositionalMethodSymbol("tan",
	"Returns the tangent of x radians. If NAN supplied, will return NAN.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The tangent of the parameter input.")) {}


const TypeSymbol* Tangent::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["radians"]->expressionValue);
	return returnType;
}


ExpressionValue Tangent::interpret(const unsigned int tick) {
	if (radians->value) {
		return NullableValueNumber(std::tan(*radians->value));
	}

	return NullableValueNumber();
}



Sine::Sine() : PositionalMethodSymbol("sin",
	"Returns the sine of x radians. If NAN supplied, will return NAN.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The sine of the parameter input.")) {}


const TypeSymbol* Sine::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["radians"]->expressionValue);
	return returnType;
}

ExpressionValue Sine::interpret(const unsigned int tick) {
	if (radians->value) {
		return NullableValueNumber(std::sin(*radians->value));
	}

	return NullableValueNumber();
}


ArcCosine::ArcCosine() : PositionalMethodSymbol("acos",
	"Returns the arc cosine of x radians. If NAN supplied, will return NAN.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The arc cosine of the parameter input.")) {}


const TypeSymbol* ArcCosine::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["radians"]->expressionValue);
	return returnType;
}

ExpressionValue ArcCosine::interpret(const unsigned int tick) {
	if (radians->value) {
		return NullableValueNumber(std::acos(*radians->value));
	}

	return NullableValueNumber();
}




ArcTan::ArcTan() : PositionalMethodSymbol("atan",
	"Returns the arc tangent of x radians. If NAN supplied, will return NAN.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The arc tangent of the parameter input.")) {}


const TypeSymbol* ArcTan::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["radians"]->expressionValue);
	return returnType;
}


ExpressionValue ArcTan::interpret(const unsigned int tick) {
	if (radians->value) {
		return NullableValueNumber(std::atan(*radians->value));
	}

	return NullableValueNumber();
}





ArcSine::ArcSine() : PositionalMethodSymbol("asin",
	"Returns the arc sine of x radians. If NAN supplied, will return NAN.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The arc sine of the parameter input.")) {}


const TypeSymbol* ArcSine::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["radians"]->expressionValue);
	return returnType;
}

ExpressionValue ArcSine::interpret(const unsigned int tick) {
	if (radians->value) {
		return NullableValueNumber(std::asin(*radians->value));
	}

	return NullableValueNumber();
}


LinearRegression::LinearRegression() : PositionalMethodSymbol("linreg",
	"Returns the rolling linear regression of last n bars.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "data", "The data we are using in the prediction"),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "bars", "The amount of bars to perform the calculation on"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The y level of the linear regression")) {}

const TypeSymbol* LinearRegression::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	bars = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["bars"]->expressionValue);
	barsNode = methodCallNode->expressionToArgList["bars"]->expression;

	return returnType;
}

/*
WARNING. If look back changes value this will return the wrong value!
*/
ExpressionValue LinearRegression::interpret(const unsigned int tick) {
	if (bars->value) {
		int lookback = (int)*bars->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", linear regression function must use positive non zero amount.", barsNode);
		}


		if (data->value) {
			bufferX.push_back(tick);
			bufferY.push_back(*data->value);

			if (bufferX.size() < lookback) {
				return NullableValueNumber();
			}
		https://towardsdatascience.com/linear-regression-using-least-squares-a4c3456e8570

			float meanX = std::accumulate(bufferX.begin(), bufferX.end(), 0) / bufferX.size();
			float meanY = std::accumulate(bufferY.begin(), bufferY.end(), 0) / bufferY.size();

			float num = 0;
			float den = 0;
			for (int i = 0; i < bufferX.size(); i++) {

				num += (bufferX.at(i) - meanX) * (bufferY.at(i) - meanY);
				den += std::pow(bufferX.at(i) - meanX, 2);
			}
			float m = num / den;
			float c = meanY - m * meanX;

			bufferX.pop_front();
			bufferY.pop_front();
			return NullableValueNumber((m * tick) + c);
		}

	}

	return NullableValueNumber();
}





Correlation::Correlation() : PositionalMethodSymbol("correlation",
	"Returns the correlation of two data sources in the last n bars.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "data1", "The first data source"),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "data2", "The second data source"),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "length", "The amount of bars to perform the calculation on"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The correlation")) {}


const TypeSymbol* Correlation::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data1 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data1"]->expressionValue);
	data2 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data2"]->expressionValue);
	length = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["length"]->expressionValue);
	lengthNode = methodCallNode->expressionToArgList["length"]->expression;
	return returnType;
}


/*
WARNING. If look back changes value this will return the wrong value!
*/
ExpressionValue Correlation::interpret(const unsigned int tick) {
	if (length->value) {
		float lookback = (int)*length->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", linear regression function must use positive non zero amount.", lengthNode);
		}


		if (data1->value && data2->value) {
			values1.push_back(*data1->value);
			values2.push_back(*data2->value);

			if (values1.size() < lookback) {
				return NullableValueNumber();
			}
			//https://tutorialspoint.dev/algorithm/mathematical-algorithms/program-find-correlation-coefficient

			int sum_X = 0, sum_Y = 0, sum_XY = 0;
			int squareSum_X = 0, squareSum_Y = 0;

			for (int i = 0; i < lookback; i++)
			{
				// sum of elements of array X. 
				sum_X = sum_X + values1[i];

				// sum of elements of array Y. 
				sum_Y = sum_Y + values2[i];

				// sum of X[i] * Y[i]. 
				sum_XY = sum_XY + values1[i] * values2[i];

				// sum of square of array elements. 
				squareSum_X = squareSum_X + values1[i] * values1[i];
				squareSum_Y = squareSum_Y + values2[i] * values2[i];
			}

			// use formula for calculating correlation coefficient. 
			float corr = (float)((lookback * sum_XY) - (sum_X * sum_Y))
				/ sqrt((lookback * squareSum_X - sum_X * sum_X)
					* (lookback * squareSum_Y - sum_Y * sum_Y));
			values1.pop_front();
			values2.pop_front();
			return NullableValueNumber(corr);
		}

	}

	return NullableValueNumber();
}









PreviousValue::PreviousValue() : PositionalMethodSymbol("prev",
	"Gets the previous value. Lookback will return the last nth non-NAN value.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "data", "Series of data to retreive value for (stores it every time its called)."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "barsback", "The amount of bars back to retrieve the value")

	}, ReturnSymbol(TypeInstances::GetNumberInstance())) {}


const TypeSymbol* PreviousValue::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	barsback = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["barsback"]->expressionValue);
	barsbackNode = methodCallNode->expressionToArgList["barsback"]->expression;
	return returnType;
}


ExpressionValue PreviousValue::interpret(const unsigned int tick) {

	if (data->value) {
		values.push_back(*data);
	}

	if (barsback->value) {
		int lookback = (int)*barsback->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", previous function must use positive non zero amount.", barsbackNode);
		}


		if (values.size() > lookback) {
			return values[tick - lookback];
		}
		return NullableValueNumber();

	}

	return NullableValueNumber();
}


// https://stackoverflow.com/questions/15843525/how-do-you-insert-the-value-in-a-sorted-vector
template< typename T >
typename std::vector<T>::iterator
insert_sorted(std::vector<T>& vec, T const& item)
{
	return vec.insert
	(
		std::upper_bound(vec.begin(), vec.end(), item),
		item
	);
}




Median::Median() : PositionalMethodSymbol("median",
	"Returns the median value. Ignores NAN values.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "data", "Data to perform median on."),

	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The median value")) {}


const TypeSymbol* Median::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	return returnType;
}


ExpressionValue Median::interpret(const unsigned int tick) {

	if (!data->value) {
		return NullableValueNumber();
	}

	insert_sorted(values, *data->value);

	if (values.size() % 2 == 0)
	{
		return NullableValueNumber((values[values.size() / 2 - 1] + values[values.size() / 2]) / 2);
	}

	return NullableValueNumber(values[values.size() / 2]);
}



MedianBars::MedianBars() : PositionalMethodSymbol("median",
	"Returns the rolling median value. Ignores NAN values.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "data", "Data to perform median on."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "barsback", "Range of bars to consider for median"),

	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The median value")) {}

const TypeSymbol* MedianBars::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	barsback = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["barsback"]->expressionValue);
	return returnType;
}


ExpressionValue MedianBars::interpret(const unsigned int tick) {

	if (!data->value) {
		return NullableValueNumber();
	}

	if (!barsback->value) {
		return NullableValueNumber();
	}


	values.push_back(*data->value);

	int lookback = *barsback->value;
	if (values.size() >= lookback) {
		std::vector<float> new_vec(values.end() - lookback, values.end());
		std::sort(new_vec.begin(), new_vec.end());
		if (new_vec.size() % 2 == 0)
		{
			return NullableValueNumber((new_vec[new_vec.size() / 2 - 1] + new_vec[new_vec.size() / 2]) / 2);
		}

		return NullableValueNumber(new_vec[new_vec.size() / 2]);
	}

	return NullableValueNumber();
}




IsPrime::IsPrime() : PositionalMethodSymbol("isprime",
	"Returns true or false if it is a prime number. Will be converted to a integer. Ignores NAN values.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "data", "Data to check if prime."),

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Is prime or not.")) {}



const TypeSymbol* IsPrime::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	return returnType;
}



ExpressionValue IsPrime::interpret(const unsigned int tick) {

	if (!data->value) {
		return NullableValueBoolean();
	}

	int n = *data->value;

	//https://www.geeksforgeeks.org/c-program-to-check-prime-number/
	// Corner case
	if (n <= 1)
		return NullableValueBoolean(false);

	// Check from 2 to n-1
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return NullableValueBoolean(false);

	return NullableValueBoolean(true);
}



IsTriangle::IsTriangle() : PositionalMethodSymbol("istriangle",
	"Returns true or false if it is a triangle number. Will be converted to a integer. Ignores NAN values.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "data", "Data to check if triangle."),

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Is triangle or not.")) {}

const TypeSymbol* IsTriangle::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	return returnType;
}

ExpressionValue IsTriangle::interpret(const unsigned int tick) {

	if (!data->value) {
		return NullableValueBoolean();
	}

	int n = *data->value;

	//https://stackoverflow.com/questions/2913215/fastest-method-to-define-whether-a-number-is-a-triangular-number

	if (n < 0)
		return NullableValueBoolean(false);

	for (int i = 0; i < n; i++) {
		if (i * (i + 1) / 2 == n) {
			return NullableValueBoolean(true);
		}
	}

	return NullableValueBoolean(false);
}