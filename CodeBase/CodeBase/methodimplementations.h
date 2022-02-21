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
	NullableValueNumber* value1;
	NullableValueNumber* value2;
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
	NullableValueNumber* value;
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
	NullableValueNumber* value;
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
	NullableValueBoolean* value;
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
	NullableValueNumber* lhsValue;
	NullableValueNumber* rhsValue;
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
	NullableValueNumber* lhsValue;
	NullableValueNumber* rhsValue;
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
	NullableValueNumber* lhsValue;
	NullableValueNumber* rhsValue;
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
	NullableValueNumber* lhsValue;
	NullableValueNumber* rhsValue;
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
	NullableValueNumber* lhsValue;
	NullableValueNumber* rhsValue;
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
	NullableValueNumber* lhsValue;
	NullableValueNumber* rhsValue;
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
	NullableValueNumber* lhsValue;
	NullableValueNumber* rhsValue;
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
	NullableValueNumber* lhsValue;
	NullableValueNumber* rhsValue;
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
	NullableValueNumber* lhsValue;
	NullableValueNumber* rhsValue;
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
	NullableValueNumber* lhsValue;
	NullableValueNumber* rhsValue;
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
	NullableValueBoolean* lhsValue;
	NullableValueBoolean* rhsValue;
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
	NullableValueBoolean* lhsValue;
	NullableValueBoolean* rhsValue;
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
	NullableValueBoolean* lhsValue;
	NullableValueBoolean* rhsValue;
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
	NullableValueNumber* lhsValue;
	NullableValueNumber* rhsValue;
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
	NullableValueBoolean* lhsValue;
	NullableValueBoolean* rhsValue;
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
	NullableValueNumber* lhsValue;
	NullableValueNumber* rhsValue;
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
	NullableValueNumber* value;
	NullableValueString* lineName;
	NullableValueString* chartId;
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

	NullableValueBoolean* when;
	NullableValueNumber* value;
	NullableValueString* lineName;
	NullableValueString* chartId;
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
	ExpressionValue currentValue{ NullableValueNumber() };
	NullableValueBoolean* when;
	NullableValueNumber* value;
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
	ExpressionValue minimumValue{ NullableValueNumber(std::numeric_limits<float>::max()) };
	NullableValueNumber* value;

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
	NullableValueNumber* value;
	NullableValueNumber* bars_back;
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
	ExpressionValue maximumValue{ NullableValueNumber(std::numeric_limits<float>::min()) };
	NullableValueNumber* value;
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

	NullableValueNumber* value;
	NullableValueNumber* bars_back;
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
	NullableValueNumber* value;

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


	NullableValueNumber* value;
	NullableValueNumber* bars_back;
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
	NullableValueNumber* value;

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
	NullableValueNumber* value;
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
	NullableValueNumber* value;
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
	NullableValueNumber* value;
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
	NullableValueBoolean* value;
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
	NullableValueBoolean* value;
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
	NullableValueNumber* value;
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
	NullableValueNumber* value;
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
	NullableValueNumber* value;
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
	NullableValueNumber* value;
	NullableValueNumber* base;
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
	NullableValueNumber* value;
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
	NullableValueNumber* value1;
	NullableValueNumber* value2;
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
	NullableValueNumber* value1;
	NullableValueNumber* value2;
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
	NullableValueNumber* value;
	NullableValueNumber* amount;
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
	NullableValueNumber* value;
	NullableValueNumber* amount;
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
	NullableValueNumber* value;
	NullableValueNumber* amount;
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
	NullableValueNumber* value;
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
	NullableValueBoolean* value;
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
	NullableValueString* value;
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
	NullableValueNumber* minvalue;
	NullableValueNumber* maxvalue;
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
	NullableValueNumber* value;
	NullableValueNumber* amount;
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
	NullableValueNumber* value;
	NullableValueNumber* amount;
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
	NullableValueNumber* radians;

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
	NullableValueNumber* radians;
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
	NullableValueNumber* radians;
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
	NullableValueNumber* radians;
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
	NullableValueNumber* radians;
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
	NullableValueNumber* radians;
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
	NullableValueNumber* data;
	NullableValueNumber* bars;
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
	NullableValueNumber* data1;
	NullableValueNumber* data2;
	NullableValueNumber* length;
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

	std::vector<NullableValueNumber> values;
	NullableValueNumber* data;
	NullableValueNumber* barsback;
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
	NullableValueNumber* data;

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
	NullableValueNumber* data;
	NullableValueNumber* barsback;

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
	NullableValueNumber* data;
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
	NullableValueNumber* data;
};