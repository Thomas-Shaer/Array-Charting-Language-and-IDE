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

ExpressionValue MethodAverage::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Float((*boost::get<Float>(_argumentValues[0]).value + *boost::get<Float>(_argumentValues[1]).value) / 2);
}


UnaryPlusOperator::UnaryPlusOperator(const std::string& _name) : MethodSymbol(_name,
	"Propagates a expression.",
	{ 
	ParameterSymbol(TypeInstances::GetFloatInstance(), "expr", "The expression to progate.")
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "Result of the propogation")) {}

ExpressionValue UnaryPlusOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if arg is nan return a nan
	if (!boost::get<Float>(_argumentValues[0]).value) {
		return Float();
	}
	return Float(+*boost::get<Float>(_argumentValues[0]).value);
}

UnaryMinusOperator::UnaryMinusOperator(const std::string& _name) : MethodSymbol(_name, 
	"Negates a expression.",

	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "expr", "The expression to negate.")

	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "Result of the negation")) {}

ExpressionValue UnaryMinusOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if arg is nan return a nan
	if (!boost::get<Float>(_argumentValues[0]).value) {
		return Float();
	}
	return Float(-*boost::get<Float>(_argumentValues[0]).value);
}

UnaryNotOperator::UnaryNotOperator(const std::string& _name) : MethodSymbol(_name, 
	"Negates a boolean expression.",
	{
	ParameterSymbol(TypeInstances::GetBooleanInstance (), "expr", "The expression to negate.")
	
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the boolean negation")) {}

ExpressionValue UnaryNotOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if arg is nan return a nan
	if (!boost::get<Boolean>(_argumentValues[0]).value) {
		return Boolean();
	}
	return Boolean(!*boost::get<Boolean>(_argumentValues[0]).value);
}


BinaryPlusOperator::BinaryPlusOperator(const std::string& _name) : MethodSymbol(_name, 
	"Adds together two numbers.",
	{ 
	ParameterSymbol(TypeInstances::GetFloatInstance(), "lhs", "The left hand side of the addition operation."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "rhs", "The rhs hand side of the addition operation.")
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "Result of the addition")) {}

ExpressionValue BinaryPlusOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Float(*boost::get<Float>(_argumentValues[0]).value + *boost::get<Float>(_argumentValues[1]).value);
}

BinaryMinusOperator::BinaryMinusOperator(const std::string& _name) : MethodSymbol(_name, 
	"Minuses two numbers.",
	{ 
	
	ParameterSymbol(TypeInstances::GetFloatInstance(), "lhs", "The left hand side of the minus operation."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "rhs", "The rhs hand side of the minus operation.")

	
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "Result of the negation")) {}

ExpressionValue BinaryMinusOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Float(*boost::get<Float>(_argumentValues[0]).value - *boost::get<Float>(_argumentValues[1]).value);
}

BinaryDivideOperator::BinaryDivideOperator(const std::string& _name) : MethodSymbol(_name, 
	"Divides two numbers.",
	{ 
		ParameterSymbol(TypeInstances::GetFloatInstance(), "lhs", "The left hand side of the division operation."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "rhs", "The rhs hand side of the division operation.")
	
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "Result of the division")) {}

ExpressionValue BinaryDivideOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Float(*boost::get<Float>(_argumentValues[0]).value / *boost::get<Float>(_argumentValues[1]).value);
}

BinaryMultiplyOperator::BinaryMultiplyOperator(const std::string& _name) : MethodSymbol(_name, 
	"Multiplies two numbers.",
	{ 
	ParameterSymbol(TypeInstances::GetFloatInstance(), "lhs", "The left hand side of the multiply operation."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "rhs", "The rhs hand side of the multiply operation.")
	
	
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "Result of the multiplication")) {}

ExpressionValue BinaryMultiplyOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Float(*boost::get<Float>(_argumentValues[0]).value * *boost::get<Float>(_argumentValues[1]).value);
}




BinaryPowOperator::BinaryPowOperator(const std::string& _name) : MethodSymbol(_name,
	"Raises number by power of another.",
	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "lhs", "The left hand side of the power operation."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "rhs", "The rhs hand side of the power operation.")


	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "Result of the power operator")) {}

ExpressionValue BinaryPowOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Float(std::powf(*boost::get<Float>(_argumentValues[0]).value, *boost::get<Float>(_argumentValues[1]).value));
}



BinaryModOperator::BinaryModOperator(const std::string& _name) : MethodSymbol(_name,
	"Applies modulus operator to number",
	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "lhs", "The left hand side of the modulus operation."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "rhs", "The rhs hand side of the modulus operation.")


	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "Result of the modulus operator")) {}

ExpressionValue BinaryModOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Float(std::fmod(*boost::get<Float>(_argumentValues[0]).value, *boost::get<Float>(_argumentValues[1]).value));
}





BinaryLessOperator::BinaryLessOperator(const std::string& _name) : MethodSymbol(_name, 
	"Performs less than operator on two numbers.",
	{ 
	
	ParameterSymbol(TypeInstances::GetFloatInstance(), "lhs", "The left hand side of the less than operation."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "rhs", "The rhs hand side of the less than operation.")
	
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the less then operation")) {}

ExpressionValue BinaryLessOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Boolean();
	}
	return Boolean(*boost::get<Float>(_argumentValues[0]).value < *boost::get<Float>(_argumentValues[1]).value);
}

