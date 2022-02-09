#pragma once

#include <exception>
#include <iostream>
#include "sourcelocation.h"

class Node;



class LanguageException : std::exception {

public:


	LanguageException(std::string _message, Node* _node);
	LanguageException(std::string _message, yy::SourceLocation sourceLoc) : message(_message), sourceLocation(sourceLoc){}

	std::string toString(const std::string& sourceCode);
	std::string message;
	yy::SourceLocation sourceLocation;
private:

};