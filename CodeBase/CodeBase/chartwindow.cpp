#include "chartwindow.h"
#include "implot.h"
#include <math.h>
#include <limits>
#include "interpretercontext.h"

#include <string>
#include "chartplot.h"
#include "screenshot.h"
#include "jsonsettings.h"

std::map<std::string, ChartWindow*> ChartWindow::allChartWindows;



ChartWindow::ChartWindow(const std::string& id) : chart_id(id), Window("Chart Window " + (id))  {

    TITLE = "Chart Screen (" + (chart_id) + ")###ChartWindow" + (chart_id);
    fbSave.SetPwd(std::filesystem::path(Settings::settingsFile["lastScreenshotExportDirectory"].get<std::string>()));


    // (optional) set browser properties
    fbSave.SetTitle("screenshot");
    fbSave.SetTypeFilters({ ".png" });
}




void ChartWindow::clearAllWindows() {
    //std::cout << ChartWindow::allChartWindows.size() << std::endl;
    for (auto& window : ChartWindow::allChartWindows) {
        window.second->reset();
    }
}


void ChartWindow::updateAllCharts() {
    for (auto& window : ChartWindow::allChartWindows) {
        std::cout << "updating : " << window.second->chart_id << std::endl;
        window.second->show = true;
        window.second->UpdateChart();
    }
}

void ChartWindow::reset() {
    CHART_LINE_DATA.clear();
    CHART_MARK_DATA.clear();
}


ChartWindow* ChartWindow::getOrCreateChartWindow(const std::string& id) {
    auto find = allChartWindows.find(id);
    if (find == allChartWindows.end()) {
        allChartWindows[id] = new ChartWindow(id);
    }
    return allChartWindows[id];
}



void ChartWindow::UpdateChart() {
    TITLE = "Chart Screen (" + (chart_id) + "): displaying " + std::to_string(CHART_LINE_DATA.size() + CHART_MARK_DATA.size()) + " plot(s) of size " + std::to_string(InterpreterContext::ticks) + "###ChartWindow" + (chart_id);
    updateChart = true;
}


