#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "valuetesthelper.h"
//#include <string>
#include "CodeBase/interpretercontext.h"
#include "CodeBase/symboltable.h"
#include "CodeBase/varsymbol.h"
#include <numbers>
#include <numeric>

BOOST_AUTO_TEST_SUITE(METHODIMPLEMENTATIONS)
#define STANDARD_VARIABLE_NAME "x"
#define MAX_TICK_SIZE 5




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



BOOST_AUTO_TEST_CASE(method_average_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("average", { "1.5", "2" }), NullableValueNumber(1.75)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("average", { "-1.5", "-2" }), NullableValueNumber(-1.75)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("average", { "0", "0" }), NullableValueNumber(0)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("average", { "null_n()", "2" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("average", { "1.5", "null_n()" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("average", { "null_n()", "null_n()" })));
}

BOOST_AUTO_TEST_CASE(method_unop_plus_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("+ 1.5"), NullableValueNumber(1.5)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("++ 1.5"), NullableValueNumber(1.5)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("+ null_n()")));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("++ null_n()")));
}

BOOST_AUTO_TEST_CASE(method_unop_minus_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("- 1.5"), NullableValueNumber(-1.5)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("-- 1.5"), NullableValueNumber(1.5)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("- null_n()")));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("-- null_n()")));
}

BOOST_AUTO_TEST_CASE(method_unop_negate_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("! true"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("!! true"), NullableValueBoolean(true)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("! null_b()")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("!! null_b()")));
}

BOOST_AUTO_TEST_CASE(method_binop_plus_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("1.5 + 2"), NullableValueNumber(3.5)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("-1.5 + -2"), NullableValueNumber(-3.5)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("0 + 0"), NullableValueNumber(0)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("null_n() + 2")));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("1.5 + null_n()")));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("null_n() + null_n()")));


    BOOST_CHECK(isEquiv(getReturn<NullableValueString>("\"Hello \" + \"World!\""), NullableValueString("Hello World!")));
    BOOST_CHECK(isNull(getReturn<NullableValueString>("null_s() + \"World!\"")));
    BOOST_CHECK(isNull(getReturn<NullableValueString>("\"Hello \" + null_s()")));
    BOOST_CHECK(isNull(getReturn<NullableValueString>("null_s() + null_s()")));
}

BOOST_AUTO_TEST_CASE(method_binop_minus_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("1.5 - 2"), NullableValueNumber(-0.5)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("-1.5 - -2"), NullableValueNumber(0.5)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("0 - 0"), NullableValueNumber(0)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("null_n() - 2")));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("1.5 - null_n()")));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("null_n() - null_n()")));
}

BOOST_AUTO_TEST_CASE(method_binop_divide_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("1.5 / 2"), NullableValueNumber(0.75)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("-1.5 / -2"), NullableValueNumber(0.75)));
    BOOST_CHECK_THROW(execute("x = 0 / 0"), LanguageException);
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("null_n() / 2")));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("1.5 / null_n()")));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("null_n() / null_n()")));
}

BOOST_AUTO_TEST_CASE(method_binop_multiply_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("1.5 * 2"), NullableValueNumber(3)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("-1.5 * -2"), NullableValueNumber(3)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("0 * 0"), NullableValueNumber(0)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("null_n() * 2")));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("1.5 * null_n()")));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("null_n() * null_n()")));
}


BOOST_AUTO_TEST_CASE(method_binop_pow_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("1.5 ^ 2"), NullableValueNumber(2.25)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("-2 ^ -2"), NullableValueNumber(-0.25)));
    BOOST_CHECK_THROW(execute("x = 0 ^ 0"), LanguageException);
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("null_n() ^ 2")));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("1.5 ^ null_n()")));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("null_n() ^ null_n()")));
}


BOOST_AUTO_TEST_CASE(method_binop_less_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("1.5 < 2"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("-1.5 < -2"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("0 < 0"), NullableValueBoolean(false)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_n() < 2")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("1.5 < null_n()")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_n() < null_n()")));
}


BOOST_AUTO_TEST_CASE(method_binop_less_equal_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("1.5 <= 2"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("-1.5 <= -2"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("0 <= 0"), NullableValueBoolean(true)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_n() <= 2")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("1.5 <= null_n()")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_n() <= null_n()")));
}

