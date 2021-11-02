#pragma once

#include <exception>
#include <iostream>

class LanguageException : std::exception {

public:

	const std::string message;
	LanguageException(std::string _message) : message(_message){}

};