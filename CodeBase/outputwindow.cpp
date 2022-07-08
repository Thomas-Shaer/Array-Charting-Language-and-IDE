#include "outputwindow.h"
#include "imgui.h"

#include "symboltable.h"
#include "varsymbol.h"
#include "typesymbol.h"
#include "jsonsettings.h"


#include <fstream>

ImGuiTabItemFlags_ OutputWindow::outputTabFlags = ImGuiTabItemFlags_None;
ImGuiTabItemFlags_ OutputWindow::codeReconstructionTabFlags = ImGuiTabItemFlags_None;
ImGuiTabItemFlags_ OutputWindow::variableTabFlags = ImGuiTabItemFlags_None;
bool OutputWindow::bringToFront = false;

std::vector<std::shared_ptr<VarSymbol>> OutputWindow::CODE_OUTPUT_VARIABLES = {};
std::string OutputWindow::CODE_OUTPUT = "No information to display. Please run some code!";
std::string OutputWindow::CODE_OUTPUT_RECONSTRUCTION = "No information to display. Please run some code!";


OutputWindow::OutputWindow() : Window("Output Window") {

    /*
    Initalise file browser
    */

    fb.SetPwd(std::filesystem::path(Settings::settingsFile["lastDataExportDirectory"].get<std::string>()));


    // (optional) set browser properties
    fb.SetTitle("title");
    fb.SetTypeFilters({ ".csv" });
}


void OutputWindow::exportColumnWise(const std::string& filePath, std::vector<std::shared_ptr<VarSymbol>> variables) {
    std::ofstream myFile(filePath);



    // write column names first
    for (int j = 0; j < variables.size(); ++j) {
        myFile << variables.at(j)->exportName;
        if (j != variables.size() - 1) {
            myFile << ","; // No comma at end of line
        }
    }
    myFile << "\n";


    // write data
    for (int i = 0; i < variables.at(0)->buffer.size(); ++i) {
        for (int j = 0; j < variables.size(); ++j) {
            myFile << boost::apply_visitor(ToFileString(), variables.at(j)->buffer[i]);
            if (j != variables.size() - 1) {
                myFile << ","; // No comma at end of line
            }
        }
        myFile << "\n";
    }
    myFile.close();

}



void OutputWindow::exportRowWise(const std::string& filePath, std::vector<std::shared_ptr<VarSymbol>> variables) {
    std::ofstream myFile(filePath);


    for (std::shared_ptr<VarSymbol> var : variables) {
        myFile << var->exportName << ",";
        for (int i = 0; i < var->buffer.size(); i++) {
            myFile << boost::apply_visitor(ToFileString(), var->buffer[i]);
            if (i != var->buffer.size() - 1) { 
                myFile << ","; // No comma at end of line
            }
        }
        myFile << "\n";

    }

    myFile.close();

}


void OutputWindow::SnapToOutputTab() {
    outputTabFlags = ImGuiTabItemFlags_SetSelected;
    OutputWindow::bringToFront = true;
}

void OutputWindow::UpdateVariablesTab() {
    variableTabFlags = ImGuiTabItemFlags_SetSelected;
    CODE_OUTPUT_VARIABLES = SymbolTable::GLOBAL_SYMBOL_TABLE->variablesToVector(true);
}

