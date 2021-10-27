
#include "node.h"



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
	return lhs->toString() + " = " + rhs->toString();
}

AssignNode::~AssignNode() {
	delete lhs;
	delete rhs;
}

ExpressionValue AssignNode::evaluate(SymbolTable* symboltable) const {
	ExpressionValue value = rhs->evaluate(symboltable);
	symboltable->values[lhs->name] = value;
	// need to store value in symbol table at lhs name
	return value;
}