#pragma once
#include <iostream>
#include <vector>
#include "interpreteroutput.h"

class BlockNode;
class SymbolTable;

/*
* Context object for running code.
*/
class InterpreterContext {

public:

	static unsigned int ticks;

	std::shared_ptr<SymbolTable> symboltable = nullptr;
	BlockNode* ast = nullptr;
	std::shared_ptr<InterpreterOutput> output;

	void execute(const std::string& code);
	void execute(std::ifstream& myfile);
	void intellisense(const std::string& code);
	static bool isIntellisense;
	~InterpreterContext();
private:


};