BinaryLessEqualOperator::BinaryLessEqualOperator(const std::string& _name) : MethodSymbol(_name, 
	"Performs less than or equal operator on two numbers.",

	{
	
	ParameterSymbol(TypeInstances::GetFloatInstance(), "lhs", "The left hand side of the less than or equal operation."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "rhs", "The rhs hand side of the less than or equal operation.")
	
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the less then or equal operation")) {}

ExpressionValue BinaryLessEqualOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Boolean();
	}
	return Boolean(*boost::get<Float>(_argumentValues[0]).value <= *boost::get<Float>(_argumentValues[1]).value);
}


BinaryGreaterOperator::BinaryGreaterOperator(const std::string& _name) : MethodSymbol(_name, 
	"Performs greater than operator on two numbers.",
	{ 
	ParameterSymbol(TypeInstances::GetFloatInstance(), "lhs", "The left hand side of the greater than operation."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "rhs", "The rhs hand side of the greater than operation.")

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the greater then operation")) {}

ExpressionValue BinaryGreaterOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Boolean();
	}
	return Boolean(*boost::get<Float>(_argumentValues[0]).value > *boost::get<Float>(_argumentValues[1]).value);
}

BinaryGreaterEqualOperator::BinaryGreaterEqualOperator(const std::string& _name) : MethodSymbol(_name, 
	
	"Performs greater than or equal operator on two numbers.",
	{ 
	
	ParameterSymbol(TypeInstances::GetFloatInstance(), "lhs", "The left hand side of the greater than or equal operation."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "rhs", "The rhs hand side of the greater than or equal operation.")
	
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the greater then or equal operation")) {}

ExpressionValue BinaryGreaterEqualOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Boolean();
	}
	return Boolean(*boost::get<Float>(_argumentValues[0]).value >= *boost::get<Float>(_argumentValues[1]).value);
}


BinaryAndOperator::BinaryAndOperator(const std::string& _name) : MethodSymbol(_name, 
	"Performs and operator on two booleans.",

	{
	
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "lhs", "The left hand side of the and operation."),
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "rhs", "The rhs hand side of the and operation.")

	
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of and operation")) {}

ExpressionValue BinaryAndOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Boolean>(_argumentValues[0]).value || !boost::get<Boolean>(_argumentValues[1]).value) {
		return Boolean();
	}
	return Boolean(*boost::get<Boolean>(_argumentValues[0]).value && *boost::get<Boolean>(_argumentValues[1]).value);
}


BinaryOrOperator::BinaryOrOperator(const std::string& _name) : MethodSymbol(_name, 
	"Performs or operator on two booleans.",
	{ 
		ParameterSymbol(TypeInstances::GetBooleanInstance(), "lhs", "The left hand side of the or operation."),
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "rhs", "The rhs hand side of the or operation.")
	
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the or operation")) {}

ExpressionValue BinaryOrOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Boolean>(_argumentValues[0]).value || !boost::get<Boolean>(_argumentValues[1]).value) {
		return Boolean();
	}
	return Boolean(*boost::get<Boolean>(_argumentValues[0]).value || *boost::get<Boolean>(_argumentValues[1]).value);
}


BinaryBooleanEqualOperator::BinaryBooleanEqualOperator(const std::string& _name) : MethodSymbol(_name, 
	"Performs equal operator on two booleans.",
	{ 
			ParameterSymbol(TypeInstances::GetBooleanInstance(), "lhs", "The left hand side of the equal operation."),
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "rhs", "The rhs hand side of the equal operation.")
	
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands equal")) {}

ExpressionValue BinaryBooleanEqualOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Boolean>(_argumentValues[0]).value || !boost::get<Boolean>(_argumentValues[1]).value) {
		return Boolean();
	}
	return Boolean(*boost::get<Boolean>(_argumentValues[0]).value == *boost::get<Boolean>(_argumentValues[1]).value);
}

BinaryFloatEqualOperator::BinaryFloatEqualOperator(const std::string& _name) : MethodSymbol(_name, 
	"Performs equal operator on two floats.",
	{ 
	ParameterSymbol(TypeInstances::GetFloatInstance(), "lhs", "The left hand side of the equal operation."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "rhs", "The rhs hand side of the equal operation.")
	
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands equal")) {}

ExpressionValue BinaryFloatEqualOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Boolean(*boost::get<Float>(_argumentValues[0]).value == *boost::get<Float>(_argumentValues[1]).value);
}


BinaryBooleanNotEqualOperator::BinaryBooleanNotEqualOperator(const std::string& _name) : MethodSymbol(_name, 
	"Performs not equal operator on two booleans.",

	{ 
			ParameterSymbol(TypeInstances::GetBooleanInstance(), "lhs", "The left hand side of the not equal operation."),
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "rhs", "The rhs hand side of the not equal operation.")
	
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands not equal")) {}

ExpressionValue BinaryBooleanNotEqualOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Boolean>(_argumentValues[0]).value || !boost::get<Boolean>(_argumentValues[1]).value) {
		return Boolean();
	}
	return Boolean(*boost::get<Boolean>(_argumentValues[0]).value != *boost::get<Boolean>(_argumentValues[1]).value);
}

