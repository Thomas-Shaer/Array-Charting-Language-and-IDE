#pragma once
#include "methodsymbol.h"
#include "typesymbol.h"
#include <vector>
#include "interpreteroutput.h"
#include <queue>
#include <deque>

class Expression;


// method named "avg" takes two float parameters and returns a float
class  MethodAverage : public PositionalMethodSymbol {
public:

	MethodAverage();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);
	ExpressionValue interpret(const unsigned int tick);
	virtual MethodAverage* clone() {
		return new MethodAverage();
	}

private:
	Float* value1;
	Float* value2;
};


class UnaryPlusOperator : public PositionalMethodSymbol {
public:
	const std::string name;
	UnaryPlusOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual UnaryPlusOperator* clone() {
		return new UnaryPlusOperator(name);
	}

private:
	Float* value;
};

class UnaryMinusOperator : public PositionalMethodSymbol {
public:
	const std::string name;
	UnaryMinusOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual UnaryMinusOperator* clone() {
		return new UnaryMinusOperator(name);
	}
private:
	Float* value;
};


class UnaryNotOperator : public PositionalMethodSymbol {
public:
	UnaryNotOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual UnaryNotOperator* clone() {
		return new UnaryNotOperator(name);
	}
private:
	Boolean* value;
};


