#pragma once
#include <iostream>
#include <vector>
#include "interpreteroutput.h"

class BlockNode;
class SymbolTable;


static std::vector<float> plotList = {0.2, 0.5, 0.8, 2.5, 4.2, 6, 3.2, 1.2, 5.6, 7.8, 2.8, 0.2, 0.5, 0.8, 2.5, 4.2, 6, 3.2, 1.2, 5.6, 7.8, 2.8, 0.2, 0.5, 0.8, 2.5, 4.2, 6, 3.2, 1.2, 5.6, 7.8, 2.8 , 0.2, 0.5, 0.8, 2.5, 4.2, 6, 3.2, 1.2, 5.6, 7.8, 2.8 , 0.2, 0.5, 0.8, 2.5, 4.2, 6, 3.2, 1.2, 5.6, 7.8, 2.8 };


/*
* Context object for running code.
*/
class InterpreterContext {

public:

	SymbolTable* symboltable = nullptr;
	BlockNode* ast = nullptr;
	InterpreterOutput output;

	void execute(const std::string& code);
	void execute(std::ifstream& myfile);

	~InterpreterContext();
private:


};