BinaryFloatNotEqualOperator::BinaryFloatNotEqualOperator(const std::string& _name) : MethodSymbol(_name, 
	
	"Performs not equal operator on two floats.",

	{ 
	
				ParameterSymbol(TypeInstances::GetFloatInstance(), "lhs", "The left hand side of the not equal operation."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "rhs", "The rhs hand side of the not equal operation.")
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Are the two operands not equal")) {}

ExpressionValue BinaryFloatNotEqualOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Boolean(*boost::get<Float>(_argumentValues[0]).value != *boost::get<Float>(_argumentValues[1]).value);
}



GetTick::GetTick() : MethodSymbol("tick",
	"Gets the current tick.",
	{ }, ReturnSymbol(TypeInstances::GetFloatInstance(), "The current tick")) {}

ExpressionValue GetTick::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	return Float(tick);
}



Plot::Plot() : MethodSymbol("plot", 
	"Plots a series of values onto the chart",
	{ 
	ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value that will be plotted at the current tick"),
	ParameterSymbol(TypeInstances::GetStringConstantInstance(), "name", "The name of the plot"),
	ParameterSymbol(TypeInstances::GetStringConstantInstance(), "chart_id", "The id of the chart to plot too.")
	
	}, ReturnSymbol(TypeInstances::GetVoidInstance())) {}


const TypeSymbol* Plot::semanticAnaylsis(std::vector<std::shared_ptr<ArgumentSymbol>> _argumentSymbols, InterpreterOutput& output) {
	const TypeSymbol* typereturn = MethodSymbol::semanticAnaylsis(_argumentSymbols, output);


	std::string name = static_cast<StringNode*>(_argumentSymbols.at(1)->expression)->value;

	std::shared_ptr<ChartPlot> newData = std::make_shared<ChartPlot>(name, output.amountTicks);
	std::string id = static_cast<StringNode*>(_argumentSymbols.at(2)->expression)->value;
	ChartWindow::getOrCreateChartWindow(id)->CHART_LINE_DATA.push_back(newData);
	std::shared_ptr<ChartPlot> first = ChartWindow::getOrCreateChartWindow(id)->CHART_LINE_DATA.back(); //returns reference, not iterator, to the first object in the vector so you had only to write the data type in the generic of your vector, i.e. myObject, and not all the iterator stuff and the vector again and :: of course
	plotdata = first;

	return typereturn;

}


ExpressionValue Plot::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	

	// if nan return a nan value else extract the correct value
	float pushBackValue = boost::get<Float>(_argumentValues.at(0)).value ? *boost::get<Float>(_argumentValues.at(0)).value : std::numeric_limits<double>::quiet_NaN();
	plotdata->data[tick] = pushBackValue;

	return Boolean(true);
}



Mark::Mark() : MethodSymbol("mark", 
	"Conditionally marks points on the chart when a condition is true.",

	{ 
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "when", "Mark the current tick or not"),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value to mark if marking this tick"),
	ParameterSymbol(TypeInstances::GetStringConstantInstance(), "name", "The name of the plot"),
	ParameterSymbol(TypeInstances::GetStringConstantInstance(), "chart_id", "The id of the chart to plot too.")


	
	}, ReturnSymbol(TypeInstances::GetVoidInstance())) {}




const TypeSymbol* Mark::semanticAnaylsis(std::vector<std::shared_ptr<ArgumentSymbol>> _argumentSymbols, InterpreterOutput& output) {
	const TypeSymbol* typereturn = MethodSymbol::semanticAnaylsis(_argumentSymbols, output);


	std::string name = static_cast<StringNode*>(_argumentSymbols.at(2)->expression)->value;

	std::shared_ptr<ChartPlot> newData = std::make_shared<ChartPlot>(name, output.amountTicks);

	std::string id = static_cast<StringNode*>(_argumentSymbols.at(3)->expression)->value;
	ChartWindow::getOrCreateChartWindow(id)->CHART_MARK_DATA.push_back(newData);
	std::shared_ptr<ChartPlot> first = ChartWindow::getOrCreateChartWindow(id)->CHART_MARK_DATA.back(); //returns reference, not iterator, to the first object in the vector so you had only to write the data type in the generic of your vector, i.e. myObject, and not all the iterator stuff and the vector again and :: of course
	plotdata = first;
	return typereturn;
}

ExpressionValue Mark::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	//if not nan
	if (boost::get<Boolean>(_argumentValues.at(0)).value) {
		
		// if positive
		if (*boost::get<Boolean>(_argumentValues.at(0)).value) {
			
			float pushBackValue = boost::get<Float>(_argumentValues.at(1)).value ? *boost::get<Float>(_argumentValues.at(1)).value : std::numeric_limits<double>::quiet_NaN();
			plotdata->data[tick] = (pushBackValue);
		}
		else {
			plotdata->data[tick] = (std::numeric_limits<double>::quiet_NaN());
		}
	}
	else {
		plotdata->data[tick] = (std::numeric_limits<double>::quiet_NaN());
	}

	return Boolean(true);
}



