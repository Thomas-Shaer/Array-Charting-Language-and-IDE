#include "unaryoperator.h"
#include "languageexception.h"

UnaryOperator::UnaryOperator(const std::string& _name, const DataType _type1,  const DataType _returnType) : Operator(_name), type1(_type1), returnType(_returnType) {}

DataType UnaryOperator::semanticAnaylsis(const DataType& _type1) const {
	if (_type1 != type1) {
		throw LanguageException(name + " operator takes type " + std::to_string((int)type1) +
			" but received type " + std::to_string((int)_type1));
	}

	return returnType;
}


UnaryPlusOperator::UnaryPlusOperator(const std::string& _name) : UnaryOperator(_name, DataType::Float, DataType::Float) {}

ExpressionValue UnaryPlusOperator::interpret(ExpressionValue _value1) const {
	return Float(+boost::get<Float>(_value1).value);
}

UnaryMinusOperator::UnaryMinusOperator(const std::string& _name) : UnaryOperator(_name, DataType::Float, DataType::Float) {}

ExpressionValue UnaryMinusOperator::interpret(ExpressionValue _value1) const {
	return Float(-boost::get<Float>(_value1).value);
}

UnaryNotOperator::UnaryNotOperator(const std::string& _name) : UnaryOperator(_name, DataType::Boolean, DataType::Boolean) {}

ExpressionValue UnaryNotOperator::interpret(ExpressionValue _value1) const {
	return Boolean(!boost::get<Boolean>(_value1).value);
}