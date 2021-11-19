#include "testgui.h"
#include "implot.h"
#include "imgui.h"
#include <math.h>
#include <limits>

#define AMOUNT 100000

void ShowDemo_LinePlots() {
    static double xs2[AMOUNT], ys2[AMOUNT];
    for (int i = 0; i < AMOUNT; ++i) {

        xs2[i] = i;
        //ys2[i] = xs2[i] * xs2[i];
        if (i % 3 == 0) {
            //ys2[i] = std::numeric_limits<double>::quiet_NaN();
            ys2[i] = i + 1;
        }
    }
    ImGui::BulletText("Test Chart Below");
    if (ImPlot::BeginPlot("Line Plot")) {
        ImPlot::SetupAxes("x", "f(x)");
        //ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
        ImPlot::PlotLine("x^2", xs2, ys2, AMOUNT);
        ImPlot::EndPlot();
    }
}

void ShowTestWindow(bool* p_open) {


    ImGui::SetNextWindowPos(ImVec2(100, 50), ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2(600, 750), ImGuiCond_FirstUseEver);
    ImGui::Begin("ImPlot Demo", p_open, ImGuiWindowFlags_MenuBar);

    //-------------------------------------------------------------------------
    ImGui::Text("ImPlot says hello. (%s)", IMPLOT_VERSION);
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

