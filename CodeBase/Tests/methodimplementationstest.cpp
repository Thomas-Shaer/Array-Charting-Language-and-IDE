#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <string>
#include "CodeBase/interpretercontext.h"
#include "CodeBase/symboltable.h"
#include "CodeBase/varsymbol.h"
#include <numbers>
#include <numeric>

BOOST_AUTO_TEST_SUITE(METHODIMPLEMENTATIONS)
#define STANDARD_VARIABLE_NAME "x"
#define MAX_TICK_SIZE 5


// method plot
// method mark
// minimum bars : internal buffer needs to be replaced
// maximum bars : internal buffer needs to be replaced
// sum bars : internal buffer needs to be replaced

std::string formatCode(std::string methodName, std::string save_to_variable, std::vector<std::string> params) {
    std::string execute_code = save_to_variable + " = " + methodName + "(";
    for (int i = 0; i < params.size(); i++) {
        if (i == params.size() - 1) {
            execute_code += params[i];
            break;
        }
        execute_code += params[i] + ",";
    }
    execute_code += ")";
    return execute_code;
}

std::string formatCode(std::string expression, std::string save_to_variable) {
    return save_to_variable + " = " + expression;
}


template<typename T>
T getReturn(std::string methodName, std::vector<std::string> params) {
    InterpreterContext context;
    BOOST_CHECK_NO_THROW(context.executeNoCatch(formatCode(methodName, STANDARD_VARIABLE_NAME, params)));
    T returnValue;
    BOOST_CHECK_NO_THROW(returnValue = boost::get<T>(context.symboltable->getVariable(STANDARD_VARIABLE_NAME)->getValue(0)));
    return returnValue;
}

std::vector<ExpressionValue> getReturnVarBuffer(std::string methodName, std::vector<std::string> params) {
    InterpreterContext context;
    BOOST_CHECK_NO_THROW(context.executeNoCatch(formatCode(methodName, STANDARD_VARIABLE_NAME, params)));
    BOOST_CHECK_NO_THROW(context.symboltable->getVariable(STANDARD_VARIABLE_NAME));
    return context.symboltable->getVariable(STANDARD_VARIABLE_NAME)->buffer;
}

std::vector<ExpressionValue> getReturnVarBuffer(std::string methodName, std::vector<std::string> params, InterpreterContext& context) {
    BOOST_CHECK_NO_THROW(context.executeNoCatch(formatCode(methodName, STANDARD_VARIABLE_NAME, params)));
    BOOST_CHECK_NO_THROW(context.symboltable->getVariable(STANDARD_VARIABLE_NAME));
    return context.symboltable->getVariable(STANDARD_VARIABLE_NAME)->buffer;
}

template<typename T>
T getReturn(std::string methodName, std::vector<std::string> params, const unsigned int index) {
    InterpreterContext context;
    BOOST_CHECK_NO_THROW(context.executeNoCatch(formatCode(methodName, STANDARD_VARIABLE_NAME, params)));
    T returnValue;
    BOOST_CHECK_NO_THROW(returnValue = boost::get<T>(context.symboltable->getVariable(STANDARD_VARIABLE_NAME)->getValue(index)));
    return returnValue;
}

template<typename T>
T getReturn(std::string methodName, std::vector<std::string> params, const unsigned int index, InterpreterContext& context) {
    BOOST_CHECK_NO_THROW(context.executeNoCatch(formatCode(methodName, STANDARD_VARIABLE_NAME, params)));
    T returnValue;
    BOOST_CHECK_NO_THROW(returnValue = boost::get<T>(context.symboltable->getVariable(STANDARD_VARIABLE_NAME)->getValue(index)));
    return returnValue;
}

void execute(std::string expression) {
    InterpreterContext context;
    context.executeNoCatch(expression);
}


template<typename T>
T getReturn(std::string expression) {
    InterpreterContext context;
    BOOST_CHECK_NO_THROW(context.executeNoCatch(formatCode(expression, STANDARD_VARIABLE_NAME)));
    T returnValue;
    BOOST_CHECK_NO_THROW(returnValue = boost::get<T>(context.symboltable->getVariable(STANDARD_VARIABLE_NAME)->getValue(0)));
    return returnValue;
}

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


