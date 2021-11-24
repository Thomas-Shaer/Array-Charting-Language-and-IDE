#include "chartwindow.h"
#include "implot.h"
#include "imgui.h"
#include <math.h>
#include <limits>
#include "displayinformation.h"


void ShowDemo_LinePlots() {

    ImGui::BulletText("Test Chart Below");
    if (ImPlot::BeginPlot("Line Plot")) {
        ImPlot::SetupAxes("x", "f(x)");
        //ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
        for (auto line : DisplayInformation::CHART_LINE_DATA) {
            ImPlot::PlotLine("data", line.data(), line.size());

        }
        for (auto line : DisplayInformation::CHART_MARK_DATA) {
            ImPlot::PlotScatter("scatter", line.data(), line.size());

        }
        //float data[3] = {1.2, std::numeric_limits<double>::quiet_NaN(), 1.2};
        //

        ImPlot::EndPlot();
    }
}

void ShowChartWindow(bool* p_open) {


    ImGui::SetNextWindowSize(ImVec2(400, 500), ImGuiCond_FirstUseEver);
    //ImGui::SetNextWindowPos(ImVec2(0, 0)), ImGuiCond_FirstUseEver;

    ImGui::Begin("Chart Screen", p_open, ImGuiWindowFlags_MenuBar);
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

