#include "chartwindow.h"
#include "implot.h"
#include "imgui.h"
#include <math.h>
#include <limits>
#include "displayinformation.h"
#include <string>
#include "chartplot.h"

void ShowDemo_LinePlots() {
    
    ImGui::BulletText("Test Chart Below");
    //ImPlot::StyleColorsAuto();

    if (ImPlot::BeginPlot("Line Plot")) {
        ImPlot::PushColormap(ImPlotColormap_Paired);


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

}

void UpdateChart() {
    unsigned int maxSize = 0;
    for (auto line : DisplayInformation::CHART_LINE_DATA) {
        maxSize = line->data.size() > maxSize ? line->data.size() : maxSize;
    }
    DisplayInformation::CHART_DESCRIPTION = "Displaying " + std::to_string(DisplayInformation::CHART_LINE_DATA.size() + DisplayInformation::CHART_MARK_DATA.size()) + " plot(s) of size " + std::to_string(maxSize);


    ImPlot::SetNextAxisToFit(ImAxis_X1);
    ImPlot::SetNextAxisToFit(ImAxis_Y1);
}


void ShowChartWindow(bool* p_open) {


    ImGui::SetNextWindowSize(ImVec2(400, 500), ImGuiCond_FirstUseEver);
    //ImGui::SetNextWindowPos(ImVec2(0, 0)), ImGuiCond_FirstUseEver;

    ImGui::Begin("Chart Screen", p_open, ImGuiWindowFlags_MenuBar);

    if (ImGui::Button("Clear Chart")) {
        DisplayInformation::CHART_LINE_DATA.clear();
        DisplayInformation::CHART_MARK_DATA.clear();
        UpdateChart();
    }

    ImGui::Text(DisplayInformation::CHART_DESCRIPTION.c_str());
    // display warning about 16-bit indices
    static bool showWarning = sizeof(ImDrawIdx) * 8 == 16 && (ImGui::GetIO().BackendFlags & ImGuiBackendFlags_RendererHasVtxOffset) == false;
    if (showWarning) {
        ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 1, 0, 1));
        ImGui::TextWrapped("WARNING: ImDrawIdx is 16-bit and ImGuiBackendFlags_RendererHasVtxOffset is false. Expect visual glitches and artifacts! See README for more information.");
        ImGui::PopStyleColor();
    }
    ImGui::Spacing();
    ShowDemo_LinePlots();


    ImGui::End();
}