BOOST_AUTO_TEST_CASE(method_average_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("average", { "1.5", "2" }), NullableValueNumber(1.75)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("average", { "-1.5", "-2" }), NullableValueNumber(-1.75)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("average", { "0", "0" }), NullableValueNumber(0)));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("average", { "nan_f()", "2" })));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("average", { "1.5", "nan_f()" })));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("average", { "nan_f()", "nan_f()" })));
}

BOOST_AUTO_TEST_CASE(method_unop_plus_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("+ 1.5"), NullableValueNumber(1.5)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("++ 1.5"), NullableValueNumber(1.5)));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("+ nan_f()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("++ nan_f()")));
}

BOOST_AUTO_TEST_CASE(method_unop_minus_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("- 1.5"), NullableValueNumber(-1.5)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("-- 1.5"), NullableValueNumber(1.5)));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("- nan_f()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("-- nan_f()")));
}

BOOST_AUTO_TEST_CASE(method_unop_negate_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("! true"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("!! true"), NullableValueBoolean(true)));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("! nan_b()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("!! nan_b()")));
}

BOOST_AUTO_TEST_CASE(method_binop_plus_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("1.5 + 2"), NullableValueNumber(3.5)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("-1.5 + -2"), NullableValueNumber(-3.5)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("0 + 0"), NullableValueNumber(0)));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("nan_f() + 2")));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("1.5 + nan_f()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("nan_f() + nan_f()")));
}

BOOST_AUTO_TEST_CASE(method_binop_minus_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("1.5 - 2"), NullableValueNumber(-0.5)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("-1.5 - -2"), NullableValueNumber(0.5)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("0 - 0"), NullableValueNumber(0)));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("nan_f() - 2")));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("1.5 - nan_f()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("nan_f() - nan_f()")));
}

BOOST_AUTO_TEST_CASE(method_binop_divide_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("1.5 / 2"), NullableValueNumber(0.75)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("-1.5 / -2"), NullableValueNumber(0.75)));
    BOOST_CHECK_THROW(execute("x = 0 / 0"), LanguageException);
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("nan_f() / 2")));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("1.5 / nan_f()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("nan_f() / nan_f()")));
}

BOOST_AUTO_TEST_CASE(method_binop_multiply_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("1.5 * 2"), NullableValueNumber(3)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("-1.5 * -2"), NullableValueNumber(3)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("0 * 0"), NullableValueNumber(0)));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("nan_f() * 2")));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("1.5 * nan_f()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("nan_f() * nan_f()")));
}


BOOST_AUTO_TEST_CASE(method_binop_pow_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("1.5 ^ 2"), NullableValueNumber(2.25)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("-2 ^ -2"), NullableValueNumber(-0.25)));
    BOOST_CHECK_THROW(execute("x = 0 ^ 0"), LanguageException);
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("nan_f() ^ 2")));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("1.5 ^ nan_f()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("nan_f() ^ nan_f()")));
}


BOOST_AUTO_TEST_CASE(method_binop_less_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("1.5 < 2"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("-1.5 < -2"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("0 < 0"), NullableValueBoolean(false)));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_f() < 2")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("1.5 < nan_f()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_f() < nan_f()")));
}


BOOST_AUTO_TEST_CASE(method_binop_less_equal_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("1.5 <= 2"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("-1.5 <= -2"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("0 <= 0"), NullableValueBoolean(true)));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_f() <= 2")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("1.5 <= nan_f()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_f() <= nan_f()")));
}

BOOST_AUTO_TEST_CASE(method_binop_greater_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("1.5 > 2"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("-1.5 > -2"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("0 > 0"), NullableValueBoolean(false)));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_f() > 2")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("1.5 > nan_f()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_f() > nan_f()")));
}


BOOST_AUTO_TEST_CASE(method_binop_greater_equal_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("1.5 >= 2"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("-1.5 >= -2"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("0 >= 0"), NullableValueBoolean(true)));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_f() >= 2")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("1.5 >= nan_f()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_f() >= nan_f()")));
}


