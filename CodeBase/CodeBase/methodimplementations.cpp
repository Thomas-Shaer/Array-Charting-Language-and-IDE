#include "methodimplementations.h"
#include "typesymbol.h"
#include "visitors.h"
#include "interpretercontext.h"
#include "chartplot.h"

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


BinaryLessOperator::BinaryLessOperator(const std::string& _name) : MethodSymbol(_name, 
	"Performs less than operator on two numbers.",
	{ 
	
	ParameterSymbol(TypeInstances::GetFloatInstance(), "lhs", "The left hand side of the less than operation."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "rhs", "The rhs hand side of the less than operation.")
	
	}, ReturnSymbol(TypeInstances::GetBooleanInstance(), "Result of the less then operation")) {}

ExpressionValue BinaryLessOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
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
		return Float();
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
		return Float();
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
		return Float();
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


static int plotNo = 0;

Plot::Plot() : MethodSymbol("plot", 
	"Plots a series of values onto the chart",
	{ 
	ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value that will be plotted at the current tick")
	
	}, ReturnSymbol(TypeInstances::GetVoidInstance())) {}


const TypeSymbol* Plot::semanticAnaylsis(std::vector<const TypeSymbol*> _argumentTypes, InterpreterOutput& output) {
	const TypeSymbol* typereturn = MethodSymbol::semanticAnaylsis(_argumentTypes, output);


	std::shared_ptr<ChartPlot> newData = std::make_shared<ChartPlot>("Plot" + std::to_string(plotNo), output.amountTicks);
	plotNo++;
	output.chartData.push_back(newData);
	std::shared_ptr<ChartPlot> first = output.chartData.back(); //returns reference, not iterator, to the first object in the vector so you had only to write the data type in the generic of your vector, i.e. myObject, and not all the iterator stuff and the vector again and :: of course
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
	ParameterSymbol(TypeInstances::GetFloatInstance(), "value", "The value to mark if marking this tick")

	
	}, ReturnSymbol(TypeInstances::GetVoidInstance())) {}


static int markNo = 0;


const TypeSymbol* Mark::semanticAnaylsis(std::vector<const TypeSymbol*> _argumentTypes, InterpreterOutput& output) {
	const TypeSymbol* typereturn = MethodSymbol::semanticAnaylsis(_argumentTypes, output);


	std::shared_ptr<ChartPlot> newData = std::make_shared<ChartPlot>("Mark" + std::to_string(markNo), output.amountTicks);
	markNo++;
	output.markData.push_back(newData);
	std::shared_ptr<ChartPlot> first = output.markData.back(); //returns reference, not iterator, to the first object in the vector so you had only to write the data type in the generic of your vector, i.e. myObject, and not all the iterator stuff and the vector again and :: of course
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