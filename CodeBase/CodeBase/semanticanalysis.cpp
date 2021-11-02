#include "node.h"
#include "symboltable.h"


void BlockNode::semanticAnalysis(SymbolTable* symboltable) const {
	for (Statement* statement : statementNodes) {
		statement->semanticAnalysis(symboltable);
	}
}

DataType NumberNode::semanticAnalysis(SymbolTable* symboltable) const {
	return DataType::Float;
}


DataType IdentifierNode::semanticAnalysis(SymbolTable* symboltable) const {
	// need to return item in symbol table
	if (symboltable->isDeclared(name)) {
		return symboltable->getVariable(name)->type;
	}
	else {
		std::cout << "ERROR NO VARIABLE EXISTS!" << std::endl;
	}

	return DataType::Float;
}

DataType BinaryOpNode::semanticAnalysis(SymbolTable* symboltable) const {
	DataType leftV = left->semanticAnalysis(symboltable);
	DataType rightV = right->semanticAnalysis(symboltable);
	if (leftV == DataType::Float && rightV == DataType::Float) {
		return DataType::Float;
	}
	else {
		std::cout << "ERROR NOT FLOATS!" << std::endl;
	}
	return DataType::Float;
}



void AssignNode::semanticAnalysis(SymbolTable* symboltable) const {
	DataType rhsType = rhs->semanticAnalysis(symboltable);

	// variable already declared therefore right side type should be same as left side type
	if (symboltable->isDeclared(name)) {
		if (symboltable->getVariable(name)->type != rhsType) {
			std::cout << "ERROR TYPES DO NOT MATCH" << std::endl;
		}
	}
	// variable not declared register new variable
	else {
		symboltable->declareVariable(std::make_shared<VarSymbol>(name, rhsType));
	}
	// need to store value in symbol table at lhs name
}