#pragma once
#include <map>
#include <memory>
#include <iostream>

class VarSymbol;

/*
* Symbol table stores values of variables e.g.
*/
class SymbolTable {
public:



	//returns true if variable is declared
	bool isDeclared(const std::string& name);
	
	//delare new variable
	void declareVariable(std::shared_ptr<VarSymbol> varsymbol);

	/*
	* Returns variable symbol given a name.
	* WARNING - must first check to see if variable is declared (declareVariable)
	*/
	std::shared_ptr<VarSymbol> getVariable(const std::string& name);

	
	//converts symbol table to string
	std::string toString();

private:
	// use of shared pointer to remove change of memory leak + helps increase compile time
	std::map<std::string, std::shared_ptr<VarSymbol>> values;
};