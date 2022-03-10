#pragma once
#include <boost/test/unit_test.hpp>
#include "CodeBase/varsymbol.h"


template<typename T>
bool isNaN(const T& val) {
    return (bool)!val.value;
}


template<typename T>
bool isEquiv(const T& val, const T& test) {
    return *val.value == *test.value;
}

template<typename T>
T safeExpressionCast(const ExpressionValue val) {
    T value;
    BOOST_CHECK_NO_THROW((value = boost::get<T>(val)));
    return value;
}
