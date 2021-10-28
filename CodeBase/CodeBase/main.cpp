
#include <iostream>


#include "node.h"


#include "bison.tab.h"
#include "flex.flex.h"


int main() {



	yyscan_t scanner;
	const char* inputCode = "x = 2 + 5 \
                             y = 123 + 21 + 51 + 312 + x";
	yylex_init(&scanner);
	yy_scan_string(inputCode, scanner);
	std::string errorReturn = "";
	BlockNode* input;

	yy::parser parseengine(scanner, &input);
	int parseResult = parseengine.parse(); 
	if (parseResult != 0) {
		std::cout << "error" << std::endl;
	}
	else {
		std::cout << "succ parsed" << std::endl;
	}

	yylex_destroy(scanner);

	std::cout << input->toString() << std::endl;
	SymbolTable* symboltable = new SymbolTable();
	
	input->evaluate(symboltable);
	std::cout << symboltable->toString() << std::endl;


	delete input;
	delete symboltable;

}