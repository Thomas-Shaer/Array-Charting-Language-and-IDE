#include "methodimplementations.h"
#include "typesymbol.h"
#include "visitors.h"

ExpressionValue MethodAverage::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Float((boost::get<Float>(_argumentValues[0]).value + boost::get<Float>(_argumentValues[1]).value) / 2);
}


UnaryPlusOperator::UnaryPlusOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance()}, TypeInstances::GetFloatInstance()) {}

ExpressionValue UnaryPlusOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Float(+boost::get<Float>(_argumentValues[0]).value);
}

UnaryMinusOperator::UnaryMinusOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance()}, TypeInstances::GetFloatInstance()) {}

ExpressionValue UnaryMinusOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Float(-boost::get<Float>(_argumentValues[0]).value);
}

UnaryNotOperator::UnaryNotOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetBooleanInstance()}, TypeInstances::GetBooleanInstance()) {}

ExpressionValue UnaryNotOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Boolean(!boost::get<Boolean>(_argumentValues[0]).value);
}


BinaryPlusOperator::BinaryPlusOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetFloatInstance()) {}

ExpressionValue BinaryPlusOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Float(boost::get<Float>(_argumentValues[0]).value + boost::get<Float>(_argumentValues[1]).value);
}

BinaryMinusOperator::BinaryMinusOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetFloatInstance()) {}

ExpressionValue BinaryMinusOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Float(boost::get<Float>(_argumentValues[0]).value - boost::get<Float>(_argumentValues[1]).value);
}

BinaryDivideOperator::BinaryDivideOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetFloatInstance()) {}

ExpressionValue BinaryDivideOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Float(boost::get<Float>(_argumentValues[0]).value / boost::get<Float>(_argumentValues[1]).value);
}

BinaryMultiplyOperator::BinaryMultiplyOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetFloatInstance()) {}

ExpressionValue BinaryMultiplyOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Float(boost::get<Float>(_argumentValues[0]).value * boost::get<Float>(_argumentValues[1]).value);
}


BinaryLessOperator::BinaryLessOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryLessOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Boolean(boost::get<Float>(_argumentValues[0]).value < boost::get<Float>(_argumentValues[1]).value);
}

BinaryLessEqualOperator::BinaryLessEqualOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryLessEqualOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Boolean(boost::get<Float>(_argumentValues[0]).value <= boost::get<Float>(_argumentValues[1]).value);
}


BinaryGreaterOperator::BinaryGreaterOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryGreaterOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Boolean(boost::get<Float>(_argumentValues[0]).value > boost::get<Float>(_argumentValues[1]).value);
}

BinaryGreaterEqualOperator::BinaryGreaterEqualOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryGreaterEqualOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Boolean(boost::get<Float>(_argumentValues[0]).value >= boost::get<Float>(_argumentValues[1]).value);
}


BinaryAndOperator::BinaryAndOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetBooleanInstance(), TypeInstances::GetBooleanInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryAndOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Boolean(boost::get<Boolean>(_argumentValues[0]).value && boost::get<Boolean>(_argumentValues[1]).value);
}


BinaryOrOperator::BinaryOrOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetBooleanInstance(), TypeInstances::GetBooleanInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryOrOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Boolean(boost::get<Boolean>(_argumentValues[0]).value || boost::get<Boolean>(_argumentValues[1]).value);
}


BinaryBooleanEqualOperator::BinaryBooleanEqualOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetBooleanInstance(), TypeInstances::GetBooleanInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryBooleanEqualOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Boolean(boost::get<Boolean>(_argumentValues[0]).value == boost::get<Boolean>(_argumentValues[1]).value);
}

BinaryFloatEqualOperator::BinaryFloatEqualOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryFloatEqualOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Boolean(boost::get<Float>(_argumentValues[0]).value == boost::get<Float>(_argumentValues[1]).value);
}


BinaryBooleanNotEqualOperator::BinaryBooleanNotEqualOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetBooleanInstance(), TypeInstances::GetBooleanInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryBooleanNotEqualOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Boolean(boost::get<Boolean>(_argumentValues[0]).value != boost::get<Boolean>(_argumentValues[1]).value);
}

BinaryFloatNotEqualOperator::BinaryFloatNotEqualOperator(const std::string& _name) : MethodSymbol(_name, { TypeInstances::GetFloatInstance(), TypeInstances::GetFloatInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue BinaryFloatNotEqualOperator::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	return Boolean(boost::get<Float>(_argumentValues[0]).value != boost::get<Float>(_argumentValues[1]).value);
}


PrintBoolean::PrintBoolean() : MethodSymbol("print", { TypeInstances::GetBooleanInstance() }, TypeInstances::GetBooleanInstance()) {}

ExpressionValue PrintBoolean::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	output.push_back(boost::apply_visitor(ToString(), _argumentValues[0]));
	return _argumentValues[0];
}



PrintFloat::PrintFloat() : MethodSymbol("print", { TypeInstances::GetFloatInstance() }, TypeInstances::GetFloatInstance()) {}

ExpressionValue PrintFloat::interpret(std::vector<ExpressionValue> _argumentValues, std::vector<std::string>& output) const {
	output.push_back(boost::apply_visitor(ToString(), _argumentValues[0]));
	return _argumentValues[0];
}
