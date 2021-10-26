
#include <iostream>
#include "node.h"

int main() {

	AssignNode* assignNode = new AssignNode(new IdentifierNode("x"), new BinaryOpNode(new NumberNode(2), BinaryOperator::PLUS, new NumberNode(132)));


	std::cout << assignNode->toString() << std::endl;
	delete assignNode;
	return 0;
}