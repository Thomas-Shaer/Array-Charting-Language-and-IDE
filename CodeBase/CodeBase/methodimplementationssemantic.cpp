#include "methodimplementations.h"
#include "node.h"
#include "typesymbol.h"
#include "argumentsymbol.h"
#include "interpretercontext.h"
#include "chartwindow.h"
#include "chartplot.h"

const TypeSymbol* MethodAverage::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value1 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value1"]->expressionValue);
	value2 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value2"]->expressionValue);
	return returnType;
}



const TypeSymbol* UnaryPlusOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["expr"]->expressionValue);
	return returnType;
}


const TypeSymbol* UnaryMinusOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["expr"]->expressionValue);

	return returnType;


}

const TypeSymbol* UnaryNotOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["expr"]->expressionValue);
	return returnType;

}


const TypeSymbol* BinaryPlusOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;

}

const TypeSymbol* BinaryStringConcat::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;

}


const TypeSymbol* BinaryMinusOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

const TypeSymbol* BinaryDivideOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	rhsNode = methodCallNode->expressionToArgList["rhs"]->expression;

	return returnType;
}


const TypeSymbol* BinaryMultiplyOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

const TypeSymbol* BinaryPowOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	rhsNode = methodCallNode->expressionToArgList["rhs"]->expression;
	return returnType;
}


const TypeSymbol* BinaryModOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	rhsNode = methodCallNode->expressionToArgList["rhs"]->expression;
	return returnType;
}


const TypeSymbol* BinaryLessOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}



const TypeSymbol* BinaryLessEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}



const TypeSymbol* BinaryGreaterOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}


const TypeSymbol* BinaryGreaterEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}


const TypeSymbol* BinaryAndOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

const TypeSymbol* BinaryOrOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}


const TypeSymbol* BinaryBooleanEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}


const TypeSymbol* BinaryFloatEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

const TypeSymbol* BinaryStringEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}


const TypeSymbol* BinaryBooleanNotEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}


const TypeSymbol* BinaryFloatNotEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}



const TypeSymbol* BinaryStringNotEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["rhs"]->expressionValue);
	return returnType;
}

const TypeSymbol* GetTick::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}



const TypeSymbol* Plot::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {

	const TypeSymbol* returnType = KeywordMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	lineName = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["name"]->expressionValue);
	chartId = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["chart_id"]->expressionValue);


	if (!InterpreterContext::isIntellisense) {
		std::shared_ptr<ChartPlot> newData = std::make_shared<ChartPlot>(*lineName->value, InterpreterContext::ticks);
		ChartWindow::getOrCreateChartWindow(*chartId->value)->CHART_LINE_DATA.push_back(newData);
		std::shared_ptr<ChartPlot> first = ChartWindow::getOrCreateChartWindow(*chartId->value)->CHART_LINE_DATA.back(); //returns reference, not iterator, to the first object in the vector so you had only to write the data type in the generic of your vector, i.e. myObject, and not all the iterator stuff and the vector again and :: of course
		plotdata = first;
	}
	return returnType;

}


const TypeSymbol* Mark::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = KeywordMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	when = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["when"]->expressionValue);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	lineName = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["name"]->expressionValue);
	chartId = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["chart_id"]->expressionValue);


	if (!InterpreterContext::isIntellisense) {
		std::shared_ptr<ChartPlot> newData = std::make_shared<ChartPlot>(*lineName->value, InterpreterContext::ticks);

		ChartWindow::getOrCreateChartWindow(*chartId->value)->CHART_MARK_DATA.push_back(newData);
		std::shared_ptr<ChartPlot> first = ChartWindow::getOrCreateChartWindow(*chartId->value)->CHART_MARK_DATA.back(); //returns reference, not iterator, to the first object in the vector so you had only to write the data type in the generic of your vector, i.e. myObject, and not all the iterator stuff and the vector again and :: of course
		plotdata = first;
	}

	return returnType;
}



const TypeSymbol* ValueWhenNumber::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	when = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["when"]->expressionValue);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}


const TypeSymbol* ValueWhenBoolean::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	when = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["when"]->expressionValue);
	value = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}


const TypeSymbol* ValueWhenString::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	when = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["when"]->expressionValue);
	value = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}



const TypeSymbol* FloatNAN::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}


const TypeSymbol* BooleanNAN::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}

const TypeSymbol* StringNAN::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}

const TypeSymbol* Minimum::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}



const TypeSymbol* MinimumBars::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["bars_back"]->expressionValue);
	barsBackNode = methodCallNode->expressionToArgList["bars_back"]->expression;
	return returnType;
}


const TypeSymbol* Maximum::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* MaximumBars::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["bars_back"]->expressionValue);
	barsBackNode = methodCallNode->expressionToArgList["bars_back"]->expression;

	return returnType;
}

