#include "node.h"
#include "symboltable.h"

void BlockNode::interpret(SymbolTable* symboltable) const {
	for (Statement* statement : statementNodes) {
		statement->semanticAnalysis(symboltable);
	}
}

ExpressionValue NumberNode::interpret(SymbolTable* symboltable) const {
	return (ExpressionValue)number;
}


ExpressionValue IdentifierNode::interpret(SymbolTable* symboltable) const {
	return symboltable->getVariable(name)->getValue();
}

ExpressionValue BinaryOpNode::interpret(SymbolTable* symboltable) const {
	ExpressionValue leftV = left->interpret(symboltable);
	ExpressionValue rightV = right->interpret(symboltable);
	return boost::get<float>(leftV) + boost::get<float>(rightV);
}



void AssignNode::interpret(SymbolTable* symboltable) const {
	ExpressionValue value = rhs->interpret(symboltable);
	symboltable->getVariable(name)->setValue(value);
	// need to store value in symbol table at lhs name
}