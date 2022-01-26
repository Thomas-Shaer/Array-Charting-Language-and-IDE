#include "chartwindow.h"
#include "implot.h"
#include "imgui.h"
#include <math.h>
#include <limits>
#include "displayinformation.h"
#include <string>
#include "chartplot.h"
#include "screenshot.h"
#include "jsonsettings.h"

ImGui::FileBrowser ChartWindowSingleton::fbSave(ImGuiFileBrowserFlags_EnterNewFilename);
bool ChartWindowSingleton::exportWithBorder = false;
bool ChartWindowSingleton::exportWithOutBorder = false;


void ChartWindowSingleton::initFileBrowserSave() {
    fbSave.SetPwd(std::filesystem::path(Settings::settingsFile["lastScreenshotExportDirectory"].get<std::string>()));


    // (optional) set browser properties
    fbSave.SetTitle("screenshot");
    fbSave.SetTypeFilters({ ".png" });
}



static std::string TITLE = "Chart Screen";

void UpdateChart() {
    unsigned int maxSize = 0;
    for (auto line : DisplayInformation::CHART_LINE_DATA) {
        maxSize = line->data.size() > maxSize ? line->data.size() : maxSize;
    }
    TITLE = "Chart Screen: displaying " + std::to_string(DisplayInformation::CHART_LINE_DATA.size() + DisplayInformation::CHART_MARK_DATA.size()) + " plot(s) of size " + std::to_string(maxSize);
    ImPlot::SetNextAxisToFit(ImAxis_X1);
    ImPlot::SetNextAxisToFit(ImAxis_Y1);
}


void ShowChartWindow(bool* p_open) {

    ImGui::SetNextWindowSize(ImVec2(400, 500), ImGuiCond_FirstUseEver | ImGuiWindowFlags_AlwaysAutoResize);
    //ImGui::SetNextWindowPos(ImVec2(0, 0)), ImGuiCond_FirstUseEver;



    ImGui::Begin(TITLE.c_str(), p_open, ImGuiWindowFlags_MenuBar);



    static bool antiAliasing = Settings::settingsFile["chartAntiAliasing"].get<bool>();
    static bool exportChart = false;
    bool exportAs = false;
    static std::string exportName = "";

    if (ImGui::BeginMenuBar()) {
        

        if (ImGui::BeginMenu("File")) {
            if (ImGui::BeginMenu("Export as...")) {
                if (ImGui::MenuItem("Border", NULL, &exportAs)) {
                    ChartWindowSingleton::exportWithBorder = true;
                }
                if (ImGui::MenuItem("No Border", NULL, &exportAs)) {
                    ChartWindowSingleton::exportWithOutBorder = true;
                }



                ImGui::EndMenu();
            }
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Chart")) {
            if (ImGui::MenuItem("Clear")) {
                DisplayInformation::CHART_LINE_DATA.clear();
                DisplayInformation::CHART_MARK_DATA.clear();
                UpdateChart();
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
        ChartWindowSingleton::fbSave.Open();
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
        for (auto line : DisplayInformation::CHART_LINE_DATA) {
            ImPlot::PushStyleColor(ImPlotCol_Line, ImPlot::GetColormapColor(i));
            ImPlot::PlotLine(line->plotName.c_str(), line->data.data(), line->data.size());
            ImPlot::PopStyleColor();
            i++;
        }
        for (auto line : DisplayInformation::CHART_MARK_DATA) {
            ImPlot::PushStyleColor(ImPlotCol_Line, ImPlot::GetColormapColor(i));
            ImPlot::PlotScatter(line->plotName.c_str(), line->data.data(), line->data.size());
            ImPlot::PopStyleColor();
            i++;
        }


        ImPlot::EndPlot();
        ImPlot::PopColormap();

    }
    ImPlot::PopStyleColor(1);
    if (exportChart) {
        if (ChartWindowSingleton::exportWithBorder) {
            ImageBuf::capture(chartAxisX, chartAxisY, chartAxisWidth, chartAxisHeight, exportName);
            ChartWindowSingleton::exportWithBorder = false;

        }
        else if (ChartWindowSingleton::exportWithOutBorder) {
            ImageBuf::capture(chartX, chartY, chartWidth, chartHeight, exportName);
            ChartWindowSingleton::exportWithOutBorder = false;
        }

        exportChart = false;
    }


    if (ChartWindowSingleton::fbSave.IsOpened()) {
        Settings::settingsFile["lastScreenshotExportDirectory"] = ChartWindowSingleton::fbSave.GetPwd().root_path().generic_string() + (ChartWindowSingleton::fbSave.GetPwd().relative_path()).generic_string();
    }

    if (ChartWindowSingleton::fbSave.HasSelected())
    {
        std::string fullPath = ChartWindowSingleton::fbSave.GetSelected().string() + ".png";
        exportName = fullPath;
        exportChart = true;
        ChartWindowSingleton::fbSave.ClearSelected();

    }


    ImGui::End();
    ChartWindowSingleton::fbSave.Display();

}