ValueWhen::ValueWhen() : MethodSymbol("valuewhen",
	"Stores and returns a value that only changes when the condition is true.",

	{
	ParameterSymbol(TypeInstances::GetBooleanInstance(), "when", "When to update the current value."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value to update it with.")


	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The value last time the condition was true")) {}



ExpressionValue ValueWhen::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Boolean>(_argumentValues.at(0)).value) {
		if (*boost::get<Boolean>(_argumentValues.at(0)).value) {
			currentValue = _argumentValues.at(1);
		}
	}

	return currentValue;
}






FloatNAN::FloatNAN() : MethodSymbol("nan_f", 
	"Get a float NAN.",

	{ }, ReturnSymbol(TypeInstances::GetFloatInstance(), "NAN value")) {}

ExpressionValue FloatNAN::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	return Float();
}


BooleanNAN::BooleanNAN() : MethodSymbol("nan_b", 
	"Get a boolean NAN.",
	{ }, ReturnSymbol(TypeInstances::GetBooleanInstance(), "NAN value")) {}

ExpressionValue BooleanNAN::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	return Boolean();
}


StringNAN::StringNAN() : MethodSymbol("nan_s",
	"Get a string NAN.",
	{ }, ReturnSymbol(TypeInstances::GetStringInstance(), "String value")) {}

ExpressionValue StringNAN::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	return String();
}



Minimum::Minimum() : MethodSymbol("min",
	"Returns the smallest value that has ever been passed to it.",

	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "Next potentially minimum value.")


	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The maximum value.")) {}



ExpressionValue Minimum::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(0)).value) {
		if (*boost::get<Float>(_argumentValues.at(0)).value < *boost::get<Float>(minimumValue).value) {
			minimumValue = _argumentValues.at(0);
		}
	}

	return minimumValue;
}



MinimumBars::MinimumBars() : MethodSymbol("min",
	"Returns the smallest value that has ever been passed to it in the last bars_back bars",

	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "Next potentially minimum value."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "bars_back", "Next potentially minimum value.")


	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The minimum value.")) {}



ExpressionValue MinimumBars::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(1)).value) {
		int lookback = (int)*boost::get<Float>(_argumentValues.at(1)).value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", moving minimum function must use positive non zero amount.");
		}

		if (boost::get<Float>(_argumentValues.at(0)).value) {
			buffer.push_back(*boost::get<Float>(_argumentValues.at(0)).value);

			if (buffer.size() < lookback) {
				return Float();
			}

			float min = *std::min_element(buffer.begin(), buffer.end());

			buffer.pop_front();
			return Float(min);
		}
	}

	return Float();
}





Maximum::Maximum() : MethodSymbol("max",
	"Returns the max value that has ever been passed to it.",

	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "Next potentially maximum value.")


	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The minimum value.")) {}



ExpressionValue Maximum::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(0)).value) {
		if (*boost::get<Float>(_argumentValues.at(0)).value > *boost::get<Float>(maximumValue).value) {
			maximumValue = _argumentValues.at(0);
		}
	}

	return maximumValue;
}



MaximumBars::MaximumBars() : MethodSymbol("max",
	"Returns the largest value that has ever been passed to it in the last bars_back bars",

	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "Next potentially maximum value."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "bars_back", "Next potentially maximum value.")


	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The maximum value.")) {}



ExpressionValue MaximumBars::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(1)).value) {
		int lookback = (int)*boost::get<Float>(_argumentValues.at(1)).value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", moving maximum function must use positive non zero amount.");
		}

		if (boost::get<Float>(_argumentValues.at(0)).value) {
			buffer.push_back(*boost::get<Float>(_argumentValues.at(0)).value);

			if (buffer.size() < lookback) {
				return Float();
			}

			float min = *std::max_element(buffer.begin(), buffer.end());

			buffer.pop_front();
			return Float(min);
		}
	}

	return Float();
}






Sum::Sum() : MethodSymbol("sum",
	"Returns the sum of the values passed to it so far",

	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "Add this to sum/")


	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The total sum.")) {}



ExpressionValue Sum::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(0)).value) {
		*boost::get<Float>(sum).value += *boost::get<Float>(_argumentValues.at(0)).value;
	}

	return sum;
}



SumBars::SumBars() : MethodSymbol("sum",
	"Returns the sum of the last bars_back bars",

	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "Current value"),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "bars_back", "Sum of bars back bars.")


	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The sum.")) {}



ExpressionValue SumBars::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(1)).value) {
		int lookback = (int)*boost::get<Float>(_argumentValues.at(1)).value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", moving sum function must use positive non zero amount.");
		}

		if (boost::get<Float>(_argumentValues.at(0)).value) {
			buffer.push_back(*boost::get<Float>(_argumentValues.at(0)).value);

			if (buffer.size() < lookback) {
				return Float();
			}

			float sum = std::accumulate(buffer.begin(), buffer.end(), 0);

			buffer.pop_front();
			return Float(sum);
		}
	}

	return Float();
}








