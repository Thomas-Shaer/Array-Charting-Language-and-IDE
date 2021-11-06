#include "node.h"
#include "symboltable.h"
#include "languageexception.h"
#include "binaryoperator.h"
#include "unaryoperator.h"
#include "methodsymbol.h"

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
	if (symboltable->isVariableDeclared(name)) {
		return symboltable->getVariable(name)->type;
	}
	throw LanguageException("No variable called " + name);
}

DataType BinaryOpNode::semanticAnalysis(SymbolTable* symboltable) const {
	DataType leftV = left->semanticAnalysis(symboltable);
	DataType rightV = right->semanticAnalysis(symboltable);


	return op->semanticAnaylsis(leftV, rightV);
}


DataType UnaryOpNode::semanticAnalysis(SymbolTable* symboltable) const {
	DataType leftV = expression->semanticAnalysis(symboltable);

	return op->semanticAnaylsis(leftV);
}


void AssignNode::semanticAnalysis(SymbolTable* symboltable) const {
	DataType rhsType = rhs->semanticAnalysis(symboltable);

	// variable already declared therefore right side type should be same as left side type
	if (symboltable->isVariableDeclared(name)) {
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

DataType MethodCallNode::semanticAnalysis(SymbolTable* symboltable) const {

	// check to see if method exists first
	if (!symboltable->isMethodDeclared(name)) {
		throw LanguageException("No method called " + name);
	}

	std::vector<DataType> argTypes;
	for (Expression* expr : arguments) {
		argTypes.push_back(expr->semanticAnalysis(symboltable));
	}

	return symboltable->getMethod(name)->semanticAnaylsis(argTypes);
}