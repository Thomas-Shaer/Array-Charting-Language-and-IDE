#pragma once
#include "methodsymbol.h"
#include "typesymbol.h"
#include <vector>
#include "interpreteroutput.h"

// method named "avg" takes two float parameters and returns a float
class  MethodAverage : public MethodSymbol {
public:

	MethodAverage() : MethodSymbol("avg",
		"Returns the average of two numbers.",
		{
		
			ParameterSymbol(TypeInstances::GetFloatInstance(), "value1", "Argument 1 for average."),
	ParameterSymbol(TypeInstances::GetFloatInstance(), "value2", "Argument 2 for average.")
		}, ReturnSymbol(TypeInstances::GetFloatInstance(), "The average")) {}

	ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual MethodAverage* clone() {
		return new MethodAverage();
	}
};


class UnaryPlusOperator : public MethodSymbol {
public:
	const std::string name;
	UnaryPlusOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual UnaryPlusOperator* clone() {
		return new UnaryPlusOperator(name);
	}

};

class UnaryMinusOperator : public MethodSymbol {
public:
	const std::string name;
	UnaryMinusOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual UnaryMinusOperator* clone() {
		return new UnaryMinusOperator(name);
	}
};


class UnaryNotOperator : public MethodSymbol {
public:
	UnaryNotOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual UnaryNotOperator* clone() {
		return new UnaryNotOperator(name);
	}
};


class BinaryPlusOperator : public MethodSymbol {
public:
	BinaryPlusOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryPlusOperator* clone() {
		return new BinaryPlusOperator(name);
	}
};

class BinaryMinusOperator : public MethodSymbol {
public:
	BinaryMinusOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryMinusOperator* clone() {
		return new BinaryMinusOperator(name);
	}
};

class BinaryDivideOperator : public MethodSymbol {
public:
	BinaryDivideOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryDivideOperator* clone() {
		return new BinaryDivideOperator(name);
	}
};

class BinaryMultiplyOperator : public MethodSymbol {
public:
	BinaryMultiplyOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryMultiplyOperator* clone() {
		return new BinaryMultiplyOperator(name);
	}
};


class BinaryLessOperator : public MethodSymbol {
public:
	BinaryLessOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryLessOperator* clone() {
		return new BinaryLessOperator(name);
	}
};

class BinaryLessEqualOperator : public MethodSymbol {
public:
	BinaryLessEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryLessEqualOperator* clone() {
		return new BinaryLessEqualOperator(name);
	}
};

class BinaryGreaterOperator : public MethodSymbol {
public:
	BinaryGreaterOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryGreaterOperator* clone() {
		return new BinaryGreaterOperator(name);
	}
};

class BinaryGreaterEqualOperator : public MethodSymbol {
public:
	BinaryGreaterEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryGreaterEqualOperator* clone() {
		return new BinaryGreaterEqualOperator(name);
	}
};

class BinaryAndOperator : public MethodSymbol {
public:
	BinaryAndOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryAndOperator* clone() {
		return new BinaryAndOperator(name);
	}
};

class BinaryOrOperator : public MethodSymbol {
public:
	BinaryOrOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryOrOperator* clone() {
		return new BinaryOrOperator(name);
	}
};

class BinaryBooleanEqualOperator : public MethodSymbol {
public:
	BinaryBooleanEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryBooleanEqualOperator* clone() {
		return new BinaryBooleanEqualOperator(name);
	}
};

class BinaryFloatEqualOperator : public MethodSymbol {
public:
	BinaryFloatEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryFloatEqualOperator* clone() {
		return new BinaryFloatEqualOperator(name);
	}
};

class BinaryBooleanNotEqualOperator : public MethodSymbol {
public:
	BinaryBooleanNotEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryBooleanNotEqualOperator* clone() {
		return new BinaryBooleanNotEqualOperator(name);
	}
};

class BinaryFloatNotEqualOperator : public MethodSymbol {
public:
	BinaryFloatNotEqualOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryFloatNotEqualOperator* clone() {
		return new BinaryFloatNotEqualOperator(name);
	}
};


class GetTick : public MethodSymbol {
public:
	GetTick();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual GetTick* clone() {
		return new GetTick();
	}
};

class Plot : public MethodSymbol {
public:
	Plot();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual const TypeSymbol* semanticAnaylsis(std::vector<const TypeSymbol*> _argumentTypes, InterpreterOutput& output);

	virtual Plot* clone() {
		return new Plot();
	}
private:
	std::shared_ptr<ChartPlot> plotdata;
};

class Mark : public MethodSymbol {
public:
	Mark();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual const TypeSymbol* semanticAnaylsis(std::vector<const TypeSymbol*> _argumentTypes, InterpreterOutput& output);
	virtual Mark* clone() {
		return new Mark();
	}
private:
	std::shared_ptr<ChartPlot> plotdata;
};


class FloatNAN : public MethodSymbol {
public:
	FloatNAN();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual FloatNAN* clone() {
		return new FloatNAN();
	}
};

class BooleanNAN : public MethodSymbol {
public:
	BooleanNAN();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BooleanNAN* clone() {
		return new BooleanNAN();
	}
};


class ValueWhen : public MethodSymbol {
public:
	ValueWhen();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual ValueWhen* clone() {
		return new ValueWhen();
	}
private:
	ExpressionValue currentValue{Float()};
};

class Minimum : public MethodSymbol {
public:
	Minimum();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Minimum* clone() {
		return new Minimum();
	}
private:
	ExpressionValue minimumValue{ Float(std::numeric_limits<float>::max()) };
};


class Maximum : public MethodSymbol {
public:
	Maximum();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Maximum* clone() {
		return new Maximum();
	}
private:
	ExpressionValue maximumValue{ Float(std::numeric_limits<float>::min()) };
};


class Sum : public MethodSymbol {
public:
	Sum();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Sum* clone() {
		return new Sum();
	}
private:
	ExpressionValue sum{ Float(0) };
};


class Mean : public MethodSymbol {
public:
	Mean();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Mean* clone() {
		return new Mean();
	}
private:
	float amountSoFar = 0;
	float sum = 0;
};

class GetPi : public MethodSymbol {
public:
	GetPi();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual GetPi* clone() {
		return new GetPi();
	}
};

class GetE : public MethodSymbol {
public:
	GetE();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual GetE* clone() {
		return new GetE();
	}
};


class Round : public MethodSymbol {
public:
	Round();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Round* clone() {
		return new Round();
	}
};