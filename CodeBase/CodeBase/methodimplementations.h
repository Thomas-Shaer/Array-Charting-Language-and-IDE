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

	MethodAverage();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);
	ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual MethodAverage* clone() {
		return new MethodAverage();
	}

private:
	Float* value1;
	Float* value2;
};


class UnaryPlusOperator : public MethodSymbol {
public:
	const std::string name;
	UnaryPlusOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual UnaryPlusOperator* clone() {
		return new UnaryPlusOperator(name);
	}

private:
	Float* value;
};

class UnaryMinusOperator : public MethodSymbol {
public:
	const std::string name;
	UnaryMinusOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual UnaryMinusOperator* clone() {
		return new UnaryMinusOperator(name);
	}
private:
	Float* value;
};


class UnaryNotOperator : public MethodSymbol {
public:
	UnaryNotOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual UnaryNotOperator* clone() {
		return new UnaryNotOperator(name);
	}
private:
	Boolean* value;
};


class BinaryPlusOperator : public MethodSymbol {
public:
	BinaryPlusOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryPlusOperator* clone() {
		return new BinaryPlusOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryMinusOperator : public MethodSymbol {
public:
	BinaryMinusOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryMinusOperator* clone() {
		return new BinaryMinusOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryDivideOperator : public MethodSymbol {
public:
	BinaryDivideOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryDivideOperator* clone() {
		return new BinaryDivideOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryMultiplyOperator : public MethodSymbol {
public:
	BinaryMultiplyOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryMultiplyOperator* clone() {
		return new BinaryMultiplyOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};


class BinaryModOperator : public MethodSymbol {
public:
	BinaryModOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryModOperator* clone() {
		return new BinaryModOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryPowOperator : public MethodSymbol {
public:
	BinaryPowOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryPowOperator* clone() {
		return new BinaryPowOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryLessOperator : public MethodSymbol {
public:
	BinaryLessOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryLessOperator* clone() {
		return new BinaryLessOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryLessEqualOperator : public MethodSymbol {
public:
	BinaryLessEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryLessEqualOperator* clone() {
		return new BinaryLessEqualOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryGreaterOperator : public MethodSymbol {
public:
	BinaryGreaterOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryGreaterOperator* clone() {
		return new BinaryGreaterOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryGreaterEqualOperator : public MethodSymbol {
public:
	BinaryGreaterEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryGreaterEqualOperator* clone() {
		return new BinaryGreaterEqualOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryAndOperator : public MethodSymbol {
public:
	BinaryAndOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryAndOperator* clone() {
		return new BinaryAndOperator(name);
	}
private:
	Boolean* lhsValue;
	Boolean* rhsValue;
};

class BinaryOrOperator : public MethodSymbol {
public:
	BinaryOrOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryOrOperator* clone() {
		return new BinaryOrOperator(name);
	}
private:
	Boolean* lhsValue;
	Boolean* rhsValue;
};

class BinaryBooleanEqualOperator : public MethodSymbol {
public:
	BinaryBooleanEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryBooleanEqualOperator* clone() {
		return new BinaryBooleanEqualOperator(name);
	}
private:
	Boolean* lhsValue;
	Boolean* rhsValue;
};

class BinaryFloatEqualOperator : public MethodSymbol {
public:
	BinaryFloatEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryFloatEqualOperator* clone() {
		return new BinaryFloatEqualOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryBooleanNotEqualOperator : public MethodSymbol {
public:
	BinaryBooleanNotEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryBooleanNotEqualOperator* clone() {
		return new BinaryBooleanNotEqualOperator(name);
	}
private:
	Boolean* lhsValue;
	Boolean* rhsValue;
};


class BinaryFloatNotEqualOperator : public MethodSymbol {
public:
	BinaryFloatNotEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BinaryFloatNotEqualOperator* clone() {
		return new BinaryFloatNotEqualOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};



class GetTick : public MethodSymbol {
public:
	GetTick();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual GetTick* clone() {
		return new GetTick();
	}
};

class Plot : public MethodSymbol {
public:
	Plot();

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual Plot* clone() {
		return new Plot();
	}
private:
	std::shared_ptr<ChartPlot> plotdata;
	Float* value;
	String* lineName;
	String* chartId;
};

class Mark : public MethodSymbol {
public:
	Mark();
	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);
	virtual Mark* clone() {
		return new Mark();
	}
private:
	std::shared_ptr<ChartPlot> plotdata;

	Boolean* when;
	Float* value;
	String* lineName;
	String* chartId;
};


class FloatNAN : public MethodSymbol {
public:
	FloatNAN();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual FloatNAN* clone() {
		return new FloatNAN();
	}
};

class BooleanNAN : public MethodSymbol {
public:
	BooleanNAN();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BooleanNAN* clone() {
		return new BooleanNAN();
	}
};

class StringNAN : public MethodSymbol {
public:
	StringNAN();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual StringNAN* clone() {
		return new StringNAN();
	}
};


class ValueWhen : public MethodSymbol {
public:
	ValueWhen();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual ValueWhen* clone() {
		return new ValueWhen();
	}
private:
	ExpressionValue currentValue{ Float() };
	Boolean* when;
	Float* value;
};

class Minimum : public MethodSymbol {
public:
	Minimum();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Minimum* clone() {
		return new Minimum();
	}
private:
	ExpressionValue minimumValue{ Float(std::numeric_limits<float>::max()) };
	Float* value;

};



class MinimumBars : public MethodSymbol {
public:
	MinimumBars();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);
	
	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual MinimumBars* clone() {
		return new MinimumBars();
	}
private:
	std::deque<float> buffer;
	Float* value;
	Float* bars_back;

};




class Maximum : public MethodSymbol {
public:
	Maximum();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Maximum* clone() {
		return new Maximum();
	}
private:
	ExpressionValue maximumValue{ Float(std::numeric_limits<float>::min()) };
	Float* value;
};

class MaximumBars : public MethodSymbol {
public:
	MaximumBars();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual MaximumBars* clone() {
		return new MaximumBars();
	}
private:
	std::deque<float> buffer;

	Float* value;
	Float* bars_back;
};


class Sum : public MethodSymbol {
public:
	Sum();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Sum* clone() {
		return new Sum();
	}
private:
	float sum = 0;
	Float* value;

};


class SumBars : public MethodSymbol {
public:
	SumBars();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual SumBars* clone() {
		return new SumBars();
	}
private:
	std::deque<float> buffer;


	Float* value;
	Float* bars_back;
};


class Mean : public MethodSymbol {
public:
	Mean();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Mean* clone() {
		return new Mean();
	}
private:
	float amountSoFar = 0;
	float sum = 0;
	Float* value;

};

class GetPi : public MethodSymbol {
public:
	GetPi();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual GetPi* clone() {
		return new GetPi();
	}
};

class GetE : public MethodSymbol {
public:
	GetE();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual GetE* clone() {
		return new GetE();
	}
};


class Round : public MethodSymbol {
public:
	Round();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Round* clone() {
		return new Round();
	}
private:
	Float* value;
};


class Floor : public MethodSymbol {
public:
	Floor();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Floor* clone() {
		return new Floor();
	}
private:
	Float* value;
};

class Ceil : public MethodSymbol {
public:
	Ceil();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Ceil* clone() {
		return new Ceil();
	}
private:
	Float* value;
};

class FloatMax : public MethodSymbol {
public:
	FloatMax();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual FloatMax* clone() {
		return new FloatMax();
	}
};

class FloatMin : public MethodSymbol {
public:
	FloatMin();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual FloatMin* clone() {
		return new FloatMin();
	}
};

class Count : public MethodSymbol {
public:
	Count();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Count* clone() {
		return new Count();
	}

private:
	int count = 0;
	Boolean* value;
};


class FloatCast : public MethodSymbol {
public:
	FloatCast();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual FloatCast* clone() {
		return new FloatCast();
	}
private:
	Boolean* value;
};

class BooleanCast : public MethodSymbol {
public:
	BooleanCast();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual BooleanCast* clone() {
		return new BooleanCast();
	}
private:
	Float* value;
};


class Absolute : public MethodSymbol {
public:
	Absolute();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Absolute* clone() {
		return new Absolute();
	}
private:
	Float* value;
};


class LogE : public MethodSymbol {
public:
	LogE();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual LogE* clone() {
		return new LogE();
	}
private:
	Float* value;
};

class LogBase : public MethodSymbol {
public:
	LogBase();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual LogBase* clone() {
		return new LogBase();
	}
private:
	Float* value;
	Float* base;
};


class SquareRoot : public MethodSymbol {
public:
	SquareRoot();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual SquareRoot* clone() {
		return new SquareRoot();
	}
private:
	Float* value;
};


class LCM : public MethodSymbol {
public:
	LCM();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual LCM* clone() {
		return new LCM();
	}
private:
	Float* value1;
	Float* value2;
};


class GCD : public MethodSymbol {
public:
	GCD();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual GCD* clone() {
		return new GCD();
	}
private:
	Float* value1;
	Float* value2;
};



class Variance : public MethodSymbol {
public:
	Variance();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Variance* clone() {
		return new Variance();
	}
private:
	std::deque<float> buffer;
	Float* value;
	Float* amount;
};

class STD : public MethodSymbol {
public:
	STD();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual STD* clone() {
		return new STD();
	}
private:
	std::deque<float> buffer;
	Float* value;
	Float* amount;
};


class MA : public MethodSymbol {
public:
	MA();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual MA* clone() {
		return new MA();
	}
private:
	std::deque<float> buffer;
	Float* value;
	Float* amount;
};


class IsNANF : public MethodSymbol {
public:
	IsNANF();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual IsNANF* clone() {
		return new IsNANF();
	}
private:
	Float* value;
};



class IsNANB : public MethodSymbol {
public:
	IsNANB();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual IsNANB* clone() {
		return new IsNANB();
	}
private:
	Boolean* value;
};

class IsNANS : public MethodSymbol {
public:
	IsNANS();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual IsNANS* clone() {
		return new IsNANS();
	}
private:
	String* value;
};


class Random : public MethodSymbol {
public:
	Random();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Random* clone() {
		return new Random();
	}
private:
	Float* minvalue;
	Float* maxvalue;
};



class Falling : public MethodSymbol {
public:
	Falling();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Falling* clone() {
		return new Falling();
	}
private:
	float currentMin = std::numeric_limits<float>::max();
	int inRow = 0;
	Float* value;
	Float* amount;
};

class Rising : public MethodSymbol {
public:
	Rising();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Rising* clone() {
		return new Rising();
	}
private:
	float currentMax = std::numeric_limits<float>::min();
	int inRow = 0;
	Float* value;
	Float* amount;
};


class Cosine : public MethodSymbol {
public:
	Cosine();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Cosine* clone() {
		return new Cosine();
	}
private:
	Float* radians;

};



class Tangent : public MethodSymbol {
public:
	Tangent();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Tangent* clone() {
		return new Tangent();
	}
private:
	Float* radians;
};


class Sine : public MethodSymbol {
public:
	Sine();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Sine* clone() {
		return new Sine();
	}
private:
	Float* radians;
};

class ArcCosine : public MethodSymbol {
public:
	ArcCosine();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual ArcCosine* clone() {
		return new ArcCosine();
	}
private:
	Float* radians;
};


class ArcTan : public MethodSymbol {
public:
	ArcTan();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual ArcTan* clone() {
		return new ArcTan();
	}
private:
	Float* radians;
};


class ArcSine : public MethodSymbol {
public:
	ArcSine();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual ArcSine* clone() {
		return new ArcSine();
	}
private:
	Float* radians;
};


class LinearRegression : public MethodSymbol {
public:
	LinearRegression();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual LinearRegression* clone() {
		return new LinearRegression();
	}
private:
	std::deque<float> bufferX;
	std::deque<float> bufferY;
	Float* data;
	Float* bars;
};

class Correlation : public MethodSymbol {
public:
	Correlation();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);
	virtual Correlation* clone() {
		return new Correlation();
	}
private:
	std::deque<float> values1;
	std::deque<float> values2;
	Float* data1;
	Float* data2;
	Float* length;

};

class PreviousValue : public MethodSymbol {
public:
	PreviousValue();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);

	virtual PreviousValue* clone() {
		return new PreviousValue();
	}
private:

	std::vector<Float> values;
	Float* data;
	Float* barsback;
};


class Median : public MethodSymbol {
public:
	Median();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);

	virtual Median* clone() {
		return new Median();
	}
private:

	std::vector<float> values;
	Float* data;

};


class MedianBars : public MethodSymbol {
public:
	MedianBars();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);

	virtual MedianBars* clone() {
		return new MedianBars();
	}
private:

	std::vector<float> values;
	Float* data;
	Float* barsback;

};


class IsPrime : public MethodSymbol {
public:
	IsPrime();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);

	virtual IsPrime* clone() {
		return new IsPrime();
	}
private:
	Float* data;
};


class IsTriangle : public MethodSymbol {
public:
	IsTriangle();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output);

	virtual ExpressionValue interpret(const unsigned int tick, InterpreterOutput& output);

	virtual IsTriangle* clone() {
		return new IsTriangle();
	}
private:
	Float* data;
};