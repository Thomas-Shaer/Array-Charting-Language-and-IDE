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
	InterpreterContext::isIntellisense = true;
	try {
		output = std::make_shared<InterpreterOutput>();

		yyscan_t scanner;
		std::string errorReturn = "";
		yylex_init(&scanner);
		yy_scan_string(code.c_str(), scanner);
		yy::SourceLocation* sl = new yy::SourceLocation();

		yy::parser parseengine(scanner, &errorReturn, &ast, &sl);
		int parseResult = parseengine.parse();
		if (parseResult != 0) {
			throw LanguageException("Parsing Error: " + errorReturn, *sl);
		}

		yylex_destroy(scanner);


		symboltable = std::make_shared<SymbolTable>(SymbolTable::GLOBAL_SYMBOL_TABLE);
		std::vector<std::shared_ptr<VarSymbol>> variables = symboltable->variablesToVector(true);

		ast->semanticAnalysis(symboltable);
	}
	catch (LanguageException langexception) {
		output->langExcept = langexception;
	}
	InterpreterContext::isIntellisense = false;
}

void InterpreterContext::execute(const std::string& code) {


	try {
		output = std::make_shared<InterpreterOutput>();

		yyscan_t scanner;
		std::string errorReturn = "";
		yylex_init(&scanner);
		yy_scan_string(code.c_str(), scanner);
		yy::SourceLocation* sl = new yy::SourceLocation();

		yy::parser parseengine(scanner, &errorReturn, &ast, &sl);
		int parseResult = parseengine.parse();
		if (parseResult != 0) {
			throw LanguageException("Parsing Error: " + errorReturn, *sl);
		}

		yylex_destroy(scanner);


		symboltable = std::make_shared<SymbolTable>(SymbolTable::GLOBAL_SYMBOL_TABLE);
		std::vector<std::shared_ptr<VarSymbol>> variables = symboltable->variablesToVector(true);
		/*
		Calculates largest series first
		*/
		for (std::shared_ptr<VarSymbol> variable : variables) {
			InterpreterContext::ticks = InterpreterContext::ticks < variable->originalSize ? variable->originalSize : InterpreterContext::ticks;
		}
		/*
		Matches all variables so they are have the same buffer size as that max series
		*/
		for (std::shared_ptr<VarSymbol> variable : variables) {
			variable->matchGlobalBufferSize();
		}



		ChartWindow::clearAllWindows();
		ast->semanticAnalysis(symboltable);
		for (int i = 0; i < ticks; i++) {
			ast->interpret(i);
		}		



	}
	catch (LanguageException langexception) {
		output->langExcept = langexception;
	}


}


void InterpreterContext::execute(std::ifstream& myfile) {
	std::string code = "";
	std::string line;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			code += line + "\n";
		}
		myfile.close();
	}

	std::shared_ptr<SymbolTable> symboltable = nullptr;
	try {
		output = std::make_shared<InterpreterOutput>();

		yyscan_t scanner;
		std::string errorReturn = "";
		yylex_init(&scanner);
		yy_scan_string(code.c_str(), scanner);

		yy::SourceLocation* sl = new yy::SourceLocation();
		yy::parser parseengine(scanner, &errorReturn, &ast, &sl);
		int parseResult = parseengine.parse();
		if (parseResult != 0) {
			throw LanguageException("Parsing Error: " + errorReturn, *sl);
		}

		yylex_destroy(scanner);


		symboltable = std::make_shared<SymbolTable>(SymbolTable::GLOBAL_SYMBOL_TABLE);

		ChartWindow::clearAllWindows();
		ast->semanticAnalysis(symboltable);
		for (int i = 0; i < ticks; i++) {
			ast->interpret(i);
		}



	}
	catch (LanguageException langexception) {
		output->langExcept = langexception;
	}



}


InterpreterContext::~InterpreterContext() {
	if (ast) {
		delete ast;
	}

}