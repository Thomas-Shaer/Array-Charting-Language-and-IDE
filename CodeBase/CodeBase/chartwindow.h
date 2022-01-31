#pragma once
#include "imfilebrowser.h"
#include <map>
#include "window.h"

class ChartPlot;


class ChartWindow : public Window {

public:

	static ChartWindow* getOrCreateChartWindow(unsigned int id);


	ChartWindow(unsigned int id);
	//ChartWindow() : chart_id(-99), Window("Chart Window (temp)", true) {}

	/*
	* Window that displays chart
	*/
	void ShowWindow();

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
	static void updateAllCharts();
	static std::map<int, ChartWindow*> allChartWindows;


private:
	std::string TITLE = "Chart Screen(0)###ChartWindow";
	bool exportChart = false;
	bool showName = true;

};
