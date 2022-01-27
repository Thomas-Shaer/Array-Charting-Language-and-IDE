#pragma once
#include "imfilebrowser.h"
#include <map>

class ChartPlot;


class ChartWindow {

public:

	static ChartWindow* getOrCreateChartWindow(unsigned int id);


	ChartWindow(unsigned int id);
	ChartWindow() : chart_id(-99) {}

	/*
	* Window that displays chart
	*/
	void ShowChartWindow(bool* p_open);

	/*
	Updates the chart viewpoint.
	*/
	void UpdateChart();


	static void initFileBrowserSave();
	static ImGui::FileBrowser fbSave;

	static bool exportWithBorder;
	static bool exportWithOutBorder;
	static int exportWindowId;


	unsigned int chart_id;

	std::vector<std::shared_ptr<ChartPlot>> CHART_LINE_DATA;
	std::vector<std::shared_ptr<ChartPlot>> CHART_MARK_DATA;


	void reset();


	static void clearAllWindows();
	static void renderAllWindows();
	static void updateAllCharts();
	static std::map<int, ChartWindow> allChartWindows;


private:
	std::string TITLE = "Chart Screen";
	bool exportChart = false;
	bool showName = true;

};
