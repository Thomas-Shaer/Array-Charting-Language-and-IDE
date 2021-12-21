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
#include "chartplot.h"
#include "textoutputwindow.h"


ImGui::FileBrowser FileBrowserSingletonDataLoader::fb;


void FileBrowserSingletonDataLoader::init() {
    fb.SetPwd(std::filesystem::path(Settings::settingsFile["lastDataDirectory"].get<std::string>()));

    for (nlohmann::json path : Settings::settingsFile["loadedInData"].get<std::vector<nlohmann::json>>()) {
        auto newData = InputData::LoadInputData(path["path"], path["name"]);
        DisplayInformation::LOADED_IN_DATA.insert(DisplayInformation::LOADED_IN_DATA.end(), newData.begin(), newData.end());
    }

    // (optional) set browser properties
    fb.SetTitle("title");
    fb.SetTypeFilters({ ".csv" });
}

void loadInData(const std::string& pathName, const std::string& fileName) {
    auto newData = InputData::LoadInputData(pathName, fileName);
    DisplayInformation::LOADED_IN_DATA.insert(DisplayInformation::LOADED_IN_DATA.end(), newData.begin(), newData.end());
    nlohmann::json newSave;
    newSave["path"] = FileBrowserSingletonDataLoader::fb.GetSelected().string();
    newSave["name"] = FileBrowserSingletonDataLoader::fb.GetSelected().filename().string();
    Settings::settingsFile["loadedInData"].push_back(newSave);
}


void createNewVariable(std::shared_ptr<InputData> data, const std::string& variableName) {
    std::vector<ExpressionValue> values;
    for (auto i : data->data) {
        values.push_back((ExpressionValue)Float(i));
    }
    data->isVariable = true;
    data->variableName = variableName;
    std::shared_ptr<VarSymbol> varSymbol = std::make_shared<VarSymbol>(data->variableName, TypeInstances::GetFloatInstance(), values);
    SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable[data->variableName] = varSymbol;
    UpdateVariablesTab();
}

void deleteVariable(std::shared_ptr<InputData> data) {
    SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.erase(SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.find(data->variableName));
    data->isVariable = false;
    UpdateVariablesTab();

}


void deleteAllVariables() {
    SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.clear();
    for (std::shared_ptr<InputData> inputdata : DisplayInformation::LOADED_IN_DATA) {
        inputdata->isVariable = false;
    }
    UpdateVariablesTab();

}

void removeFile(const std::string& fileName) {
    DisplayInformation::LOADED_IN_DATA.erase(std::remove_if(DisplayInformation::LOADED_IN_DATA.begin(),
        DisplayInformation::LOADED_IN_DATA.end(),
        [fileName](std::shared_ptr<InputData> input) {return input->fileName == fileName; }),
        DisplayInformation::LOADED_IN_DATA.end());
    Settings::settingsFile["loadedInData"].erase(std::remove_if(Settings::settingsFile["loadedInData"].begin(),
        Settings::settingsFile["loadedInData"].end(),
        [fileName](nlohmann::json json) {return json["name"] == fileName; }),
        Settings::settingsFile["loadedInData"].end());
}

void removeAllFiles() {
    DisplayInformation::LOADED_IN_DATA.clear();
    Settings::settingsFile["loadedInData"] = nlohmann::json::array();
}

std::string makeVariableName(std::string name) {
    boost::algorithm::to_lower(name);
    std::replace_if(std::begin(name), std::end(name),
        [](std::string::value_type v) { return v == ' '; },
        '_');
    return name;
}


void ShowDataWindow() {
    ImGui::Begin("Data Manager", nullptr, /*ImGuiWindowFlags_HorizontalScrollbar | */ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(500, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(100, 600), ImGuiCond_FirstUseEver);

    static std::string current_item;
    static int selected = -1;
    static char characters[40];


    /*
    Combobox widget containing current loaded in files.
    */
    if (ImGui::BeginCombo("Files", current_item.c_str())) {
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
        FileBrowserSingletonDataLoader::fb.Open();
    }
    ImGui::SameLine();

    if (ImGui::Button("Remove File")) {
        removeFile(current_item);

        selected = -1;
        current_item = "";
    }

    ImGui::SameLine();

    if (ImGui::Button("Remove all Files")) {
        removeAllFiles();


        selected = -1;
        current_item = "";
    }




    /*
    Load all data input names on the left hand side of the pane scroller.
    */
    ImGui::BeginChild("left pane", ImVec2(150, 0), true);
    for (int i = 0; i < DisplayInformation::LOADED_IN_DATA.size(); i ++) {
        std::shared_ptr<InputData> data = DisplayInformation::LOADED_IN_DATA.at(i);

        /*
        Give it a slight different colour if variable has been made.
        */
        if (data->isVariable) {
            ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
        }


        if (ImGui::Selectable(DisplayInformation::LOADED_IN_DATA.at(i)->name.c_str())) {
            selected = i;
            std::string name = makeVariableName(data->name);
            strncpy_s(characters, name.c_str(), sizeof(characters));
        }

        if (data->isVariable) {
            ImGui::PopStyleColor();
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
            DisplayInformation::CHART_LINE_DATA.push_back(std::make_shared<ChartPlot>(data->name, data->data));
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

        bool createVariable = false;

        if (data->isVariable) {
            ImGui::BeginDisabled();
        }
        if (ImGui::Button("Create Variable"))
        {
            createVariable = true;
        }
        if (data->isVariable) {
            ImGui::EndDisabled();
        }
        if (createVariable) {
            createNewVariable(data, std::string(characters));
        }

        if (data->isVariable) {
            /*
            Could be optimised, recreates entire variable symbol rather then just changing the symbol name.
            */
            if (ImGui::Button("Rename Variable")) {
                std::shared_ptr<VarSymbol> oldSymbol = SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable[data->variableName];
                SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.erase(SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.find(data->variableName));
                data->variableName = std::string(characters);
                std::shared_ptr<VarSymbol> varSymbol = std::make_shared<VarSymbol>(data->variableName, TypeInstances::GetFloatInstance(), oldSymbol->getValues());
                SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable[data->variableName] = varSymbol;
                UpdateVariablesTab();
            }


            if (ImGui::Button("Delete Variable")) {
                deleteVariable(data);
            }
        }

    }
    ImGui::EndGroup();



    ImGui::End();
    FileBrowserSingletonDataLoader::fb.Display();
    if(FileBrowserSingletonDataLoader::fb.IsOpened()) {
        Settings::settingsFile["lastDataDirectory"] = FileBrowserSingletonDataLoader::fb.GetPwd().root_path().generic_string() + (FileBrowserSingletonDataLoader::fb.GetPwd().relative_path()).generic_string();
    }


    if (FileBrowserSingletonDataLoader::fb.HasSelected())
    {
        loadInData(FileBrowserSingletonDataLoader::fb.GetSelected().string(), FileBrowserSingletonDataLoader::fb.GetSelected().filename().string());
        FileBrowserSingletonDataLoader::fb.ClearSelected();


    }
}
