#pragma once

#include <exception>
#include <iostream>

class DataParseException : std::exception {

public:

	const std::string message;
	DataParseException(std::string _message) : message(_message) {}

};