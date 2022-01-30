#include "datamanagerwindow.h"
#include "imgui.h"
#include <iostream>
#include "jsonsettings.h"

#include "symboltable.h"
#include "typesymbol.h"
#include "inputdata.h"
#include "implot.h"
#include "varsymbol.h"
#include "chartwindow.h"
#include <boost/algorithm/string.hpp>
#include "chartplot.h"
#include "textoutputwindow.h"
#include "dataparseexception.h"


ImGui::FileBrowser DataManagerWindow::fb;
std::vector<std::shared_ptr<InputData>> DataManagerWindow::LOADED_IN_DATA = { };


void DataManagerWindow::init() {
    fb.SetPwd(std::filesystem::path(Settings::settingsFile["lastDataImportDirectory"].get<std::string>()));

    for (nlohmann::json path : Settings::settingsFile["loadedInData"].get<std::vector<nlohmann::json>>()) {
        auto newData = InputData::LoadInputData(StringToImportPolicy(path["policy"]), path["path"], path["name"], path["trueImportString"], path["falseImportString"], path["NANImportString"]);
        LOADED_IN_DATA.insert(LOADED_IN_DATA.end(), newData.begin(), newData.end());
    }

    // (optional) set browser properties
    fb.SetTitle("title");
    fb.SetTypeFilters({ ".csv" });
}

void DataManagerWindow::loadInData(const ImportPolicy importPolicy, const std::string& pathName, const std::string& fileName, const std::string& TrueString, const std::string& FalseString, const std::string& NANString) {
    auto newData = InputData::LoadInputData(importPolicy, pathName, fileName, TrueString, FalseString, NANString);
    LOADED_IN_DATA.insert(LOADED_IN_DATA.end(), newData.begin(), newData.end());
    
    /*
    Saves data
    */
    nlohmann::json newSave;
    newSave["path"] = pathName;
    newSave["name"] = fileName;
    newSave["policy"] = ImportPolicyToString(importPolicy);
    newSave["trueImportString"] = TrueString;
    newSave["falseImportString"] = FalseString;
    newSave["NANImportString"] = NANString;
    Settings::settingsFile["loadedInData"].push_back(newSave);
}


void DataManagerWindow::createNewVariable(std::shared_ptr<InputData> data, const std::string& variableName) {
    data->isVariable = true;
    data->variableName = variableName;
    std::shared_ptr<VarSymbol> varSymbol = VarSymbol::createVarSymbol(data->variableName, TypeInstances::GetFloatInstance(), data->data);
    SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable[data->variableName] = varSymbol;
    OutputWindow::UpdateVariablesTab();
    
}

void DataManagerWindow::renameVariable(std::shared_ptr<InputData> data, const std::string& variableName) {
    std::shared_ptr<VarSymbol> oldSymbol = SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable[data->variableName];
    SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.erase(SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.find(data->variableName));
    data->variableName = variableName;
    std::shared_ptr<VarSymbol> varSymbol = VarSymbol::createVarSymbol(data->variableName, TypeInstances::GetFloatInstance(), oldSymbol->getValues());
    SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable[data->variableName] = varSymbol;
    OutputWindow::UpdateVariablesTab();
}

void DataManagerWindow::deleteVariable(std::shared_ptr<InputData> data) {
    SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.erase(SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.find(data->variableName));
    data->isVariable = false;
    OutputWindow::UpdateVariablesTab();

}


void DataManagerWindow::deleteAllVariables() {
    SymbolTable::GLOBAL_SYMBOL_TABLE->variableTable.clear();
    for (std::shared_ptr<InputData> inputdata : LOADED_IN_DATA) {
        inputdata->isVariable = false;
    }
    OutputWindow::UpdateVariablesTab();

}

void DataManagerWindow::removeFile(const std::string& fileName) {
    LOADED_IN_DATA.erase(std::remove_if(LOADED_IN_DATA.begin(),
        LOADED_IN_DATA.end(),
        [fileName](std::shared_ptr<InputData> input) {return input->fileName == fileName; }),
        LOADED_IN_DATA.end());
    Settings::settingsFile["loadedInData"].erase(std::remove_if(Settings::settingsFile["loadedInData"].begin(),
        Settings::settingsFile["loadedInData"].end(),
        [fileName](nlohmann::json json) {return json["name"] == fileName; }),
        Settings::settingsFile["loadedInData"].end());
}

