#include "node.h"
#include "symboltable.h"
#include "languageexception.h"
#include "operator.h"

void BlockNode::semanticAnalysis(SymbolTable* symboltable) const {
	for (Statement* statement : statementNodes) {
		statement->semanticAnalysis(symboltable);
	}
}

DataType NumberNode::semanticAnalysis(SymbolTable* symboltable) const {
	return DataType::Float;
}

DataType BooleanNode::semanticAnalysis(SymbolTable* symboltable) const {
	return DataType::Boolean;
}



DataType IdentifierNode::semanticAnalysis(SymbolTable* symboltable) const {
	// need to return item in symbol table
	if (symboltable->isDeclared(name)) {
		return symboltable->getVariable(name)->type;
	}
	throw LanguageException("No variable called " + name);
}

DataType BinaryOpNode::semanticAnalysis(SymbolTable* symboltable) const {
	DataType leftV = left->semanticAnalysis(symboltable);
	DataType rightV = right->semanticAnalysis(symboltable);


	return op->semanticAnaylsis(leftV, rightV);
}



void AssignNode::semanticAnalysis(SymbolTable* symboltable) const {
	DataType rhsType = rhs->semanticAnalysis(symboltable);

	// variable already declared therefore right side type should be same as left side type
	if (symboltable->isDeclared(name)) {
		if (symboltable->getVariable(name)->type != rhsType) {
			throw LanguageException("RHS type does not match LHS");
		}
	}
	// variable not declared register new variable
	else {
		symboltable->declareVariable(std::make_shared<VarSymbol>(name, rhsType));
	}
	// need to store value in symbol table at lhs name
}