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
#define NULLSTRING "nan"


std::pair<std::vector<ExpressionValue>, TypeSymbol*> parseNoError(const std::vector<std::string>& data) {
    std::pair<std::vector<ExpressionValue>, TypeSymbol*> results;
    BOOST_CHECK_NO_THROW(results = InputSeries::parse(data, TRUESTRING, FALSESTRING, NULLSTRING));
    BOOST_CHECK(results.first.size() == data.size());
    return results;
}

void parseError(const std::vector<std::string>& data) {
    BOOST_CHECK_THROW(InputSeries::parse(data, TRUESTRING, FALSESTRING, NULLSTRING), DataParseException);
}

BOOST_AUTO_TEST_CASE(input_series_parse_misc_test)
{

    parseError({});
    parseError({ NULLSTRING });
    parseError({ NULLSTRING, NULLSTRING, NULLSTRING });
    parseError({ NULLSTRING, "adsadasd", NULLSTRING });
    parseError({ "1.23", "adsadasd", NULLSTRING });
    parseError({ TRUESTRING, "adsadasd", NULLSTRING });
    parseError({ "1.2", TRUESTRING, NULLSTRING });


}


BOOST_AUTO_TEST_CASE(input_series_parse_number_test)
{

    auto resultParse1 = parseNoError({ NULLSTRING , NULLSTRING, "1", "1.2" });
    BOOST_CHECK(resultParse1.second == TypeInstances::GetNumberInstance());
    BOOST_CHECK(isNull<NullableValueNumber>(safeExpressionCast<NullableValueNumber>(resultParse1.first.at(0))));
    BOOST_CHECK(isNull<NullableValueNumber>(safeExpressionCast<NullableValueNumber>(resultParse1.first.at(1))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse1.first.at(2)), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse1.first.at(3)), NullableValueNumber(1.2)));


    auto resultParse2 = parseNoError({ "1", "1.2", NULLSTRING , NULLSTRING});
    BOOST_CHECK(resultParse2.second == TypeInstances::GetNumberInstance());
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse2.first.at(0)), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse2.first.at(1)), NullableValueNumber(1.2)));
    BOOST_CHECK(isNull<NullableValueNumber>(safeExpressionCast<NullableValueNumber>(resultParse2.first.at(2))));
    BOOST_CHECK(isNull<NullableValueNumber>(safeExpressionCast<NullableValueNumber>(resultParse2.first.at(3))));

    auto resultParse3 = parseNoError({ "1", "1.2", "1.3" , "1.5"});
    BOOST_CHECK(resultParse3.second == TypeInstances::GetNumberInstance());
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse3.first.at(0)), NullableValueNumber(1)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse3.first.at(1)), NullableValueNumber(1.2)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse3.first.at(2)), NullableValueNumber(1.3)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueNumber>(resultParse3.first.at(3)), NullableValueNumber(1.5)));

}

BOOST_AUTO_TEST_CASE(input_series_parse_boolean_test)
{

    auto resultParse1 = parseNoError({ NULLSTRING , NULLSTRING, TRUESTRING, FALSESTRING });
    BOOST_CHECK(resultParse1.second == TypeInstances::GetBooleanInstance());
    BOOST_CHECK(isNull<NullableValueBoolean>(safeExpressionCast<NullableValueBoolean>(resultParse1.first.at(0))));
    BOOST_CHECK(isNull<NullableValueBoolean>(safeExpressionCast<NullableValueBoolean>(resultParse1.first.at(1))));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse1.first.at(2)), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse1.first.at(3)), NullableValueBoolean(false)));


    auto resultParse2 = parseNoError({ TRUESTRING, FALSESTRING , NULLSTRING , NULLSTRING });
    BOOST_CHECK(resultParse2.second == TypeInstances::GetBooleanInstance());
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse2.first.at(0)), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse2.first.at(1)), NullableValueBoolean(false)));
    BOOST_CHECK(isNull<NullableValueBoolean>(safeExpressionCast<NullableValueBoolean>(resultParse2.first.at(2))));
    BOOST_CHECK(isNull<NullableValueBoolean>(safeExpressionCast<NullableValueBoolean>(resultParse2.first.at(3))));

    auto resultParse3 = parseNoError({ TRUESTRING, FALSESTRING, FALSESTRING, TRUESTRING });
    BOOST_CHECK(resultParse3.second == TypeInstances::GetBooleanInstance());
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse3.first.at(0)), NullableValueBoolean(true)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse3.first.at(1)), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse3.first.at(2)), NullableValueBoolean(false)));
    BOOST_CHECK(isEquiv(safeExpressionCast<NullableValueBoolean>(resultParse3.first.at(3)), NullableValueBoolean(true)));

}


BOOST_AUTO_TEST_SUITE_END()
