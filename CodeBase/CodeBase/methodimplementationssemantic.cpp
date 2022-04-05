#include "methodimplementations.h"
#include "node.h"
#include "typesymbol.h"
#include "argumentsymbol.h"
#include "interpretercontext.h"
#include "chartwindow.h"
#include "chartplot.h"

const TypeSymbol* MethodAverage::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	// execute generic type checking
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	// save pointers to locations where the runtime argument values will be stored
	value1 = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value1"]->expressionValue);
	value2 = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value2"]->expressionValue);
	// return the method type of the method
	return returnType;
}



const TypeSymbol* UnaryPlusOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["expr"]->expressionValue);
	return returnType;
}


const TypeSymbol* UnaryMinusOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["expr"]->expressionValue);

	return returnType;


}

const TypeSymbol* UnaryNotOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["expr"]->expressionValue);
	return returnType;

}


const TypeSymbol* BinaryPlusOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;

}

const TypeSymbol* BinaryStringConcat::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;

}


const TypeSymbol* BinaryMinusOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}

const TypeSymbol* BinaryDivideOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	rhsNode = methodCallNode->argNameToArgumentSymbol["rhs"]->expression;

	return returnType;
}


const TypeSymbol* BinaryMultiplyOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}

const TypeSymbol* BinaryPowOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	rhsNode = methodCallNode->argNameToArgumentSymbol["rhs"]->expression;
	return returnType;
}


const TypeSymbol* BinaryModOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	rhsNode = methodCallNode->argNameToArgumentSymbol["rhs"]->expression;
	return returnType;
}


const TypeSymbol* BinaryLessOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}



const TypeSymbol* BinaryLessEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}



const TypeSymbol* BinaryGreaterOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}


const TypeSymbol* BinaryGreaterEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}


const TypeSymbol* BinaryAndOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}

const TypeSymbol* BinaryOrOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}


const TypeSymbol* BinaryBooleanEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}


const TypeSymbol* BinaryFloatEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}

const TypeSymbol* BinaryStringEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}


const TypeSymbol* BinaryBooleanNotEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}


const TypeSymbol* BinaryFloatNotEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}



const TypeSymbol* BinaryStringNotEqualOperator::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	lhsValue = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["lhs"]->expressionValue);
	rhsValue = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["rhs"]->expressionValue);
	return returnType;
}

const TypeSymbol* GetTick::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}



const TypeSymbol* Plot::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {

	const TypeSymbol* returnType = KeywordMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	lineName = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["name"]->expressionValue);
	chartId = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["chart_id"]->expressionValue);


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
	when = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["when"]->expressionValue);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	lineName = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["name"]->expressionValue);
	chartId = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["chart_id"]->expressionValue);


	if (!InterpreterContext::isIntellisense) {
		std::shared_ptr<ChartPlot> newData = std::make_shared<ChartPlot>(*lineName->value, InterpreterContext::ticks);

		ChartWindow::getOrCreateChartWindow(*chartId->value)->CHART_MARK_DATA.push_back(newData);
		std::shared_ptr<ChartPlot> first = ChartWindow::getOrCreateChartWindow(*chartId->value)->CHART_MARK_DATA.back(); //returns reference, not iterator, to the first object in the vector so you had only to write the data type in the generic of your vector, i.e. myObject, and not all the iterator stuff and the vector again and :: of course
		plotdata = first;
	}

	return returnType;
}

const TypeSymbol* Text::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = KeywordMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	when = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["when"]->expressionValue);
	value = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	ylevel = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["ylevel"]->expressionValue);
	lineName = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["name"]->expressionValue);
	chartId = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["chart_id"]->expressionValue);
	vertical = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["vertical"]->expressionValue);


	if (!InterpreterContext::isIntellisense) {
		std::shared_ptr<ChartPlot> newData = std::make_shared<ChartPlot>(*lineName->value, InterpreterContext::ticks);

		ChartWindow::getOrCreateChartWindow(*chartId->value)->CHART_MARK_DATA.push_back(newData);
		std::shared_ptr<ChartPlot> first = ChartWindow::getOrCreateChartWindow(*chartId->value)->CHART_MARK_DATA.back(); //returns reference, not iterator, to the first object in the vector so you had only to write the data type in the generic of your vector, i.e. myObject, and not all the iterator stuff and the vector again and :: of course
		plotdata = first;
		first->stringMark = true;
	}

	return returnType;
}



const TypeSymbol* ValueWhenNumber::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	when = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["when"]->expressionValue);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}


const TypeSymbol* ValueWhenBoolean::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	when = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["when"]->expressionValue);
	value = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}


