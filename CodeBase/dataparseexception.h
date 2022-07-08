#pragma once

#include <exception>
#include <iostream>

/*
Exception class designated for all actions
related to data parsing. 
Primarily used by Input Series
*/
class DataParseException : std::exception {

public:

	DataParseException(std::string _message) : message(_message) {}

	// error message
	const std::string message;

};