Mean::Mean() : MethodSymbol("mean",
	"Returns the mean of values passed to it so far. (Doesn't take na values into account).",

	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value to add to the mean calculation. (Will ignore NAs)")


	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The mean value so far.")) {}



ExpressionValue Mean::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(0)).value) {
		amountSoFar++;
		sum += *boost::get<Float>(_argumentValues.at(0)).value;
	}

	return Float(sum / amountSoFar);
}


GetPi::GetPi() : MethodSymbol("pi",
	"Gets the PI constant.",

	{
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The PI constant")) {}


ExpressionValue GetPi::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	return Float(std::numbers::pi_v<float>);
}


GetE::GetE() : MethodSymbol("e",
	"Gets the E constant.",

	{
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The E constant")) {}


ExpressionValue GetE::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	return Float(std::numbers::e);
}


Round::Round() : MethodSymbol("round",
	"Rounds to nearest int. Returns NA if NA passed.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value to round")
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The rounded value")) {}


ExpressionValue Round::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	
	if (boost::get<Float>(_argumentValues.at(0)).value) {
		return Float(std::round(*boost::get<Float>(_argumentValues.at(0)).value));
	}
	
	return Float();
}




Floor::Floor() : MethodSymbol("floor",
	"Floors value",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value to floor")
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The floored value")) {}


ExpressionValue Floor::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (boost::get<Float>(_argumentValues.at(0)).value) {
		return Float(std::floor(*boost::get<Float>(_argumentValues.at(0)).value));
	}

	return Float();
}



Ceil::Ceil() : MethodSymbol("ceil",
	"Ceils value",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value to ceil")
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The ceiled value")) {}


ExpressionValue Ceil::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (boost::get<Float>(_argumentValues.at(0)).value) {
		return Float(std::ceil(*boost::get<Float>(_argumentValues.at(0)).value));
	}

	return Float();
}



FloatMax::FloatMax() : MethodSymbol("floatmax",
	"The max float value",

	{
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The largest possible float value")) {}


ExpressionValue FloatMax::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	return Float((std::numeric_limits<float>::max)());
}


FloatMin::FloatMin() : MethodSymbol("floatmin",
	"The minimum float value",

	{
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The smallest possible float value")) {}


ExpressionValue FloatMin::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	return Float((std::numeric_limits<float>::min)());
}



Count::Count() : MethodSymbol("count",
	"The amount of times a condition has been true.",

	{
		ParameterSymbol(TypeInstances::GetBooleanInstance(), "condition", "The condition to count.")
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The amount of times that condition has been true.")) {}


ExpressionValue Count::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (boost::get<Boolean>(_argumentValues.at(0)).value) {
		if (*boost::get<Boolean>(_argumentValues.at(0)).value) {
			count++;
		}
	}

	return Float(count);
}


FloatCast::FloatCast() : MethodSymbol("float",
	"Casts value to a float.",

	{
		ParameterSymbol(TypeInstances::GetBooleanInstance(), "value", "The value to convert")
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The value as a float.")) {}


ExpressionValue FloatCast::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (boost::get<Boolean>(_argumentValues.at(0)).value) {
		return Float(*boost::get<Boolean>(_argumentValues.at(0)).value);
	}

	return Float();
}



BooleanCast::BooleanCast() : MethodSymbol("boolean",
	"Casts value to a boolea.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value to convert")
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "The value as a boolean.")) {}


ExpressionValue BooleanCast::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (boost::get<Float>(_argumentValues.at(0)).value) {
		return Boolean(*boost::get<Float>(_argumentValues.at(0)).value);
	}

	return Boolean();
}




Absolute::Absolute() : MethodSymbol("abs",
	"Returns the abs of a value.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value to abs.")
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The value as a abs.")) {}


ExpressionValue Absolute::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (boost::get<Float>(_argumentValues.at(0)).value) {
		return Float(std::abs(*boost::get<Float>(_argumentValues.at(0)).value));
	}
	
	return Float();
}




LogE::LogE() : MethodSymbol("log",
	"Returns the natural base-e log of a number. Can throw a run time error if <= 0.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value to log. Has to be positive non-zero value.")
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The logged value")) {}


ExpressionValue LogE::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (boost::get<Float>(_argumentValues.at(0)).value) {
		if (*boost::get<Float>(_argumentValues.at(0)).value <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", log function must use positive non zero value.");
		}
		return Float(std::log(*boost::get<Float>(_argumentValues.at(0)).value));
	}

	return Float();
}



LogBase::LogBase() : MethodSymbol("log",
	"Returns the log of a number given a base. Can throw a run time error if <= 0.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value to log. Has to be positive non-zero value."),
		ParameterSymbol(TypeInstances::GetFloatInstance(), "base", "The base of the log. Has to be positive non-zero value.")
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The logged value.")) {}


ExpressionValue LogBase::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (boost::get<Float>(_argumentValues.at(0)).value) {
		if (*boost::get<Float>(_argumentValues.at(0)).value <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", log function must use positive non zero value.");
		}
	}
	if(boost::get<Float>(_argumentValues.at(1)).value) {
		if (*boost::get<Float>(_argumentValues.at(1)).value <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", log function must use positive non zero base.");
		}
		return Float(log(*boost::get<Float>(_argumentValues.at(0)).value) / log(*boost::get<Float>(_argumentValues.at(1)).value));
	}

	return Float();
}



