#pragma once
#include "window.h"



/*
Window containing automatically generated documentation.
*/
class DocumentationWindow : public Window {

public:

	DocumentationWindow() : Window("Documentation Window") {}

	/*
	* Window that shows documentation for the language.
	*/
	void ShowWindow();

};