const TypeSymbol* ValueWhenString::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	when = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["when"]->expressionValue);
	value = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}



const TypeSymbol* NumberNull::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}


const TypeSymbol* BooleanNull::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}

const TypeSymbol* StringNull::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	return PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
}

const TypeSymbol* Minimum::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}



const TypeSymbol* MinimumBars::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["bars_back"]->expressionValue);
	barsBackNode = methodCallNode->argNameToArgumentSymbol["bars_back"]->expression;
	
	buffer = std::vector<float>(InterpreterContext::ticks);
	std::fill(buffer.begin(), buffer.end(), std::numeric_limits<float>::quiet_NaN());

	return returnType;
}


const TypeSymbol* Maximum::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* MaximumBars::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["bars_back"]->expressionValue);
	barsBackNode = methodCallNode->argNameToArgumentSymbol["bars_back"]->expression;

	buffer = std::vector<float>(InterpreterContext::ticks);
	std::fill(buffer.begin(), buffer.end(), std::numeric_limits<float>::quiet_NaN());


	return returnType;
}

const TypeSymbol* Sum::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* SumBars::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["bars_back"]->expressionValue);
	barsBackNode = methodCallNode->argNameToArgumentSymbol["bars_back"]->expression;


	buffer = std::vector<float>(InterpreterContext::ticks);
	std::fill(buffer.begin(), buffer.end(), std::numeric_limits<float>::quiet_NaN());

	return returnType;
}

const TypeSymbol* Mean::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
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
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* Floor::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* Ceil::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
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
	value = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["condition"]->expressionValue);
	return returnType;
}

const TypeSymbol* Boolean2NumberCast::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* Boolean2StringCast::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* Float2StringCast::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}


const TypeSymbol* Float2BooleanCast::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* Absolute::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}


const TypeSymbol* LogE::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	valueNode = methodCallNode->argNameToArgumentSymbol["value"]->expression;
	return returnType;
}



const TypeSymbol* LogBase::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	base = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["base"]->expressionValue);
	valueNode = methodCallNode->argNameToArgumentSymbol["value"]->expression;
	baseNode = methodCallNode->argNameToArgumentSymbol["base"]->expression;

	return returnType;
}

const TypeSymbol* SquareRoot::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	valueNode = methodCallNode->argNameToArgumentSymbol["value"]->expression;
	return returnType;
}

const TypeSymbol* LCM::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value1 = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value1"]->expressionValue);
	value2 = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value2"]->expressionValue);
	value1Node = methodCallNode->argNameToArgumentSymbol["value1"]->expression;
	value2Node = methodCallNode->argNameToArgumentSymbol["value2"]->expression;

	return returnType;
}


const TypeSymbol* GCD::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value1 = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value1"]->expressionValue);
	value2 = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value2"]->expressionValue);
	value1Node = methodCallNode->argNameToArgumentSymbol["value1"]->expression;
	value2Node = methodCallNode->argNameToArgumentSymbol["value2"]->expression;
	return returnType;
}

const TypeSymbol* Variance::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["amount"]->expressionValue);
	barsBackNode = methodCallNode->argNameToArgumentSymbol["amount"]->expression;

	buffer = std::vector<float>(InterpreterContext::ticks);
	std::fill(buffer.begin(), buffer.end(), std::numeric_limits<float>::quiet_NaN());

	return returnType;
}


const TypeSymbol* STD::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["amount"]->expressionValue);
	barsBackNode = methodCallNode->argNameToArgumentSymbol["amount"]->expression;

	buffer = std::vector<float>(InterpreterContext::ticks);
	std::fill(buffer.begin(), buffer.end(), std::numeric_limits<float>::quiet_NaN());

	return returnType;
}

const TypeSymbol* MA::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	amount = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["amount"]->expressionValue);
	amountNode = methodCallNode->argNameToArgumentSymbol["amount"]->expression;

	buffer = std::vector<float>(InterpreterContext::ticks);
	std::fill(buffer.begin(), buffer.end(), std::numeric_limits<float>::quiet_NaN());

	return returnType;
}

const TypeSymbol* IsNullN::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* IsNullB::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* IsNullS::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	return returnType;
}

const TypeSymbol* Random::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	minvalue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["minvalue"]->expressionValue);
	maxvalue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["maxvalue"]->expressionValue);
	return returnType;
}

const TypeSymbol* Falling::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["amount"]->expressionValue);
	barsBackNode = methodCallNode->argNameToArgumentSymbol["amount"]->expression;

	buffer = std::vector<float>(InterpreterContext::ticks);
	std::fill(buffer.begin(), buffer.end(), std::numeric_limits<float>::quiet_NaN());

	return returnType;
}


