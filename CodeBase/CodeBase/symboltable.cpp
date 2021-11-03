#include "symboltable.h"
#include "varsymbol.h"


SymbolTable::SymbolTable() {

	std::shared_ptr<VarSymbol> trueLiteral = std::make_shared<VarSymbol>("true", DataType::Boolean);
	trueLiteral->setValue(Boolean(true));
	declareVariable(trueLiteral);

	std::shared_ptr<VarSymbol> falseLiteral = std::make_shared<VarSymbol>("false", DataType::Boolean);
	falseLiteral->setValue(Boolean(false));
	declareVariable(falseLiteral);
}

std::string SymbolTable::toString() {
	std::string output = "SYMBOL TABLE\n";

	for (const auto& value : values) {
		output += value.second->toString() + "\n";
	}
	return output;
}

//returns true if variable is declared
bool SymbolTable::isDeclared(const std::string& name) {
	return values.find(name) != values.end();
}

std::shared_ptr<VarSymbol> SymbolTable::getVariable(const std::string& name) {
	return values[name];
}


void SymbolTable::declareVariable(std::shared_ptr<VarSymbol> varsymbol) {
	values[varsymbol->name] = varsymbol;
}
