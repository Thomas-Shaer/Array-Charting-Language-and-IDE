#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "valuetesthelper.h"
//#include <string>
#include "CodeBase/inputseries.h"
#include "CodeBase/typesymbol.h"
#include "CodeBase/dataparseexception.h"

BOOST_AUTO_TEST_SUITE(INPUTSERIES)


#define TRUESTRING "true"
#define FALSESTRING "false"
#define NANSTRING "nan"


std::pair<std::vector<ExpressionValue>, TypeSymbol*> parseNoError(const std::vector<std::string>& data) {
    std::pair<std::vector<ExpressionValue>, TypeSymbol*> results;
    BOOST_CHECK_NO_THROW(results = InputSeries::parse(data, TRUESTRING, FALSESTRING, NANSTRING));
    BOOST_CHECK(results.first.size() == data.size());
    return results;
}

void parseError(const std::vector<std::string>& data) {
    BOOST_CHECK_THROW(InputSeries::parse(data, TRUESTRING, FALSESTRING, NANSTRING), DataParseException);
}

BOOST_AUTO_TEST_CASE(input_series_parse_misc_test)
{

    parseError({});
    parseError({ NANSTRING });
    parseError({ NANSTRING, NANSTRING, NANSTRING });
    parseError({ NANSTRING, "adsadasd", NANSTRING });
    parseError({ "1.23", "adsadasd", NANSTRING });
    parseError({ TRUESTRING, "adsadasd", NANSTRING });
    parseError({ "1.2", TRUESTRING, NANSTRING });


}


BOOST_AUTO_TEST_CASE(input_series_parse_number_test)
{

    auto resultParse1 = parseNoError({ NANSTRING , NANSTRING, "1", "1.2" });
    BOOST_CHECK(resultParse1.second == TypeInstances::GetNumberInstance());
    BOOST_CHECK(isNaN<NullableValueNumber>(safeExpressionCast<NullableValueNumber>(resultParse1.first.at(0))));
    BOOST_CHECK(isNaN<NullableValueNumber>(safeExpressionCast<NullableValueNumber>(resultParse1.first.at(1))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse1.first.at(2)), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse1.first.at(3)), NullableValueNumber(1.2)));


    auto resultParse2 = parseNoError({ "1", "1.2", NANSTRING , NANSTRING});
    BOOST_CHECK(resultParse2.second == TypeInstances::GetNumberInstance());
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse2.first.at(0)), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse2.first.at(1)), NullableValueNumber(1.2)));
    BOOST_CHECK(isNaN<NullableValueNumber>(safeExpressionCast<NullableValueNumber>(resultParse2.first.at(2))));
    BOOST_CHECK(isNaN<NullableValueNumber>(safeExpressionCast<NullableValueNumber>(resultParse2.first.at(3))));

    auto resultParse3 = parseNoError({ "1", "1.2", "1.3" , "1.5"});
    BOOST_CHECK(resultParse3.second == TypeInstances::GetNumberInstance());
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse3.first.at(0)), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse3.first.at(1)), NullableValueNumber(1.2)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse3.first.at(2)), NullableValueNumber(1.3)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse3.first.at(3)), NullableValueNumber(1.5)));

}

BOOST_AUTO_TEST_CASE(input_series_parse_boolean_test)
{

    auto resultParse1 = parseNoError({ NANSTRING , NANSTRING, TRUESTRING, FALSESTRING });
    BOOST_CHECK(resultParse1.second == TypeInstances::GetBooleanInstance());
    BOOST_CHECK(isNaN<NullableValueBoolean>(safeExpressionCast<NullableValueBoolean>(resultParse1.first.at(0))));
    BOOST_CHECK(isNaN<NullableValueBoolean>(safeExpressionCast<NullableValueBoolean>(resultParse1.first.at(1))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse1.first.at(2)), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse1.first.at(3)), NullableValueBoolean(false)));


    auto resultParse2 = parseNoError({ TRUESTRING, FALSESTRING , NANSTRING , NANSTRING });
    BOOST_CHECK(resultParse2.second == TypeInstances::GetBooleanInstance());
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse2.first.at(0)), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse2.first.at(1)), NullableValueBoolean(false)));
    BOOST_CHECK(isNaN<NullableValueBoolean>(safeExpressionCast<NullableValueBoolean>(resultParse2.first.at(2))));
    BOOST_CHECK(isNaN<NullableValueBoolean>(safeExpressionCast<NullableValueBoolean>(resultParse2.first.at(3))));

    auto resultParse3 = parseNoError({ TRUESTRING, FALSESTRING, FALSESTRING, TRUESTRING });
    BOOST_CHECK(resultParse3.second == TypeInstances::GetBooleanInstance());
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse3.first.at(0)), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse3.first.at(1)), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse3.first.at(2)), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse3.first.at(3)), NullableValueBoolean(true)));

}


BOOST_AUTO_TEST_SUITE_END()
