#include "documentationwindow.h"
#include "imgui.h"
#include "symboltable.h"
#include "methodbucket.h"

void ShowDocumentationWindow() {
    ImGui::Begin("Documentation", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(500, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(100, 600), ImGuiCond_FirstUseEver);


    if (ImGui::BeginTabBar("ImPlotDemoTabs")) {
        if (ImGui::BeginTabItem("Methods")) {
            ImGui::BeginChild("Scrolling");
            for (auto symbol : SymbolTable::methodTable) {
                MethodBucket* bucket = symbol.second;
                if (ImGui::CollapsingHeader(symbol.first.c_str())) {
                    ImGui::Text(symbol.second->toString().c_str());
                }
            }
                
            ImGui::EndChild();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Variables")) {
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Help")) {
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }


    ImGui::End();
}