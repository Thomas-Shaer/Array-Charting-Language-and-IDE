#pragma once
#include <boost/variant/static_visitor.hpp>
#include "global.h"


struct ToString : public boost::static_visitor<std::string> {

	template <typename T>
	std::string operator() (const T& value) const {
		return value.toString();
	}
};

struct ToFileString : public boost::static_visitor<std::string> {

	template <typename T>
	std::string operator() (const T& value) const {
		return value.toFileString();
	}
};