BOOST_AUTO_TEST_CASE(method_binop_and_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false && false"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true && false"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false && true"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true && true"), NullableValueBoolean(true)));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_b() && false")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("true && nan_b()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_b() && nan_b()")));
}

BOOST_AUTO_TEST_CASE(method_binop_or_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false || false"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true || false"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false || true"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true || true"), NullableValueBoolean(true)));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_b() || false")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("true || nan_b()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_b() || nan_b()")));
}


BOOST_AUTO_TEST_CASE(method_binop_equal_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false == false"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true == false"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false == true"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true == true"), NullableValueBoolean(true)));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_b() == false")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("true == nan_b()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_b() == nan_b()")));


    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("1.5 == 2"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("-1.5 == -2"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("0 == 0"), NullableValueBoolean(true)));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_f() == 2")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("1.5 == nan_f()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_f() == nan_f()")));


    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("\"Hello World\" == \"Helo\""), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("\"Hello\" == \"Hello\""), NullableValueBoolean(true)));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_s() == \"Hello\"")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("\"Hello\" == nan_s()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_s() == nan_s()")));

}


BOOST_AUTO_TEST_CASE(method_binop_not_equal_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false != false"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true != false"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false != true"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true != true"), NullableValueBoolean(false)));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_b() != false")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("true != nan_b()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_b() != nan_b()")));


    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("1.5 != 2"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("-1.5 != -2"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("0 != 0"), NullableValueBoolean(false)));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_f() != 2")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("1.5 != nan_f()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_f() != nan_f()")));


    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("\"Hello World\" != \"Helo\""), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("\"Hello\" != \"Hello\""), NullableValueBoolean(false)));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_s() != \"Hello\"")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("\"Hello\" != nan_s()")));
    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_s() != nan_s()")));

}

BOOST_AUTO_TEST_CASE(method_get_tick_test)
{
    InterpreterContext context1;
    context1.ticks = MAX_TICK_SIZE;
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("tick", {}, 4, context1), NullableValueNumber(MAX_TICK_SIZE-1)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("tick", {}, 0), NullableValueNumber(0)));
}



BOOST_AUTO_TEST_CASE(method_value_when_test)
{
    InterpreterContext context1;
    context1.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer1 = getReturnVarBuffer("valuewhen", { "tick() > 3", "1" }, context1);
    BOOST_CHECK(isNaN<NullableValueNumber>(safeExpressionCast<NullableValueNumber>(buffer1.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(MAX_TICK_SIZE-1)), NullableValueNumber(1)));


    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("valuewhen", { "tick() > 3", "\"Test\"" }, context2);
    BOOST_CHECK(isNaN<NullableValueString>(safeExpressionCast<NullableValueString>(buffer2.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueString>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueString("Test")));


    InterpreterContext context3;
    context3.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer3 = getReturnVarBuffer("valuewhen", { "tick() > 3", "true" }, context3);
    BOOST_CHECK(isNaN<NullableValueBoolean>(safeExpressionCast<NullableValueBoolean>(buffer3.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(buffer3.at(MAX_TICK_SIZE - 1)), NullableValueBoolean(true)));
}


BOOST_AUTO_TEST_CASE(method_nan_number_test)
{

    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("nan_f()")));
}

BOOST_AUTO_TEST_CASE(method_nan_string_test)
{

    BOOST_CHECK(isNaN(getReturn<NullableValueString>("nan_s()")));
}

BOOST_AUTO_TEST_CASE(method_nan_boolean_test)
{

    BOOST_CHECK(isNaN(getReturn<NullableValueBoolean>("nan_b()")));
}


BOOST_AUTO_TEST_CASE(method_min_test)
{

    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("min", { "tick()" }, context2);
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(0)), NullableValueNumber(0)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(0)));

    InterpreterContext context1;
    context1.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer1 = getReturnVarBuffer("min", { "-tick()"}, context1);
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(0)), NullableValueNumber(0)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(MAX_TICK_SIZE - 1)), NullableValueNumber(-4)));
}



