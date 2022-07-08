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


/*
Visitors for applying common operations to 
ExpressionValue without knowing the exact type 
stored in the variant.
*/

/*
ToString visitor, calls and returns NullableValue's toString() method
*/
struct ToString : public boost::static_visitor<std::string> {

	template <typename T>
	std::string operator() (const T& value) const {
		return value.toString();
	}
};


/*
ToFileString visitor, calls and returns NullableValue's toFileString() method
*/
struct ToFileString : public boost::static_visitor<std::string> {

	template <typename T>
	std::string operator() (const T& value) const {
		return value.toFileString();
	}
};

