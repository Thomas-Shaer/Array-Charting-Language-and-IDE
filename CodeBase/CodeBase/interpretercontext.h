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

	SymbolTable* symboltable = nullptr;
	BlockNode* ast = nullptr;
	InterpreterOutput output;

	void execute(const std::string& code);
	void execute(std::ifstream& myfile);

	~InterpreterContext();
private:


};