#pragma once

#include <exception>
#include <iostream>
#include "sourcelocation.h"

class Node;



/*
Language Exception class.
Used for error handeling the users code.
Must be given a source code location relating to where the error happened.
*/
class LanguageException : std::exception {

public:


	LanguageException(std::string _message, Node* _node);
	LanguageException(std::string _message, yy::SourceLocation sourceLoc) : message(_message), sourceLocation(sourceLoc){}

	std::string toString(const std::string& sourceCode);

	// message of the error
	std::string message;

	// location of the error in the users code
	yy::SourceLocation sourceLocation;
private:

};