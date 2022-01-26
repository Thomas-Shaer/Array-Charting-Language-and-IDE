#pragma once
#include "imfilebrowser.h"


/*
Contains all the GUI that requires a one time initalisation for the chart window
*/
struct ChartWindowSingleton {

	static void initFileBrowserSave();
	static ImGui::FileBrowser fbSave;

	static bool exportWithBorder;
	static bool exportWithOutBorder;
};

/*
* Window that displays chart
*/
void ShowChartWindow(bool* p_open);

/*
Updates the chart viewpoint.
*/
void UpdateChart();

