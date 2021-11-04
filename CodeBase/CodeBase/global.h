#pragma once
#include "boolean.h"
#include "float.h"
#include <boost/variant.hpp>

typedef boost::variant<Float, Boolean> ExpressionValue;
enum class DataType : unsigned int { Boolean, Float };