void ChartWindow::ShowWindow() {

    ImGui::SetNextWindowSize(ImVec2(400, 500), ImGuiCond_FirstUseEver | ImGuiWindowFlags_AlwaysAutoResize);

    if (chart_id == DEFAULT_CHART_WINDOW_ID) {
        ImGui::Begin(TITLE.c_str(), &show, ImGuiWindowFlags_MenuBar);

    }
    else {
        ImGui::Begin(TITLE.c_str(), &show, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoSavedSettings);
    }
    /*
    If you are not the main chart window, and you are closed:
    Remove this window from the chartWindows tracker.
    Remove this window from the global window tracker.
    Delete this (as we have been turned into a pointer)
    */
    if (!show) {
        if (chart_id != DEFAULT_CHART_WINDOW_ID) {
            ChartWindow::allChartWindows.erase(chart_id);
            deleteWindow();
        }
    }



    static bool antiAliasing = Settings::settingsFile["chartAntiAliasing"].get<bool>();
    bool exportAs = false;
    static std::string exportName = "";

    if (ImGui::BeginMenuBar()) {
        

        if (ImGui::BeginMenu("File")) {
            if (ImGui::BeginMenu("Export as...")) {
                if (ImGui::MenuItem("Border", NULL, &exportAs)) {

                    exportWithBorder = true;
                }
                if (ImGui::MenuItem("No Border", NULL, &exportAs)) {

                    exportWithOutBorder = true;
                }



                ImGui::EndMenu();
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Chart")) {
            if (ImGui::MenuItem("Clear")) {
                reset();
                UpdateChart();
            }
            if (ImGui::MenuItem("Fit to data")) {
                UpdateChart();
            }
            if (ImGui::MenuItem("Show Key", NULL, showName)) {
                showName = !showName;
                //Settings::settingsFile["chartAntiAliasing"] = antiAliasing;
            }
            
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Settings")) {
            if (ImGui::MenuItem("Anti-Aliasing", NULL, antiAliasing)) {
                antiAliasing = !antiAliasing;
                Settings::settingsFile["chartAntiAliasing"] = antiAliasing;
            }
            ImGui::EndMenu();
        }

        
        ImGui::EndMenuBar();
    }

    ImPlot::GetStyle().AntiAliasedLines = antiAliasing;


    if (exportAs) {
        ChartWindow::fbSave.Open();
    }

    int chartX = 0, chartY = 0, chartWidth = 0, chartHeight = 0;
    int chartAxisX = 0, chartAxisY = 0, chartAxisWidth = 0, chartAxisHeight = 0;


    // display warning about 16-bit indices
    static bool showWarning = sizeof(ImDrawIdx) * 8 == 16 && (ImGui::GetIO().BackendFlags & ImGuiBackendFlags_RendererHasVtxOffset) == false;
    if (showWarning) {
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 1, 0, 1));
        ImGui::TextWrapped("WARNING: ImDrawIdx is 16-bit and ImGuiBackendFlags_RendererHasVtxOffset is false. Expect visual glitches and artifacts! See README for more information.");
        ImGui::PopStyleColor();
    }
    ImGui::Spacing();



    if (updateChart) {
        ImPlot::SetNextAxisToFit(ImAxis_X1);
        ImPlot::SetNextAxisToFit(ImAxis_Y1);
        updateChart = false;
    }

    //ImPlot::StyleColorsAuto();
    ImPlot::PushStyleColor(ImPlotCol_FrameBg, { 0.152,0.286,0.447,1 });
    if (ImPlot::BeginPlot(chart_id.c_str(), ImVec2(-1, -1))) {
        ImPlot::PushColormap(ImPlotColormap_Paired);


        chartX = ImPlot::GetPlotPos().x;
        chartY = ImPlot::GetPlotPos().y;
        chartWidth = ImPlot::GetPlotSize().x;
        chartHeight = ImPlot::GetPlotSize().y;

       
        chartAxisX = ImGui::GetItemRectMin().x;
        chartAxisY = ImGui::GetItemRectMin().y;
        chartAxisWidth = ImGui::GetItemRectSize().x;
        chartAxisHeight = ImGui::GetItemRectSize().y;


        int i = 0;
        for (auto line : CHART_LINE_DATA) {
            std::string name = showName ? line->plotName : "";
            ImPlot::PushStyleColor(ImPlotCol_Line, ImPlot::GetColormapColor(i));
            ImPlot::PlotLine(name.c_str(), line->data.data(), line->data.size());
            ImPlot::PopStyleColor();
            i++;
        }
        for (auto line : CHART_MARK_DATA) {
            std::string name = showName ? line->plotName : "";
            ImPlot::PushStyleColor(ImPlotCol_Line, ImPlot::GetColormapColor(i));
            ImPlot::PlotScatter(name.c_str(), line->data.data(), line->data.size());
            ImPlot::PopStyleColor();
            i++;
        }


        ImPlot::EndPlot();
        ImPlot::PopColormap();

    }
    ImPlot::PopStyleColor(1);




    if (exportChart) {

        if (ChartWindow::exportWithBorder) {
            ImageBuf::capture(chartAxisX, chartAxisY, chartAxisWidth, chartAxisHeight, exportName);
            ChartWindow::exportWithBorder = false;

        }
        else if (ChartWindow::exportWithOutBorder) {
            ImageBuf::capture(chartX, chartY, chartWidth, chartHeight, exportName);
            ChartWindow::exportWithOutBorder = false;
        }

        exportChart = false;
    }

    if (ChartWindow::fbSave.IsOpened()) {
        Settings::settingsFile["lastScreenshotExportDirectory"] = ChartWindow::fbSave.GetPwd().root_path().generic_string() + (ChartWindow::fbSave.GetPwd().relative_path()).generic_string();
    }

    if (ChartWindow::fbSave.HasSelected())
    {
        std::string fullPath = ChartWindow::fbSave.GetSelected().string() + ".png";
        exportName = fullPath;
        exportChart = true;
        ChartWindow::fbSave.ClearSelected();


    }
    
    

    fbSave.Display();

    ImGui::End();

}

