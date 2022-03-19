#include "methodimplementations.h"
#include "typesymbol.h"

#include "interpretercontext.h"

#include "chartwindow.h"
#include "node.h"


MethodAverage::MethodAverage() : PositionalMethodSymbol("avg",
	"Returns the average of two numbers.",
	{

		ParameterSymbol(TypeInstances::GetNumberInstance(), "value1", "Argument 1 for average."),
ParameterSymbol(TypeInstances::GetNumberInstance(), "value2", "Argument 2 for average.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The average")) {}




UnaryPlusOperator::UnaryPlusOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Propagates a expression.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "expr", "The expression to progate.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the propogation")) {}






UnaryMinusOperator::UnaryMinusOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Negates a expression.",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "expr", "The expression to negate.")

	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the negation")) {}






UnaryNotOperator::UnaryNotOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Negates a boolean expression.",
	{
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "expr", "The expression to negate.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the boolean negation")) {}





BinaryPlusOperator::BinaryPlusOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Adds together two numbers.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the addition operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the addition operation.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the addition")) {}



BinaryStringConcat::BinaryStringConcat(const std::string& _name) : PositionalMethodSymbol(_name,
	"Concatenate two strings.",
	{
	ParameterSymbol(TypeInstances::GetStringInstance(), "lhs", "The left hand side of the concat operation."),
	ParameterSymbol(TypeInstances::GetStringInstance(), "rhs", "The rhs hand side of the concat operation.")
	}, ReturnSymbol(TypeInstances::GetStringInstance(), "Result of the concatenation")) {}


