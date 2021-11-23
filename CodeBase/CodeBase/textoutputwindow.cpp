#include "textoutputwindow.h"
#include "imgui.h"
#include "displayinformation.h"

void ShowTextOutputWindow() {
    ImGui::Begin("Program Output", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(500, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(100, 600), ImGuiCond_FirstUseEver);



    if (ImGui::BeginTabBar("Output Menu")) {
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
    }


    ImGui::End();
}