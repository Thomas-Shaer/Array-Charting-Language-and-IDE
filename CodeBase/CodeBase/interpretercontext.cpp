#include "interpretercontext.h"

#include "node.h"


#include "bison.tab.h"
#include "flex.flex.h"
#include "symboltable.h"
#include "languageexception.h"
#include <fstream>
#include <string>
#include "chartwindow.h"


unsigned int InterpreterContext::ticks = 30;
bool InterpreterContext::isIntellisense = false;


void InterpreterContext::intellisense(const std::string& code) {
	yy::SourceLocation* sl = new yy::SourceLocation();
	InterpreterContext::isIntellisense = true;
	try {
		/*
		Performs lexing + parsing operations
		via flex + bison.
		Parsing errors will be caught.
		*/
		output = std::make_shared<InterpreterOutput>();

		yyscan_t scanner;
		std::string errorReturn = "";
		yylex_init(&scanner);
		yy_scan_string(code.c_str(), scanner);
		

		yy::parser parseengine(scanner, &errorReturn, &ast, &sl);
		int parseResult = parseengine.parse();
		if (parseResult != 0) {
			throw LanguageException("Parsing Error: " + errorReturn, *sl);
		}


		yylex_destroy(scanner);



		/*
		Performs semantic anaylsis stage. 
		Semantic errors will be caught.
		*/
		symboltable = std::make_shared<SymbolTable>(SymbolTable::GLOBAL_SYMBOL_TABLE);
		std::vector<std::shared_ptr<VarSymbol>> variables = symboltable->variablesToVector(true);

		ast->semanticAnalysis(symboltable);
	}
	catch (LanguageException langexception) {
		output->langExcept = langexception;
	}
	InterpreterContext::isIntellisense = false;
	delete sl;
}

void InterpreterContext::execute(const std::string& code) {

	yy::SourceLocation* sl = new yy::SourceLocation();
	try {

		/*
		Performs lexing + parsing operations
		via flex + bison.
		Parsing errors will be caught.
		*/
		output = std::make_shared<InterpreterOutput>();

		yyscan_t scanner;
		std::string errorReturn = "";
		yylex_init(&scanner);
		yy_scan_string(code.c_str(), scanner);
		

		yy::parser parseengine(scanner, &errorReturn, &ast, &sl);
		int parseResult = parseengine.parse();
		if (parseResult != 0) {
			throw LanguageException("Parsing Error: " + errorReturn, *sl);
		}

		yylex_destroy(scanner);


		/*
		Performs semantic anaylsis stage.
		Semantic errors will be caught.
		*/
		symboltable = std::make_shared<SymbolTable>(SymbolTable::GLOBAL_SYMBOL_TABLE);
		std::vector<std::shared_ptr<VarSymbol>> variables = symboltable->variablesToVector(true);
		/*
		Finding the largest array to set the tick size to.
		*/
		for (std::shared_ptr<VarSymbol> variable : variables) {
			InterpreterContext::ticks = InterpreterContext::ticks < variable->originalSize ? variable->originalSize : InterpreterContext::ticks;
		}
		/*
		Matches all variables so they are have the same buffer size as that max series
		*/
		for (std::shared_ptr<VarSymbol> variable : variables) {
			variable->matchTickSize();
		}



		ChartWindow::clearAllCharts();
		
		
		ast->semanticAnalysis(symboltable);
		
		
		/*
		Performs interpretation for each tick
		*/
		for (int i = 0; i < ticks; i++) {
			ast->interpret(i);
		}		
	}
	catch (LanguageException langexception) {
		output->langExcept = langexception;
	}
	delete sl;
}


InterpreterContext::~InterpreterContext() {
	if (ast) {
		delete ast;
	}

}