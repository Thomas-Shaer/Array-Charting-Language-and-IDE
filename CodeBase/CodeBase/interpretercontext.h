#pragma once
#include <iostream>
#include <vector>

class BlockNode;
class SymbolTable;

/*
* Context object for running code.
*/
class InterpreterContext {

public:

	SymbolTable* symboltable = nullptr;
	BlockNode* ast = nullptr;
	std::vector<std::string> output;

	void execute(const std::string& code);
	void execute(std::ifstream& myfile);

	~InterpreterContext();
private:


};