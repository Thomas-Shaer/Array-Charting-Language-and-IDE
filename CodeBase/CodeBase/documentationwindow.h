#pragma once
#include "window.h"




class DocumentationWindow : public Window {

public:

	DocumentationWindow() : Window("Documentation Window", true) {}


	/*
	* Window that shows documentation for the language.
	*/
	void ShowWindow();


private:



};