#include "methodbucket.h"
#include "languageexception.h"
#include "methodsymbol.h"
#include "maingui.h"

std::string OverloadedMethodBucket::toString() const {
	std::string output = "";
	for (MethodSymbol* overload : overloads) {
		output += overload->getSignature() + "\n";
	}
	return output;
}

MethodSymbol* OverloadedMethodBucket::getMethodSymbol(std::vector<const TypeSymbol*> _argumentTypes) const {
	for (MethodSymbol* overload : overloads) {
		try {
			overload->semanticAnaylsis(_argumentTypes);
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
	
	throw LanguageException(errorOverloads);
	return nullptr;
}


void OverloadedMethodBucket::renderAsDocumentation() const {

	for (MethodSymbol* overload : overloads) {
		ImGui::PushFont(Fonts::SMALLFONT);
		ImGui::Text(std::string(overload->description).c_str());
		ImGui::Text(std::string(overload->getDescription()).c_str());
		ImGui::Text(std::string(overload->returnType.toString()).c_str());
		ImGui::Text(std::string("\n").c_str());
		ImGui::PopFont();
		ImGui::Text(std::string(overload->getSignature()).c_str());
		ImGui::Text(std::string("\n").c_str());


	}

	
}

std::string SingleMethodBucket::toString() const {
	return methodsymbol->getSignature();
}

MethodSymbol* SingleMethodBucket::getMethodSymbol(std::vector<const TypeSymbol*> _argumentTypes) const {
	return methodsymbol;
}

void SingleMethodBucket::renderAsDocumentation() const {

	ImGui::PushFont(Fonts::SMALLFONT);
	ImGui::Text(std::string(methodsymbol->description).c_str());
	ImGui::Text(std::string(methodsymbol->getDescription()).c_str());
	ImGui::Text(std::string(methodsymbol->returnType.toString()).c_str());
	ImGui::Text(std::string("\n").c_str());
	ImGui::PopFont();
	ImGui::Text(toString().c_str());
}