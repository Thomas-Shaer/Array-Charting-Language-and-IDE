#include "chartwindow.h"
#include "implot.h"
#include "imgui.h"
#include <math.h>
#include <limits>

#include <string>
#include "chartplot.h"
#include "screenshot.h"
#include "jsonsettings.h"

ImGui::FileBrowser ChartWindow::fbSave(ImGuiFileBrowserFlags_EnterNewFilename);
bool ChartWindow::exportWithBorder = false;
bool ChartWindow::exportWithOutBorder = false;
std::map<int, ChartWindow> ChartWindow::allChartWindows;
int ChartWindow::exportWindowId = 0;



ChartWindow::ChartWindow(unsigned int id) : chart_id(id), Window("Chart Window " + std::to_string(id), false)  {

    TITLE = "Chart Screen (" + std::to_string(chart_id) + ")"; 
}




void ChartWindow::clearAllWindows() {
    //std::cout << ChartWindow::allChartWindows.size() << std::endl;
    for (auto& window : ChartWindow::allChartWindows) {
        window.second.reset();
    }
}

void ChartWindow::renderAllWindows() {
    bool temp = true;
    for (auto& window : ChartWindow::allChartWindows) {
        window.second.ShowWindow();
    }
}

void ChartWindow::updateAllCharts() {
    for (auto& window : ChartWindow::allChartWindows) {
        window.second.UpdateChart();
    }
}

void ChartWindow::reset() {
    CHART_LINE_DATA.clear();
    CHART_MARK_DATA.clear();
}


ChartWindow* ChartWindow::getOrCreateChartWindow(unsigned int id) {
    auto find = allChartWindows.find(id);
    if (find == allChartWindows.end()) {
        allChartWindows[id] = ChartWindow(id);
    }
    return &allChartWindows[id];
}



void ChartWindow::initFileBrowserSave() {
    fbSave.SetPwd(std::filesystem::path(Settings::settingsFile["lastScreenshotExportDirectory"].get<std::string>()));


    // (optional) set browser properties
    fbSave.SetTitle("screenshot");
    fbSave.SetTypeFilters({ ".png" });
}




void ChartWindow::UpdateChart() {
    unsigned int maxSize = 0;
    for (auto line : CHART_LINE_DATA) {
        maxSize = line->data.size() > maxSize ? line->data.size() : maxSize;
    }
    TITLE = "Chart Screen (" + std::to_string(chart_id) + "): displaying " + std::to_string(CHART_LINE_DATA.size() + CHART_MARK_DATA.size()) + " plot(s) of size " + std::to_string(maxSize);
    ImPlot::SetNextAxisToFit(ImAxis_X1);
    ImPlot::SetNextAxisToFit(ImAxis_Y1);
}


void ChartWindow::ShowWindow() {

    ImGui::SetNextWindowSize(ImVec2(400, 500), ImGuiCond_FirstUseEver | ImGuiWindowFlags_AlwaysAutoResize);
    //ImGui::SetNextWindowPos(ImVec2(0, 0)), ImGuiCond_FirstUseEver;



    ImGui::Begin(TITLE.c_str(), nullptr, ImGuiWindowFlags_MenuBar);



    static bool antiAliasing = Settings::settingsFile["chartAntiAliasing"].get<bool>();
    bool exportAs = false;
    static std::string exportName = "";

    if (ImGui::BeginMenuBar()) {
        

        if (ImGui::BeginMenu("File")) {
            if (ImGui::BeginMenu("Export as...")) {
                if (ImGui::MenuItem("Border", NULL, &exportAs)) {
                    ChartWindow::exportWindowId = chart_id;
                    ChartWindow::exportWithBorder = true;
                }
                if (ImGui::MenuItem("No Border", NULL, &exportAs)) {
                    ChartWindow::exportWindowId = chart_id;
                    ChartWindow::exportWithOutBorder = true;
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





    //ImPlot::StyleColorsAuto();
    ImPlot::PushStyleColor(ImPlotCol_FrameBg, { 0.152,0.286,0.447,1 });
    if (ImPlot::BeginPlot("Line Plot", ImVec2(-1, -1))) {
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



    if (ChartWindow::exportWindowId == chart_id) {

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
    }
    
    


    ImGui::End();

}

