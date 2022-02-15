#pragma once
#include "nullablevalueboolean.h"
#include "nullablevaluenumber.h"
#include "nullablevaluestring.h"
#include <boost/variant.hpp>

/*
Variant of which we store the all possible expression values for 
easy and convienent access.
*/
typedef boost::variant<NullableValueNumber, NullableValueBoolean, NullableValueString> ExpressionValue;