BOOST_AUTO_TEST_CASE(method_max_test)
{
    InterpreterContext context1;
    context1.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer1 = getReturnVarBuffer("max", { "tick()" }, context1);
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(0)), NullableValueNumber(0)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(MAX_TICK_SIZE - 1)), NullableValueNumber(4)));


    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("max", { "-tick()" }, context2);
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(0)), NullableValueNumber(0)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(0)));
}


BOOST_AUTO_TEST_CASE(method_sum_test)
{
    InterpreterContext context1;
    context1.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer1 = getReturnVarBuffer("sum", { "tick()" }, context1);
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(0)), NullableValueNumber(0)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(MAX_TICK_SIZE - 1)), NullableValueNumber(10)));


    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("sum", { "-tick()" }, context1);
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(0)), NullableValueNumber(0)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(-10)));
}


BOOST_AUTO_TEST_CASE(method_mean_test)
{
    InterpreterContext context1;
    context1.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer1 = getReturnVarBuffer("mean", { "tick()" }, context1);
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(0)), NullableValueNumber(0)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(MAX_TICK_SIZE - 1)), NullableValueNumber(2)));

    // nan tests


    //InterpreterContext context2;
    //context2.ticks = MAX_TICK_SIZE;
    //std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("mean", { "tick() < 2 ? na_f() : tick()" }, context2);
    //BOOST_CHECK(isNaN(safeExpressionCast<NullableValueNumber>(buffer2.at(0))));
    //BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(3)));
}


BOOST_AUTO_TEST_CASE(method_get_pi_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("pi", { }), NullableValueNumber(std::numbers::pi_v<float>)));
}

BOOST_AUTO_TEST_CASE(method_get_e_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("e", { }), NullableValueNumber(std::numbers::e)));
}

BOOST_AUTO_TEST_CASE(method_round_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("round", {"1.5" }), NullableValueNumber(2)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("round", {"1.4" }), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("round", { "-1.5" }), NullableValueNumber(-2)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("round", { "-1.4" }), NullableValueNumber(-1)));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("round", {"nan_f()" })));

}

BOOST_AUTO_TEST_CASE(method_floor_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("floor", { "1.5" }), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("floor", { "1.4" }), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("floor", { "-1.5" }), NullableValueNumber(-2)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("floor", { "-1.4" }), NullableValueNumber(-2)));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("floor", { "nan_f()" })));

}

BOOST_AUTO_TEST_CASE(method_ceil_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("ceil", { "1.5" }), NullableValueNumber(2)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("ceil", { "1.4" }), NullableValueNumber(2)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("ceil", { "-1.5" }), NullableValueNumber(-1)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("ceil", { "-1.4" }), NullableValueNumber(-1)));
    BOOST_CHECK(isNaN(getReturn<NullableValueNumber>("ceil", { "nan_f()" })));

}


BOOST_AUTO_TEST_CASE(method_float_max_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("maxnumber", { }), NullableValueNumber(std::numeric_limits<float>::max())));
}

BOOST_AUTO_TEST_CASE(method_float_min_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("minnumber", { }), NullableValueNumber(-std::numeric_limits<float>::max())));
}

BOOST_AUTO_TEST_CASE(method_count_test)
{
    InterpreterContext context1;
    context1.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer1 = getReturnVarBuffer("count", { "true" }, context1);
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(0)), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(MAX_TICK_SIZE - 1)), NullableValueNumber(5)));

    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("count", { "nan_b()" }, context2);
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(0)), NullableValueNumber(0)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(0)));

    InterpreterContext context3;
    context3.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer3 = getReturnVarBuffer("count", { "false" }, context3);
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer3.at(0)), NullableValueNumber(0)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer3.at(MAX_TICK_SIZE - 1)), NullableValueNumber(0)));


    InterpreterContext context4;
    context4.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer4 = getReturnVarBuffer("count", { "tick() > 2" }, context4);
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer4.at(0)), NullableValueNumber(0)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer4.at(MAX_TICK_SIZE - 1)), NullableValueNumber(2)));
}



BOOST_AUTO_TEST_SUITE_END()
