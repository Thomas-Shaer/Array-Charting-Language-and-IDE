#include "operator.h"
#include "varsymbol.h"
#include "languageexception.h"

Operator::Operator(const std::string& _name, const DataType _type1, const DataType _type2, const DataType _returnType) : name(_name), type1(_type1), type2(_type2), returnType(_returnType) {}

DataType Operator::semanticAnaylsis(const DataType& _type1, const DataType& _type2) const {
	if (_type1 != type1 || _type2 != type2) {
		throw LanguageException(name + " operator takes type " + std::to_string((int)type1) + " and " + std::to_string((int)type2) + 
			" but received types " + std::to_string((int)_type1) + " and " + std::to_string((int)_type2));
	}

	return returnType;
}


PlusOperator::PlusOperator(const std::string& _name) : Operator(_name, DataType::Float, DataType::Float, DataType::Float) {}

ExpressionValue PlusOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Float(boost::get<Float>(_value1).value + boost::get<Float>(_value2).value);
}

MinusOperator::MinusOperator(const std::string& _name) : Operator(_name, DataType::Float, DataType::Float, DataType::Float) {}

ExpressionValue MinusOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Float(boost::get<Float>(_value1).value - boost::get<Float>(_value2).value);
}

DivideOperator::DivideOperator(const std::string& _name) : Operator(_name, DataType::Float, DataType::Float, DataType::Float) {}

ExpressionValue DivideOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Float(boost::get<Float>(_value1).value / boost::get<Float>(_value2).value);
}

MultiplyOperator::MultiplyOperator(const std::string& _name) : Operator(_name, DataType::Float, DataType::Float, DataType::Float) {}

ExpressionValue MultiplyOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Float(boost::get<Float>(_value1).value * boost::get<Float>(_value2).value);
}


LessOperator::LessOperator(const std::string& _name) : Operator(_name, DataType::Float, DataType::Float, DataType::Boolean) {}

ExpressionValue LessOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Boolean(boost::get<Float>(_value1).value < boost::get<Float>(_value2).value);
}

LessEqualOperator::LessEqualOperator(const std::string& _name) : Operator(_name, DataType::Float, DataType::Float, DataType::Boolean) {}

ExpressionValue LessEqualOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Boolean(boost::get<Float>(_value1).value <= boost::get<Float>(_value2).value);
}


GreaterOperator::GreaterOperator(const std::string& _name) : Operator(_name, DataType::Float, DataType::Float, DataType::Boolean) {}

ExpressionValue GreaterOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Boolean(boost::get<Float>(_value1).value > boost::get<Float>(_value2).value);
}

GreaterEqualOperator::GreaterEqualOperator(const std::string& _name) : Operator(_name, DataType::Float, DataType::Float, DataType::Boolean) {}

ExpressionValue GreaterEqualOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Boolean(boost::get<Float>(_value1).value >= boost::get<Float>(_value2).value);
}


AndOperator::AndOperator(const std::string& _name) : Operator(_name, DataType::Boolean, DataType::Boolean, DataType::Boolean) {}

ExpressionValue AndOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Boolean(boost::get<Boolean>(_value1).value && boost::get<Boolean>(_value2).value);
}


OrOperator::OrOperator(const std::string& _name) : Operator(_name, DataType::Boolean, DataType::Boolean, DataType::Boolean) {}

ExpressionValue OrOperator::interpret(ExpressionValue _value1, ExpressionValue _value2) const {
	return Boolean(boost::get<Boolean>(_value1).value || boost::get<Boolean>(_value2).value);
}

