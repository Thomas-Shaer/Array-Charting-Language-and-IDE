#include "methodimplementations.h"


ExpressionValue MethodAverage::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Float((boost::get<Float>(_argumentValues[0]).value + boost::get<Float>(_argumentValues[1]).value) / 2);
}


UnaryPlusOperator::UnaryPlusOperator(const std::string& _name) : MethodSymbol(_name, { DataType::Float}, DataType::Float) {}

ExpressionValue UnaryPlusOperator::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Float(+boost::get<Float>(_argumentValues[0]).value);
}

UnaryMinusOperator::UnaryMinusOperator(const std::string& _name) : MethodSymbol(_name, { DataType::Float}, DataType::Float) {}

ExpressionValue UnaryMinusOperator::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Float(-boost::get<Float>(_argumentValues[0]).value);
}

UnaryNotOperator::UnaryNotOperator(const std::string& _name) : MethodSymbol(_name, { DataType::Boolean}, DataType::Boolean) {}

ExpressionValue UnaryNotOperator::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Boolean(!boost::get<Boolean>(_argumentValues[0]).value);
}


BinaryPlusOperator::BinaryPlusOperator(const std::string& _name) : MethodSymbol(_name, { DataType::Float, DataType::Float }, DataType::Float) {}

ExpressionValue BinaryPlusOperator::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Float(boost::get<Float>(_argumentValues[0]).value + boost::get<Float>(_argumentValues[1]).value);
}

BinaryMinusOperator::BinaryMinusOperator(const std::string& _name) : MethodSymbol(_name, { DataType::Float, DataType::Float }, DataType::Float) {}

ExpressionValue BinaryMinusOperator::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Float(boost::get<Float>(_argumentValues[0]).value - boost::get<Float>(_argumentValues[1]).value);
}

BinaryDivideOperator::BinaryDivideOperator(const std::string& _name) : MethodSymbol(_name, { DataType::Float, DataType::Float }, DataType::Float) {}

ExpressionValue BinaryDivideOperator::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Float(boost::get<Float>(_argumentValues[0]).value / boost::get<Float>(_argumentValues[1]).value);
}

BinaryMultiplyOperator::BinaryMultiplyOperator(const std::string& _name) : MethodSymbol(_name, { DataType::Float, DataType::Float }, DataType::Float) {}

ExpressionValue BinaryMultiplyOperator::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Float(boost::get<Float>(_argumentValues[0]).value * boost::get<Float>(_argumentValues[1]).value);
}


BinaryLessOperator::BinaryLessOperator(const std::string& _name) : MethodSymbol(_name, { DataType::Float, DataType::Float }, DataType::Boolean) {}

ExpressionValue BinaryLessOperator::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Boolean(boost::get<Float>(_argumentValues[0]).value < boost::get<Float>(_argumentValues[1]).value);
}

BinaryLessEqualOperator::BinaryLessEqualOperator(const std::string& _name) : MethodSymbol(_name, { DataType::Float, DataType::Float }, DataType::Boolean) {}

ExpressionValue BinaryLessEqualOperator::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Boolean(boost::get<Float>(_argumentValues[0]).value <= boost::get<Float>(_argumentValues[1]).value);
}


BinaryGreaterOperator::BinaryGreaterOperator(const std::string& _name) : MethodSymbol(_name, { DataType::Float, DataType::Float }, DataType::Boolean) {}

ExpressionValue BinaryGreaterOperator::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Boolean(boost::get<Float>(_argumentValues[0]).value > boost::get<Float>(_argumentValues[1]).value);
}

BinaryGreaterEqualOperator::BinaryGreaterEqualOperator(const std::string& _name) : MethodSymbol(_name, { DataType::Float, DataType::Float }, DataType::Boolean) {}

ExpressionValue BinaryGreaterEqualOperator::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Boolean(boost::get<Float>(_argumentValues[0]).value >= boost::get<Float>(_argumentValues[1]).value);
}


BinaryAndOperator::BinaryAndOperator(const std::string& _name) : MethodSymbol(_name, { DataType::Boolean, DataType::Boolean }, DataType::Boolean) {}

ExpressionValue BinaryAndOperator::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Boolean(boost::get<Boolean>(_argumentValues[0]).value && boost::get<Boolean>(_argumentValues[1]).value);
}


BinaryOrOperator::BinaryOrOperator(const std::string& _name) : MethodSymbol(_name, { DataType::Boolean, DataType::Boolean }, DataType::Boolean) {}

ExpressionValue BinaryOrOperator::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Boolean(boost::get<Boolean>(_argumentValues[0]).value || boost::get<Boolean>(_argumentValues[1]).value);
}

