#include "textoutputwindow.h"
#include "imgui.h"
#include "displayinformation.h"
#include "symboltable.h"
#include "varsymbol.h"
#include "typesymbol.h"
#include "jsonsettings.h"
#include "exportdata.h"


ImGui::FileBrowser TextOutputWindow::fb(ImGuiFileBrowserFlags_EnterNewFilename);


void TextOutputWindow::init() {
    fb.SetPwd(std::filesystem::path(Settings::settingsFile["lastExportDirectory"].get<std::string>()));


    // (optional) set browser properties
    fb.SetTitle("title");
    fb.SetTypeFilters({ ".csv" });
}

/*
Flags to indicate whether tab should be opened or not.
*/
static ImGuiTabItemFlags_ outputTabFlags = ImGuiTabItemFlags_None;
static ImGuiTabItemFlags_ codeReconstructionTabFlags = ImGuiTabItemFlags_None;
static ImGuiTabItemFlags_ variableTabFlags = ImGuiTabItemFlags_None;

void SnapToOutputTab() {
    outputTabFlags = ImGuiTabItemFlags_SetSelected;
}

void UpdateVariablesTab() {
    variableTabFlags = ImGuiTabItemFlags_SetSelected;
    DisplayInformation::CODE_OUTPUT_VARIABLES = SymbolTable::GLOBAL_SYMBOL_TABLE->variablesToVector(true);
}

void ShowTextOutputWindow() {
    ImGui::Begin("Program Output", nullptr, ImGuiWindowFlags_MenuBar);
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

            std::vector<std::shared_ptr<VarSymbol>> outputVariables;
            for (std::shared_ptr<VarSymbol> var : DisplayInformation::CODE_OUTPUT_VARIABLES) {
                if (var->exportVariable) {
                    outputVariables.push_back(var);
                }
            }


            static bool showExportPopup = false;
            enum ExportPolicy { COLUMN_WISE, ROW_WISE};
            static std::string exportPolicySelectionText = "Column-wise";
            static ExportPolicy exportPolicySelection = COLUMN_WISE;


            if (outputVariables.empty()) {
                ImGui::BeginDisabled();
            }
            if (ImGui::Button("Export data")) {
                showExportPopup = true;
            }
            if (outputVariables.empty()) {
                ImGui::EndDisabled();
            }

            if (showExportPopup)
            {
                ImGui::OpenPopup("Export Data");
            }

            if (ImGui::BeginPopupModal("Export Data"))
            {
                
                ImGui::Text(std::string("Export " + std::to_string(outputVariables.size()) + " data items.").c_str());
                ImGui::NewLine();
                ImGui::Text("Export Policy");
                if (ImGui::BeginCombo("", exportPolicySelectionText.c_str())) {
                    bool is_selected = false;
                    if (ImGui::Selectable("Column-wise", is_selected)) {
                        exportPolicySelectionText = "Column-wise";
                        exportPolicySelection = ExportPolicy::COLUMN_WISE;
                    }
                    if (ImGui::Selectable("Row-wise", is_selected)) {
                        exportPolicySelectionText = "Row-wise";
                        exportPolicySelection = ExportPolicy::ROW_WISE;
                    }
                    ImGui::EndCombo();
                }

                ImGui::Text("NaN text (40 char)");
                ImGui::InputText("##nantext", NaNHelper::NANFILESTRING, sizeof(NaNHelper::NANFILESTRING));

                ImGui::Text("True text (40 char)");
                ImGui::InputText("##truetext", Boolean::TRUEFILESTRING, sizeof(Boolean::TRUEFILESTRING));

                ImGui::Text("False text (40 char)");
                ImGui::InputText("##falsetext", Boolean::FALSEFILESTRING, sizeof(Boolean::FALSEFILESTRING));

                
                ImGui::NewLine();
                if (ImGui::Button("Export file")) {
                    TextOutputWindow::fb.Open();
                }
                ImGui::SameLine();

                if (ImGui::Button("Cancel")) {
                    showExportPopup = false;
                    ImGui::CloseCurrentPopup();
                }


                TextOutputWindow::fb.Display();
                if (TextOutputWindow::fb.IsOpened()) {
                    Settings::settingsFile["lastExportDirectory"] = TextOutputWindow::fb.GetPwd().root_path().generic_string() + (TextOutputWindow::fb.GetPwd().relative_path()).generic_string();
                }


                if (TextOutputWindow::fb.HasSelected())
                {
                    if (exportPolicySelection == ExportPolicy::COLUMN_WISE) {
                        exportColumnWise(TextOutputWindow::fb.GetSelected().string() + ".csv", outputVariables);
                    }
                    else {
                        exportRowWise(TextOutputWindow::fb.GetSelected().string() + ".csv", outputVariables);
                    }
                    TextOutputWindow::fb.ClearSelected();
                    showExportPopup = false;
                    ImGui::CloseCurrentPopup();
                }





                ImGui::EndPopup();
            }

            
            static int selected = -1;
            static char characters[40];

            if (selected >= DisplayInformation::CODE_OUTPUT_VARIABLES.size()) {
                selected = -1;
            }

            ImGui::BeginChild("left pane", ImVec2(150, 0), true);
            for (int i = 0; i < DisplayInformation::CODE_OUTPUT_VARIABLES.size(); i++) {
                std::shared_ptr<VarSymbol> data = DisplayInformation::CODE_OUTPUT_VARIABLES.at(i);
               

                if (data->exportVariable) {
                    ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
                }

                if (ImGui::Selectable(data->name.c_str())) {
                    selected = i;
                    strncpy_s(characters, data->exportName.c_str(), sizeof(characters));
                }
                
                if (data->exportVariable) {
                    ImGui::PopStyleColor();
                }

            }


            ImGui::EndChild();
            ImGui::SameLine();
            ImGui::BeginGroup();
            if (selected != -1) {

                std::shared_ptr<VarSymbol> data = DisplayInformation::CODE_OUTPUT_VARIABLES.at(selected);

                ImGui::Text(std::string("Name: " + data->name).c_str());
                //ImGui::NewLine();
                ImGui::Text(std::string("Type: " + data->type->name).c_str());
                //ImGui::NewLine();
                ImGui::Text(std::string("Size: " + std::to_string(data->buffer.size())).c_str());
                ImGui::Text(std::string("Modifiable: " + std::string(data->modifiable ? "true" : "false")).c_str());
                ImGui::NewLine();
                ImGui::PushItemWidth(200);
                ImGui::Text("Export name (40 char)");
                ImGui::InputText("##exportname", characters, sizeof(characters));
                data->exportName = std::string(characters);
                ImGui::Checkbox("Export", &data->exportVariable);
            }
            ImGui::EndGroup();





            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    

    outputTabFlags = ImGuiTabItemFlags_None;
    codeReconstructionTabFlags = ImGuiTabItemFlags_None;
    variableTabFlags = ImGuiTabItemFlags_None;
    ImGui::End();


    

}