BOOST_AUTO_TEST_CASE(method_binop_greater_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("1.5 > 2"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("-1.5 > -2"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("0 > 0"), NullableValueBoolean(false)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_n() > 2")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("1.5 > null_n()")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_n() > null_n()")));
}


BOOST_AUTO_TEST_CASE(method_binop_greater_equal_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("1.5 >= 2"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("-1.5 >= -2"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("0 >= 0"), NullableValueBoolean(true)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_n() >= 2")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("1.5 >= null_n()")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_n() >= null_n()")));
}


BOOST_AUTO_TEST_CASE(method_binop_and_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false && false"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true && false"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false && true"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true && true"), NullableValueBoolean(true)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_b() && false")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("true && null_b()")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_b() && null_b()")));
}

BOOST_AUTO_TEST_CASE(method_binop_or_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false || false"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true || false"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false || true"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true || true"), NullableValueBoolean(true)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_b() || false")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("true || null_b()")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_b() || null_b()")));
}


BOOST_AUTO_TEST_CASE(method_binop_equal_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false == false"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true == false"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false == true"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true == true"), NullableValueBoolean(true)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_b() == false")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("true == null_b()")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_b() == null_b()")));


    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("1.5 == 2"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("-1.5 == -2"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("0 == 0"), NullableValueBoolean(true)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_n() == 2")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("1.5 == null_n()")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_n() == null_n()")));


    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("\"Hello World\" == \"Helo\""), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("\"Hello\" == \"Hello\""), NullableValueBoolean(true)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_s() == \"Hello\"")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("\"Hello\" == null_s()")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_s() == null_s()")));

}


BOOST_AUTO_TEST_CASE(method_binop_not_equal_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false != false"), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true != false"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("false != true"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("true != true"), NullableValueBoolean(false)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_b() != false")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("true != null_b()")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_b() != null_b()")));


    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("1.5 != 2"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("-1.5 != -2"), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("0 != 0"), NullableValueBoolean(false)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_n() != 2")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("1.5 != null_n()")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_n() != null_n()")));


    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("\"Hello World\" != \"Helo\""), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("\"Hello\" != \"Hello\""), NullableValueBoolean(false)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_s() != \"Hello\"")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("\"Hello\" != null_s()")));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_s() != null_s()")));

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
    BOOST_CHECK(isNull<NullableValueNumber>(safeExpressionCast<NullableValueNumber>(buffer1.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(MAX_TICK_SIZE-1)), NullableValueNumber(1)));


    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("valuewhen", { "tick() > 3", "\"Test\"" }, context2);
    BOOST_CHECK(isNull<NullableValueString>(safeExpressionCast<NullableValueString>(buffer2.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueString>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueString("Test")));


    InterpreterContext context3;
    context3.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer3 = getReturnVarBuffer("valuewhen", { "tick() > 3", "true" }, context3);
    BOOST_CHECK(isNull<NullableValueBoolean>(safeExpressionCast<NullableValueBoolean>(buffer3.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(buffer3.at(MAX_TICK_SIZE - 1)), NullableValueBoolean(true)));
}


BOOST_AUTO_TEST_CASE(method_null_number_test)
{

    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("null_n()")));
}

BOOST_AUTO_TEST_CASE(method_null_string_test)
{

    BOOST_CHECK(isNull(getReturn<NullableValueString>("null_s()")));
}

BOOST_AUTO_TEST_CASE(method_null_boolean_test)
{

    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("null_b()")));
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
    //BOOST_CHECK(isNull(safeExpressionCast<NullableValueNumber>(buffer2.at(0))));
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
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("round", {"null_n()" })));

}

BOOST_AUTO_TEST_CASE(method_floor_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("floor", { "1.5" }), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("floor", { "1.4" }), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("floor", { "-1.5" }), NullableValueNumber(-2)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("floor", { "-1.4" }), NullableValueNumber(-2)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("floor", { "null_n()" })));

}

BOOST_AUTO_TEST_CASE(method_ceil_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("ceil", { "1.5" }), NullableValueNumber(2)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("ceil", { "1.4" }), NullableValueNumber(2)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("ceil", { "-1.5" }), NullableValueNumber(-1)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("ceil", { "-1.4" }), NullableValueNumber(-1)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("ceil", { "null_n()" })));

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
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("count", { "null_b()" }, context2);
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


