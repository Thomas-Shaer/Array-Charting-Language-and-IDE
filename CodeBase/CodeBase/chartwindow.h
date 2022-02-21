#pragma once
#include "imfilebrowser.h"
#include <map>
#include "window.h"

#define DEFAULT_CHART_WINDOW_ID "main"

class ChartPlot;


class ChartWindow : public Window {

public:

	/*
	supplementary lookup map saving string ids to chart window
	(chart windows require additional management as they
	should all be updated whenever code is executed)
	*/
	static std::map<std::string, ChartWindow*> allChartWindows;


	/*
	Given a string id, will create or return a pointer to a chart window.
	*/
	static ChartWindow* getOrCreateChartWindow(const std::string& id);


	/*
	Give the string id of the window
	*/
	ChartWindow(const std::string& id);

	/*
	* Window that displays chart
	*/
	void ShowWindow();

	/*
	Updates the chart viewpoint.
	*/
	void UpdateChart();


	// chart data for lines
	std::vector<std::shared_ptr<ChartPlot>> CHART_LINE_DATA;
	// chart data for plots
	std::vector<std::shared_ptr<ChartPlot>> CHART_MARK_DATA;


	// clears the plots from the chart
	void clearChart();



	/*
	Clears all charts
	*/
	static void clearAllCharts();
	
	/*
	Updates all charts by redrawing its plot data
	*/
	static void updateAllCharts();


private:
	std::string TITLE = "Chart Screen(0)###ChartWindow";

	// flag to indicate whether to display the chart title
	bool showChartTitle = true;

	// flag to indicate whether chart should be updated
	bool updateChart = false;

	// flag to indicate whether chart should be exported
	bool screenshotChart = false;
	// if to be exported, export with the chart border
	bool screenshotWithBorder = false;
	// if to be exported, export without the chart border
	bool screenshotNoBorder = false;


	ImGui::FileBrowser fbSave{ ImGuiFileBrowserFlags_EnterNewFilename };


	// id of this chart window
	std::string chart_id;
};