const TypeSymbol* Rising::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["value"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["amount"]->expressionValue);
	barsBackNode = methodCallNode->argNameToArgumentSymbol["amount"]->expression;

	buffer = std::vector<float>(InterpreterContext::ticks);
	std::fill(buffer.begin(), buffer.end(), std::numeric_limits<float>::quiet_NaN());

	return returnType;
}

const TypeSymbol* Cosine::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["radians"]->expressionValue);
	return returnType;
}

const TypeSymbol* Tangent::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["radians"]->expressionValue);
	return returnType;
}


const TypeSymbol* Sine::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["radians"]->expressionValue);
	return returnType;
}

const TypeSymbol* ArcCosine::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["radians"]->expressionValue);
	arg = methodCallNode->argNameToArgumentSymbol["radians"]->expression;
	return returnType;
}

const TypeSymbol* ArcTan::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["radians"]->expressionValue);
	return returnType;
}


const TypeSymbol* ArcSine::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	radians = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["radians"]->expressionValue);
	arg = methodCallNode->argNameToArgumentSymbol["radians"]->expression;
	return returnType;
}


const TypeSymbol* LinearRegressionAtTick::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["data"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["bars"]->expressionValue);
	xvalue = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["x"]->expressionValue);
	barsBackNode = methodCallNode->argNameToArgumentSymbol["bars"]->expression;

	buffer = std::vector<float>(InterpreterContext::ticks);
	std::fill(buffer.begin(), buffer.end(), std::numeric_limits<float>::quiet_NaN());

	return returnType;
}

const TypeSymbol* Correlation::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data1 = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["data1"]->expressionValue);
	data2 = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["data2"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["length"]->expressionValue);
	barsBackNode = methodCallNode->argNameToArgumentSymbol["length"]->expression;

	buffer1 = std::vector<float>(InterpreterContext::ticks);
	std::fill(buffer1.begin(), buffer1.end(), std::numeric_limits<float>::quiet_NaN());

	buffer2 = std::vector<float>(InterpreterContext::ticks);
	std::fill(buffer2.begin(), buffer2.end(), std::numeric_limits<float>::quiet_NaN());

	return returnType;
}


const TypeSymbol* PreviousNumberValue::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["data"]->expressionValue);
	barsback = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["barsback"]->expressionValue);
	barsbackNode = methodCallNode->argNameToArgumentSymbol["barsback"]->expression;

	buffer = std::vector<NullableValueNumber>(InterpreterContext::ticks);
	std::fill(buffer.begin(), buffer.end(), NullableValueNumber());

	return returnType;
}

const TypeSymbol* PreviousStringValue::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueString>(&methodCallNode->argNameToArgumentSymbol["data"]->expressionValue);
	barsback = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["barsback"]->expressionValue);
	barsbackNode = methodCallNode->argNameToArgumentSymbol["barsback"]->expression;


	buffer = std::vector<NullableValueString>(InterpreterContext::ticks);
	std::fill(buffer.begin(), buffer.end(), NullableValueString());

	return returnType;
}

const TypeSymbol* PreviousBooleanValue::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueBoolean>(&methodCallNode->argNameToArgumentSymbol["data"]->expressionValue);
	barsback = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["barsback"]->expressionValue);
	barsbackNode = methodCallNode->argNameToArgumentSymbol["barsback"]->expression;

	buffer = std::vector<NullableValueBoolean>(InterpreterContext::ticks);
	std::fill(buffer.begin(), buffer.end(), NullableValueBoolean());

	return returnType;
}


const TypeSymbol* Median::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["data"]->expressionValue);
	return returnType;
}


const TypeSymbol* MedianBars::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	value = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["data"]->expressionValue);
	bars_back = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["barsback"]->expressionValue);
	barsBackNode = methodCallNode->argNameToArgumentSymbol["barsback"]->expression;

	buffer = std::vector<float>(InterpreterContext::ticks);
	std::fill(buffer.begin(), buffer.end(), std::numeric_limits<float>::quiet_NaN());

	return returnType;
}

const TypeSymbol* IsPrime::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["data"]->expressionValue);
	return returnType;
}

const TypeSymbol* IsTriangle::semanticAnaylsis(MethodCallNode* methodCallNode, std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* returnType = PositionalMethodSymbol::semanticAnaylsis(methodCallNode, symboltable);
	data = boost::get<NullableValueNumber>(&methodCallNode->argNameToArgumentSymbol["data"]->expressionValue);
	return returnType;
}

