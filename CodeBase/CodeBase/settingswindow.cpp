#include "settingswindow.h"
#include "imgui.h"
#include "jsonsettings.h"
#include <iostream>

void ShowSettingsWindow() {
    ImGui::Begin("Settings Window", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(500, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(100, 600), ImGuiCond_FirstUseEver);

    static float textScale = Settings::settingsFile["zoom"].get<float>();
    if (ImGui::SliderFloat("Text scale", &textScale, 1, 3)) {
        Settings::settingsFile["zoom"] = textScale;
    }
    ImGui::GetIO().FontGlobalScale = textScale;
    /*if (ImGui::BeginTabBar("Output Menu")) {
        if (ImGui::BeginTabItem("Output")) {
            ImGui::Text(DisplayInformation::CODE_OUTPUT.c_str());
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Code Reconstruction")) {
            ImGui::Text(DisplayInformation::CODE_OUTPUT_RECONSTRUCTION.c_str());
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Variables")) {
            ImGui::Text(DisplayInformation::CODE_OUTPUT_VARIABLES.c_str());
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }*/


    ImGui::End();


}