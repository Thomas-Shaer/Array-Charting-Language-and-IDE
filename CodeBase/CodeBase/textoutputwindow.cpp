#include "textoutputwindow.h"
#include "imgui.h"
#include "displayinformation.h"
#include "symboltable.h"


static ImGuiTabItemFlags_ outputTabFlags = ImGuiTabItemFlags_None;
static ImGuiTabItemFlags_ codeReconstructionTabFlags = ImGuiTabItemFlags_None;
static ImGuiTabItemFlags_ variableTabFlags = ImGuiTabItemFlags_None;

void UpdateVariablesTab() {
    variableTabFlags = ImGuiTabItemFlags_SetSelected;
    DisplayInformation::CODE_OUTPUT_VARIABLES = SymbolTable::globalVariablesToString();
}

void ShowTextOutputWindow() {
    ImGui::Begin("Program Output", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(500, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(100, 600), ImGuiCond_FirstUseEver);




    if (ImGui::BeginTabBar("Output Menu")) {
        bool open = true; // placeholder

        if (ImGui::BeginTabItem("Output", &open)) {
            ImGui::Text(DisplayInformation::CODE_OUTPUT.c_str());
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Code Reconstruction", &open)) {
            ImGui::Text(DisplayInformation::CODE_OUTPUT_RECONSTRUCTION.c_str());
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Variables", &open, ImGuiTabItemFlags_SetSelected)) {
            ImGui::Text(DisplayInformation::CODE_OUTPUT_VARIABLES.c_str());
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }

    outputTabFlags = ImGuiTabItemFlags_None;
    codeReconstructionTabFlags = ImGuiTabItemFlags_None;
    variableTabFlags = ImGuiTabItemFlags_None;
    ImGui::End();
}