BinaryMinusOperator::BinaryMinusOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Minuses two numbers.",
	{

	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the minus operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the minus operation.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the negation")) {}






BinaryDivideOperator::BinaryDivideOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Divides two numbers.",
	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the division operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the division operation.")

	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the division")) {}





BinaryMultiplyOperator::BinaryMultiplyOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Multiplies two numbers.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the multiply operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the multiply operation.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the multiplication")) {}








BinaryPowOperator::BinaryPowOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Raises number by power of another.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the power operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the power operation.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the power operator")) {}






BinaryModOperator::BinaryModOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Applies modulus operator to number",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the modulus operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the modulus operation.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "Result of the modulus operator")) {}





BinaryLessOperator::BinaryLessOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs less than operator on two numbers.",
	{

	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the less than operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the less than operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the less then operation")) {}




BinaryLessEqualOperator::BinaryLessEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs less than or equal operator on two numbers.",

	{

	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the less than or equal operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the less than or equal operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the less then or equal operation")) {}




BinaryGreaterOperator::BinaryGreaterOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs greater than operator on two numbers.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the greater than operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the greater than operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the greater then operation")) {}



BinaryGreaterEqualOperator::BinaryGreaterEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,

	"Performs greater than or equal operator on two numbers.",
	{

	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the greater than or equal operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the greater than or equal operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the greater then or equal operation")) {}




BinaryAndOperator::BinaryAndOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs and operator on two booleans.",

	{

	ParameterSymbol(TypeInstances::GetBooleanInstance(), "lhs", "The left hand side of the and operation."),
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "rhs", "The rhs hand side of the and operation.")


	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of and operation")) {}





BinaryOrOperator::BinaryOrOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs or operator on two booleans.",
	{
		ParameterSymbol(TypeInstances::GetBooleanInstance(), "lhs", "The left hand side of the or operation."),
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "rhs", "The rhs hand side of the or operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the or operation")) {}



BinaryBooleanEqualOperator::BinaryBooleanEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs equal operator on two booleans.",
	{
			ParameterSymbol(TypeInstances::GetBooleanInstance(), "lhs", "The left hand side of the equal operation."),
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "rhs", "The rhs hand side of the equal operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands equal")) {}





BinaryFloatEqualOperator::BinaryFloatEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs equal operator on two numbers.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the equal operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the equal operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands equal")) {}



BinaryStringEqualOperator::BinaryStringEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs equal operator on two strings.",
	{
	ParameterSymbol(TypeInstances::GetStringInstance(), "lhs", "The left hand side of the equal operation."),
	ParameterSymbol(TypeInstances::GetStringInstance(), "rhs", "The rhs hand side of the equal operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands equal")) {}




BinaryBooleanNotEqualOperator::BinaryBooleanNotEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,
	"Performs not equal operator on two booleans.",

	{
			ParameterSymbol(TypeInstances::GetBooleanInstance(), "lhs", "The left hand side of the not equal operation."),
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "rhs", "The rhs hand side of the not equal operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands not equal")) {}



BinaryFloatNotEqualOperator::BinaryFloatNotEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,

	"Performs not equal operator on two numbers.",

	{

				ParameterSymbol(TypeInstances::GetNumberInstance(), "lhs", "The left hand side of the not equal operation."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "rhs", "The rhs hand side of the not equal operation.")
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands not equal")) {}



BinaryStringNotEqualOperator::BinaryStringNotEqualOperator(const std::string& _name) : PositionalMethodSymbol(_name,

	"Performs not equal operator on two strings.",

	{

				ParameterSymbol(TypeInstances::GetStringInstance(), "lhs", "The left hand side of the not equal operation."),
	ParameterSymbol(TypeInstances::GetStringInstance(), "rhs", "The rhs hand side of the not equal operation.")
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands not equal")) {}




GetTick::GetTick() : PositionalMethodSymbol("tick",
	"Gets the current tick.",
	{ }, ReturnSymbol(TypeInstances::GetNumberInstance(), "The current tick")) {}




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




Text::Text() : KeywordMethodSymbol("text",
	"Conditionally draws text on the chart when a condition is true.",

	{
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "when", "Mark the current tick or not"),
	ParameterSymbol(TypeInstances::GetStringInstance(), "value", "The value to mark if marking this tick"),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "ylevel", "The ylevel to plot the text at"),
	},
	{
	OptionalParameterSymbol(TypeInstances::GetBooleanInstance(), NullableValueBoolean(false), "vertical", "Should text be vertical."),
	OptionalParameterSymbol(TypeInstances::GetStringConstantInstance(), NullableValueString(""), "name", "The name of the plot"),
	OptionalParameterSymbol(TypeInstances::GetStringConstantInstance(), NullableValueString(DEFAULT_CHART_WINDOW_ID), "chart_id", "The id of the chart to plot too.")
	},
	ReturnSymbol(TypeInstances::GetVoidInstance())) {}





ValueWhenNumber::ValueWhenNumber() : PositionalMethodSymbol("valuewhen",
	"Stores and returns a value that only changes when the condition is true.",

	{
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "when", "When to update the current value."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to update it with.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The value last time the condition was true")) {}


ValueWhenString::ValueWhenString() : PositionalMethodSymbol("valuewhen",
	"Stores and returns a value that only changes when the condition is true.",

	{
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "when", "When to update the current value."),
	ParameterSymbol(TypeInstances::GetStringInstance(), "value", "The value to update it with.")


	}, ReturnSymbol(TypeInstances::GetStringInstance(), "The value last time the condition was true")) {}


ValueWhenBoolean::ValueWhenBoolean() : PositionalMethodSymbol("valuewhen",
	"Stores and returns a value that only changes when the condition is true.",

	{
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "when", "When to update the current value."),
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "value", "The value to update it with.")


	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "The value last time the condition was true")) {}





NumberNull::NumberNull() : PositionalMethodSymbol("null_n",
	"Get a number null.",

	{ }, ReturnSymbol(TypeInstances::GetNumberInstance(), "Null value")) {}




BooleanNull::BooleanNull() : PositionalMethodSymbol("null_b",
	"Get a boolean null.",
	{ }, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Null value")) {}





StringNull::StringNull() : PositionalMethodSymbol("null_s",
	"Get a string null.",
	{ }, ReturnSymbol(TypeInstances::GetStringInstance(), "Null value")) {}





Minimum::Minimum() : PositionalMethodSymbol("min",
	"Returns the smallest value that has ever been passed to it.",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "Next potentially minimum value.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The maximum value.")) {}








MinimumBars::MinimumBars() : PositionalMethodSymbol("min",
	"Returns the smallest value that has ever been passed to it in the last bars_back bars",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "Next potentially minimum value."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "bars_back", "Next potentially minimum value.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The minimum value.")) {}







Maximum::Maximum() : PositionalMethodSymbol("max",
	"Returns the max value that has ever been passed to it.",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "Next potentially maximum value.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The minimum value.")) {}





MaximumBars::MaximumBars() : PositionalMethodSymbol("max",
	"Returns the largest value that has ever been passed to it in the last bars_back bars",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "Next potentially maximum value."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "bars_back", "Next potentially maximum value.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The maximum value.")) {}




Sum::Sum() : PositionalMethodSymbol("sum",
	"Returns the sum of the values passed to it so far",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "Add this to sum/")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The total sum.")) {}






SumBars::SumBars() : PositionalMethodSymbol("sum",
	"Returns the sum of the last bars_back bars",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "Current value"),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "bars_back", "Sum of bars back bars.")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The sum.")) {}