SquareRoot::SquareRoot() : MethodSymbol("sqrt",
	"Returns the square root of a number. ",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value to root. Must be a positive number."),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The rooted value.")) {}


ExpressionValue SquareRoot::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (boost::get<Float>(_argumentValues.at(0)).value) {
		if (*boost::get<Float>(_argumentValues.at(0)).value < 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", log function must use positive zero value.");
		}

		return Float(std::sqrt(*boost::get<Float>(_argumentValues.at(0)).value));
	}

	return Float();
}



LCM::LCM() : MethodSymbol("lcm",
	"Returns the lowest common multiple of two numbers. Note: converts both numbers to ints.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value1", "The LCM value 1."),
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value2", "The LCM value 2."),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The LCM.")) {}


ExpressionValue LCM::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (boost::get<Float>(_argumentValues.at(0)).value && boost::get<Float>(_argumentValues.at(0)).value) {
		
		return Float(std::lcm((int)*boost::get<Float>(_argumentValues.at(0)).value, (int)*boost::get<Float>(_argumentValues.at(1)).value));
	}

	return Float();
}



GCD::GCD() : MethodSymbol("gcd",
	"Returns the greatest common divider of two numbers. Note: converts both numbers to ints.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value1", "The GCD value 1."),
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value2", "The GCD value 2."),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The GCD.")) {}


ExpressionValue GCD::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (boost::get<Float>(_argumentValues.at(0)).value && boost::get<Float>(_argumentValues.at(0)).value) {

		return Float(std::gcd((int)*boost::get<Float>(_argumentValues.at(0)).value, (int)*boost::get<Float>(_argumentValues.at(1)).value));
	}

	return Float();
}



Variance::Variance() : MethodSymbol("variance",
	"Returns the variance of a value.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetFloatInstance(), "amount", "Amount values must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The variance of the data.")) {}


ExpressionValue Variance::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(1)).value) {
		int lookback = (int)*boost::get<Float>(_argumentValues.at(1)).value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", variance function must use positive non zero amount.");
		}

		if (boost::get<Float>(_argumentValues.at(0)).value) {
			buffer.push_back(*boost::get<Float>(_argumentValues.at(0)).value);

			if (buffer.size() < lookback) {
				return Float();
			}

			float sum = std::accumulate(buffer.begin(), buffer.end(), 0);
			float mean = sum / buffer.size();

			float variance = 0;
			for (int i = buffer.size() - 1; i >= 0; i--) {
				variance += std::pow(buffer[i] - mean, 2);
			}
			variance = variance / buffer.size();
			buffer.pop_front();
			return Float(variance);
		}
	}

	return Float();
}




STD::STD() : MethodSymbol("std",
	"Returns the std of a value.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetFloatInstance(), "amount", "Amount values must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The std of the data.")) {}


ExpressionValue STD::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	ExpressionValue variance = var.interpret(tick, _argumentValues, output);
	if (boost::get<Float>(variance).value) {
		return Float(std::sqrt(*boost::get<Float>(variance).value));
	}
	return Float();
}




MA::MA() : MethodSymbol("ma",
	"Returns the moving average of a value.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetFloatInstance(), "amount", "Amount values must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The moving average of the data.")) {}


ExpressionValue MA::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(1)).value) {
		int lookback = (int)*boost::get<Float>(_argumentValues.at(1)).value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", moving average function must use positive non zero amount.");
		}

		if (boost::get<Float>(_argumentValues.at(0)).value) {
			buffer.push_back(*boost::get<Float>(_argumentValues.at(0)).value);

			if (buffer.size() < lookback) {
				return Float();
			}

			float sum = std::accumulate(buffer.begin(), buffer.end(), 0);
			float mean = sum / buffer.size();

			buffer.pop_front();
			return Float(mean);
		}
	}

	return Float();
}




IsNANF::IsNANF() : MethodSymbol("isnan",
	"Returns true if float value is NAN",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value to test"),
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Whether the value is NAN or not")) {}


ExpressionValue IsNANF::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	return Boolean((bool) ! boost::get<Float>(_argumentValues.at(0)).value);
}


IsNANB::IsNANB() : MethodSymbol("isnan",
	"Returns true if boolean value is NAN",

	{
		ParameterSymbol(TypeInstances::GetBooleanInstance(), "value", "The value to test"),
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Whether the value is NAN or not")) {}


ExpressionValue IsNANB::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	return Boolean((bool)!boost::get<Boolean>(_argumentValues.at(0)).value);
}


IsNANS::IsNANS() : MethodSymbol("isnan",
	"Returns true if string value is NAN",

	{
		ParameterSymbol(TypeInstances::GetStringInstance(), "value", "The value to test"),
	}, ReturnSymbol(TypeInstances::GetStringInstance(), "Whether the value is NAN or not")) {}


ExpressionValue IsNANS::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	return Boolean((bool)!boost::get<String>(_argumentValues.at(0)).value);
}





Random::Random() : MethodSymbol("random",
	"Returns random value between the two ranges",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "minvalue", "The minimum range (will be casted to int)."),
		ParameterSymbol(TypeInstances::GetFloatInstance(), "maxvalue", "The maximum range (will be casted to int)."),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The random number in the range.")) {}


