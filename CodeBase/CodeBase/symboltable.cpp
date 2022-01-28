


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
class AssignNode;
class IdentifierNode;
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
		registerMethod("average", new SingleMethodBucket(new MethodAverage(), METHOD_TYPE::MATHEMATICAL)),
	//{"average", new SingleMethodBucket(new MethodAverage(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("plot", new SingleMethodBucket(new Plot(), METHOD_TYPE::OUTPUT)),
	registerMethod("tick", new SingleMethodBucket(new GetTick(), METHOD_TYPE::MISC)),
	registerMethod("mark", new SingleMethodBucket(new Mark(), METHOD_TYPE::MATHEMATICAL)),

	registerMethod("nan_f", new SingleMethodBucket(new FloatNAN(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("nan_b", new SingleMethodBucket(new BooleanNAN(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("valuewhen", new SingleMethodBucket(new ValueWhen(), METHOD_TYPE::LOGIC)),

	registerMethod("min", new OverloadedMethodBucket(
		{(new Minimum()),
		 (new MinimumBars())
		}
	, METHOD_TYPE::MATHEMATICAL)),


	registerMethod("max", new OverloadedMethodBucket(
		{(new Maximum()),
		 (new MaximumBars())
		}
	, METHOD_TYPE::MATHEMATICAL)),


	registerMethod("sum", new OverloadedMethodBucket(
		{(new Sum()),
		 (new SumBars())
		}
	, METHOD_TYPE::MATHEMATICAL)),

	registerMethod("mean", new SingleMethodBucket(new Mean(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("pi", new SingleMethodBucket(new GetPi(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("e", new SingleMethodBucket(new GetE(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("round", new SingleMethodBucket(new Round(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("floor", new SingleMethodBucket(new Floor(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("ceil", new SingleMethodBucket(new Ceil(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("floatmax", new SingleMethodBucket(new FloatMax(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("floatmin", new SingleMethodBucket(new FloatMin(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("count", new SingleMethodBucket(new Count(), METHOD_TYPE::LOGIC)),
	registerMethod("float", new SingleMethodBucket(new FloatCast(), METHOD_TYPE::MISC)),
	registerMethod("boolean", new SingleMethodBucket(new BooleanCast(), METHOD_TYPE::MISC)),
	registerMethod("abs", new SingleMethodBucket(new Absolute(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("sqrt", new SingleMethodBucket(new SquareRoot(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("lcm", new SingleMethodBucket(new LCM(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("gcd", new SingleMethodBucket(new GCD(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("variance", new SingleMethodBucket(new Variance(), METHOD_TYPE::STATISTICS)),
	registerMethod("std", new SingleMethodBucket(new STD(), METHOD_TYPE::STATISTICS)),
	registerMethod("ma", new SingleMethodBucket(new MA(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("random", new SingleMethodBucket(new Random(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("falling", new SingleMethodBucket(new Falling(), METHOD_TYPE::LOGIC)),
	registerMethod("rising", new SingleMethodBucket(new Rising(), METHOD_TYPE::LOGIC)),
	registerMethod("cos", new SingleMethodBucket(new Cosine(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("tan", new SingleMethodBucket(new Tangent(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("sin", new SingleMethodBucket(new Sine(), METHOD_TYPE::MATHEMATICAL)),
	registerMethod("acos", new SingleMethodBucket(new ArcCosine(), METHOD_TYPE::MATHEMATICAL)),
		registerMethod("atan", new SingleMethodBucket(new ArcTan(), METHOD_TYPE::MATHEMATICAL)),
		registerMethod("asin", new SingleMethodBucket(new ArcSine(), METHOD_TYPE::MATHEMATICAL)),
		registerMethod("linreg", new SingleMethodBucket(new LinearRegression(), METHOD_TYPE::STATISTICS)),
		registerMethod("correlation", new SingleMethodBucket(new Correlation(), METHOD_TYPE::STATISTICS)),
		registerMethod("prev", new SingleMethodBucket(new PreviousValue(), METHOD_TYPE::MISC)),
		registerMethod("isprime", new SingleMethodBucket(new IsPrime(), METHOD_TYPE::MATHEMATICAL)),
		registerMethod("istriangle", new SingleMethodBucket(new IsTriangle(), METHOD_TYPE::MATHEMATICAL)),


		registerMethod("median", new OverloadedMethodBucket(
		{(new Median()),
		 (new MedianBars())
		}
	,METHOD_TYPE::MATHEMATICAL)),


	registerMethod("log", new OverloadedMethodBucket(
		{(new LogE()),
		 (new LogBase())
		}
	,METHOD_TYPE::MATHEMATICAL)),

	registerMethod("isnan", new OverloadedMethodBucket(
		{(new IsNANF()),
		(new IsNANB())
		}
	,METHOD_TYPE::LOGIC)),



	registerMethod("operator" + token_name(yy::parser::token::TPLUS), new OverloadedMethodBucket(
		{new UnaryPlusOperator("operator" + token_name(yy::parser::token::TPLUS)),
		 new BinaryPlusOperator("operator" + token_name(yy::parser::token::TPLUS))
		}
	,METHOD_TYPE::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TMINUS), new OverloadedMethodBucket(
		{new UnaryMinusOperator("operator" + token_name(yy::parser::token::TMINUS)),
		 new BinaryMinusOperator("operator" + token_name(yy::parser::token::TMINUS))
		}
	,METHOD_TYPE::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TEQUAL), new OverloadedMethodBucket(
		{new BinaryFloatEqualOperator("operator" + token_name(yy::parser::token::TEQUAL)),
		 new BinaryBooleanEqualOperator("operator" + token_name(yy::parser::token::TEQUAL))
		}
	,METHOD_TYPE::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TNOTEQUAL), new OverloadedMethodBucket(
		{new BinaryFloatNotEqualOperator("operator" + token_name(yy::parser::token::TNOTEQUAL)),
		 new BinaryBooleanNotEqualOperator("operator" + token_name(yy::parser::token::TNOTEQUAL))
		}
	,METHOD_TYPE::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TNOT), new SingleMethodBucket(new UnaryNotOperator("operator" + token_name(yy::parser::token::TNOT)),METHOD_TYPE::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TMUL), new SingleMethodBucket(new BinaryMultiplyOperator("operator" + token_name(yy::parser::token::TMUL)),METHOD_TYPE::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TDIV), new SingleMethodBucket(new BinaryDivideOperator("operator" + token_name(yy::parser::token::TDIV)),METHOD_TYPE::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TLESS), new SingleMethodBucket(new BinaryLessOperator("operator" + token_name(yy::parser::token::TLESS)),METHOD_TYPE::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TLESSEQUAL), new SingleMethodBucket(new BinaryLessEqualOperator("operator" + token_name(yy::parser::token::TLESSEQUAL)),METHOD_TYPE::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TGREATER), new SingleMethodBucket(new BinaryGreaterOperator("operator" + token_name(yy::parser::token::TGREATER)),METHOD_TYPE::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TGREATEREQUAL), new SingleMethodBucket(new BinaryGreaterEqualOperator("operator" + token_name(yy::parser::token::TGREATEREQUAL)),METHOD_TYPE::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TAND), new SingleMethodBucket(new BinaryAndOperator("operator" + token_name(yy::parser::token::TAND)),METHOD_TYPE::OPERATOR)),
	registerMethod("operator" + token_name(yy::parser::token::TOR), new SingleMethodBucket(new BinaryOrOperator("operator" + token_name(yy::parser::token::TOR)),METHOD_TYPE::OPERATOR)),


		registerMethod("operator" + token_name(yy::parser::token::TPOW), new SingleMethodBucket(new BinaryPowOperator("operator" + token_name(yy::parser::token::TPOW)), METHOD_TYPE::OPERATOR)),
		registerMethod("operator" + token_name(yy::parser::token::TMOD), new SingleMethodBucket(new BinaryModOperator("operator" + token_name(yy::parser::token::TMOD)), METHOD_TYPE::OPERATOR)),

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

std::string SymbolTable::variablesToString(bool _enclosing) {
	std::string output = "";
	for (const auto& value : variableTable) {
		output += value.second->toString() + "\n";
	}
	if (_enclosing) {
		if (enclosingSymbolTable) {
			output += "######\n";
			output += enclosingSymbolTable->variablesToString(_enclosing);
		}
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