Mean::Mean() : PositionalMethodSymbol("mean",
	"Returns the mean of values passed to it so far. (Doesn't take na values into account).",

	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to add to the mean calculation. (Will ignore NAs)")


	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The mean value so far.")) {}





GetPi::GetPi() : PositionalMethodSymbol("pi",
	"Gets the PI constant.",

	{
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The PI constant")) {}




GetE::GetE() : PositionalMethodSymbol("e",
	"Gets the E constant.",

	{
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The E constant")) {}





Round::Round() : PositionalMethodSymbol("round",
	"Rounds to nearest int. Returns NA if NA passed.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to round")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The rounded value")) {}







Floor::Floor() : PositionalMethodSymbol("floor",
	"Floors value",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to floor")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The floored value")) {}






Ceil::Ceil() : PositionalMethodSymbol("ceil",
	"Ceils value",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to ceil")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The ceiled value")) {}






MaxNumber::MaxNumber() : PositionalMethodSymbol("maxnumber",
	"The max number value",

	{
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The largest possible number value")) {}




MinNumber::MinNumber() : PositionalMethodSymbol("minnumber",
	"The minimum number value",

	{
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The smallest possible number value")) {}




Count::Count() : PositionalMethodSymbol("count",
	"The amount of times a condition has been true.",

	{
		ParameterSymbol(TypeInstances::GetBooleanInstance(), "condition", "The condition to count.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The amount of times that condition has been true.")) {}





Boolean2NumberCast::Boolean2NumberCast() : PositionalMethodSymbol("number",
	"Casts value to a number.",

	{
		ParameterSymbol(TypeInstances::GetBooleanInstance(), "value", "The value to convert")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The value as a number.")) {}



Boolean2StringCast::Boolean2StringCast() : PositionalMethodSymbol("string",
	"Casts value to a string.",

	{
		ParameterSymbol(TypeInstances::GetBooleanInstance(), "value", "The value to convert")
	}, ReturnSymbol(TypeInstances::GetStringInstance(), "The value as a string.")) {}




Float2BooleanCast::Float2BooleanCast() : PositionalMethodSymbol("boolean",
	"Casts value to a boolea.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to convert")
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "The value as a boolean.")) {}


Float2StringCast::Float2StringCast() : PositionalMethodSymbol("string",
	"Casts value to a string.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to convert")
	}, ReturnSymbol(TypeInstances::GetStringInstance(), "The value as a string.")) {}




Absolute::Absolute() : PositionalMethodSymbol("abs",
	"Returns the abs of a value.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to abs.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The value as a abs.")) {}







LogE::LogE() : PositionalMethodSymbol("log",
	"Returns the natural base-e log of a number. Can throw a run time error if <= 0.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to log. Has to be positive non-zero value.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The logged value")) {}






LogBase::LogBase() : PositionalMethodSymbol("log",
	"Returns the log of a number given a base. Can throw a run time error if <= 0.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to log. Has to be positive non-zero value."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "base", "The base of the log. Has to be positive non-zero value.")
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The logged value.")) {}





SquareRoot::SquareRoot() : PositionalMethodSymbol("sqrt",
	"Returns the square root of a number. ",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to root. Must be a positive number."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The rooted value.")) {}




LCM::LCM() : PositionalMethodSymbol("lcm",
	"Returns the lowest common multiple of two numbers. Note: converts both numbers to ints.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value1", "The LCM value 1."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value2", "The LCM value 2."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The LCM.")) {}






GCD::GCD() : PositionalMethodSymbol("gcd",
	"Returns the greatest common divider of two numbers. Note: converts both numbers to ints.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value1", "The GCD value 1."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value2", "The GCD value 2."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The GCD.")) {}






Variance::Variance() : PositionalMethodSymbol("variance",
	"Returns the variance of a value.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "amount", "Amount values must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The variance of the data.")) {}





STD::STD() : PositionalMethodSymbol("std",
	"Returns the std of a value.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "amount", "Amount values must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The std of the data.")) {}







MA::MA() : PositionalMethodSymbol("ma",
	"Returns the moving average of a value.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "amount", "Amount values must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The moving average of the data.")) {}






IsNullN::IsNullN() : PositionalMethodSymbol("isnull",
	"Returns true if number value is null",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value to test"),
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Whether the value is null or not")) {}






IsNullB::IsNullB() : PositionalMethodSymbol("isnull",
	"Returns true if boolean value is null",

	{
		ParameterSymbol(TypeInstances::GetBooleanInstance(), "value", "The value to test"),
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Whether the value is null or not")) {}






IsNullS::IsNullS() : PositionalMethodSymbol("isnull",
	"Returns true if string value is null",

	{
		ParameterSymbol(TypeInstances::GetStringInstance(), "value", "The value to test"),
	}, ReturnSymbol(TypeInstances::GetStringInstance(), "Whether the value is null or not")) {}



Random::Random() : PositionalMethodSymbol("random",
	"Returns random value between the two ranges",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "minvalue", "The minimum range (will be casted to int)."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "maxvalue", "The maximum range (will be casted to int)."),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The random number in the range.")) {}







Falling::Falling() : PositionalMethodSymbol("falling",
	"Returns true if data has been dropping for n bars in a row.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "amount", "Amount bars must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "True or false if it has been falling for n bars in a row.")) {}




Rising::Rising() : PositionalMethodSymbol("rising",
	"Returns true if data has been rising for n bars in a row.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "amount", "Amount bars must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "True or false if it has been rising for n bars in a row.")) {}




Cosine::Cosine() : PositionalMethodSymbol("cos",
	"Returns the cosine of x radians. If null supplied, will return null.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The consine of the parameter input.")) {}



Tangent::Tangent() : PositionalMethodSymbol("tan",
	"Returns the tangent of x radians. If null supplied, will return null.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The tangent of the parameter input.")) {}



Sine::Sine() : PositionalMethodSymbol("sin",
	"Returns the sine of x radians. If null supplied, will return null.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The sine of the parameter input.")) {}




ArcCosine::ArcCosine() : PositionalMethodSymbol("acos",
	"Returns the arc cosine of x radians. If null supplied, will return null.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The arc cosine of the parameter input.")) {}



ArcTan::ArcTan() : PositionalMethodSymbol("atan",
	"Returns the arc tangent of x radians. If null supplied, will return null.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The arc tangent of the parameter input.")) {}



