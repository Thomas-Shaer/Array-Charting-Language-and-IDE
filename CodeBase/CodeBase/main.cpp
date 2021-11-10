
#include <iostream>


#include "node.h"


#include "bison.tab.h"
#include "flex.flex.h"
#include "symboltable.h"
#include "languageexception.h"

void execute(const std::string& code) {



	BlockNode* input = nullptr;
	SymbolTable* symboltable = nullptr;
	try {
		yyscan_t scanner;

		yylex_init(&scanner);
		yy_scan_string(code.c_str(), scanner);
		std::string errorReturn = "";

		yy::parser parseengine(scanner, &input);
		int parseResult = parseengine.parse();
		if (parseResult != 0) {
			//std::cout << "error" << std::endl;
			throw LanguageException("Parsing Error");
		}

		yylex_destroy(scanner);

		std::cout << input->toString() << std::endl;

		symboltable = new SymbolTable();

		input->semanticAnalysis(symboltable);
		input->interpret(symboltable);
		std::cout << symboltable->toString() << std::endl;



	}
	catch (LanguageException langexception) {
		std::cout << langexception.message << std::endl;
	}

	if (input) {
		delete input;
	}

	if (symboltable) {
		delete symboltable;
	}
	std::cout << "_______________________________" << std::endl;
}

int main() {
	//execute("x = 2 + 5 \
 //            y = 123 + 21 + 51 + 312 + x + q");


	//execute("z = true - false");

	//execute("false = 1.1231312 * 413 + 12");


	execute("a = 2 + 5 \
            b = 2 - 5 \
            c = 2 / 5 \
            d = 2 * 5 \
            e = 2 > 5 \
            f = 5 >= 5 \
            g = 5 < 2 \
            h = 1 <= 2 \
            i = false && false \
            i = false || false \
            k = 2 + 412 - 2");


	execute("a = +true");
	execute("a = 2 == 5");



	//execute("a = ! ! !false \
 //           b = + - - - - 2");


	/*execute("q = average(13, 12)");
	execute("q = average(13, 12, 13)");
	execute("q = average(13)");
	execute("q = average()");
	execute("q = average(true, 12)");*/
	//execute("x = -1");

}