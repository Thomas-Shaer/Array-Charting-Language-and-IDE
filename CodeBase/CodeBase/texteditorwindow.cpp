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
#include "jsonsettings.h"
#include <fstream>
#include <sstream> //std::stringstream
#include "inputdata.h"
#include "datamanagerwindow.h"

ImGui::FileBrowser TextEditorSingleton::fbSave(ImGuiFileBrowserFlags_EnterNewFilename);
ImGui::FileBrowser TextEditorSingleton::fbOpen;
TextEditor TextEditorSingleton::textEditor;



static void saveFile(const std::string& filePath) {
    nlohmann::json saveJSON;
    saveJSON["code"] = TextEditorSingleton::textEditor.GetText();
    saveJSON["variables"] = nlohmann::json::array();

    for (std::shared_ptr<InputData> data : DisplayInformation::LOADED_IN_DATA) {
        if (data->isVariable) {
            nlohmann::json variableJSON;
            variableJSON["variableName"] = data->variableName;
            variableJSON["fileName"] = data->fileName;
            variableJSON["path"] = data->path;
            variableJSON["dataName"] = data->name;
            saveJSON["variables"].push_back(variableJSON);
        }
    }
    std::ofstream o(filePath);
    o << saveJSON << std::endl;
    o.close();
}



void loadFile(const std::string& filePath) {
    deleteAllVariables();
    nlohmann::json saveJSON;
    std::ifstream inputjson(filePath);
    inputjson >> saveJSON;
    for (nlohmann::json variable : saveJSON["variables"].get<std::vector<nlohmann::json>>()) {
        std::string variableName = variable["variableName"];
        std::string fileName = variable["fileName"];
        std::string dataName = variable["dataName"];
        std::string filepath = variable["path"];

        bool dataLoadedIn = false;
        
        /*
        If detected that the data file associated with the variable has been removed,
        attempt to load it in again.
        */
        for (nlohmann::json path : Settings::settingsFile["loadedInData"].get<std::vector<nlohmann::json>>()) {
            if (path["path"] == filepath) {
                dataLoadedIn = true;
                break;
            }
        }

        if (!dataLoadedIn) {
            loadInData(filepath, fileName);
        }

        for (std::shared_ptr<InputData> data : DisplayInformation::LOADED_IN_DATA) {
            if (data->name == dataName) {
                createNewVariable(data, variableName);
            }
        }

   
    }
    TextEditorSingleton::textEditor.SetText(saveJSON["code"]);

    //InputData::LoadInputData(std::string name, std::string filename)
}



void TextEditorSingleton::initFileBrowserSave() {
    fbSave.SetPwd(std::filesystem::path(Settings::settingsFile["lastSaveDirectory"].get<std::string>()));


    // (optional) set browser properties
    fbSave.SetTitle("title");
    fbSave.SetTypeFilters({ ".al" });
}


void TextEditorSingleton::initFileBrowserOpen() {
    fbOpen.SetPwd(std::filesystem::path(Settings::settingsFile["lastOpenDirectory"].get<std::string>()));


    // (optional) set browser properties
    fbOpen.SetTitle("title");
    fbOpen.SetTypeFilters({ ".al" });
}



void TextEditorSingleton::initTextEditor() {
    auto lang = TextEditor::LanguageDefinition::CPlusPlus();
    textEditor.SetLanguageDefinition(lang);
    textEditor.SetText(DisplayInformation::PLACEHOLDER_CODE);


    std::string currentCodeFile = Settings::settingsFile["currentCodeFile"].get<std::string>();
    if (currentCodeFile != "") {
        loadFile(currentCodeFile);
    }
}


void executeCode(const std::string& code) {
    DisplayInformation::CODE_OUTPUT = "";
    DisplayInformation::CODE_OUTPUT_RECONSTRUCTION = "";
    DisplayInformation::CODE_OUTPUT_VARIABLES = {};
    InterpreterContext context;
    context.execute(code);


    if (!context.output->textOutput.empty()) {
        for (auto string : context.output->textOutput) {
            DisplayInformation::CODE_OUTPUT += string + "\n";
        }
        SnapToOutputTab();
    }

    if (context.ast) {
        DisplayInformation::CODE_OUTPUT_RECONSTRUCTION = context.ast->toString();
    }
    if (context.symboltable) {
        DisplayInformation::CODE_OUTPUT_VARIABLES = context.symboltable->variablesToVector(true);
    }
    DisplayInformation::CHART_LINE_DATA = context.output->chartData;
    DisplayInformation::CHART_MARK_DATA = context.output->markData;
    UpdateChart();
}


void ShowEditorWindow() {
    ImGui::Begin("Code Input", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(10, 600), ImGuiCond_FirstUseEver);

    std::string currentCodeFile = Settings::settingsFile["currentCodeFile"].get<std::string>();


    bool openNewFile = false;
    bool openLoadFile = false;
    bool openSaveFile = false;
    bool openSaveAsFile = false;

    bool noFile = currentCodeFile == "";

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("File")) {
            ImGui::MenuItem("New", NULL, &openNewFile);
            ImGui::MenuItem("Open", NULL, &openLoadFile);
            ImGui::MenuItem("Save", NULL, &openSaveFile);
            ImGui::MenuItem("Save as...", NULL, &openSaveAsFile);
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    if (openSaveAsFile) {
        TextEditorSingleton::fbSave.Open();
    } else if (openLoadFile) {
        TextEditorSingleton::fbOpen.Open();
    } else if (openSaveFile) {
        saveFile(currentCodeFile);
    } else if (openNewFile) {
        TextEditorSingleton::textEditor.SetText("");
        Settings::settingsFile["currentCodeFile"] = "";
    }

    if (ImGui::Button("Execute")) {
        executeCode(TextEditorSingleton::textEditor.GetText());
    }

    TextEditorSingleton::textEditor.Render("TextEditor");

    ImGui::End();

    /*
    Controls for "save as" dialog.
    */

    TextEditorSingleton::fbSave.Display();

    if (TextEditorSingleton::fbSave.IsOpened()) {
        Settings::settingsFile["lastSaveDirectory"] = TextEditorSingleton::fbSave.GetPwd().root_path().generic_string() + (TextEditorSingleton::fbSave.GetPwd().relative_path()).generic_string();
    }

    if (TextEditorSingleton::fbSave.HasSelected())
    {
        std::string fileName = TextEditorSingleton::fbSave.GetSelected().filename().string() + ".al";
        std::string fullPath = TextEditorSingleton::fbSave.GetSelected().string() + ".al";
        
        saveFile(fullPath);
        Settings::settingsFile["currentCodeFile"] = fullPath;

        TextEditorSingleton::fbSave.ClearSelected();

    }

    /*
    Controls for "open" dialog.
    */

    TextEditorSingleton::fbOpen.Display();

    if (TextEditorSingleton::fbOpen.IsOpened()) {
        Settings::settingsFile["lastOpenDirectory"] = TextEditorSingleton::fbOpen.GetPwd().root_path().generic_string() + (TextEditorSingleton::fbOpen.GetPwd().relative_path()).generic_string();
    }

    if (TextEditorSingleton::fbOpen.HasSelected())
    {
        std::string openFile = (TextEditorSingleton::fbOpen.GetSelected().string());
        loadFile(openFile);
        Settings::settingsFile["currentCodeFile"] = openFile;
        TextEditorSingleton::fbOpen.ClearSelected();

    }



}
