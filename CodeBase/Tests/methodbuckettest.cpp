#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <string>
#include "CodeBase/methodsymbol.h"
#include "CodeBase/typesymbol.h"
#include "CodeBase/returnsymbol.h"
#include "CodeBase/parametersymbol.h"
#include "CodeBase/node.h"
#include "CodeBase/symboltable.h"
#include "CodeBase/methodbucket.h"
#include "CodeBase/languageexception.h"


BOOST_AUTO_TEST_SUITE(METHODBUCKET)

#define TEST_METHOD_NAME "testmethod"

BOOST_AUTO_TEST_CASE(single_method_bucket_test)
{
    /*
    A typical method with 2 parameters
    */
    class TestPositionalMethod : public PositionalMethodSymbol {
    public:
        TestPositionalMethod()
            : PositionalMethodSymbol(TEST_METHOD_NAME, "description",
                { ParameterSymbol(TypeInstances::GetBooleanInstance(), "param1", "descr"),
                 ParameterSymbol(TypeInstances::GetBooleanInstance(), "param2", "descr") },
                ReturnSymbol(TypeInstances::GetBooleanInstance())) {}

        virtual ExpressionValue interpret(const unsigned int tick) override { return NullableValueBoolean(); }
        virtual TestPositionalMethod* clone() { return new TestPositionalMethod(); };
    };


    TestPositionalMethod* testMethod = new TestPositionalMethod();

    SingleMethodBucket* singleMethodBucket = new SingleMethodBucket(testMethod, METHOD_CAT::MISC);
    BOOST_CHECK(singleMethodBucket->getMethodSymbol(nullptr, nullptr) == testMethod);
    delete testMethod;
    delete singleMethodBucket;
}


BOOST_AUTO_TEST_CASE(overloaded_method_bucket_test)
{
    /*
    A typical method with 2 parameters
    */
    class TestPositionalMethod1 : public PositionalMethodSymbol {
    public:
        TestPositionalMethod1()
            : PositionalMethodSymbol(TEST_METHOD_NAME, "description",
                { ParameterSymbol(TypeInstances::GetBooleanInstance(), "param1", "descr"),
                 ParameterSymbol(TypeInstances::GetBooleanInstance(), "param2", "descr") },
                ReturnSymbol(TypeInstances::GetBooleanInstance())) {}

        virtual ExpressionValue interpret(const unsigned int tick) override { return NullableValueBoolean(); }
        virtual TestPositionalMethod1* clone() { return new TestPositionalMethod1(); };
    };

    class TestPositionalMethod2 : public PositionalMethodSymbol {
    public:
        TestPositionalMethod2()
            : PositionalMethodSymbol(TEST_METHOD_NAME, "description",
                { ParameterSymbol(TypeInstances::GetBooleanInstance(), "param1", "descr"),
                 ParameterSymbol(TypeInstances::GetBooleanInstance(), "param2", "descr"),
                 ParameterSymbol(TypeInstances::GetBooleanInstance(), "param3", "descr") },
                ReturnSymbol(TypeInstances::GetBooleanInstance())) {}

        virtual ExpressionValue interpret(const unsigned int tick) override { return NullableValueBoolean(); }
        virtual TestPositionalMethod2* clone() { return new TestPositionalMethod2(); };
    };


    TestPositionalMethod1* testMethod1 = new TestPositionalMethod1();
    TestPositionalMethod2* testMethod2 = new TestPositionalMethod2();

    OverloadedMethodBucket* overloadMethodBucket = new OverloadedMethodBucket({testMethod1, testMethod2}, METHOD_CAT::MISC);
    std::shared_ptr<SymbolTable> table = std::make_shared<SymbolTable>(nullptr);


    // should choose first overload
    MethodCallNode* methodcallNode1 = new MethodCallNode(TEST_METHOD_NAME,
        { new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()) },
        yy::SourceLocation());



    BOOST_CHECK(overloadMethodBucket->getMethodSymbol(methodcallNode1, table) == testMethod1);

    // should choose second overload
    MethodCallNode* methodcallNode2 = new MethodCallNode(TEST_METHOD_NAME,
        { new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()) },
        yy::SourceLocation());

    BOOST_CHECK(overloadMethodBucket->getMethodSymbol(methodcallNode2, table) == testMethod2);


    delete methodcallNode1;
    delete methodcallNode2;
    delete testMethod1;
    delete testMethod2;
    delete overloadMethodBucket;
}


BOOST_AUTO_TEST_SUITE_END()
