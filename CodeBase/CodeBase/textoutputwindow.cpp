#include "textoutputwindow.h"
#include "imgui.h"
#include "displayinformation.h"
#include "symboltable.h"


static ImGuiTabItemFlags_ outputTabFlags = ImGuiTabItemFlags_None;
static ImGuiTabItemFlags_ codeReconstructionTabFlags = ImGuiTabItemFlags_None;
static ImGuiTabItemFlags_ variableTabFlags = ImGuiTabItemFlags_None;

void SnapToOutputTab() {
    outputTabFlags = ImGuiTabItemFlags_SetSelected;
}

void UpdateVariablesTab() {
    variableTabFlags = ImGuiTabItemFlags_SetSelected;
    DisplayInformation::CODE_OUTPUT_VARIABLES = SymbolTable::GLOBAL_SYMBOL_TABLE->variablesToString(true);
}

void ShowTextOutputWindow() {
    ImGui::Begin("Program Output", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(500, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(100, 600), ImGuiCond_FirstUseEver);




    if (ImGui::BeginTabBar("Output Menu")) {
        bool open = true; // placeholder

        if (ImGui::BeginTabItem("Output", &open, outputTabFlags)) {
            ImGui::Text(DisplayInformation::CODE_OUTPUT.c_str());
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Code Reconstruction", &open, codeReconstructionTabFlags)) {
            ImGui::Text(DisplayInformation::CODE_OUTPUT_RECONSTRUCTION.c_str());
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Variables", &open, variableTabFlags)) {
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