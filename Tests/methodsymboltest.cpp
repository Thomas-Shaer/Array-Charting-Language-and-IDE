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


BOOST_AUTO_TEST_SUITE(METHODSYMBOL)

#define TEST_METHOD_NAME "testmethod"

BOOST_AUTO_TEST_CASE(positonal_method_symbol_semantic_test)
{
    /*
    A typical method with 2 parameters
    */
    class TestPositionalMethod : public PositionalMethodSymbol {
    public:
        TestPositionalMethod() 
            : PositionalMethodSymbol(TEST_METHOD_NAME, "description",
                {ParameterSymbol(TypeInstances::GetBooleanInstance(), "param1", "descr"),
                 ParameterSymbol(TypeInstances::GetBooleanInstance(), "param2", "descr") },
                ReturnSymbol(TypeInstances::GetBooleanInstance())) {}
        
        virtual ExpressionValue interpret(const unsigned int tick) override { return NullableValueBoolean(); }
        virtual TestPositionalMethod* clone() { return new TestPositionalMethod(); };
    };


    // set up and register method in symbol table
    std::shared_ptr<SymbolTable> symboltable = std::make_shared<SymbolTable>(
        std::map<std::string, MethodBucket*>({{TEST_METHOD_NAME, new SingleMethodBucket(new TestPositionalMethod(), METHOD_CAT::MISC)} }),
        std::map<std::string, std::shared_ptr<VarSymbol>>());



    // 0 params supplied should throw a error
    MethodCallNode* methodcallNode2 = new MethodCallNode(TEST_METHOD_NAME, {}, yy::SourceLocation());
    BOOST_CHECK_THROW(methodcallNode2->semanticAnalysis(symboltable), LanguageException);
    delete methodcallNode2;

    // 2 params supplied should pass fine
    MethodCallNode* methodcallNode1 = new MethodCallNode(TEST_METHOD_NAME, 
        {new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()) },
        yy::SourceLocation());

    BOOST_CHECK_NO_THROW(methodcallNode1->semanticAnalysis(symboltable));
    delete methodcallNode1;

    // 3 params supplied should throw a error
    MethodCallNode* methodcallNode3 = new MethodCallNode(TEST_METHOD_NAME,
        { new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()) },
        yy::SourceLocation());

    BOOST_CHECK_THROW(methodcallNode3->semanticAnalysis(symboltable), LanguageException);
    delete methodcallNode3;


    // 2 params but wrong type supplied should throw error
    MethodCallNode* methodcallNode4 = new MethodCallNode(TEST_METHOD_NAME,
        { new NumberNode(1.23, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()) },
        yy::SourceLocation());

    BOOST_CHECK_THROW(methodcallNode4->semanticAnalysis(symboltable), LanguageException);
    delete methodcallNode4;

    // 3 params supplied and wrong type should throw a error
    MethodCallNode* methodcallNode5 = new MethodCallNode(TEST_METHOD_NAME,
        { new BooleanNode(true, yy::SourceLocation()),
        new NumberNode(1.123, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()) },
        yy::SourceLocation());

    BOOST_CHECK_THROW(methodcallNode5->semanticAnalysis(symboltable), LanguageException);
    delete methodcallNode5;
}



BOOST_AUTO_TEST_CASE(keyword_method_symbol_semantic_test)
{
    /*
    A typical method with 2 parameters
    */
    class TestKeywordMethod : public KeywordMethodSymbol {
    public:
        TestKeywordMethod()
            : KeywordMethodSymbol(TEST_METHOD_NAME, "description",
                { ParameterSymbol(TypeInstances::GetBooleanInstance(), "param1", "descr"),
                 ParameterSymbol(TypeInstances::GetBooleanInstance(), "param2", "descr") },
                { OptionalParameterSymbol(TypeInstances::GetBooleanInstance(), NullableValueBoolean(), "param3", "descr"),
                OptionalParameterSymbol(TypeInstances::GetBooleanInstance(), NullableValueBoolean(), "param4", "descr") },
                ReturnSymbol(TypeInstances::GetBooleanInstance())) {}

        virtual ExpressionValue interpret(const unsigned int tick) override { return NullableValueBoolean(); }
        virtual TestKeywordMethod* clone() { return new TestKeywordMethod(); };
    };


    // set up and register method in symbol table
    std::shared_ptr<SymbolTable> symboltable = std::make_shared<SymbolTable>(
        std::map<std::string, MethodBucket*>({ {TEST_METHOD_NAME, new SingleMethodBucket(new TestKeywordMethod(), METHOD_CAT::MISC)} }),
        std::map<std::string, std::shared_ptr<VarSymbol>>());



    // 0 params supplied should throw a error
    MethodCallNode* methodcallNode2 = new MethodCallNode(TEST_METHOD_NAME, {}, yy::SourceLocation());
    BOOST_CHECK_THROW(methodcallNode2->semanticAnalysis(symboltable), LanguageException);
    delete methodcallNode2;


    // 2 positional params supplied should pass fine
    MethodCallNode* methodcallNode1 = new MethodCallNode(TEST_METHOD_NAME,
        { new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()) },
        yy::SourceLocation());

    BOOST_CHECK_NO_THROW(methodcallNode1->semanticAnalysis(symboltable));
    delete methodcallNode1;

    // 4 positional params supplied should pass fine
    MethodCallNode* methodcallNode3 = new MethodCallNode(TEST_METHOD_NAME,
        { new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()) },
        yy::SourceLocation());

    BOOST_CHECK_NO_THROW(methodcallNode3->semanticAnalysis(symboltable));
    delete methodcallNode3;


    // 5 positional params supplied should throw error
    MethodCallNode* methodcallNode4 = new MethodCallNode(TEST_METHOD_NAME,
        { new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()) },
        yy::SourceLocation());

    BOOST_CHECK_THROW(methodcallNode4->semanticAnalysis(symboltable), LanguageException);
    delete methodcallNode4;


    // 2 positional params supplied, 2 keyword should pass fine
    MethodCallNode* methodcallNode5 = new MethodCallNode(TEST_METHOD_NAME,
        { new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()),
        new KeywordNode("param3", new BooleanNode(true, yy::SourceLocation()), yy::SourceLocation()),
        new KeywordNode("param4", new BooleanNode(true, yy::SourceLocation()), yy::SourceLocation())},
        yy::SourceLocation());

    BOOST_CHECK_NO_THROW(methodcallNode5->semanticAnalysis(symboltable));
    delete methodcallNode5;


    // 2 positional params supplied, 2 keyword with wrong name - should throw error
    MethodCallNode* methodcallNode6 = new MethodCallNode(TEST_METHOD_NAME,
        { new BooleanNode(true, yy::SourceLocation()),
        new BooleanNode(true, yy::SourceLocation()),
        new KeywordNode("wrong_name", new BooleanNode(true, yy::SourceLocation()), yy::SourceLocation()),
        new KeywordNode("wrong_name2", new BooleanNode(true, yy::SourceLocation()), yy::SourceLocation()) },
        yy::SourceLocation());

    BOOST_CHECK_THROW(methodcallNode6->semanticAnalysis(symboltable), LanguageException);
    delete methodcallNode6;


  
}




BOOST_AUTO_TEST_SUITE_END()
