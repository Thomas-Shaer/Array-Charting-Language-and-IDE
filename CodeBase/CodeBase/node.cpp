
#include "node.h"


std::string BlockNode::toString() const {
	std::string block;

	for (Statement* statement : statementNodes) {
		block += statement->toString() + "\n";
	}


	return block;
}

BlockNode::~BlockNode() {
	for (Statement* statement : statementNodes) {
		delete statement;
	}
}

void BlockNode::evaluate(SymbolTable* symboltable) const {
	for (Statement* statement : statementNodes) {
		statement->evaluate(symboltable);
	}
}



std::string NumberNode::toString() const {
	return std::to_string(number);
}

NumberNode::~NumberNode() {}

ExpressionValue NumberNode::evaluate(SymbolTable* symboltable) const {
	return (ExpressionValue)number;
}



std::string IdentifierNode::toString() const {
	return name;
}

IdentifierNode::~IdentifierNode() {}

ExpressionValue IdentifierNode::evaluate(SymbolTable* symboltable) const {
	// need to return item in symbol table


	//return (ExpressionValue)number;
	return symboltable->values[name];
}



std::string BinaryOpNode::toString() const {
	return left->toString() + " + " + right->toString();
}

BinaryOpNode::~BinaryOpNode() {
	delete left;
	delete right;
}

ExpressionValue BinaryOpNode::evaluate(SymbolTable* symboltable) const {
	ExpressionValue leftV = left->evaluate(symboltable);
	ExpressionValue rightV = right->evaluate(symboltable);
	if (leftV.type() == typeid(float) && rightV.type() == typeid(float)) {
		return boost::get<float>(leftV) + boost::get<float>(rightV);
	}
	else {
		std::cout << "ERROR NOT FLOATS!" << std::endl;
	}
	return (float)0;
}



std::string AssignNode::toString() const {
	return name + " = " + rhs->toString();
}

AssignNode::~AssignNode() {
	delete rhs;
}

void AssignNode::evaluate(SymbolTable* symboltable) const {
	ExpressionValue value = rhs->evaluate(symboltable);
	symboltable->values[name] = value;
	// need to store value in symbol table at lhs name
}