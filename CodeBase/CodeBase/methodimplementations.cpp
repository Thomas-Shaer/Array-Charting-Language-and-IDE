#include "methodimplementations.h"


ExpressionValue MethodAverage::interpret(std::vector<ExpressionValue> _argumentValues) const {
	return Float((boost::get<Float>(_argumentValues[0]).value + boost::get<Float>(_argumentValues[1]).value) / 2);
}
