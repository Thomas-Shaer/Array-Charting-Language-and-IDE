#include "texteditorwindow.h"
#include "imgui.h"
#include <iostream>
#include "interpretercontext.h"
#include "textoutputwindow.h"
#include "displayinformation.h"
#include "node.h"
#include "symboltable.h"

void ShowEditorWindow(TextEditor& texteditor) {
    ImGui::Begin("Code Input", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(10, 600), ImGuiCond_FirstUseEver);

    bool runCode = false;



    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            //ImGui::MenuItem("Execute Script", NULL, &runCode);
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
        for (auto string : context.output) {
            //std::cout << "what" << std::endl;
            DisplayInformation::CODE_OUTPUT += string + "\n";
            //std::cout << string << std::endl;
        }
        if (context.ast) {
            DisplayInformation::CODE_OUTPUT_RECONSTRUCTION = context.ast->toString();
        }
        if (context.symboltable) {
            DisplayInformation::CODE_OUTPUT_VARIABLES = context.symboltable->variablesToString();
        }
        //std::cout << "what" << std::endl;
    }

    texteditor.Render("TextEditor");

    ImGui::End();
}
