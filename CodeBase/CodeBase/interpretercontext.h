#pragma once
#include <iostream>


class InterpreterContext {

public:

	void execute(const std::string& code);
	void execute(std::ifstream& myfile);

private:


};