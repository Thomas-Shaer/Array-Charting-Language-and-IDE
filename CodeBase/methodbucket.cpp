#include "methodbucket.h"
#include "languageexception.h"
#include "methodsymbol.h"
#include "maingui.h"
#include "node.h"


std::map<METHOD_CAT, std::vector<MethodBucket*>> MethodBucket::methodTypeMappings;


MethodBucket::MethodBucket(const METHOD_CAT _methodType) : methodCat(_methodType) {
	if (methodTypeMappings.find(_methodType) == methodTypeMappings.end()) {
		methodTypeMappings[_methodType] = std::vector<MethodBucket*>();
	}
	methodTypeMappings[_methodType].push_back(this);
}

std::string OverloadedMethodBucket::toString() const {
	std::string output = "";
	for (MethodSymbol* overload : overloads) {
		output += overload->getSignature() + "\n";
	}
	return output;
}

MethodSymbol* OverloadedMethodBucket::getMethodSymbol(MethodCallNode* methodcall, std::shared_ptr<SymbolTable> symbolTable) const {
	for (MethodSymbol* overload : overloads) {
		try {
			overload->semanticAnaylsis(methodcall, symbolTable);
		}
		catch (LanguageException langexception) {
			continue;
		}
		return overload;
	}
	
	std::string errorOverloads = "No overload matches arguments. Possible overloads are: \n";
	for (MethodSymbol* overload : overloads) {
		errorOverloads += overload->getSignature() + "\n";
	}
	
	throw LanguageException(errorOverloads, methodcall);
	return nullptr;
}


void OverloadedMethodBucket::renderAsDocumentation() const {

	for (MethodSymbol* overload : overloads) {
		ImGui::Text(std::string(overload->getSignature()).c_str());
		ImGui::Text(std::string("\n").c_str());
		ImGui::PushFont(Fonts::SMALLFONT);
		ImGui::Text(std::string(overload->description).c_str());
		ImGui::Text(std::string(overload->getDescription()).c_str());
		ImGui::Text(std::string(overload->returnType.toString()).c_str());
		ImGui::Text(std::string("\n").c_str());
		ImGui::PopFont();
	}

	
}

std::string OverloadedMethodBucket::asDocumentation() const {
	std::string text;
	for (MethodSymbol* methodsymbol : overloads) {
		text += methodsymbol->getSignature() + "\n\n" + methodsymbol->description + "\n" + methodsymbol->getDescription() + "\n" + methodsymbol->returnType.toString() + "\n";
	}
	return text;
}

std::string SingleMethodBucket::toString() const {
	return methodsymbol->getSignature();
}

MethodSymbol* SingleMethodBucket::getMethodSymbol(MethodCallNode* methodcall, std::shared_ptr<SymbolTable> symbolTable) const {
	return methodsymbol;
}

void SingleMethodBucket::renderAsDocumentation() const {

	ImGui::Text(std::string(methodsymbol->getSignature()).c_str());
	ImGui::Text(std::string("\n").c_str());
	ImGui::PushFont(Fonts::SMALLFONT);
	ImGui::Text(std::string(methodsymbol->description).c_str());
	ImGui::Text(std::string(methodsymbol->getDescription()).c_str());
	ImGui::Text(std::string(methodsymbol->returnType.toString()).c_str());
	ImGui::Text(std::string("\n").c_str());
	ImGui::PopFont();
}

std::string SingleMethodBucket::asDocumentation() const {
	return methodsymbol->getSignature() + "\n\n" + methodsymbol->description + "\n" + methodsymbol->getDescription() + "\n" + methodsymbol->returnType.toString();
}