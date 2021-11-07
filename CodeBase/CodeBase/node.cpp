
#include "node.h"
#include <map>



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



std::string NumberNode::toString() const {
	return std::to_string(number);
}


NumberNode::~NumberNode() {}


std::string BooleanNode::toString() const {
	return value ? "true" : "false";
}

BooleanNode::~BooleanNode() {}


std::string IdentifierNode::toString() const {
	return name;
}

IdentifierNode::~IdentifierNode() {}





std::string AssignNode::toString() const {
	return name + " = " + rhs->toString();
}

AssignNode::~AssignNode() {
	delete rhs;
}



std::string MethodCallNode::toString() const {
	std::string output = name + "(";
	for (const Expression* argument : arguments) {
		output += argument->toString() + ", ";
	}
	output += ")";
	return output;
}

MethodCallNode::~MethodCallNode() {
	for (const Expression* argument : arguments) {
		delete argument;
	}
}