void DataManagerWindow::removeAllFiles() {
    LOADED_IN_DATA.clear();
    Settings::settingsFile["loadedInData"] = nlohmann::json::array();
}

std::string DataManagerWindow::makeVariableName(std::string name) {
    boost::algorithm::to_lower(name);
    std::replace_if(std::begin(name), std::end(name),
        [](std::string::value_type v) { return v == ' '; },
        '_');
    return name;
}


void DataManagerWindow::ShowWindow() {
    ImGui::Begin("Data Manager", &show, /*ImGuiWindowFlags_HorizontalScrollbar | */ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(500, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(100, 600), ImGuiCond_FirstUseEver);

    static std::string current_item;
    static int selected = -1;
    static char characters[40];
    static bool showImportPopup = false;
    static char defaultTrue[40];
    static char defaultFalse[40];
    static char defaultNAN[40];
    static std::string variableNameMessage = "";

    if (ImGui::BeginMenuBar()) {


        if (ImGui::BeginMenu("File")) {

            if (ImGui::MenuItem("Import File", NULL, false)) {
                showImportPopup = true;
            }

            if (ImGui::MenuItem("Remove all Files", NULL, false)) {
                removeAllFiles();
                selected = -1;
                current_item = "";
            }

            
            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }





    


    if (showImportPopup)
    {
        ImGui::OpenPopup("Import Data");

        strncpy_s(defaultTrue, Settings::settingsFile["defaultTrueImportLiteral"].get<std::string>().c_str(), sizeof(defaultTrue));
        strncpy_s(defaultFalse, Settings::settingsFile["defaultFalseImportLiteral"].get<std::string>().c_str(), sizeof(defaultFalse));
        strncpy_s(defaultNAN, Settings::settingsFile["defaultNANImportLiteral"].get<std::string>().c_str(), sizeof(defaultNAN));

    }

    if (ImGui::BeginPopupModal("Import Data"))
    {

        static std::string fileName = "";
        static std::string filePath = "";
        static std::string parseMessage = "";

        static ImportPolicy importPolicySelection = ImportPolicy::COLUMN_WISE;

        ImGui::Text(std::string("Import data.").c_str());
        ImGui::NewLine();
        ImGui::Text("Import Policy");
        if (ImGui::BeginCombo("", ImportPolicyToString(importPolicySelection).c_str())) {
            bool is_selected = false;
            if (ImGui::Selectable(ImportPolicyToString(ImportPolicy::COLUMN_WISE).c_str(), is_selected)) {
                importPolicySelection = ImportPolicy::COLUMN_WISE;
            }
            if (ImGui::Selectable(ImportPolicyToString(ImportPolicy::ROW_WISE).c_str(), is_selected)) {
                importPolicySelection = ImportPolicy::ROW_WISE;
            }
            ImGui::EndCombo();
        }


        ImGui::Text("True text (40 char)");
        ImGui::InputText("##truetext", defaultTrue, sizeof(defaultTrue));

        ImGui::Text("False text (40 char)");
        ImGui::InputText("##falsetext", defaultFalse, sizeof(defaultFalse));

        ImGui::Text("NAN text (40 char)");
        ImGui::InputText("##nantext", defaultNAN, sizeof(defaultNAN));

        /*
        Save values
        */
        Settings::settingsFile["defaultTrueImportLiteral"] = std::string(defaultTrue);
        Settings::settingsFile["defaultFalseImportLiteral"] = std::string(defaultFalse);
        Settings::settingsFile["defaultNANImportLiteral"] = std::string(defaultNAN);


        if (ImGui::Button("Select File")) {
            fb.Open();
        }
        ImGui::Text(std::string("File: " + fileName).c_str());


        if (fileName == "") {
            ImGui::BeginDisabled();
        }
        if (ImGui::Button("Import")) {

            try {
                parseMessage = "";
                loadInData(importPolicySelection, filePath, fileName, std::string(defaultTrue), std::string(defaultFalse), std::string(defaultNAN));
                showImportPopup = false;
                ImGui::CloseCurrentPopup();
            }
            catch (DataParseException e) {
                parseMessage = e.message;
            }


        }

        if (fileName == "") {
            ImGui::EndDisabled();
        }

        ImGui::SameLine();

        if (ImGui::Button("Cancel")) {
            showImportPopup = false;
            ImGui::CloseCurrentPopup();
        }

        ImGui::Text(parseMessage.c_str());



        fb.Display();
        if (fb.IsOpened()) {
            Settings::settingsFile["lastDataImportDirectory"] = fb.GetPwd().root_path().generic_string() + (fb.GetPwd().relative_path()).generic_string();
        }


        if (fb.HasSelected())
        {
            fileName = fb.GetSelected().filename().string();
            filePath = fb.GetSelected().string();
            fb.ClearSelected();
        }

        ImGui::EndPopup();
    }

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

    ImGui::SameLine();

    if (ImGui::Button("Remove File")) {
        removeFile(current_item);

        selected = -1;
        current_item = "";
    }






    /*
    Load all data input names on the left hand side of the pane scroller.
    */
    ImGui::BeginChild("left pane", ImVec2(150, 0), true);
    for (int i = 0; i < LOADED_IN_DATA.size(); i ++) {
        std::shared_ptr<InputData> data = LOADED_IN_DATA.at(i);

        /*
        Give it a slight different colour if variable has been made.
        */
        if (data->isVariable) {
            ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
        }


        if (ImGui::Selectable(std::string(std::to_string(i + 1) + ") " + LOADED_IN_DATA.at(i)->name).c_str())) {
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
        std::shared_ptr<InputData> data = LOADED_IN_DATA.at(selected);

        ImGui::Text(data->name.c_str());

        if (data->type == TypeInstances::GetFloatInstance()) {
            if (ImGui::Button("Plot"))
            {
                std::vector<float> values;
                for (auto val : data->data) {
                    Float f = boost::get<Float>(val);
                    if (!f.value) {
                        values.push_back(std::numeric_limits<float>::quiet_NaN());
                        continue;
                    }
                    values.push_back(*f.value);
                }
                ChartWindow::getOrCreateChartWindow(0)->CHART_LINE_DATA.push_back(std::make_shared<ChartPlot>(data->name, values));
                ChartWindow::getOrCreateChartWindow(0)->UpdateChart();
            }
        }
        else if(data->type == TypeInstances::GetBooleanInstance()) {
            if (ImGui::Button("Mark"))
            {
                std::vector<float> values;
                for (auto val : data->data) {
                    Boolean f = boost::get<Boolean>(val);
                    if (!f.value) {
                        values.push_back(std::numeric_limits<float>::quiet_NaN());
                        continue;
                    }
                    values.push_back(*f.value ? 1 : 0);
                }
                ChartWindow::getOrCreateChartWindow(0)->CHART_LINE_DATA.push_back(std::make_shared<ChartPlot>(data->name, values));
                ChartWindow::getOrCreateChartWindow(0)->UpdateChart();
            }
        }
        

        //ImGui::Size
        ImGui::NewLine();
        ImGui::Text(std::string( "File: \"" + data->fileName + "\"").c_str());
        ImGui::NewLine();
        ImGui::Text(std::string("Type: " + data->type->name).c_str());
        ImGui::NewLine();
        ImGui::Text((std::string("Size: ") + std::to_string(data->data.size())).c_str());
        ImGui::NewLine();
        ImGui::Text(variableNameMessage.c_str());

        ImGui::PushItemWidth(200);
        ImGui::Text("Variable name (40 char)");
        ImGui::InputText("##variablename", characters, sizeof(characters));

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

            if (VarSymbol::isValidName(std::string(characters))) {
                createNewVariable(data, std::string(characters));
                variableNameMessage = "";
            }
            else {
                variableNameMessage = "Not a valid variable name " + std::string(characters);
            }
        }

        if (data->isVariable) {
            /*
            Could be optimised, recreates entire variable symbol rather then just changing the symbol name.
            */
            if (ImGui::Button("Rename Variable")) {

                if (VarSymbol::isValidName(std::string(characters))) {
                    renameVariable(data, std::string(characters));
                    variableNameMessage = "";
                }
                else {
                    variableNameMessage = "Not a valid variable name " + std::string(characters);
                }
            }


            if (ImGui::Button("Delete Variable")) {
                deleteVariable(data);
            }
        }

    }
    ImGui::EndGroup();



    ImGui::End();
    
}
