#pragma once
#include "methodsymbol.h"
#include "typesymbol.h"
#include <vector>

#include <queue>
#include <deque>

class Expression;
class ChartPlot;

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

class BinaryStringConcat : public PositionalMethodSymbol {
public:
	BinaryStringConcat(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryStringConcat* clone() {
		return new BinaryStringConcat(name);
	}
private:
	NullableValueString* lhsValue;
	NullableValueString* rhsValue;
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
	Expression* rhsNode;
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
	Expression* rhsNode;
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
	Expression* rhsNode;
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


class BinaryStringEqualOperator : public PositionalMethodSymbol {
public:
	BinaryStringEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryStringEqualOperator* clone() {
		return new BinaryStringEqualOperator(name);
	}
private:
	NullableValueString* lhsValue;
	NullableValueString* rhsValue;
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

class BinaryStringNotEqualOperator : public PositionalMethodSymbol {
public:
	BinaryStringNotEqualOperator(const std::string& _name);
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual BinaryStringNotEqualOperator* clone() {
		return new BinaryStringNotEqualOperator(name);
	}
private:
	NullableValueString* lhsValue;
	NullableValueString* rhsValue;
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


class Text : public KeywordMethodSymbol {
public:
	Text();
	virtual ExpressionValue interpret(const unsigned int tick);
	virtual const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);
	virtual Text* clone() {
		return new Text();
	}
private:
	std::shared_ptr<ChartPlot> plotdata;

	NullableValueBoolean* when;
	NullableValueString* value;
	NullableValueNumber* ylevel;
	NullableValueBoolean* vertical;
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


class ValueWhenNumber : public PositionalMethodSymbol {
public:
	ValueWhenNumber();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual ValueWhenNumber* clone() {
		return new ValueWhenNumber();
	}
private:
	NullableValueNumber currentValue;
	NullableValueBoolean* when;
	NullableValueNumber* value;
};


class ValueWhenBoolean : public PositionalMethodSymbol {
public:
	ValueWhenBoolean();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual ValueWhenBoolean* clone() {
		return new ValueWhenBoolean();
	}
private:
	NullableValueBoolean currentValue;
	NullableValueBoolean* when;
	NullableValueBoolean* value;
};

class ValueWhenString : public PositionalMethodSymbol {
public:
	ValueWhenString();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual ValueWhenString* clone() {
		return new ValueWhenString();
	}
private:
	NullableValueString currentValue;
	NullableValueBoolean* when;
	NullableValueString* value;
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
	NullableValueNumber currentMinimum{ std::numeric_limits<float>::max() };
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
	std::vector<float> buffer;
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
	NullableValueNumber maximumValue{-std::numeric_limits<float>::max() };
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
	std::vector<float> buffer;

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
	std::vector<float> buffer;


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

class MaxNumber : public PositionalMethodSymbol {
public:
	MaxNumber();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual MaxNumber* clone() {
		return new MaxNumber();
	}
};

class MinNumber : public PositionalMethodSymbol {
public:
	MinNumber();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual MinNumber* clone() {
		return new MinNumber();
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


class Boolean2NumberCast : public PositionalMethodSymbol {
public:
	Boolean2NumberCast();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Boolean2NumberCast* clone() {
		return new Boolean2NumberCast();
	}
private:
	NullableValueBoolean* value;
};

class Boolean2StringCast : public PositionalMethodSymbol {
public:
	Boolean2StringCast();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Boolean2StringCast* clone() {
		return new Boolean2StringCast();
	}
private:
	NullableValueBoolean* value;
};

class Float2BooleanCast : public PositionalMethodSymbol {
public:
	Float2BooleanCast();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Float2BooleanCast* clone() {
		return new Float2BooleanCast();
	}
private:
	NullableValueNumber* value;
};

class Float2StringCast : public PositionalMethodSymbol {
public:
	Float2StringCast();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual Float2StringCast* clone() {
		return new Float2StringCast();
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
	Expression* value1Node;
	NullableValueNumber* value2;
	Expression* value2Node;
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
	Expression* value1Node;
	NullableValueNumber* value2;
	Expression* value2Node;
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
	std::vector<float> buffer;
	NullableValueNumber* value;
	NullableValueNumber* bars_back;
	Expression* barsBackNode;
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
	std::vector<float> buffer;
	NullableValueNumber* value;
	NullableValueNumber* bars_back;
	Expression* barsBackNode;
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
	std::vector<float> buffer;
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
	std::vector<float> buffer;
	NullableValueNumber* value;
	NullableValueNumber* bars_back;
	Expression* barsBackNode;
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
	std::vector<float> buffer;
	NullableValueNumber* value;
	NullableValueNumber* bars_back;
	Expression* barsBackNode;
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
	Expression* arg;
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
	Expression* arg;
};


class LinearRegressionAtTick : public PositionalMethodSymbol {
public:
	LinearRegressionAtTick();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);
	virtual LinearRegressionAtTick* clone() {
		return new LinearRegressionAtTick();
	}
private:
	std::vector<float> buffer;
	NullableValueNumber* value;
	NullableValueNumber* bars_back;
	NullableValueNumber* xvalue;
	Expression* barsBackNode;
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
	std::vector<float> buffer1;
	std::vector<float> buffer2;
	NullableValueNumber* data1;
	NullableValueNumber* data2;
	NullableValueNumber* bars_back;
	Expression* barsBackNode;

};

class PreviousNumberValue : public PositionalMethodSymbol {
public:
	PreviousNumberValue();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);

	virtual PreviousNumberValue* clone() {
		return new PreviousNumberValue();
	}
private:

	std::vector<NullableValueNumber> buffer;
	NullableValueNumber* data;
	NullableValueNumber* barsback;
	Expression* barsbackNode;
};


class PreviousStringValue : public PositionalMethodSymbol {
public:
	PreviousStringValue();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);

	virtual PreviousStringValue* clone() {
		return new PreviousStringValue();
	}
private:

	std::vector<NullableValueString> buffer;
	NullableValueString* data;
	NullableValueNumber* barsback;
	Expression* barsbackNode;
};


class PreviousBooleanValue : public PositionalMethodSymbol {
public:
	PreviousBooleanValue();
	const TypeSymbol* semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable);

	virtual ExpressionValue interpret(const unsigned int tick);

	virtual PreviousBooleanValue* clone() {
		return new PreviousBooleanValue();
	}
private:

	std::vector<NullableValueBoolean> buffer;
	NullableValueBoolean* data;
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

	std::vector<float> buffer;
	NullableValueNumber* value;
	NullableValueNumber* bars_back;
	Expression* barsBackNode;

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