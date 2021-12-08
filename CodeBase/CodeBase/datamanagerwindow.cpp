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
    ImGui::Begin("Data Manager", nullptr, /*ImGuiWindowFlags_HorizontalScrollbar | */ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(500, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(100, 600), ImGuiCond_FirstUseEver);



    //ImGui::NewLine();
    static std::string current_item;
    static int selected = -1;
    static char characters[40];

    if (ImGui::BeginCombo("Files", current_item.c_str())) // The second parameter is the label previewed before opening the combo.
    {
        for (nlohmann::json path : Settings::settingsFile["loadedInData"].get<std::vector<nlohmann::json>>()) {

                bool is_selected = false; // You can store your selection however you want, outside or inside your objects
                if (ImGui::Selectable(path["name"].get<std::string>().c_str(), is_selected)) {
                    current_item = path["name"].get<std::string>();
                }
                if (is_selected) {
                    ImGui::SetItemDefaultFocus();
                }
        }
        ImGui::EndCombo();
    }

    if (ImGui::Button("Import File")) {
        fileDialog.Open();
    }
    ImGui::SameLine();

    if (ImGui::Button("Remove File")) {
        DisplayInformation::LOADED_IN_DATA.erase(std::remove_if(DisplayInformation::LOADED_IN_DATA.begin(),
            DisplayInformation::LOADED_IN_DATA.end(),
            [](std::shared_ptr<InputData> input) {return input->fileName == current_item; }),
            DisplayInformation::LOADED_IN_DATA.end());
        Settings::settingsFile["loadedInData"].erase(std::remove_if(Settings::settingsFile["loadedInData"].begin(),
            Settings::settingsFile["loadedInData"].end(),
            [](nlohmann::json json) {return json["name"] == current_item; }),
            Settings::settingsFile["loadedInData"].end());

        selected = -1;
        current_item = "";
    }
    ImGui::SameLine();
    if (ImGui::Button("Remove all Files")) {
        // remove all laoded in data
        // clear loaded files
        DisplayInformation::LOADED_IN_DATA.clear();
        Settings::settingsFile["loadedInData"] = nlohmann::json::array();


        selected = -1;
        current_item = "";
    }




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
        ImGui::Text(std::string( "File: \"" + data->fileName + "\"").c_str());
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
        auto newData = InputData::LoadInputData(fileDialog.GetSelected().string(), fileDialog.GetSelected().filename().string());
        DisplayInformation::LOADED_IN_DATA.insert(DisplayInformation::LOADED_IN_DATA.end(), newData.begin(), newData.end());
        nlohmann::json newSave;
        newSave["path"] = fileDialog.GetSelected().string();
        newSave["name"] = fileDialog.GetSelected().filename().string();
        Settings::settingsFile["loadedInData"].push_back(newSave);
        fileDialog.ClearSelected();


    }
}
