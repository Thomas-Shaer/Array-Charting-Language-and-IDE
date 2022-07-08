#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <string>
#include <CodeBase/sourcelocation.h>

BOOST_AUTO_TEST_SUITE(SOURCELOCATION)

BOOST_AUTO_TEST_CASE(source_location_concat_test)
{
    yy::SourceLocation source1(yy::Position(10, 20), yy::Position(40, 10));
    yy::SourceLocation source2(yy::Position(2, 41), yy::Position(80, 90));

    auto concat = source1 + source2;

    BOOST_CHECK(concat.begin.line == source2.begin.line);
    BOOST_CHECK(concat.begin.column == source1.begin.column);
    BOOST_CHECK(concat.end.line == source2.end.line);
    BOOST_CHECK(concat.end.column == source2.end.column);
}

BOOST_AUTO_TEST_CASE(source_location_highlight_test)
{
    yy::SourceLocation source1(yy::Position(0, 0), yy::Position(0, 5));
    BOOST_CHECK(source1.highlightSourceLocation("Hello World!") == "Hello World!\n^^^^^");
}
BOOST_AUTO_TEST_SUITE_END()