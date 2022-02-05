#pragma once
#include "imfilebrowser.h"
#include <map>
#include "window.h"

#define DEFAULT_CHART_WINDOW_ID "main"

class ChartPlot;


class ChartWindow : public Window {

public:

	static ChartWindow* getOrCreateChartWindow(const std::string& id);


	ChartWindow(const std::string& id);
	//ChartWindow() : chart_id(-99), Window("Chart Window (temp)", true) {}

	/*
	* Window that displays chart
	*/
	void ShowWindow();

	/*
	Updates the chart viewpoint.
	*/
	void UpdateChart();


	ImGui::FileBrowser fbSave{ ImGuiFileBrowserFlags_EnterNewFilename };

	bool exportWithBorder = false;
	bool exportWithOutBorder = false;


	std::string chart_id;

	std::vector<std::shared_ptr<ChartPlot>> CHART_LINE_DATA;
	std::vector<std::shared_ptr<ChartPlot>> CHART_MARK_DATA;


	void reset();


	static void clearAllWindows();
	static void updateAllCharts();
	static std::map<std::string, ChartWindow*> allChartWindows;


private:
	std::string TITLE = "Chart Screen(0)###ChartWindow";
	bool exportChart = false;
	bool showName = true;
	bool updateChart = false;

};