BOOST_AUTO_TEST_CASE(method_float_cast_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("number", { "true" }), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("number", { "false" }), NullableValueNumber(0)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("number", { "null_b()" })));

}

BOOST_AUTO_TEST_CASE(method_boolean_cast_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("boolean", { "1" }), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("boolean", { "0" }), NullableValueBoolean(false)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("boolean", { "null_n()" })));

}

BOOST_AUTO_TEST_CASE(method_string_cast_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueString>("string", { "12345" }), NullableValueString(std::to_string((float)12345))));
    BOOST_CHECK(isNull(getReturn<NullableValueString>("string", { "null_n()" })));


    BOOST_CHECK(isEquiv(getReturn<NullableValueString>("string", { "true" }), NullableValueString("true")));
    BOOST_CHECK(isEquiv(getReturn<NullableValueString>("string", { "false" }), NullableValueString("false")));
    BOOST_CHECK(isNull(getReturn<NullableValueString>("string", { "null_b()" })));

}


BOOST_AUTO_TEST_CASE(method_absolute_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("abs", { "-1" }), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("abs", { "0" }), NullableValueNumber(0)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("abs", { "1" }), NullableValueNumber(1)));

}

BOOST_AUTO_TEST_CASE(method_log_e_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("log", { "1" }), NullableValueNumber(0)));
    BOOST_CHECK_THROW(execute("log(0)"), LanguageException);
    BOOST_CHECK_THROW(execute("log(-1)"), LanguageException);
}

BOOST_AUTO_TEST_CASE(method_log_base_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("log", { "9", "3" }), NullableValueNumber(2)));
    BOOST_CHECK_THROW(execute("log(0, 3)"), LanguageException);
    BOOST_CHECK_THROW(execute("log(-1, 3)"), LanguageException);
    BOOST_CHECK_THROW(execute("log(9, 0)"), LanguageException);
    BOOST_CHECK_THROW(execute("log(9, -1)"), LanguageException);
    BOOST_CHECK_THROW(execute("log(0, 0)"), LanguageException);
    BOOST_CHECK_THROW(execute("log(-1, -1)"), LanguageException);
}


BOOST_AUTO_TEST_CASE(method_sqrt_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("sqrt", { "9" }), NullableValueNumber(3)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("sqrt", { "0" }), NullableValueNumber(0)));

    BOOST_CHECK_THROW(execute("sqrt(-1)"), LanguageException);
}


BOOST_AUTO_TEST_CASE(method_lcm_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("lcm", { "4", "6" }), NullableValueNumber(12)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("lcm", { "-4", "6" }), NullableValueNumber(12)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("lcm", { "4", "-6" }), NullableValueNumber(12)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("lcm", { "-4", "-6" }), NullableValueNumber(12)));

    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("lcm", { "null_n()", "6" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("lcm", { "6", "null_n()" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("lcm", { "null_n()", "null_n()" })));

    BOOST_CHECK_THROW(execute("lcm(0, 0)"), LanguageException);
    BOOST_CHECK_THROW(execute("lcm(0, 6)"), LanguageException);
    BOOST_CHECK_THROW(execute("lcm(6, 0)"), LanguageException);
}


BOOST_AUTO_TEST_CASE(method_gcd_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("gcd", { "4", "6" }), NullableValueNumber(2)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("gcd", { "-4", "6" }), NullableValueNumber(2)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("gcd", { "4", "-6" }), NullableValueNumber(2)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("gcd", { "-4", "-6" }), NullableValueNumber(2)));

    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("gcd", { "null_n()", "6" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("gcd", { "6", "null_n()" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("gcd", { "null_n()", "null_n()" })));

    BOOST_CHECK_THROW(execute("gcd(0, 0)"), LanguageException);
    BOOST_CHECK_THROW(execute("gcd(0, 6)"), LanguageException);
    BOOST_CHECK_THROW(execute("gcd(6, 0)"), LanguageException);
}




BOOST_AUTO_TEST_CASE(method_is_null_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isnull", { "false"}), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isnull", { "true"}), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isnull", { "null_b()"}), NullableValueBoolean(true)));


    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isnull", { "1" }), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isnull", { "-1" }), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isnull", { "null_n()" }), NullableValueBoolean(true)));

    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isnull", { "\"Hello World!\"" }), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isnull", { "null_s()" }), NullableValueBoolean(true)));
}



