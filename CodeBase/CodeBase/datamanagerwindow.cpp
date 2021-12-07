#include "datamanagerwindow.h"
#include "imgui.h"
#include <iostream>
#include "jsonsettings.h"
#include "displayinformation.h"
#include "symboltable.h"
#include "typesymbol.h"
#include "inputdata.h"
#include "implot.h"
#include "varsymbol.h"
#include "chartwindow.h"
#include <boost/algorithm/string.hpp>


void ShowDataWindow(ImGui::FileBrowser& fileDialog) {
    ImGui::Begin("Data Manager", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(500, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(100, 600), ImGuiCond_FirstUseEver);

    if (ImGui::Button("open file dialog")) {
        fileDialog.Open();
    }


    static int selected = -1;
    static char characters[40];

    ImGui::BeginChild("left pane", ImVec2(150, 0), true);
        for (int i = 0; i < DisplayInformation::LOADED_IN_DATA.size(); i ++) {
        // FIXME: Good candidate to use ImGuiSelectableFlags_SelectOnNav
        if (ImGui::Selectable(DisplayInformation::LOADED_IN_DATA.at(i)->name.c_str())) {
            selected = i;
            std::shared_ptr<InputData> data = DisplayInformation::LOADED_IN_DATA.at(selected);
            std::string name = data->name;
            boost::algorithm::to_lower(name);
            std::replace_if(std::begin(name), std::end(name),
                [](std::string::value_type v) { return v == ' '; },
                '_');

            strncpy_s(characters, name.c_str(), sizeof(characters));
        }
    }


    ImGui::EndChild();
    ImGui::SameLine();
    ImGui::BeginGroup();
    if (selected != -1) {
        std::shared_ptr<InputData> data = DisplayInformation::LOADED_IN_DATA.at(selected);

        ImGui::Text(data->name.c_str());

        if (ImGui::Button("Plot"))
        {
            DisplayInformation::CHART_LINE_DATA.push_back(data->data);
            UpdateChart();
        }

        //ImGui::Size
        ImGui::NewLine();
        ImGui::Text((std::string("Size: ") + std::to_string(data->data.size())).c_str());
        ImGui::NewLine();
        ImGui::PushItemWidth(200);
        ImGui::Text("Variable name (40 char)");
        ImGui::InputText("", characters, sizeof(characters));
        if (ImGui::Button("Create Variable"))
        {
            std::vector<ExpressionValue> values;
            for (auto i : data->data) {
                values.push_back((ExpressionValue)Float(i));
            }
            std::shared_ptr<VarSymbol> varSymbol = std::make_shared<VarSymbol>(std::string(characters), TypeInstances::GetFloatInstance(), values);
            SymbolTable::globalVariableTable[std::string(characters)] = varSymbol;
        }
    }
    ImGui::EndGroup();

    ImGui::End();
    fileDialog.Display();
    if(fileDialog.IsOpened()) {
        Settings::settingsFile["lastDirectory"] = fileDialog.GetPwd().root_path().generic_string() + (fileDialog.GetPwd().relative_path()).generic_string();
    }


    if (fileDialog.HasSelected())
    {
        auto newData = InputData::LoadInputData(fileDialog.GetSelected().string());
        DisplayInformation::LOADED_IN_DATA.insert(DisplayInformation::LOADED_IN_DATA.end(), newData.begin(), newData.end());
        Settings::settingsFile["loadedInData"].push_back(fileDialog.GetSelected().string());
        fileDialog.ClearSelected();
    }
}
