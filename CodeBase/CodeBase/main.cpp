#include "maingui.h"
#include "interpretercontext.h"

int main(int, char**) {


	InterpreterContext test;
	test.execute("hey = 2");

	return start();

}