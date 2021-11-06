#include "symboltable.h"
#include "varsymbol.h"
#include "methodsymbol.h"
#include "methodimplementations.h"


std::map<std::string, MethodSymbol*> SymbolTable::methodTable{
	{"average", new MethodAverage()}
};

SymbolTable::SymbolTable() {}

std::string SymbolTable::toString() {
	std::string output = "SYMBOL TABLE\nVariables:\n";

	for (const auto& value : variableTable) {
		output += value.second->toString() + "\n";
	}

	output += "Methods:\n";

	for (const auto& value : methodTable) {
		output += value.second->toString() + "\n";
	}

	return output;
}

bool SymbolTable::isVariableDeclared(const std::string& name) {
	return variableTable.find(name) != variableTable.end();
}

bool SymbolTable::isMethodDeclared(const std::string& name) {
	return methodTable.find(name) != methodTable.end();
}

std::shared_ptr<VarSymbol> SymbolTable::getVariable(const std::string& name) {
	return variableTable[name];
}


MethodSymbol* SymbolTable::getMethod(const std::string& name) {
	return methodTable[name];
}

void SymbolTable::declareVariable(std::shared_ptr<VarSymbol> varsymbol) {
	variableTable[varsymbol->name] = varsymbol;
}