void OutputWindow::ShowWindow() {
    ImGui::Begin("Program Output", &show, ImGuiWindowFlags_MenuBar);
    if (bringToFront) {
        ImGui::SetWindowFocus();
        bringToFront = false;
    }
    ImGui::SetWindowSize(ImVec2(500, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(100, 600), ImGuiCond_FirstUseEver);



    if (ImGui::BeginTabBar("Output Menu")) {
        bool open = true; // placeholder

        if (ImGui::BeginTabItem("Output", &open, outputTabFlags)) {
            ImGui::Text(CODE_OUTPUT.c_str());
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Code Reconstruction", &open, codeReconstructionTabFlags)) {
            ImGui::Text(CODE_OUTPUT_RECONSTRUCTION.c_str());
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Variables", &open, variableTabFlags)) {

            std::vector<std::shared_ptr<VarSymbol>> outputVariables;
            for (std::shared_ptr<VarSymbol> var : CODE_OUTPUT_VARIABLES) {
                if (var->exportVariable) {
                    outputVariables.push_back(var);
                }
            }


            static bool showExportPopup = false;
            enum ExportPolicy { COLUMN_WISE, ROW_WISE};
            static std::string exportPolicySelectionText = "Column-wise";
            static ExportPolicy exportPolicySelection = COLUMN_WISE;
            static char defaultTrue[40];
            static char defaultFalse[40];
            static char defaultNull[40];

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
                strncpy_s(defaultTrue, Settings::settingsFile["defaultTrueExportLiteral"].get<std::string>().c_str(), sizeof(defaultTrue));
                strncpy_s(defaultFalse, Settings::settingsFile["defaultFalseExportLiteral"].get<std::string>().c_str(), sizeof(defaultFalse));
                strncpy_s(defaultNull, Settings::settingsFile["defaultNullExportLiteral"].get<std::string>().c_str(), sizeof(defaultNull));
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



                ImGui::Text("True text (40 char)");
                ImGui::InputText("##truetext", defaultTrue, sizeof(defaultTrue));

                ImGui::Text("False text (40 char)");
                ImGui::InputText("##falsetext", defaultFalse, sizeof(defaultFalse));

                ImGui::Text("Null text (40 char)");
                ImGui::InputText("##nantext", defaultNull, sizeof(defaultNull));

                /*
                Save values
                */
                Settings::settingsFile["defaultTrueExportLiteral"] = std::string(defaultTrue);
                Settings::settingsFile["defaultFalseExportLiteral"] = std::string(defaultFalse);
                Settings::settingsFile["defaultNullExportLiteral"] = std::string(defaultNull);

                
                ImGui::NewLine();
                if (ImGui::Button("Export file")) {
                    fb.Open();
                }
                ImGui::SameLine();

                if (ImGui::Button("Cancel")) {
                    showExportPopup = false;
                    ImGui::CloseCurrentPopup();
                }


                fb.Display();
                if (fb.IsOpened()) {
                    Settings::settingsFile["lastDataExportDirectory"] = fb.GetPwd().root_path().generic_string() + (fb.GetPwd().relative_path()).generic_string();
                }


                if (fb.HasSelected())
                {
                    if (exportPolicySelection == ExportPolicy::COLUMN_WISE) {
                        exportColumnWise(fb.GetSelected().string() + ".csv", outputVariables);
                    }
                    else {
                        exportRowWise(fb.GetSelected().string() + ".csv", outputVariables);
                    }
                    fb.ClearSelected();
                    showExportPopup = false;
                    ImGui::CloseCurrentPopup();
                }





                ImGui::EndPopup();
            }

            
            static int selected = -1;
            static char characters[40];

            // if deleted variable and selected index out of bounds reset it
            if (selected >= CODE_OUTPUT_VARIABLES.size()) {
                selected = -1;
            }

            ImGui::BeginChild("left pane", ImVec2(150, 0), true);
            for (int i = 0; i < CODE_OUTPUT_VARIABLES.size(); i++) {
                std::shared_ptr<VarSymbol> data = CODE_OUTPUT_VARIABLES.at(i);
               

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
            /*
            Information about each variable
            */
            if (selected != -1) {
                std::shared_ptr<VarSymbol> data = CODE_OUTPUT_VARIABLES.at(selected);
                ImGui::Text(std::string("Name: " + data->name).c_str());
                ImGui::Text(std::string("Type: " + data->type->name).c_str());
                ImGui::Text(std::string("Size: " + std::to_string(data->buffer.size())).c_str());
                ImGui::Text(std::string("Original Size: " + std::to_string(data->originalSize)).c_str());
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