#pragma once
#include <iostream>
#include <vector>
#include "languageexception.h"
#include <optional>

class BlockNode;
class SymbolTable;

/*
* Context object for running code.
*/
class InterpreterContext {

public:

	/*
	Amount of times the code will be executed in the interpreter stage.
	This will be the size of the largest series of data inputted into the program.
	*/
	static unsigned int ticks;

	/*
	The main symbol table.
	*/
	std::shared_ptr<SymbolTable> symboltable = nullptr;
	
	/*
	The AST of the program
	*/
	BlockNode* ast = nullptr;

	/*
	The output of the program
	*/
	std::optional<LanguageException> langExcept;

	/*
	Executes the source code read in from a string.
	*/
	void execute(const std::string& code);


	/*
	Executes the source code read in from a string.
	*/
	void executeNoCatch(const std::string& code);
	
	
	/*
	Runs "error highlighting" execution of source code which
	only involves executing the parser + semantic analyzer
	such that compile time errors can be read. 
	*/
	void errorHighlighting(const std::string& code);

	/*
	Flag for when interpeter is running as intellisense.
	*/
	static bool isIntellisense;
	~InterpreterContext();
private:


};