#include "node.h"
#include "symboltable.h"
#include "binaryoperator.h"
#include "unaryoperator.h"

void BlockNode::interpret(SymbolTable* symboltable) const {
	for (Statement* statement : statementNodes) {
		statement->interpret(symboltable);
	}
}

ExpressionValue NumberNode::interpret(SymbolTable* symboltable) const {
	return (ExpressionValue)Float(number);
}

ExpressionValue BooleanNode::interpret(SymbolTable* symboltable) const {
	return (ExpressionValue)Boolean(value);
}


ExpressionValue IdentifierNode::interpret(SymbolTable* symboltable) const {
	return symboltable->getVariable(name)->getValue();
}

ExpressionValue BinaryOpNode::interpret(SymbolTable* symboltable) const {
	ExpressionValue leftV = left->interpret(symboltable);
	ExpressionValue rightV = right->interpret(symboltable);
	return op->interpret(leftV, rightV);
}


ExpressionValue UnaryOpNode::interpret(SymbolTable* symboltable) const {
	ExpressionValue leftV = expression->interpret(symboltable);
	return op->interpret(leftV);
}



void AssignNode::interpret(SymbolTable* symboltable) const {
	ExpressionValue value = rhs->interpret(symboltable);
	symboltable->getVariable(name)->setValue(value);
	// need to store value in symbol table at lhs name
}