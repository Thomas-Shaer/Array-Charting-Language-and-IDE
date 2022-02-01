#pragma once
#include "boolean.h"
#include "float.h"
#include "string.h"
#include <boost/variant.hpp>

typedef boost::variant<Float, Boolean, String> ExpressionValue;