class BinaryPlusOperator : public PositionalMethodSymbol {
public:
	BinaryPlusOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryPlusOperator* clone() {
		return new BinaryPlusOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryMinusOperator : public PositionalMethodSymbol {
public:
	BinaryMinusOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryMinusOperator* clone() {
		return new BinaryMinusOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryDivideOperator : public PositionalMethodSymbol {
public:
	BinaryDivideOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryDivideOperator* clone() {
		return new BinaryDivideOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryMultiplyOperator : public PositionalMethodSymbol {
public:
	BinaryMultiplyOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryMultiplyOperator* clone() {
		return new BinaryMultiplyOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};


class BinaryModOperator : public PositionalMethodSymbol {
public:
	BinaryModOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryModOperator* clone() {
		return new BinaryModOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryPowOperator : public PositionalMethodSymbol {
public:
	BinaryPowOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryPowOperator* clone() {
		return new BinaryPowOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryLessOperator : public PositionalMethodSymbol {
public:
	BinaryLessOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryLessOperator* clone() {
		return new BinaryLessOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryLessEqualOperator : public PositionalMethodSymbol {
public:
	BinaryLessEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryLessEqualOperator* clone() {
		return new BinaryLessEqualOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryGreaterOperator : public PositionalMethodSymbol {
public:
	BinaryGreaterOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryGreaterOperator* clone() {
		return new BinaryGreaterOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryGreaterEqualOperator : public PositionalMethodSymbol {
public:
	BinaryGreaterEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryGreaterEqualOperator* clone() {
		return new BinaryGreaterEqualOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryAndOperator : public PositionalMethodSymbol {
public:
	BinaryAndOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryAndOperator* clone() {
		return new BinaryAndOperator(name);
	}
private:
	Boolean* lhsValue;
	Boolean* rhsValue;
};

class BinaryOrOperator : public PositionalMethodSymbol {
public:
	BinaryOrOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryOrOperator* clone() {
		return new BinaryOrOperator(name);
	}
private:
	Boolean* lhsValue;
	Boolean* rhsValue;
};

class BinaryBooleanEqualOperator : public PositionalMethodSymbol {
public:
	BinaryBooleanEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryBooleanEqualOperator* clone() {
		return new BinaryBooleanEqualOperator(name);
	}
private:
	Boolean* lhsValue;
	Boolean* rhsValue;
};

class BinaryFloatEqualOperator : public PositionalMethodSymbol {
public:
	BinaryFloatEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryFloatEqualOperator* clone() {
		return new BinaryFloatEqualOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};

class BinaryBooleanNotEqualOperator : public PositionalMethodSymbol {
public:
	BinaryBooleanNotEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryBooleanNotEqualOperator* clone() {
		return new BinaryBooleanNotEqualOperator(name);
	}
private:
	Boolean* lhsValue;
	Boolean* rhsValue;
};


class BinaryFloatNotEqualOperator : public PositionalMethodSymbol {
public:
	BinaryFloatNotEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryFloatNotEqualOperator* clone() {
		return new BinaryFloatNotEqualOperator(name);
	}
private:
	Float* lhsValue;
	Float* rhsValue;
};



class GetTick : public PositionalMethodSymbol {
public:
	GetTick();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual GetTick* clone() {
		return new GetTick();
	}
};

class Plot : public KeywordMethodSymbol {
public:
	Plot();

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual Plot* clone() {
		return new Plot();
	}
private:
	std::shared_ptr<ChartPlot> plotdata;
	Float* value;
	String* lineName;
	String* chartId;
};

class Mark : public KeywordMethodSymbol {
public:
	Mark();
	virtual ExpressionValue interpret(const unsigned int tick);
	virtual const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);
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


class FloatNAN : public PositionalMethodSymbol {
public:
	FloatNAN();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual FloatNAN* clone() {
		return new FloatNAN();
	}
};

class BooleanNAN : public PositionalMethodSymbol {
public:
	BooleanNAN();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BooleanNAN* clone() {
		return new BooleanNAN();
	}
};

class StringNAN : public PositionalMethodSymbol {
public:
	StringNAN();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual StringNAN* clone() {
		return new StringNAN();
	}
};


class ValueWhen : public PositionalMethodSymbol {
public:
	ValueWhen();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual ValueWhen* clone() {
		return new ValueWhen();
	}
private:
	ExpressionValue currentValue{ Float() };
	Boolean* when;
	Float* value;
};

class Minimum : public PositionalMethodSymbol {
public:
	Minimum();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Minimum* clone() {
		return new Minimum();
	}
private:
	ExpressionValue minimumValue{ Float(std::numeric_limits<float>::max()) };
	Float* value;

};



class MinimumBars : public PositionalMethodSymbol {
public:
	MinimumBars();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);
	
	virtual ExpressionValue interpret(const unsigned int tick);
	virtual MinimumBars* clone() {
		return new MinimumBars();
	}
private:
	std::deque<float> buffer;
	Float* value;
	Float* bars_back;
	Expression* barsBackNode;

};




class Maximum : public PositionalMethodSymbol {
public:
	Maximum();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Maximum* clone() {
		return new Maximum();
	}
private:
	ExpressionValue maximumValue{ Float(std::numeric_limits<float>::min()) };
	Float* value;
};

class MaximumBars : public PositionalMethodSymbol {
public:
	MaximumBars();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual MaximumBars* clone() {
		return new MaximumBars();
	}
private:
	std::deque<float> buffer;

	Float* value;
	Float* bars_back;
	Expression* barsBackNode;

};


class Sum : public PositionalMethodSymbol {
public:
	Sum();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Sum* clone() {
		return new Sum();
	}
private:
	float sum = 0;
	Float* value;

};


class SumBars : public PositionalMethodSymbol {
public:
	SumBars();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual SumBars* clone() {
		return new SumBars();
	}
private:
	std::deque<float> buffer;


	Float* value;
	Float* bars_back;
	Expression* barsBackNode;

};


class Mean : public PositionalMethodSymbol {
public:
	Mean();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Mean* clone() {
		return new Mean();
	}
private:
	float amountSoFar = 0;
	float sum = 0;
	Float* value;

};

class GetPi : public PositionalMethodSymbol {
public:
	GetPi();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual GetPi* clone() {
		return new GetPi();
	}
};

class GetE : public PositionalMethodSymbol {
public:
	GetE();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual GetE* clone() {
		return new GetE();
	}
};


class Round : public PositionalMethodSymbol {
public:
	Round();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Round* clone() {
		return new Round();
	}
private:
	Float* value;
};


class Floor : public PositionalMethodSymbol {
public:
	Floor();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Floor* clone() {
		return new Floor();
	}
private:
	Float* value;
};

class Ceil : public PositionalMethodSymbol {
public:
	Ceil();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Ceil* clone() {
		return new Ceil();
	}
private:
	Float* value;
};

class FloatMax : public PositionalMethodSymbol {
public:
	FloatMax();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual FloatMax* clone() {
		return new FloatMax();
	}
};

class FloatMin : public PositionalMethodSymbol {
public:
	FloatMin();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual FloatMin* clone() {
		return new FloatMin();
	}
};

class Count : public PositionalMethodSymbol {
public:
	Count();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Count* clone() {
		return new Count();
	}

private:
	int count = 0;
	Boolean* value;
};


class FloatCast : public PositionalMethodSymbol {
public:
	FloatCast();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual FloatCast* clone() {
		return new FloatCast();
	}
private:
	Boolean* value;
};

class BooleanCast : public PositionalMethodSymbol {
public:
	BooleanCast();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BooleanCast* clone() {
		return new BooleanCast();
	}
private:
	Float* value;
};


class Absolute : public PositionalMethodSymbol {
public:
	Absolute();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Absolute* clone() {
		return new Absolute();
	}
private:
	Float* value;
};


class LogE : public PositionalMethodSymbol {
public:
	LogE();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual LogE* clone() {
		return new LogE();
	}
private:
	Float* value;
	Expression* valueNode;
};

class LogBase : public PositionalMethodSymbol {
public:
	LogBase();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual LogBase* clone() {
		return new LogBase();
	}
private:
	Float* value;
	Float* base;
	Expression* valueNode;
	Expression* baseNode;
};


class SquareRoot : public PositionalMethodSymbol {
public:
	SquareRoot();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual SquareRoot* clone() {
		return new SquareRoot();
	}
private:
	Float* value;
	Expression* valueNode;
};


class LCM : public PositionalMethodSymbol {
public:
	LCM();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual LCM* clone() {
		return new LCM();
	}
private:
	Float* value1;
	Float* value2;
};


class GCD : public PositionalMethodSymbol {
public:
	GCD();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual GCD* clone() {
		return new GCD();
	}
private:
	Float* value1;
	Float* value2;
};



class Variance : public PositionalMethodSymbol {
public:
	Variance();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Variance* clone() {
		return new Variance();
	}
private:
	std::deque<float> buffer;
	Float* value;
	Float* amount;
	Expression* amountNode;
};

class STD : public PositionalMethodSymbol {
public:
	STD();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual STD* clone() {
		return new STD();
	}
private:
	std::deque<float> buffer;
	Float* value;
	Float* amount;
	Expression* amountNode;
};


class MA : public PositionalMethodSymbol {
public:
	MA();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual MA* clone() {
		return new MA();
	}
private:
	std::deque<float> buffer;
	Float* value;
	Float* amount;
	Expression* amountNode;
};


class IsNANF : public PositionalMethodSymbol {
public:
	IsNANF();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual IsNANF* clone() {
		return new IsNANF();
	}
private:
	Float* value;
};



class IsNANB : public PositionalMethodSymbol {
public:
	IsNANB();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual IsNANB* clone() {
		return new IsNANB();
	}
private:
	Boolean* value;
};

class IsNANS : public PositionalMethodSymbol {
public:
	IsNANS();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual IsNANS* clone() {
		return new IsNANS();
	}
private:
	String* value;
};


class Random : public PositionalMethodSymbol {
public:
	Random();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Random* clone() {
		return new Random();
	}
private:
	Float* minvalue;
	Float* maxvalue;
};



class Falling : public PositionalMethodSymbol {
public:
	Falling();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Falling* clone() {
		return new Falling();
	}
private:
	float currentMin = std::numeric_limits<float>::max();
	int inRow = 0;
	Float* value;
	Float* amount;
	Expression* amountNode;
};

class Rising : public PositionalMethodSymbol {
public:
	Rising();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Rising* clone() {
		return new Rising();
	}
private:
	float currentMax = std::numeric_limits<float>::min();
	int inRow = 0;
	Float* value;
	Float* amount;
	Expression* amountNode;
};


class Cosine : public PositionalMethodSymbol {
public:
	Cosine();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Cosine* clone() {
		return new Cosine();
	}
private:
	Float* radians;

};



class Tangent : public PositionalMethodSymbol {
public:
	Tangent();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Tangent* clone() {
		return new Tangent();
	}
private:
	Float* radians;
};


class Sine : public PositionalMethodSymbol {
public:
	Sine();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Sine* clone() {
		return new Sine();
	}
private:
	Float* radians;
};

class ArcCosine : public PositionalMethodSymbol {
public:
	ArcCosine();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual ArcCosine* clone() {
		return new ArcCosine();
	}
private:
	Float* radians;
};


class ArcTan : public PositionalMethodSymbol {
public:
	ArcTan();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual ArcTan* clone() {
		return new ArcTan();
	}
private:
	Float* radians;
};


class ArcSine : public PositionalMethodSymbol {
public:
	ArcSine();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual ArcSine* clone() {
		return new ArcSine();
	}
private:
	Float* radians;
};


class LinearRegression : public PositionalMethodSymbol {
public:
	LinearRegression();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual LinearRegression* clone() {
		return new LinearRegression();
	}
private:
	std::deque<float> bufferX;
	std::deque<float> bufferY;
	Float* data;
	Float* bars;
	Expression* barsNode;
};

class Correlation : public PositionalMethodSymbol {
public:
	Correlation();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Correlation* clone() {
		return new Correlation();
	}
private:
	std::deque<float> values1;
	std::deque<float> values2;
	Float* data1;
	Float* data2;
	Float* length;
	Expression* lengthNode;

};

class PreviousValue : public PositionalMethodSymbol {
public:
	PreviousValue();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);

	virtual PreviousValue* clone() {
		return new PreviousValue();
	}
private:

	std::vector<Float> values;
	Float* data;
	Float* barsback;
	Expression* barsbackNode;
};


class Median : public PositionalMethodSymbol {
public:
	Median();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);

	virtual Median* clone() {
		return new Median();
	}
private:

	std::vector<float> values;
	Float* data;

};


class MedianBars : public PositionalMethodSymbol {
public:
	MedianBars();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);

	virtual MedianBars* clone() {
		return new MedianBars();
	}
private:

	std::vector<float> values;
	Float* data;
	Float* barsback;

};


class IsPrime : public PositionalMethodSymbol {
public:
	IsPrime();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);

	virtual IsPrime* clone() {
		return new IsPrime();
	}
private:
	Float* data;
};


class IsTriangle : public PositionalMethodSymbol {
public:
	IsTriangle();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);

	virtual IsTriangle* clone() {
		return new IsTriangle();
	}
private:
	Float* data;
};