BOOST_AUTO_TEST_CASE(method_random_test)
{

    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("random", { "3", "3" }), NullableValueNumber(3)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("random", { "-3", "-3" }), NullableValueNumber(-3)));

    BOOST_CHECK(!isNull(getReturn<NullableValueNumber>("random", { "3", "6" })));
    BOOST_CHECK(!isNull(getReturn<NullableValueNumber>("random", { "6", "3" })));


    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("random", { "null_n()", "6" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("random", { "3", "null_n()" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("random", { "null_n()", "null_n()" })));

}

BOOST_AUTO_TEST_CASE(method_cosine_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("cos", {"2" }), NullableValueNumber(std::cos(*NullableValueNumber(2).value))));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("cos", {"0" }), NullableValueNumber(std::cos(*NullableValueNumber(0).value))));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("cos", {"-2" }), NullableValueNumber(std::cos(*NullableValueNumber(-2).value))));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("cos", { "null_n()"})));

}


BOOST_AUTO_TEST_CASE(method_tangent_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("tan", { "2" }), NullableValueNumber(std::tan(*NullableValueNumber(2).value))));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("tan", { "0" }), NullableValueNumber(std::tan(*NullableValueNumber(0).value))));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("tan", { "-2" }), NullableValueNumber(std::tan(*NullableValueNumber(-2).value))));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("tan", { "null_n()" })));
}

BOOST_AUTO_TEST_CASE(method_sine_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("sin", { "2" }), NullableValueNumber(std::sin(*NullableValueNumber(2).value))));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("sin", { "0" }), NullableValueNumber(std::sin(*NullableValueNumber(0).value))));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("sin", { "-2" }), NullableValueNumber(std::sin(*NullableValueNumber(-2).value))));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("sin", { "null_n()" })));
}





BOOST_AUTO_TEST_CASE(method_arctangent_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("atan", { "2" }), NullableValueNumber(std::atan(*NullableValueNumber(2).value))));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("atan", { "0" }), NullableValueNumber(std::atan(*NullableValueNumber(0).value))));
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("atan", { "-2" }), NullableValueNumber(std::atan(*NullableValueNumber(-2).value))));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("atan", { "null_n()" })));
}


BOOST_AUTO_TEST_CASE(method_arccosine_test)
{
    BOOST_CHECK_THROW(execute("acos(1.1)"), LanguageException);
    BOOST_CHECK_THROW(execute("acos(-1.1)"), LanguageException);
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("acos", { "0" }), NullableValueNumber(std::acos(*NullableValueNumber(0).value))));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("acos", { "null_n()" })));
}


BOOST_AUTO_TEST_CASE(method_arcsin_test)
{
    BOOST_CHECK_THROW(execute("asin(1.1)"), LanguageException);
    BOOST_CHECK_THROW(execute("asin(-1.1)"), LanguageException);
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("asin", { "0" }), NullableValueNumber(std::asin(*NullableValueNumber(0).value))));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("asin", { "null_n()" })));
}



BOOST_AUTO_TEST_CASE(method_prev_test)
{
    InterpreterContext context1;
    context1.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer1 = getReturnVarBuffer("prev", { "tick()", "1" }, context1);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueNumber>(buffer1.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(MAX_TICK_SIZE - 1)), NullableValueNumber(3)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("prev", { "tick()", "null_n()"})));

    BOOST_CHECK_THROW(execute("prev(tick(), -10)"), LanguageException);


    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("prev", { "\"Hello World!\"", "1" }, context2);

    BOOST_CHECK(isNull(safeExpressionCast<NullableValueString>(buffer2.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueString>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueString("Hello World!")));

    BOOST_CHECK(isNull(getReturn<NullableValueString>("prev", { "\"Hello World!\"", "null_n()" })));

    BOOST_CHECK_THROW(execute("prev(\"Hello World!\", -10)"), LanguageException);


    InterpreterContext context3;
    context3.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer3 = getReturnVarBuffer("prev", { "true", "1" }, context3);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueBoolean>(buffer3.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(buffer3.at(MAX_TICK_SIZE - 1)), NullableValueBoolean(true)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("prev", { "true", "null_n()" })));


    BOOST_CHECK_THROW(execute("prev(true, -10)"), LanguageException);

}


