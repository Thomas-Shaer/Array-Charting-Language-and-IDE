


#include "symboltable.h"
#include "varsymbol.h"
#include "methodsymbol.h"
#include "methodimplementations.h"
#include "methodbucket.h"

// have to forward declare for whatever reason to keep bison include happy
class NumberNode;
class BooleanNode;
class Expression;
class Statement;
class Node;
class BinaryOpNode;
class BlockNode;
class StringNode;
class AssignNode;
class IdentifierNode;
class KeywordNode;
class MethodCallNode;
class ExpressionStatementNode;
class IfStatementNode;
class TernaryNode;

#include "bison.tab.h"

/*
A helper function that sets the method buckets name to the same as the symbol table key.
*/
std::pair<std::string, MethodBucket*> registerMethod(const std::string& name, MethodBucket* bucket) {
	bucket->name = name;
	return { name, bucket };
}


std::shared_ptr<SymbolTable> SymbolTable::GLOBAL_SYMBOL_TABLE = std::make_shared<SymbolTable>(

	// methods declarations
	std::map<std::string, MethodBucket*>({
		registerMethod("average", new SingleMethodBucket(new MethodAverage(), METHOD_CAT::MATHEMATICAL)),
	//{"average", new SingleMethodBucket(new MethodAverage(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("plot", new SingleMethodBucket(new Plot(), METHOD_CAT::OUTPUT)),
	registerMethod("tick", new SingleMethodBucket(new GetTick(), METHOD_CAT::MISC)),
	registerMethod("mark", new SingleMethodBucket(new Mark(), METHOD_CAT::OUTPUT)),

	registerMethod("nan_f", new SingleMethodBucket(new FloatNAN(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("nan_b", new SingleMethodBucket(new BooleanNAN(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("nan_s", new SingleMethodBucket(new StringNAN(), METHOD_CAT::MATHEMATICAL)),

	registerMethod("valuewhen", new OverloadedMethodBucket(
		{(new ValueWhenBoolean()),
		 (new ValueWhenNumber()),
		 (new ValueWhenString())
		}
	, METHOD_CAT::MATHEMATICAL)),


	registerMethod("min", new OverloadedMethodBucket(
		{(new Minimum()),
		 (new MinimumBars())
		}
	, METHOD_CAT::MATHEMATICAL)),


	registerMethod("max", new OverloadedMethodBucket(
		{(new Maximum()),
		 (new MaximumBars())
		}
	, METHOD_CAT::MATHEMATICAL)),


	registerMethod("sum", new OverloadedMethodBucket(
		{(new Sum()),
		 (new SumBars())
		}
	, METHOD_CAT::MATHEMATICAL)),

	registerMethod("mean", new SingleMethodBucket(new Mean(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("pi", new SingleMethodBucket(new GetPi(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("e", new SingleMethodBucket(new GetE(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("round", new SingleMethodBucket(new Round(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("floor", new SingleMethodBucket(new Floor(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("ceil", new SingleMethodBucket(new Ceil(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("maxnumber", new SingleMethodBucket(new MaxNumber(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("minnumber", new SingleMethodBucket(new MinNumber(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("count", new SingleMethodBucket(new Count(), METHOD_CAT::LOGIC)),


	registerMethod("float", new SingleMethodBucket(new Boolean2FloatCast(), METHOD_CAT::MISC)),
	
		
		
	registerMethod("boolean", new SingleMethodBucket(new Float2BooleanCast(), METHOD_CAT::MISC)),


	registerMethod("string", new OverloadedMethodBucket(
		{(new Float2StringCast()),
		 (new Boolean2StringCast())
		}
	, METHOD_CAT::MISC)),

	registerMethod("abs", new SingleMethodBucket(new Absolute(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("sqrt", new SingleMethodBucket(new SquareRoot(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("lcm", new SingleMethodBucket(new LCM(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("gcd", new SingleMethodBucket(new GCD(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("variance", new SingleMethodBucket(new Variance(), METHOD_CAT::STATISTICS)),
	registerMethod("std", new SingleMethodBucket(new STD(), METHOD_CAT::STATISTICS)),
	registerMethod("ma", new SingleMethodBucket(new MA(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("random", new SingleMethodBucket(new Random(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("falling", new SingleMethodBucket(new Falling(), METHOD_CAT::LOGIC)),
	registerMethod("rising", new SingleMethodBucket(new Rising(), METHOD_CAT::LOGIC)),
	registerMethod("cos", new SingleMethodBucket(new Cosine(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("tan", new SingleMethodBucket(new Tangent(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("sin", new SingleMethodBucket(new Sine(), METHOD_CAT::MATHEMATICAL)),
	registerMethod("acos", new SingleMethodBucket(new ArcCosine(), METHOD_CAT::MATHEMATICAL)),
		registerMethod("atan", new SingleMethodBucket(new ArcTan(), METHOD_CAT::MATHEMATICAL)),
		registerMethod("asin", new SingleMethodBucket(new ArcSine(), METHOD_CAT::MATHEMATICAL)),
		registerMethod("linreg", new SingleMethodBucket(new LinearRegressionAtTick(), METHOD_CAT::STATISTICS)),
		registerMethod("corr", new SingleMethodBucket(new Correlation(), METHOD_CAT::STATISTICS)),

			registerMethod("prev", new OverloadedMethodBucket(
		{(new PreviousNumberValue()),
		 (new PreviousStringValue()),
		 (new PreviousBooleanValue())
		}
	, METHOD_CAT::MISC)),

		registerMethod("isprime", new SingleMethodBucket(new IsPrime(), METHOD_CAT::MATHEMATICAL)),
		registerMethod("istriangle", new SingleMethodBucket(new IsTriangle(), METHOD_CAT::MATHEMATICAL)),


		registerMethod("median", new OverloadedMethodBucket(
		{(new Median()),
		 (new MedianBars())
		}
	,METHOD_CAT::MATHEMATICAL)),


	registerMethod("log", new OverloadedMethodBucket(
		{(new LogE()),
		 (new LogBase())
		}
	,METHOD_CAT::MATHEMATICAL)),

	registerMethod("isnan", new OverloadedMethodBucket(
		{(new IsNANF()),
		(new IsNANB()),
		(new IsNANS())
		}
	,METHOD_CAT::LOGIC)),



	registerMethod("operator" + token_name(yy::parser::token::TPLUS), new OverloadedMethodBucket(
		{new UnaryPlusOperator("operator" + token_name(yy::parser::token::TPLUS)),
		 new BinaryPlusOperator("operator" + token_name(yy::parser::token::TPLUS)),
		 new BinaryStringConcat("operator" + token_name(yy::parser::token::TPLUS))
		}
	,METHOD_CAT::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TMINUS), new OverloadedMethodBucket(
		{new UnaryMinusOperator("operator" + token_name(yy::parser::token::TMINUS)),
		 new BinaryMinusOperator("operator" + token_name(yy::parser::token::TMINUS))
		}
	,METHOD_CAT::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TEQUAL), new OverloadedMethodBucket(
		{new BinaryFloatEqualOperator("operator" + token_name(yy::parser::token::TEQUAL)),
		 new BinaryBooleanEqualOperator("operator" + token_name(yy::parser::token::TEQUAL)),
		 new BinaryStringEqualOperator("operator" + token_name(yy::parser::token::TEQUAL))
		}
	,METHOD_CAT::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TNOTEQUAL), new OverloadedMethodBucket(
		{new BinaryFloatNotEqualOperator("operator" + token_name(yy::parser::token::TNOTEQUAL)),
		 new BinaryBooleanNotEqualOperator("operator" + token_name(yy::parser::token::TNOTEQUAL)),
		 new BinaryStringNotEqualOperator("operator" + token_name(yy::parser::token::TNOTEQUAL))
		}
	,METHOD_CAT::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TNOT), new SingleMethodBucket(new UnaryNotOperator("operator" + token_name(yy::parser::token::TNOT)),METHOD_CAT::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TMUL), new SingleMethodBucket(new BinaryMultiplyOperator("operator" + token_name(yy::parser::token::TMUL)),METHOD_CAT::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TDIV), new SingleMethodBucket(new BinaryDivideOperator("operator" + token_name(yy::parser::token::TDIV)),METHOD_CAT::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TLESS), new SingleMethodBucket(new BinaryLessOperator("operator" + token_name(yy::parser::token::TLESS)),METHOD_CAT::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TLESSEQUAL), new SingleMethodBucket(new BinaryLessEqualOperator("operator" + token_name(yy::parser::token::TLESSEQUAL)),METHOD_CAT::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TGREATER), new SingleMethodBucket(new BinaryGreaterOperator("operator" + token_name(yy::parser::token::TGREATER)),METHOD_CAT::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TGREATEREQUAL), new SingleMethodBucket(new BinaryGreaterEqualOperator("operator" + token_name(yy::parser::token::TGREATEREQUAL)),METHOD_CAT::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TAND), new SingleMethodBucket(new BinaryAndOperator("operator" + token_name(yy::parser::token::TAND)),METHOD_CAT::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TOR), new SingleMethodBucket(new BinaryOrOperator("operator" + token_name(yy::parser::token::TOR)),METHOD_CAT::OPERATOR)),


		registerMethod("operator" + token_name(yy::parser::token::TPOW), new SingleMethodBucket(new BinaryPowOperator("operator" + token_name(yy::parser::token::TPOW)), METHOD_CAT::OPERATOR)),
		registerMethod("operator" + token_name(yy::parser::token::TMOD), new SingleMethodBucket(new BinaryModOperator("operator" + token_name(yy::parser::token::TMOD)), METHOD_CAT::OPERATOR)),

	}),
	

	// variables declarations
	std::map<std::string, std::shared_ptr<VarSymbol>>({})
	);



SymbolTable::SymbolTable(std::shared_ptr<SymbolTable> _enclosingSymbolTable) 
	: enclosingSymbolTable(_enclosingSymbolTable) {}

SymbolTable::SymbolTable(std::map<std::string, MethodBucket*> _methodTable,
	std::map<std::string, std::shared_ptr<VarSymbol>> _variableTable)
	: methodTable(_methodTable), variableTable(_variableTable) {}

std::string SymbolTable::toString() {
	std::string output = "SYMBOL TABLE\nVariables:\n";

	for (const auto& value : variableTable) {
		output += value.second->toString() + "\n";
	}

	output += "Methods:\n";

	for (const auto& value : methodTable) {
		output += value.second->toString() + "\n";
	}

	return output;
}


std::vector<std::shared_ptr<VarSymbol>> SymbolTable::variablesToVector(bool _enclosing) {
	std::vector<std::shared_ptr<VarSymbol>> table;
	for (auto pair : variableTable) {
		table.push_back(pair.second);
	}
	if (_enclosing) {
		if (enclosingSymbolTable) {
			auto newTable = enclosingSymbolTable->variablesToVector(_enclosing);
			table.insert(table.end(), newTable.begin(), newTable.end());
		}
	}
	return table;
}



bool SymbolTable::isVariableDeclared(const std::string& name) {
	if (variableTable.find(name) != variableTable.end()) {
		return true;
	}
	else {
		if (enclosingSymbolTable) {
			return enclosingSymbolTable->isVariableDeclared(name);
		}
	}

	return false;
}

bool SymbolTable::isMethodDeclared(const std::string& name) {

	if (methodTable.find(name) != methodTable.end()) {
		return true;
	}
	else {
		if (enclosingSymbolTable) {
			return enclosingSymbolTable->isMethodDeclared(name);
		}
	}

	return false;
}

std::shared_ptr<VarSymbol> SymbolTable::getVariable(const std::string& name) {
	if (variableTable.find(name) != variableTable.end()) {
		return variableTable.find(name)->second;
	}
	else {
		if (enclosingSymbolTable) {
			return enclosingSymbolTable->getVariable(name);
		}
	}
	return nullptr;
}


MethodBucket* SymbolTable::getMethod(const std::string& name) {



	if (methodTable.find(name) != methodTable.end()) {
		return methodTable.find(name)->second;
	}
	else {
		if (enclosingSymbolTable) {
			return enclosingSymbolTable->getMethod(name);
		}
	}
	return nullptr;
}

void SymbolTable::declareVariable(std::shared_ptr<VarSymbol> varsymbol) {
	variableTable[varsymbol->name] = varsymbol;
}
