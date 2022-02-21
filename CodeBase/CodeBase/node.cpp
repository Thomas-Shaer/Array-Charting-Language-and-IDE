
#include "node.h"
#include <map>
#include <sstream>


Node::Node(yy::SourceLocation csourceLocation) : sourceLocation(csourceLocation) {
}


std::string ExpressionStatementNode::toString() const {
	return expressionNode->toString();
}



ExpressionStatementNode::~ExpressionStatementNode() {
	delete expressionNode;
}


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


std::string StringNode::toString() const {
	return "\"" + (value) + "\"";
}


StringNode::~StringNode() {}


std::string BooleanNode::toString() const {
	return value ? "true" : "false";
}


KeywordNode::~KeywordNode() {
	delete rhs;
}


std::string KeywordNode::toString() const {
	return name + " = " + rhs->toString();
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
	
	//std::cout << name << " amount: " << arguments.size() << std::endl;
	for (const Expression* argument : arguments) {
		delete argument;
	}
	delete methodsymbol;
}



std::string IfStatementNode::toString() const {
	std::string output =  "if (" + condition->toString() + ") { \n" + block->toString() + "}";
	return output;
}

IfStatementNode::~IfStatementNode() {
	delete condition;
	delete block;
}


std::string TernaryNode::toString() const {
	std::string output = condition->toString() + " ? " + expression1->toString() + " : " + expression2->toString();
	return output;
}

TernaryNode::~TernaryNode() {
	delete condition;
	delete expression1;
	delete expression2;
}