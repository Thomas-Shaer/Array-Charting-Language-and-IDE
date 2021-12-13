#include "texteditorwindow.h"
#include "imgui.h"
#include <iostream>
#include "interpretercontext.h"
#include "textoutputwindow.h"
#include "displayinformation.h"
#include "node.h"
#include "symboltable.h"
#include "implot.h"
#include "chartwindow.h"

void ShowEditorWindow(TextEditor& texteditor) {
    ImGui::Begin("Code Input", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(10, 600), ImGuiCond_FirstUseEver);

    static int textScale =0;
    if (ImGui::SliderInt("Amount ticks", &textScale, 0, 1000)) {
    }


    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            //ImGui::MenuItem("Execute Script", NULL, &runCode);s
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    if (ImGui::Button("Execute")) {
        DisplayInformation::CODE_OUTPUT = "";
        DisplayInformation::CODE_OUTPUT_RECONSTRUCTION = "";
        DisplayInformation::CODE_OUTPUT_VARIABLES = "";
        InterpreterContext context;
        context.execute(texteditor.GetText());


        if (!context.output.textOutput.empty()) {
            for (auto string : context.output.textOutput) {
                DisplayInformation::CODE_OUTPUT += string + "\n";
            }
            SnapToOutputTab();
        }
        
        if (context.ast) {
            DisplayInformation::CODE_OUTPUT_RECONSTRUCTION = context.ast->toString();
        }
        if (context.symboltable) {
            DisplayInformation::CODE_OUTPUT_VARIABLES = context.symboltable->variablesToString();
        }
        DisplayInformation::CHART_LINE_DATA = context.output.chartData;
        DisplayInformation::CHART_MARK_DATA = context.output.markData;
        UpdateChart();
        //std::cout << "what" << std::endl;
    }

    texteditor.Render("TextEditor");

    ImGui::End();
}
