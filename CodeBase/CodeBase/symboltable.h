#pragma once
#include <map>
#include <memory>
#include <iostream>
class VarSymbol;
class MethodBucket;

/*
* Symbol table stores variable and method symbols
*/
class SymbolTable {
public:

	static std::shared_ptr<SymbolTable> GLOBAL_SYMBOL_TABLE;

	/*
	Symbol table for dynamically created ones. 
	Therefore pass a enclosing symbol table.
	*/
	SymbolTable(std::shared_ptr<SymbolTable> _enclosingSymbolTable);

	/*
	Global symbol table creation. 
	I.e. no enclosing symbol table, so
	load this one with variables/methods.
	*/
	SymbolTable(std::map<std::string, MethodBucket*> _methodTable,
		std::map<std::string, std::shared_ptr<VarSymbol>> _variableTable);

	//returns true if variable is declared
	bool isVariableDeclared(const std::string& name);

	// returns true if method is declared
	bool isMethodDeclared(const std::string& name);
	
	//delare new variable
	void declareVariable(std::shared_ptr<VarSymbol> varsymbol);


	/*
	* Returns variable symbol given a name.
	* WARNING - must first check to see if variable is declared (isVariableDeclared)
	*/
	std::shared_ptr<VarSymbol> getVariable(const std::string& name);


	/*
	* Returns method symbol given a name.
	* WARNING - must first check to see if method is declared (isMethodDeclared)
	*/
	MethodBucket* getMethod(const std::string& name);


	
	//converts symbol table to string
	std::string toString();

	std::string variablesToString(bool _enclosing = false);

	// since methods can't be declared this table will never be changed.
	// therefore make it static so it isn't recreated every time symbol table is spawned
	// also no need for shared pointers for same reason. Use regular pointers to help compile time
	std::map<std::string, MethodBucket*> methodTable;


	// use of shared pointer to remove change of memory leak + helps increase compile time
	std::map<std::string, std::shared_ptr<VarSymbol>> variableTable;

private:

	std::shared_ptr<SymbolTable> enclosingSymbolTable;

};