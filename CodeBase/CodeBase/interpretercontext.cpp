#include "interpretercontext.h"

#include "node.h"


#include "bison.tab.h"
#include "flex.flex.h"
#include "symboltable.h"
#include "languageexception.h"
#include <fstream>
#include <string>


unsigned int InterpreterContext::ticks = 30;

void InterpreterContext::execute(const std::string& code) {


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

		symboltable = std::make_shared<SymbolTable>(SymbolTable::GLOBAL_SYMBOL_TABLE);

		output = std::make_shared<InterpreterOutput>(ticks);

		ast->semanticAnalysis(symboltable, *output);

		for (int i = 0; i < ticks; i++) {
			ast->interpret(i, *output);
		}		//std::cout << symboltable->toString() << std::endl;



	}
	catch (LanguageException langexception) {
		std::cout << langexception.message << std::endl;
		output->textOutput.push_back(langexception.message);
	}


	//std::cout << "_______________________________" << std::endl;
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


		symboltable = std::make_shared<SymbolTable>(SymbolTable::GLOBAL_SYMBOL_TABLE);
		output = std::make_shared<InterpreterOutput>(ticks);
		ast->semanticAnalysis(symboltable, *output);
		for (int i = 0; i < ticks; i++) {
			ast->interpret(i, *output);
		}



	}
	catch (LanguageException langexception) {
		std::cout << langexception.message << std::endl;
		output->textOutput.push_back(langexception.message);

	}



}


InterpreterContext::~InterpreterContext() {
	if (ast) {
		delete ast;
	}

}