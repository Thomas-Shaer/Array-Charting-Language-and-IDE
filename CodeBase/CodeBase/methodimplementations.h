#pragma once
#include "methodsymbol.h"
#include "typesymbol.h"
#include <vector>
#include "interpreteroutput.h"
#include <queue>
#include <deque>

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


class BinaryModOperator : public MethodSymbol {
public:
	BinaryModOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryModOperator* clone() {
		return new BinaryModOperator(name);
	}
};

class BinaryPowOperator : public MethodSymbol {
public:
	BinaryPowOperator(const std::string& _name);
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BinaryPowOperator* clone() {
		return new BinaryPowOperator(name);
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
	virtual const TypeSymbol* semanticAnaylsis(std::vector<std::shared_ptr<ArgumentSymbol>> _argumentSymbols, InterpreterOutput& output);

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
	virtual const TypeSymbol* semanticAnaylsis(std::vector<std::shared_ptr<ArgumentSymbol>> _argumentSymbols, InterpreterOutput& output);
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

class StringNAN : public MethodSymbol {
public:
	StringNAN();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual StringNAN* clone() {
		return new StringNAN();
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



class MinimumBars : public MethodSymbol {
public:
	MinimumBars();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual MinimumBars* clone() {
		return new MinimumBars();
	}
private:
	std::deque<float> buffer;
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

class MaximumBars : public MethodSymbol {
public:
	MaximumBars();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual MaximumBars* clone() {
		return new MaximumBars();
	}
private:
	std::deque<float> buffer;
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


class SumBars : public MethodSymbol {
public:
	SumBars();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual SumBars* clone() {
		return new SumBars();
	}
private:
	std::deque<float> buffer;
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


class Floor : public MethodSymbol {
public:
	Floor();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Floor* clone() {
		return new Floor();
	}
};

class Ceil : public MethodSymbol {
public:
	Ceil();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Ceil* clone() {
		return new Ceil();
	}
};

class FloatMax : public MethodSymbol {
public:
	FloatMax();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual FloatMax* clone() {
		return new FloatMax();
	}
};

class FloatMin : public MethodSymbol {
public:
	FloatMin();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual FloatMin* clone() {
		return new FloatMin();
	}
};

class Count : public MethodSymbol {
public:
	Count();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Count* clone() {
		return new Count();
	}

private:
	int count = 0;
};


class FloatCast : public MethodSymbol {
public:
	FloatCast();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual FloatCast* clone() {
		return new FloatCast();
	}
};

class BooleanCast : public MethodSymbol {
public:
	BooleanCast();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual BooleanCast* clone() {
		return new BooleanCast();
	}
};


class Absolute : public MethodSymbol {
public:
	Absolute();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Absolute* clone() {
		return new Absolute();
	}
};


class LogE : public MethodSymbol {
public:
	LogE();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual LogE* clone() {
		return new LogE();
	}
};

class LogBase : public MethodSymbol {
public:
	LogBase();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual LogBase* clone() {
		return new LogBase();
	}
};


class SquareRoot : public MethodSymbol {
public:
	SquareRoot();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual SquareRoot* clone() {
		return new SquareRoot();
	}
};


class LCM : public MethodSymbol {
public:
	LCM();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual LCM* clone() {
		return new LCM();
	}
};


class GCD : public MethodSymbol {
public:
	GCD();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual GCD* clone() {
		return new GCD();
	}
};



class Variance : public MethodSymbol {
public:
	Variance();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Variance* clone() {
		return new Variance();
	}
private:
	std::deque<float> buffer;
};

class STD : public MethodSymbol {
public:
	STD();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual STD* clone() {
		return new STD();
	}
	Variance var;
};


class MA : public MethodSymbol {
public:
	MA();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual MA* clone() {
		return new MA();
	}
private:
	std::deque<float> buffer;
};


class IsNANF : public MethodSymbol {
public:
	IsNANF();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual IsNANF* clone() {
		return new IsNANF();
	}
};



class IsNANB : public MethodSymbol {
public:
	IsNANB();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual IsNANB* clone() {
		return new IsNANB();
	}
};

class IsNANS : public MethodSymbol {
public:
	IsNANS();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual IsNANS* clone() {
		return new IsNANS();
	}
};


class Random : public MethodSymbol {
public:
	Random();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Random* clone() {
		return new Random();
	}
};



class Falling : public MethodSymbol {
public:
	Falling();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Falling* clone() {
		return new Falling();
	}
private:
	float currentMin = std::numeric_limits<float>::max();
	int inRow = 0;
};

class Rising : public MethodSymbol {
public:
	Rising();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Rising* clone() {
		return new Rising();
	}
private:
	float currentMax = std::numeric_limits<float>::min();
	int inRow = 0;
};


class Cosine : public MethodSymbol {
public:
	Cosine();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Cosine* clone() {
		return new Cosine();
	}
};



class Tangent : public MethodSymbol {
public:
	Tangent();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Tangent* clone() {
		return new Tangent();
	}
};


class Sine : public MethodSymbol {
public:
	Sine();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Sine* clone() {
		return new Sine();
	}
};

class ArcCosine : public MethodSymbol {
public:
	ArcCosine();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual ArcCosine* clone() {
		return new ArcCosine();
	}
};


class ArcTan : public MethodSymbol {
public:
	ArcTan();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual ArcTan* clone() {
		return new ArcTan();
	}
};


class ArcSine : public MethodSymbol {
public:
	ArcSine();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual ArcSine* clone() {
		return new ArcSine();
	}
};


class LinearRegression : public MethodSymbol {
public:
	LinearRegression();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual LinearRegression* clone() {
		return new LinearRegression();
	}
private:
	std::deque<float> bufferX;
	std::deque<float> bufferY;
};

class Correlation : public MethodSymbol {
public:
	Correlation();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);
	virtual Correlation* clone() {
		return new Correlation();
	}
private:
	std::deque<float> values1;
	std::deque<float> values2;
};

class PreviousValue : public MethodSymbol {
public:
	PreviousValue();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);

	virtual PreviousValue* clone() {
		return new PreviousValue();
	}
private:

	std::vector<Float> values;
};


class Median : public MethodSymbol {
public:
	Median();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);

	virtual Median* clone() {
		return new Median();
	}
private:

	std::vector<float> values;
};


class MedianBars : public MethodSymbol {
public:
	MedianBars();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);

	virtual MedianBars* clone() {
		return new MedianBars();
	}
private:

	std::vector<float> values;
};


class IsPrime : public MethodSymbol {
public:
	IsPrime();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);

	virtual IsPrime* clone() {
		return new IsPrime();
	}
};


class IsTriangle : public MethodSymbol {
public:
	IsTriangle();
	virtual ExpressionValue interpret(const unsigned int tick, std::vector<ExpressionValue> _argumentValues, InterpreterOutput& output);

	virtual IsTriangle* clone() {
		return new IsTriangle();
	}
};