ArcSine::ArcSine() : PositionalMethodSymbol("asin",
	"Returns the arc sine of x radians. If null supplied, will return null.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The arc sine of the parameter input.")) {}


LinearRegressionAtTick::LinearRegressionAtTick() : PositionalMethodSymbol("linreg",
	"Returns the rolling linear regression of last n bars.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "data", "The data we are using in the prediction"),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "bars", "The amount of bars to perform the calculation on"),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "x", "The x value you would like to predict"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The y level of the linear regression")) {}





Correlation::Correlation() : PositionalMethodSymbol("correlation",
	"Returns the correlation of two data sources in the last n bars.",

	{
		ParameterSymbol(TypeInstances::GetNumberInstance(), "data1", "The first data source"),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "data2", "The second data source"),
		ParameterSymbol(TypeInstances::GetNumberInstance(), "length", "The amount of bars to perform the calculation on"),
	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The correlation")) {}





PreviousNumberValue::PreviousNumberValue() : PositionalMethodSymbol("prev",
	"Gets the previous value. Lookback will return the last nth value.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "data", "Series of data to retreive value for (stores it every time its called)."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "barsback", "The amount of bars back to retrieve the value")

	}, ReturnSymbol(TypeInstances::GetNumberInstance())) {}


PreviousStringValue::PreviousStringValue() : PositionalMethodSymbol("prev",
	"Gets the previous value. Lookback will return the last nth value.",
	{
	ParameterSymbol(TypeInstances::GetStringInstance(), "data", "Series of data to retreive value for (stores it every time its called)."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "barsback", "The amount of bars back to retrieve the value")

	}, ReturnSymbol(TypeInstances::GetStringInstance())) {}


PreviousBooleanValue::PreviousBooleanValue() : PositionalMethodSymbol("prev",
	"Gets the previous value. Lookback will return the last nth value.",
	{
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "data", "Series of data to retreive value for (stores it every time its called)."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "barsback", "The amount of bars back to retrieve the value")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance())) {}






Median::Median() : PositionalMethodSymbol("median",
	"Returns the median value. Ignores null values.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "data", "Data to perform median on."),

	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The median value")) {}





MedianBars::MedianBars() : PositionalMethodSymbol("median",
	"Returns the rolling median value. Ignores null values.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "data", "Data to perform median on."),
	ParameterSymbol(TypeInstances::GetNumberInstance(), "barsback", "Range of bars to consider for median"),

	}, ReturnSymbol(TypeInstances::GetNumberInstance(), "The median value")) {}







IsPrime::IsPrime() : PositionalMethodSymbol("isprime",
	"Returns true or false if it is a prime number. Will be converted to a integer. Ignores null values.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "data", "Data to check if prime."),

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Is prime or not.")) {}







IsTriangle::IsTriangle() : PositionalMethodSymbol("istriangle",
	"Returns true or false if it is a triangle number. Will be converted to a integer. Ignores null values.",
	{
	ParameterSymbol(TypeInstances::GetNumberInstance(), "data", "Data to check if triangle."),

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Is triangle or not.")) {}


