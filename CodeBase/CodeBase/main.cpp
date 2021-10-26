
#include <iostream>
#include "node.h"



int main() {

	SymbolTable* symboltable = new SymbolTable();

	AssignNode* assignNode = new AssignNode(new IdentifierNode("x"), new BinaryOpNode(new NumberNode(2), BinaryOperator::PLUS, new NumberNode(132)));
	AssignNode* assignNode2 = new AssignNode(new IdentifierNode("y"), new IdentifierNode("x"));


	std::cout << assignNode->toString() << std::endl;
	std::cout << assignNode2->toString() << std::endl;
	std::cout << assignNode->evaluate(symboltable) << std::endl;
	std::cout << assignNode2->evaluate(symboltable) << std::endl;
	std::cout << symboltable->toString() << std::endl;
	delete assignNode;
	return 0;
}