#include "interpretercontext.h"

#include "node.h"


#include "bison.tab.h"
#include "flex.flex.h"
#include "symboltable.h"
#include "languageexception.h"
#include <fstream>
#include <string>



void InterpreterContext::execute(const std::string& code) {
	output.maxTicks = plotList.size();
	output.chartData.push_back(plotList);


	try {
		yyscan_t scanner;

		yylex_init(&scanner);
		yy_scan_string(code.c_str(), scanner);
		std::string errorReturn = "";

		yy::parser parseengine(scanner, &ast);
		int parseResult = parseengine.parse();
		if (parseResult != 0) {
			//std::cout << "error" << std::endl;
			throw LanguageException("Parsing Error");
		}

		yylex_destroy(scanner);

		std::cout << ast->toString() << std::endl;

		symboltable = new SymbolTable();

		ast->semanticAnalysis(symboltable, output);

		for (int i = 0; i < plotList.size(); i++) {
			ast->interpret(i, symboltable, output);
		}		//std::cout << symboltable->toString() << std::endl;



	}
	catch (LanguageException langexception) {
		std::cout << langexception.message << std::endl;
		output.textOutput.push_back(langexception.message);
	}


	//std::cout << "_______________________________" << std::endl;
}


void InterpreterContext::execute(std::ifstream& myfile) {
	output.maxTicks = plotList.size();
	output.chartData.push_back(plotList);
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

	SymbolTable* symboltable = nullptr;
	try {
		yyscan_t scanner;

		yylex_init(&scanner);
		yy_scan_string(code.c_str(), scanner);
		std::string errorReturn = "";

		yy::parser parseengine(scanner, &ast);
		int parseResult = parseengine.parse();
		if (parseResult != 0) {
			//std::cout << "error" << std::endl;
			throw LanguageException("Parsing Error");
		}

		yylex_destroy(scanner);


		symboltable = new SymbolTable();

		ast->semanticAnalysis(symboltable, output);
		for (int i = 0; i < plotList.size(); i++) {
			ast->interpret(i, symboltable, output);
		}



	}
	catch (LanguageException langexception) {
		std::cout << langexception.message << std::endl;
		output.textOutput.push_back(langexception.message);

	}



}


InterpreterContext::~InterpreterContext() {
	if (ast) {
		delete ast;
	}
	if (symboltable) {
		delete symboltable;
	}
}