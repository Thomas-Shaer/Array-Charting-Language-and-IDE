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
	return TypeInstances::GetNumberConstantInstance();
}

const TypeSymbol* BooleanNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	return TypeInstances::GetBooleanInstance();
}


const TypeSymbol* StringNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	return TypeInstances::GetStringConstantInstance();
}



const TypeSymbol* IdentifierNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	if (!semanticExecuted) {
		semanticExecuted = true;
		// need to return item in symbol table
		if (symboltable->isVariableDeclared(name)) {
			varSymbol = symboltable->getVariable(name);
			cachedReturnType = varSymbol->type;
			return varSymbol->type;
		}
		throw LanguageException("No variable called " + name, this);
	}
	return cachedReturnType;

}



void ExpressionStatementNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	expressionNode->semanticAnalysis(symboltable);
}


void AssignNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	if (!semanticExecuted) {
		semanticExecuted = true;
		const TypeSymbol* rhsType = rhs->semanticAnalysis(symboltable);

		// x = void
		if (rhsType == TypeInstances::GetVoidInstance()) {
			throw LanguageException("Void is not a assignable type.", rhs);
		}

		// x = 2
		// store as float, not float_constant
		if (rhsType == TypeInstances::GetNumberConstantInstance()) {
			rhsType = TypeInstances::GetNumberInstance();
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
				throw LanguageException(name + " is not a modifiable variable", this);
			}

			if (varSymbol->type != rhsType) {
				throw LanguageException("RHS type does not match LHS", rhs);
			}
		}
		// variable not declared register new variable
		else {
			varSymbol = VarSymbol::createVarSymbol(name, rhsType);


			symboltable->declareVariable(varSymbol);
		}
	}
	// need to store value in symbol table at lhs name
}


void AssignOnceNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	AssignNode::semanticAnalysis(symboltable);
}

const TypeSymbol* MethodCallNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	if (!semanticExecuted) {
		semanticExecuted = true;
		// check to see if method exists first
		if (!symboltable->isMethodDeclared(name)) {
			throw LanguageException("No method called " + name, this);
		}

		for (Expression* expr : arguments) {
			expr->semanticAnalysis(symboltable);
		}

		methodsymbol = symboltable->getMethod(name)->getMethodSymbol(this, symboltable)->clone();
		cachedReturnType = methodsymbol->semanticAnaylsis(this, symboltable);
		return cachedReturnType;
	}
	return cachedReturnType;
}


const TypeSymbol* KeywordNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	if (!semanticExecuted) {
		semanticExecuted = true;
		cachedReturnType = rhs->semanticAnalysis(symboltable);
		return cachedReturnType;
	} 
	return cachedReturnType;
}



void IfStatementNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	if (!semanticExecuted) {
		semanticExecuted = true;
		if (condition->semanticAnalysis(symboltable) != TypeInstances::GetBooleanInstance()) {
			throw LanguageException("If statement condition must be a boolean.", condition);
		}
		// create new symbol table
		std::shared_ptr<SymbolTable> ifStatementSymbolTable = std::make_shared<SymbolTable>(symboltable);
		block->semanticAnalysis(ifStatementSymbolTable);
	}
}

const TypeSymbol* TernaryNode::semanticAnalysis(std::shared_ptr<SymbolTable> symboltable) {
	if (!semanticExecuted) {
		semanticExecuted = true;
		if (condition->semanticAnalysis(symboltable) != TypeInstances::GetBooleanInstance()) {
			throw LanguageException("Ternary condition must be a boolean.", condition);
		}


		const TypeSymbol* lhsType = expression1->semanticAnalysis(symboltable);
		const TypeSymbol* rhstype = expression2->semanticAnalysis(symboltable);

		if (lhsType == TypeInstances::GetNumberConstantInstance()) {
			lhsType = TypeInstances::GetNumberInstance();
		}

		if (rhstype == TypeInstances::GetNumberConstantInstance()) {
			rhstype = TypeInstances::GetNumberInstance();
		}

		if (lhsType == TypeInstances::GetStringConstantInstance()) {
			lhsType = TypeInstances::GetStringInstance();
		}

		if (rhstype == TypeInstances::GetStringConstantInstance()) {
			rhstype = TypeInstances::GetStringInstance();
		}


		if (lhsType != rhstype) {
			throw LanguageException("Ternary expression, returning types must be the same - got " + lhsType->name + " and " + rhstype->name, this);
		}

		cachedReturnType = lhsType;

		return cachedReturnType;
	}
	return cachedReturnType;
}