BOOST_AUTO_TEST_CASE(method_median_test)
{

    // odd number case
    InterpreterContext context1;
    context1.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer1 = getReturnVarBuffer("median", { "tick()"}, context1);
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer1.at(MAX_TICK_SIZE - 1)), NullableValueNumber(2)));

    // even number case
    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE + 1;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("median", { "tick()" }, context2);
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE)), NullableValueNumber(2.5)));


    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("median", { "null_n()" })));
}

BOOST_AUTO_TEST_CASE(method_is_prime_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isprime", { "7" }), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isprime", { "3" }), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isprime", { "2" }), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isprime", { "1" }), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isprime", { "0" }), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("isprime", { "-1" }), NullableValueBoolean(false)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("isprime", { "null_n()" })));
}


BOOST_AUTO_TEST_CASE(method_is_triangle_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("istriangle", { "10" }), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("istriangle", { "3" }), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("istriangle", { "2" }), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("istriangle", { "1" }), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("istriangle", { "0" }), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("istriangle", { "-1" }), NullableValueBoolean(false)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("istriangle", { "null_n()" })));
}

BOOST_AUTO_TEST_CASE(method_ma_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("ma", { "0", "1" }), NullableValueNumber(0)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("ma", { "null_n()", "1" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("ma", { "1", "null_n()" })));
    BOOST_CHECK_THROW(execute("ma(1, -1)"), LanguageException);
    BOOST_CHECK_THROW(execute("ma(1, 0)"), LanguageException);

    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("ma", { "tick()", "2" }, context2);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueNumber>(buffer2.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(1)), NullableValueNumber(0.5)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(3.5)));

}

BOOST_AUTO_TEST_CASE(method_max_bars_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("max", { "0", "1" }), NullableValueNumber(0)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("max", { "null_n()", "1" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("max", { "1", "null_n()" })));
    BOOST_CHECK_THROW(execute("max(1, -1)"), LanguageException);
    BOOST_CHECK_THROW(execute("max(1, 0)"), LanguageException);

    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("max", { "tick()", "2" }, context2);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueNumber>(buffer2.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(1)), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(MAX_TICK_SIZE - 1)));
}

BOOST_AUTO_TEST_CASE(method_min_bars_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("min", { "0", "1" }), NullableValueNumber(0)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("min", { "null_n()", "1" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("min", { "1", "null_n()" })));
    BOOST_CHECK_THROW(execute("min(1, -1)"), LanguageException);
    BOOST_CHECK_THROW(execute("min(1, 0)"), LanguageException);

    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("min", { "tick()", "2" }, context2);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueNumber>(buffer2.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(1)), NullableValueNumber(0)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(MAX_TICK_SIZE - 2)));
}

BOOST_AUTO_TEST_CASE(method_sum_bars_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("sum", { "0", "1" }), NullableValueNumber(0)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("sum", { "null_n()", "1" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("sum", { "1", "null_n()" })));
    BOOST_CHECK_THROW(execute("sum(1, -1)"), LanguageException);
    BOOST_CHECK_THROW(execute("sum(1, 0)"), LanguageException);

    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("sum", { "tick()", "2" }, context2);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueNumber>(buffer2.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(1)), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(7)));
}


BOOST_AUTO_TEST_CASE(method_falling_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("falling", { "0", "1" }), NullableValueBoolean(true)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("falling", { "null_n()", "1" })));
    BOOST_CHECK_THROW(execute("falling(1, -1)"), LanguageException);
    BOOST_CHECK_THROW(execute("falling(1, 0)"), LanguageException);
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("falling", { "1", "null_n()" })));

    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("falling", { "tick()", "2" }, context2);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueBoolean>(buffer2.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(buffer2.at(1)), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueBoolean(false)));

    InterpreterContext context3;
    context3.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer3 = getReturnVarBuffer("falling", { "-tick()", "2" }, context3);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueBoolean>(buffer3.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(buffer3.at(1)), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(buffer3.at(MAX_TICK_SIZE - 1)), NullableValueBoolean(true)));
}


