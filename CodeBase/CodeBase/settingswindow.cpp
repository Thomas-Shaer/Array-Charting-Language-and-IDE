#include "settingswindow.h"
#include "imgui.h"
#include "jsonsettings.h"
#include <iostream>

void SettingsWindow::ShowWindow() {
    ImGui::Begin("Settings Window", &show, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(500, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(100, 600), ImGuiCond_FirstUseEver);

    /*
    Text zoom slider
    */
    static float textScale = Settings::settingsFile["zoom"].get<float>();
    if (ImGui::SliderFloat("Text scale", &textScale, 1, 3)) {
        Settings::settingsFile["zoom"] = textScale;
    }
    ImGui::GetIO().FontGlobalScale = textScale;

    ImGui::End();


}