ExpressionValue Random::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (!boost::get<Float>(_argumentValues[0]).value) {
		return Float();
	}
	if (!boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}

	std::random_device seeder;
	std::mt19937 engine(seeder());
	std::uniform_int_distribution<int> dist((int)*boost::get<Float>(_argumentValues[0]).value, (int)*boost::get<Float>(_argumentValues[1]).value);
	int compGuess = dist(engine);

	return Float(compGuess);
}



Falling::Falling() : MethodSymbol("falling",
	"Returns true if data has been dropping for n bars in a row.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetFloatInstance(), "amount", "Amount bars must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "True or false if it has been falling for n bars in a row.")) {}


ExpressionValue Falling::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(1)).value) {
		int lookback = (int)*boost::get<Float>(_argumentValues.at(1)).value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", falling function must use positive non zero amount.");
		}

		if (boost::get<Float>(_argumentValues.at(0)).value) {
			float newVal = *boost::get<Float>(_argumentValues.at(0)).value;
			if (newVal < currentMin) {
				inRow++;
			}
			else {
				inRow = 0;
			}
			currentMin = newVal;

			if (inRow >= lookback) {
				return Boolean(true);
			}
			return Boolean(false);
		}
	}

	return Boolean();
}



Rising::Rising() : MethodSymbol("rising",
	"Returns true if data has been rising for n bars in a row.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value."),
		ParameterSymbol(TypeInstances::GetFloatInstance(), "amount", "Amount bars must be positive non zero value. Will be converted to a int."),
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "True or false if it has been rising for n bars in a row.")) {}


ExpressionValue Rising::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(1)).value) {
		int lookback = (int)*boost::get<Float>(_argumentValues.at(1)).value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", rising function must use positive non zero amount.");
		}

		if (boost::get<Float>(_argumentValues.at(0)).value) {
			float newVal = *boost::get<Float>(_argumentValues.at(0)).value;
			if (newVal > currentMax) {
				inRow++;
			}
			else {
				inRow = 0;
			}
			currentMax = newVal;

			if (inRow >= lookback) {
				return Boolean(true);
			}
			return Boolean(false);
		}
	}

	return Boolean();
}



Cosine::Cosine() : MethodSymbol("cos",
	"Returns the cosine of x radians. If NAN supplied, will return NAN.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The consine of the parameter input.")) {}


ExpressionValue Cosine::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(0)).value) {
		return Float(std::cos(*boost::get<Float>(_argumentValues.at(0)).value));
	}

	return Float();
}



Tangent::Tangent() : MethodSymbol("tan",
	"Returns the tangent of x radians. If NAN supplied, will return NAN.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The tangent of the parameter input.")) {}


ExpressionValue Tangent::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(0)).value) {
		return Float(std::tan(*boost::get<Float>(_argumentValues.at(0)).value));
	}

	return Float();
}



Sine::Sine() : MethodSymbol("sin",
	"Returns the sine of x radians. If NAN supplied, will return NAN.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The sine of the parameter input.")) {}


ExpressionValue Sine::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(0)).value) {
		return Float(std::sin(*boost::get<Float>(_argumentValues.at(0)).value));
	}

	return Float();
}


ArcCosine::ArcCosine() : MethodSymbol("acos",
	"Returns the arc cosine of x radians. If NAN supplied, will return NAN.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The arc cosine of the parameter input.")) {}


ExpressionValue ArcCosine::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(0)).value) {
		return Float(std::acos(*boost::get<Float>(_argumentValues.at(0)).value));
	}

	return Float();
}




ArcTan::ArcTan() : MethodSymbol("atan",
	"Returns the arc tangent of x radians. If NAN supplied, will return NAN.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The arc tangent of the parameter input.")) {}


ExpressionValue ArcTan::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(0)).value) {
		return Float(std::atan(*boost::get<Float>(_argumentValues.at(0)).value));
	}

	return Float();
}





ArcSine::ArcSine() : MethodSymbol("asin",
	"Returns the arc sine of x radians. If NAN supplied, will return NAN.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "radians", "The amount of radians"),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The arc sine of the parameter input.")) {}


ExpressionValue ArcSine::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(0)).value) {
		return Float(std::asin(*boost::get<Float>(_argumentValues.at(0)).value));
	}

	return Float();
}


LinearRegression::LinearRegression() : MethodSymbol("linreg",
	"Returns the rolling linear regression of last n bars.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "data", "The data we are using in the prediction"),
		ParameterSymbol(TypeInstances::GetFloatInstance(), "bars", "The amount of bars to perform the calculation on"),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The y level of the linear regression")) {}

/*
WARNING. If look back changes value this will return the wrong value!
*/
ExpressionValue LinearRegression::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(1)).value) {
		int lookback = (int)*boost::get<Float>(_argumentValues.at(1)).value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", linear regression function must use positive non zero amount.");
		}


		if (boost::get<Float>(_argumentValues.at(0)).value) {
			bufferX.push_back(tick);
			bufferY.push_back(*boost::get<Float>(_argumentValues.at(0)).value);

			if (bufferX.size() < lookback) {
				return Float();
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
			return Float((m * tick) + c);
		}

	}

	return Float();
}





