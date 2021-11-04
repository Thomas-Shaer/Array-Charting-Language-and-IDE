#include "binaryoperator.h"
#include "varsymbol.h"
#include "languageexception.h"

BinaryOperator::BinaryOperator(const std::string& _name, const DataType _type1, const DataType _type2, const DataType _returnType) : Operator(_name), type1(_type1), type2(_type2), returnType(_returnType) {}

DataType BinaryOperator::semanticAnaylsis(const DataType& _type1, const DataType& _type2) const {
	if (_type1 != type1 || _type2 != type2) {
		throw LanguageException(name + " operator takes type " + std::to_string((int)type1) + " and " + std::to_string((int)type2) + 
			" but received types " + std::to_string((int)_type1) + " and " + std::to_string((int)_type2));
	}

	return returnType;
}


BinaryPlusOperator::BinaryPlusOperator(const std::string& _name) : BinaryOperator(_name, DataType::Float, DataType::Float, DataType::Float) {}

ExpressionValue BinaryPlusOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Float(boost::get<Float>(_value1).value + boost::get<Float>(_value2).value);
}

BinaryMinusOperator::BinaryMinusOperator(const std::string& _name) : BinaryOperator(_name, DataType::Float, DataType::Float, DataType::Float) {}

ExpressionValue BinaryMinusOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Float(boost::get<Float>(_value1).value - boost::get<Float>(_value2).value);
}

BinaryDivideOperator::BinaryDivideOperator(const std::string& _name) : BinaryOperator(_name, DataType::Float, DataType::Float, DataType::Float) {}

ExpressionValue BinaryDivideOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Float(boost::get<Float>(_value1).value / boost::get<Float>(_value2).value);
}

BinaryMultiplyOperator::BinaryMultiplyOperator(const std::string& _name) : BinaryOperator(_name, DataType::Float, DataType::Float, DataType::Float) {}

ExpressionValue BinaryMultiplyOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Float(boost::get<Float>(_value1).value * boost::get<Float>(_value2).value);
}


BinaryLessOperator::BinaryLessOperator(const std::string& _name) : BinaryOperator(_name, DataType::Float, DataType::Float, DataType::Boolean) {}

ExpressionValue BinaryLessOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Boolean(boost::get<Float>(_value1).value < boost::get<Float>(_value2).value);
}

BinaryLessEqualOperator::BinaryLessEqualOperator(const std::string& _name) : BinaryOperator(_name, DataType::Float, DataType::Float, DataType::Boolean) {}

ExpressionValue BinaryLessEqualOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Boolean(boost::get<Float>(_value1).value <= boost::get<Float>(_value2).value);
}


BinaryGreaterOperator::BinaryGreaterOperator(const std::string& _name) : BinaryOperator(_name, DataType::Float, DataType::Float, DataType::Boolean) {}

ExpressionValue BinaryGreaterOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Boolean(boost::get<Float>(_value1).value > boost::get<Float>(_value2).value);
}

BinaryGreaterEqualOperator::BinaryGreaterEqualOperator(const std::string& _name) : BinaryOperator(_name, DataType::Float, DataType::Float, DataType::Boolean) {}

ExpressionValue BinaryGreaterEqualOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Boolean(boost::get<Float>(_value1).value >= boost::get<Float>(_value2).value);
}


BinaryAndOperator::BinaryAndOperator(const std::string& _name) : BinaryOperator(_name, DataType::Boolean, DataType::Boolean, DataType::Boolean) {}

ExpressionValue BinaryAndOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Boolean(boost::get<Boolean>(_value1).value && boost::get<Boolean>(_value2).value);
}


BinaryOrOperator::BinaryOrOperator(const std::string& _name) : BinaryOperator(_name, DataType::Boolean, DataType::Boolean, DataType::Boolean) {}

ExpressionValue BinaryOrOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Boolean(boost::get<Boolean>(_value1).value || boost::get<Boolean>(_value2).value);
}