BOOST_AUTO_TEST_CASE(method_rising_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueBoolean>("rising", { "0", "1" }), NullableValueBoolean(true)));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("rising", { "null_n()", "1" })));
    BOOST_CHECK(isNull(getReturn<NullableValueBoolean>("rising", { "1", "null_n()" })));
    BOOST_CHECK_THROW(execute("rising(1, -1)"), LanguageException);
    BOOST_CHECK_THROW(execute("rising(1, 0)"), LanguageException);

    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("rising", { "tick()", "2" }, context2);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueBoolean>(buffer2.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(buffer2.at(1)), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueBoolean(true)));

    InterpreterContext context3;
    context3.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer3 = getReturnVarBuffer("rising", { "-tick()", "2" }, context3);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueBoolean>(buffer3.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(buffer3.at(1)), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(buffer3.at(MAX_TICK_SIZE - 1)), NullableValueBoolean(false)));
}


BOOST_AUTO_TEST_CASE(method_median_bars_test)
{
    BOOST_CHECK(isEquiv(getReturn<NullableValueNumber>("median", { "0", "1" }), NullableValueNumber(0)));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("median", { "null_n()", "1" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("median", { "1", "null_n()" })));
    BOOST_CHECK_THROW(execute("median(1, -1)"), LanguageException);
    BOOST_CHECK_THROW(execute("median(1, 0)"), LanguageException);

    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("median", { "tick()", "2" }, context2);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueNumber>(buffer2.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(1)), NullableValueNumber(0.5)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(3.5)));
}


BOOST_AUTO_TEST_CASE(method_variance_test)
{
    BOOST_CHECK_THROW(execute("variance(0, 1, tick())"), LanguageException);


    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("variance", { "null_n()", "2" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("variance", { "1", "null_n()" })));
    BOOST_CHECK_THROW(execute("variance(1, -1)"), LanguageException);
    BOOST_CHECK_THROW(execute("variance(1, 0)"), LanguageException);

    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("variance", { "tick()", "2" }, context2);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueNumber>(buffer2.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(1)), NullableValueNumber(0.5)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(0.5)));
}


BOOST_AUTO_TEST_CASE(method_std_test)
{
    BOOST_CHECK_THROW(execute("std(0, 1, tick())"), LanguageException);


    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("std", { "null_n()", "2" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("std", { "1", "null_n()" })));
    BOOST_CHECK_THROW(execute("std(1, -1)"), LanguageException);
    BOOST_CHECK_THROW(execute("std(1, 0)"), LanguageException);

    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("std", { "tick()", "2" }, context2);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueNumber>(buffer2.at(0))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(1)), NullableValueNumber(std::sqrt(0.5))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(std::sqrt(0.5))));
}


BOOST_AUTO_TEST_CASE(method_linreg_test)
{
    BOOST_CHECK_THROW(execute("linreg(0, 1, tick())"), LanguageException);
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("linreg", { "null_n()", "2", "tick()" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("linreg", { "0", "2", "null_n()" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("linreg", { "null_n()", "2", "null_n()" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("linreg", { "1", "null_n()", "tick()" })));
    BOOST_CHECK_THROW(execute("linreg(1, -1, tick())"), LanguageException);
    BOOST_CHECK_THROW(execute("linreg(1, 0), tick()"), LanguageException);

    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("linreg", { "tick()", "2", "tick()" }, context2);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueNumber>(buffer2.at(0))));
    std::cout << safeExpressionCast<NullableValueNumber>(buffer2.at(1)).toString() << std::endl;
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(1)), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(4)));
}


BOOST_AUTO_TEST_CASE(method_corr_test)
{
    BOOST_CHECK_THROW(execute("corr(tick(), tick(), 1)"), LanguageException);
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("corr", { "null_n()", "tick()", "2" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("corr", { "tick()", "null_n()", "2" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("corr", { "null_n()", "null_n()", "2" })));
    BOOST_CHECK(isNull(getReturn<NullableValueNumber>("corr", { "null_n()", "null_n()", "null_n()" })));


    InterpreterContext context2;
    context2.ticks = MAX_TICK_SIZE;
    std::vector<ExpressionValue> buffer2 = getReturnVarBuffer("corr", { "tick()", "tick()", "2" }, context2);
    BOOST_CHECK(isNull(safeExpressionCast<NullableValueNumber>(buffer2.at(0))));
    std::cout << safeExpressionCast<NullableValueNumber>(buffer2.at(1)).toString() << std::endl;
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(1)), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(buffer2.at(MAX_TICK_SIZE - 1)), NullableValueNumber(1)));
}

BOOST_AUTO_TEST_SUITE_END()