Correlation::Correlation() : MethodSymbol("correlation",
	"Returns the correlation of two data sources in the last n bars.",

	{
		ParameterSymbol(TypeInstances::GetFloatInstance(), "data1", "The first data source"),
		ParameterSymbol(TypeInstances::GetFloatInstance(), "data2", "The second data source"),
		ParameterSymbol(TypeInstances::GetFloatInstance(), "length", "The amount of bars to perform the calculation on"),
	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The correlation")) {}

/*
WARNING. If look back changes value this will return the wrong value!
*/
ExpressionValue Correlation::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	if (boost::get<Float>(_argumentValues.at(2)).value) {
		float lookback = (int)*boost::get<Float>(_argumentValues.at(2)).value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", linear regression function must use positive non zero amount.");
		}


		if (boost::get<Float>(_argumentValues.at(0)).value && boost::get<Float>(_argumentValues.at(1)).value) {
			values1.push_back(*boost::get<Float>(_argumentValues.at(0)).value);
			values2.push_back(*boost::get<Float>(_argumentValues.at(1)).value);

			if (values1.size() < lookback) {
				return Float();
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
			return Float(corr);
		}

	}

	return Float();
}









PreviousValue::PreviousValue() : MethodSymbol("prev",
	"Gets the previous value. Lookback will return the last nth non-NAN value.",
	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "data", "Series of data to retreive value for (stores it every time its called)."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "barsback", "The amount of bars back to retrieve the value")

	}, ReturnSymbol(TypeInstances::GetFloatInstance())) {}



ExpressionValue PreviousValue::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (boost::get<Float>(_argumentValues.at(0)).value) {
		values.push_back(boost::get<Float>(_argumentValues.at(0)));
	}

	if (boost::get<Float>(_argumentValues.at(1)).value) {
		int lookback = (int)*boost::get<Float>(_argumentValues.at(1)).value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", previous function must use positive non zero amount.");
		}
		
		
		if (values.size() > lookback) {
			return values[tick - lookback];
		}
		return Float();

	}

	return Float();
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




Median::Median() : MethodSymbol("median",
	"Returns the median value. Ignores NAN values.",
	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "data", "Data to perform median on."),

	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The median value")) {}



ExpressionValue Median::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (!boost::get<Float>(_argumentValues.at(0)).value) {
		return Float();
	}

	insert_sorted(values, *boost::get<Float>(_argumentValues.at(0)).value);

	if (values.size() % 2 == 0)
	{
		return Float((values[values.size() / 2 - 1] + values[values.size() / 2]) / 2);
	}
	
	return Float(values[values.size() / 2]);
}



MedianBars::MedianBars() : MethodSymbol("median",
	"Returns the rolling median value. Ignores NAN values.",
	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "data", "Data to perform median on."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "barsback", "Range of bars to consider for median"),

	}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The median value")) {}



ExpressionValue MedianBars::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (!boost::get<Float>(_argumentValues.at(0)).value) {
		return Float();
	}

	if (!boost::get<Float>(_argumentValues.at(1)).value) {
		return Float();
	}


	values.push_back(*boost::get<Float>(_argumentValues.at(0)).value);
	
	int lookback = *boost::get<Float>(_argumentValues.at(1)).value;
	if (values.size() >= lookback) {
		std::vector<float> new_vec(values.end() - lookback, values.end());
		std::sort(new_vec.begin(), new_vec.end());
		if (new_vec.size() % 2 == 0)
		{
			return Float((new_vec[new_vec.size() / 2 - 1] + new_vec[new_vec.size() / 2]) / 2);
		}

		return Float(new_vec[new_vec.size() / 2]);
	}

	return Float();
}




IsPrime::IsPrime() : MethodSymbol("isprime",
	"Returns true or false if it is a prime number. Will be converted to a integer. Ignores NAN values.",
	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "data", "Data to check if prime."),

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Is prime or not.")) {}



ExpressionValue IsPrime::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (!boost::get<Float>(_argumentValues.at(0)).value) {
		return Boolean();
	}

	int n = *boost::get<Float>(_argumentValues.at(0)).value;

	//https://www.geeksforgeeks.org/c-program-to-check-prime-number/
	// Corner case
	if (n <= 1)
		return Boolean(false);

	// Check from 2 to n-1
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return Boolean(false);

	return Boolean(true);
}



IsTriangle::IsTriangle() : MethodSymbol("istriangle",
	"Returns true or false if it is a triangle number. Will be converted to a integer. Ignores NAN values.",
	{
	ParameterSymbol(TypeInstances::GetFloatInstance(), "data", "Data to check if triangle."),

	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Is triangle or not.")) {}



ExpressionValue IsTriangle::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	if (!boost::get<Float>(_argumentValues.at(0)).value) {
		return Boolean();
	}

	int n = *boost::get<Float>(_argumentValues.at(0)).value;

	//https://stackoverflow.com/questions/2913215/fastest-method-to-define-whether-a-number-is-a-triangular-number

	if (n < 0)
		return Boolean(false);

	for (int i = 0; i < n; i++) {
		if (i * (i + 1) / 2 == n) {
			return Boolean(true);
		}
	}
		
	return Boolean(false);
}