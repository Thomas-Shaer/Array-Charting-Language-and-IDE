#include "methodimplementations.h"
#include "typesymbol.h"
#include "visitors.h"
#include "interpretercontext.h"

ExpressionValue MethodAverage::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {

	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Float((*boost::get<Float>(_argumentValues[0]).value + *boost::get<Float>(_argumentValues[1]).value) / 2);
}


UnaryPlusOperator::UnaryPlusOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance()}, TypeInstances::GetFloatInstance()) {}

ExpressionValue UnaryPlusOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if arg is nan return a nan
	if (!boost::get<Float>(_argumentValues[0]).value) {
		return Float();
	}
	return Float(+*boost::get<Float>(_argumentValues[0]).value);
}

UnaryMinusOperator::UnaryMinusOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance()}, TypeInstances::GetFloatInstance()) {}

ExpressionValue UnaryMinusOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if arg is nan return a nan
	if (!boost::get<Float>(_argumentValues[0]).value) {
		return Float();
	}
	return Float(-*boost::get<Float>(_argumentValues[0]).value);
}

UnaryNotOperator::UnaryNotOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetBooleanInstance()}, TypeInstances::GetBooleanInstance()) {}

ExpressionValue UnaryNotOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if arg is nan return a nan
	if (!boost::get<Boolean>(_argumentValues[0]).value) {
		return Boolean();
	}
	return Boolean(!*boost::get<Boolean>(_argumentValues[0]).value);
}


BinaryPlusOperator::BinaryPlusOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetFloatInstance()) {}

ExpressionValue BinaryPlusOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Float(*boost::get<Float>(_argumentValues[0]).value + *boost::get<Float>(_argumentValues[1]).value);
}

BinaryMinusOperator::BinaryMinusOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetFloatInstance()) {}

ExpressionValue BinaryMinusOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Float(*boost::get<Float>(_argumentValues[0]).value - *boost::get<Float>(_argumentValues[1]).value);
}

BinaryDivideOperator::BinaryDivideOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetFloatInstance()) {}

ExpressionValue BinaryDivideOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Float(*boost::get<Float>(_argumentValues[0]).value / *boost::get<Float>(_argumentValues[1]).value);
}

BinaryMultiplyOperator::BinaryMultiplyOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetFloatInstance()) {}

ExpressionValue BinaryMultiplyOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Float(*boost::get<Float>(_argumentValues[0]).value * *boost::get<Float>(_argumentValues[1]).value);
}


BinaryLessOperator::BinaryLessOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryLessOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Boolean(*boost::get<Float>(_argumentValues[0]).value < *boost::get<Float>(_argumentValues[1]).value);
}

BinaryLessEqualOperator::BinaryLessEqualOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryLessEqualOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Boolean(*boost::get<Float>(_argumentValues[0]).value <= *boost::get<Float>(_argumentValues[1]).value);
}


BinaryGreaterOperator::BinaryGreaterOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryGreaterOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Boolean(*boost::get<Float>(_argumentValues[0]).value > *boost::get<Float>(_argumentValues[1]).value);
}

BinaryGreaterEqualOperator::BinaryGreaterEqualOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryGreaterEqualOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Boolean(*boost::get<Float>(_argumentValues[0]).value >= *boost::get<Float>(_argumentValues[1]).value);
}


BinaryAndOperator::BinaryAndOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetBooleanInstance(), TypeInstances::GetBooleanInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryAndOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Boolean>(_argumentValues[0]).value || !boost::get<Boolean>(_argumentValues[1]).value) {
		return Boolean();
	}
	return Boolean(*boost::get<Boolean>(_argumentValues[0]).value && *boost::get<Boolean>(_argumentValues[1]).value);
}


BinaryOrOperator::BinaryOrOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetBooleanInstance(), TypeInstances::GetBooleanInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryOrOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Boolean>(_argumentValues[0]).value || !boost::get<Boolean>(_argumentValues[1]).value) {
		return Boolean();
	}
	return Boolean(*boost::get<Boolean>(_argumentValues[0]).value || *boost::get<Boolean>(_argumentValues[1]).value);
}


BinaryBooleanEqualOperator::BinaryBooleanEqualOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetBooleanInstance(), TypeInstances::GetBooleanInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryBooleanEqualOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Boolean>(_argumentValues[0]).value || !boost::get<Boolean>(_argumentValues[1]).value) {
		return Boolean();
	}
	return Boolean(*boost::get<Boolean>(_argumentValues[0]).value == *boost::get<Boolean>(_argumentValues[1]).value);
}

BinaryFloatEqualOperator::BinaryFloatEqualOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryFloatEqualOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Boolean(*boost::get<Float>(_argumentValues[0]).value == *boost::get<Float>(_argumentValues[1]).value);
}


BinaryBooleanNotEqualOperator::BinaryBooleanNotEqualOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetBooleanInstance(), TypeInstances::GetBooleanInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryBooleanNotEqualOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Boolean>(_argumentValues[0]).value || !boost::get<Boolean>(_argumentValues[1]).value) {
		return Boolean();
	}
	return Boolean(*boost::get<Boolean>(_argumentValues[0]).value != *boost::get<Boolean>(_argumentValues[1]).value);
}

BinaryFloatNotEqualOperator::BinaryFloatNotEqualOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryFloatNotEqualOperator::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if any argument is a NAN return NAN
	if (!boost::get<Float>(_argumentValues[0]).value || !boost::get<Float>(_argumentValues[1]).value) {
		return Float();
	}
	return Boolean(*boost::get<Float>(_argumentValues[0]).value != *boost::get<Float>(_argumentValues[1]).value);
}



GetTick::GetTick() : MethodSymbol("tick", { }, TypeInstances::GetFloatInstance()) {}

ExpressionValue GetTick::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	return Float(tick);
}




Plot::Plot() : MethodSymbol("plot", { TypeInstances::GetFloatInstance()}, TypeInstances::GetBooleanInstance()) {}

ExpressionValue Plot::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	// if nan return a nan value else extract the correct value
	float pushBackValue = boost::get<Float>(_argumentValues.at(0)).value ? *boost::get<Float>(_argumentValues.at(0)).value : std::numeric_limits<double>::quiet_NaN();
	plotdata.push_back(pushBackValue);
	if (tick == InterpreterContext::ticks - 1) {
		output.chartData.push_back(plotdata);
		plotdata.clear();
	}
	return Boolean(true);
}

Mark::Mark() : MethodSymbol("mark", { TypeInstances::GetBooleanInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue Mark::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	//if not nan
	if (boost::get<Boolean>(_argumentValues.at(0)).value) {
		
		// if positive
		if (*boost::get<Boolean>(_argumentValues.at(0)).value) {
			
			float pushBackValue = boost::get<Float>(_argumentValues.at(1)).value ? *boost::get<Float>(_argumentValues.at(1)).value : std::numeric_limits<double>::quiet_NaN();
			plotdata.push_back(pushBackValue);
		}
		else {
			plotdata.push_back(std::numeric_limits<double>::quiet_NaN());
		}
	}
	else {
		plotdata.push_back(std::numeric_limits<double>::quiet_NaN());
	}
	if (tick == InterpreterContext::ticks - 1) {
		output.markData.push_back(plotdata);
		plotdata.clear();
	}
	return Boolean(true);
}





FloatNAN::FloatNAN() : MethodSymbol("nan_f", { }, TypeInstances::GetFloatInstance()) {}

ExpressionValue FloatNAN::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	return Float();
}


BooleanNAN::BooleanNAN() : MethodSymbol("nan_b", { }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BooleanNAN::interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output) {
	return Boolean();
}