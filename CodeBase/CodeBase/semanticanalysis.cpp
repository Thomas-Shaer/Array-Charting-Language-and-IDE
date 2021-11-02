#include "node.h"


void BlockNode::semanticAnalysis(SymbolTable* symboltable) const {
	for (Statement* statement : statementNodes) {
		statement->semanticAnalysis(symboltable);
	}
}

ExpressionValue NumberNode::semanticAnalysis(SymbolTable* symboltable) const {
	return (ExpressionValue)number;
}


ExpressionValue IdentifierNode::semanticAnalysis(SymbolTable* symboltable) const {
	// need to return item in symbol table


	//return (ExpressionValue)number;
	return symboltable->values[name];
}

ExpressionValue BinaryOpNode::semanticAnalysis(SymbolTable* symboltable) const {
	ExpressionValue leftV = left->semanticAnalysis(symboltable);
	ExpressionValue rightV = right->semanticAnalysis(symboltable);
	if (leftV.type() == typeid(float) && rightV.type() == typeid(float)) {
		return boost::get<float>(leftV) + boost::get<float>(rightV);
	}
	else {
		std::cout << "ERROR NOT FLOATS!" << std::endl;
	}
	return (float)0;
}



void AssignNode::semanticAnalysis(SymbolTable* symboltable) const {
	ExpressionValue value = rhs->semanticAnalysis(symboltable);
	symboltable->values[name] = value;
	// need to store value in symbol table at lhs name
}