const TypeSymbol* Sum::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* SumBars::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["bars_back"]->expressionValue);
	barsBackNode = methodCallNode->expressionToArgList["bars_back"]->expression;

	return returnType;
}

const TypeSymbol* Mean::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}


const TypeSymbol* GetPi::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}

const TypeSymbol* GetE::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}


const TypeSymbol* Round::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* Floor::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* Ceil::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* MaxNumber::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}

const TypeSymbol* MinNumber::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}


const TypeSymbol* Count::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["condition"]->expressionValue);
	return returnType;
}

const TypeSymbol* Boolean2FloatCast::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* Boolean2StringCast::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* Float2StringCast::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}


const TypeSymbol* Float2BooleanCast::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* Absolute::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}


const TypeSymbol* LogE::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	valueNode = methodCallNode->expressionToArgList["value"]->expression;
	return returnType;
}



const TypeSymbol* LogBase::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	base = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["base"]->expressionValue);
	valueNode = methodCallNode->expressionToArgList["value"]->expression;
	baseNode = methodCallNode->expressionToArgList["base"]->expression;

	return returnType;
}

const TypeSymbol* SquareRoot::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	valueNode = methodCallNode->expressionToArgList["value"]->expression;
	return returnType;
}

const TypeSymbol* LCM::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value1 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value1"]->expressionValue);
	value2 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value2"]->expressionValue);
	value1Node = methodCallNode->expressionToArgList["value1"]->expression;
	value2Node = methodCallNode->expressionToArgList["value2"]->expression;

	return returnType;
}


const TypeSymbol* GCD::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value1 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value1"]->expressionValue);
	value2 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value2"]->expressionValue);
	value1Node = methodCallNode->expressionToArgList["value1"]->expression;
	value2Node = methodCallNode->expressionToArgList["value2"]->expression;
	return returnType;
}

const TypeSymbol* Variance::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	amount = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["amount"]->expressionValue);
	amountNode = methodCallNode->expressionToArgList["amount"]->expression;

	return returnType;
}


const TypeSymbol* STD::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	amount = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["amount"]->expressionValue);
	amountNode = methodCallNode->expressionToArgList["amount"]->expression;

	return returnType;
}

const TypeSymbol* MA::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	amount = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["amount"]->expressionValue);
	amountNode = methodCallNode->expressionToArgList["amount"]->expression;

	return returnType;
}

const TypeSymbol* IsNANF::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* IsNANB::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* IsNANS::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* Random::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	minvalue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["minvalue"]->expressionValue);
	maxvalue = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["maxvalue"]->expressionValue);
	return returnType;
}

const TypeSymbol* Falling::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	amount = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["amount"]->expressionValue);
	amountNode = methodCallNode->expressionToArgList["amount"]->expression;

	return returnType;
}


const TypeSymbol* Rising::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["value"]->expressionValue);
	amount = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["amount"]->expressionValue);
	amountNode = methodCallNode->expressionToArgList["amount"]->expression;

	return returnType;
}

const TypeSymbol* Cosine::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["radians"]->expressionValue);
	return returnType;
}

const TypeSymbol* Tangent::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["radians"]->expressionValue);
	return returnType;
}


const TypeSymbol* Sine::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["radians"]->expressionValue);
	return returnType;
}

const TypeSymbol* ArcCosine::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["radians"]->expressionValue);
	return returnType;
}

const TypeSymbol* ArcTan::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["radians"]->expressionValue);
	return returnType;
}


const TypeSymbol* ArcSine::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["radians"]->expressionValue);
	return returnType;
}


const TypeSymbol* LinearRegression::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	bars = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["bars"]->expressionValue);
	barsNode = methodCallNode->expressionToArgList["bars"]->expression;

	return returnType;
}

const TypeSymbol* Correlation::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data1 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data1"]->expressionValue);
	data2 = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data2"]->expressionValue);
	length = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["length"]->expressionValue);
	lengthNode = methodCallNode->expressionToArgList["length"]->expression;
	return returnType;
}


const TypeSymbol* PreviousNumberValue::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	barsback = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["barsback"]->expressionValue);
	barsbackNode = methodCallNode->expressionToArgList["barsback"]->expression;
	return returnType;
}

const TypeSymbol* PreviousStringValue::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueString>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	barsback = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["barsback"]->expressionValue);
	barsbackNode = methodCallNode->expressionToArgList["barsback"]->expression;
	return returnType;
}

const TypeSymbol* PreviousBooleanValue::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueBoolean>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	barsback = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["barsback"]->expressionValue);
	barsbackNode = methodCallNode->expressionToArgList["barsback"]->expression;
	return returnType;
}


const TypeSymbol* Median::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	return returnType;
}


const TypeSymbol* MedianBars::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	barsback = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["barsback"]->expressionValue);
	return returnType;
}

const TypeSymbol* IsPrime::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	return returnType;
}

const TypeSymbol* IsTriangle::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->expressionToArgList["data"]->expressionValue);
	return returnType;
}

