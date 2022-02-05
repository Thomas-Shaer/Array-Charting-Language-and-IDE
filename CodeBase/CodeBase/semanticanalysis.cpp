#include "node.h"
#include "symboltable.h"
#include "languageexception.h"
#include "methodsymbol.h"
#include "methodbucket.h"
#include "typesymbol.h"
#include "argumentsymbol.h"

void BlockNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	for (Statement* statement : statementNodes) {
		statement->semanticAnalysis(symboltable);
	}
}

const TypeSymbol* NumberNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	return TypeInstances::GetFloatConstantInstance();
}

const TypeSymbol* BooleanNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	return TypeInstances::GetBooleanInstance();
}


const TypeSymbol* StringNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	return TypeInstances::GetStringConstantInstance();
}



const TypeSymbol* IdentifierNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	// need to return item in symbol table
	if (symboltable->isVariableDeclared(name)) {
		varSymbol = symboltable->getVariable(name);
		return varSymbol->type;
	}
	throw LanguageException("No variable called " + name);
}



void ExpressionStatementNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	expressionNode->semanticAnalysis(symboltable);
}


void AssignNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	const TypeSymbol* rhsType = rhs->semanticAnalysis(symboltable);

	// x = void
	if (rhsType == TypeInstances::GetVoidInstance()) {
		throw LanguageException("Void is not a assignable type.");
	}

	// x = 2
	// store as float, not float_constant
	if (rhsType == TypeInstances::GetFloatConstantInstance()) {
		rhsType = TypeInstances::GetFloatInstance();
	}


	// x = "hello"
	// store as string, not string_constant
	if (rhsType == TypeInstances::GetStringConstantInstance()) {
		rhsType = TypeInstances::GetStringInstance();
	}


	// variable already declared therefore right side type should be same as left side type
	if (symboltable->isVariableDeclared(name)) {
		varSymbol = symboltable->getVariable(name);

		if (!varSymbol->modifiable) {
			throw LanguageException(name + " is not a modifiable variable");
		}

		if (varSymbol->type != rhsType) {
			throw LanguageException("RHS type does not match LHS");
		}
	}
	// variable not declared register new variable
	else {
		varSymbol = VarSymbol::createVarSymbol(name, rhsType);


		symboltable->declareVariable(varSymbol);
	}
	// need to store value in symbol table at lhs name
}

const TypeSymbol* MethodCallNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {

	// check to see if method exists first
	if (!symboltable->isMethodDeclared(name)) {
		throw LanguageException("No method called " + name);
	}

	this->methodsymbol = symboltable->getMethod(name)->getMethodSymbol(this, symboltable)->clone();
	return methodsymbol->semanticAnaylsis(this, symboltable);
}


const TypeSymbol* KeywordNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	return rhs->semanticAnalysis(symboltable);
}



void IfStatementNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	if (condition->semanticAnalysis(symboltable) != TypeInstances::GetBooleanInstance()) {
		throw LanguageException("If statement condition must be a boolean.");
	}
	// create new symbol table
	std::shared_ptr<SymbolTable> ifStatementSymbolTable = std::make_shared<SymbolTable>(symboltable);
	block->semanticAnalysis(ifStatementSymbolTable);
}

const TypeSymbol* TernaryNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	if (condition->semanticAnalysis(symboltable) != TypeInstances::GetBooleanInstance()) {
		throw LanguageException("Ternary condition must be a boolean.");
	}


	const TypeSymbol* lhsType = expression1->semanticAnalysis(symboltable);
	const TypeSymbol* rhstype = expression2->semanticAnalysis(symboltable);

	if (lhsType == TypeInstances::GetFloatConstantInstance()) {
		lhsType = TypeInstances::GetFloatInstance();
	}

	if (rhstype == TypeInstances::GetFloatConstantInstance()) {
		rhstype = TypeInstances::GetFloatInstance();
	}

	if (lhsType == TypeInstances::GetStringConstantInstance()) {
		lhsType = TypeInstances::GetStringInstance();
	}

	if (rhstype == TypeInstances::GetStringConstantInstance()) {
		rhstype = TypeInstances::GetStringInstance();
	}


	if (lhsType != rhstype) {
		throw LanguageException("Ternary expression, returning types must be the same - got " + lhsType->name + " and " + rhstype->name);
	}

	return lhsType;
}