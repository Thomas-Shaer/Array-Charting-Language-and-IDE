#include "languageexception.h"
#include "node.h"

LanguageException::LanguageException(std::string _message, Node* _node) : message(_message), sourceLocation(_node->sourceLocation) {
}


std::string LanguageException::toString(const std::string& sourceCode) {
	return message + "\n" + sourceLocation.getNodeSourceCode(sourceCode);
}
