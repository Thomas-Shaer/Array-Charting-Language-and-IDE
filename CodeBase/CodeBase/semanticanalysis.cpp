#include "node.h"
#include "symboltable.h"
#include "languageexception.h"
#include "methodsymbol.h"
#include "methodbucket.h"
#include "typesymbol.h"
#include "argumentsymbol.h"

void BlockNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	for (Statement* statement : statementNodes) {
		statement->semanticAnalysis(symboltable, output);
	}
}

const TypeSymbol* NumberNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	return TypeInstances::GetFloatConstantInstance();
}

const TypeSymbol* BooleanNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	return TypeInstances::GetBooleanInstance();
}



const TypeSymbol* IdentifierNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	// need to return item in symbol table
	if (symboltable->isVariableDeclared(name)) {
		varSymbol = symboltable->getVariable(name);
		return varSymbol->type;
	}
	throw LanguageException("No variable called " + name);
}



void ExpressionStatementNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	expressionNode->semanticAnalysis(symboltable, output);
}


void AssignNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	const TypeSymbol* rhsType = rhs->semanticAnalysis(symboltable, output);

	// x = void
	if (rhsType == TypeInstances::GetVoidInstance()) {
		throw LanguageException("Void is not a assignable type.");
	}

	// x = 2
	// store as float, not float_constant
	if (rhsType == TypeInstances::GetFloatConstantInstance()) {
		rhsType = TypeInstances::GetFloatInstance();
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

const TypeSymbol* MethodCallNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {

	// check to see if method exists first
	if (!symboltable->isMethodDeclared(name)) {
		throw LanguageException("No method called " + name);
	}

	std::vector<std::shared_ptr<ArgumentSymbol>> argTypes;
	for (Expression* expr : arguments) {
		argTypes.push_back(std::make_shared<ArgumentSymbol>(expr->semanticAnalysis(symboltable, output), expr));
	}

	this->methodsymbol = symboltable->getMethod(name)->getMethodSymbol(argTypes)->clone();
	return methodsymbol->semanticAnaylsis(argTypes, output);
}

void IfStatementNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	if (condition->semanticAnalysis(symboltable, output) != TypeInstances::GetBooleanInstance()) {
		throw LanguageException("If statement condition must be a boolean.");
	}
	// create new symbol table
	std::shared_ptr<SymbolTable> ifStatementSymbolTable = std::make_shared<SymbolTable>(symboltable);
	block->semanticAnalysis(ifStatementSymbolTable, output);
}

const TypeSymbol* TernaryNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable, InterpreterOutput& output) {
	if (condition->semanticAnalysis(symboltable, output) != TypeInstances::GetBooleanInstance()) {
		throw LanguageException("Ternary condition must be a boolean.");
	}
	const TypeSymbol* lhsType = expression1->semanticAnalysis(symboltable, output);
	const TypeSymbol* rhstype = expression2->semanticAnalysis(symboltable, output);

	if (lhsType == TypeInstances::GetFloatConstantInstance()) {
		lhsType = TypeInstances::GetFloatInstance();
	}

	if (rhstype == TypeInstances::GetFloatConstantInstance()) {
		rhstype = TypeInstances::GetFloatInstance();
	}

	if (lhsType != rhstype) {
		throw LanguageException("Ternary expression, returning types must be the same - got " + lhsType->name + " and " + rhstype->name);
	}

	return lhsType;
}