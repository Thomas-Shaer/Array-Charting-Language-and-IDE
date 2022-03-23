#include "texteditorwindow.h"
#include "imgui.h"
#include <iostream>
#include "interpretercontext.h"
#include "outputwindow.h"

#include "node.h"
#include "symboltable.h"
#include "implot.h"
#include "chartwindow.h"
#include "jsonsettings.h"
#include <fstream>
#include <sstream> //std::stringstream
#include "inputseries.h"
#include "datamanagerwindow.h"
#include "dataparseexception.h"
#include "languageexception.h"




std::string TextEditorWindow::PLACEHOLDER_CODE = "plot(tick(), 0)\nmark(tick() > 5 && tick() < 20, tick(), 0)";
bool TextEditorWindow::codemodifysignal = false;





TextEditorWindow::TextEditorWindow() : Window("Text Editor Window") {

    /*
    Initialise text editor widget
    */

    auto lang = TextEditor::LanguageDefinition::CUSTOM();
    textEditor.SetLanguageDefinition(lang);
    textEditor.SetText(PLACEHOLDER_CODE);

    std::string currentCodeFile = Settings::settingsFile["currentCodeFile"].get<std::string>();
    if (currentCodeFile != "") {
        loadFile(currentCodeFile);
    }

    /*
    Initalise file browser for saving
    */

    fbSave.SetPwd(std::filesystem::path(Settings::settingsFile["lastCodeSaveDirectory"].get<std::string>()));


    // (optional) set browser properties
    fbSave.SetTitle("title");
    fbSave.SetTypeFilters({ ".al" });

    /*
    Initalise file browser for loading
    */
    
    fbOpen.SetPwd(std::filesystem::path(Settings::settingsFile["lastCodeOpenDirectory"].get<std::string>()));


    // (optional) set browser properties
    fbOpen.SetTitle("title");
    fbOpen.SetTypeFilters({ ".al" });
}

void TextEditorWindow::saveFile(const std::string& filePath) {
    nlohmann::json saveJSON;
    saveJSON["code"] = textEditor.GetText();
    saveJSON["variables"] = nlohmann::json::array();

    for (std::shared_ptr<InputSeries> data : DataManagerWindow::LOADED_IN_DATA) {
        if (data->isVariable) {
            nlohmann::json variableJSON;
            variableJSON["variableName"] = data->variableName;
            variableJSON["fileName"] = data->fileName;
            variableJSON["path"] = data->path;
            variableJSON["dataName"] = data->name;
            variableJSON["policy"] = InputSeries::ImportPolicyToString(data->importPolicy);
            variableJSON["trueImportString"] = data->trueLiteral;
            variableJSON["falseImportString"] = data->falseLiteral;
            variableJSON["nullImportString"] = data->nullLiteral;
            saveJSON["variables"].push_back(variableJSON);
        }
    }
    std::ofstream o(filePath);
    o << saveJSON << std::endl;
    o.close();
}



void TextEditorWindow::loadFile(const std::string& filePath) {
    // delete existing variables 
    DataManagerWindow::deleteAllVariables();
    nlohmann::json saveJSON;
    std::ifstream inputjson(filePath);
    if (inputjson) {
        inputjson >> saveJSON;
        /*
        For every variable in the save file,
        parse it's relevant json and load the file
        */
        for (nlohmann::json variable : saveJSON["variables"].get<std::vector<nlohmann::json>>()) {
            std::string variableName = variable["variableName"];
            std::string fileName = variable["fileName"];
            std::string dataName = variable["dataName"];
            std::string filepath = variable["path"];

            std::string trueImport = variable["trueImportString"];
            std::string falseImport = variable["falseImportString"];
            std::string nullImport = variable["nullImportString"];
            ImportPolicy importPolicy = InputSeries::StringToImportPolicy(variable["policy"]);


            InputSeries::LoadInputData(importPolicy, filepath, fileName, trueImport, falseImport, nullImport);

            // mark it as a variable
            for (std::shared_ptr<InputSeries> data : DataManagerWindow::LOADED_IN_DATA) {
                if (data->name == dataName) {
                    try {
                        data->createNewVariable(variableName);
                    }
                    catch (DataParseException e) {
                    }
                }
            }


        }

        // set the text editor to the code
        TextEditorWindow::textEditor.SetText(saveJSON["code"]);
    }
    
}




void TextEditorWindow::executeCode(const std::string& code) {

    // create interpreter context object
    InterpreterContext context;

    // run code
    context.execute(code);


    
    /*
    Collect and display output
    */
    
    // reset error markers
    textEditor.SetErrorMarkers({});

    OutputWindow::CODE_OUTPUT = "";
    // if a error display it
    if (context.langExcept) {
        OutputWindow::CODE_OUTPUT += context.langExcept->toString(code);
        TextEditor::ErrorMarkers markers;
        markers.insert(std::make_pair<int, std::string>(static_cast<int>(context.langExcept->sourceLocation.begin.line) + 1, context.langExcept->message.c_str()));
        textEditor.SetErrorMarkers(markers);
        OutputWindow::SnapToOutputTab();

    }

    // display the ast as a string
    if (context.ast) {
        OutputWindow::CODE_OUTPUT_RECONSTRUCTION = context.ast->toString();
    }
    // display all the variables from the symbol table
    if (context.symboltable) {
        OutputWindow::CODE_OUTPUT_VARIABLES = context.symboltable->variablesToVector(true);
    }
    // update all the charts
    ChartWindow::updateAllCharts();
}



void TextEditorWindow::executeErrorHighlighting(const std::string& code) {

    // create interpreter context object
    InterpreterContext context;

    // run code in errorhighlighting mode
    context.errorHighlighting(code);

    /*
    Collect and display output
    */

    // reset error markers
    textEditor.SetErrorMarkers({});

    OutputWindow::CODE_OUTPUT = "";
    // if a error display it
    if (context.langExcept) {
        OutputWindow::CODE_OUTPUT += context.langExcept->toString(code);
        TextEditor::ErrorMarkers markers;
        markers.insert(std::make_pair<int, std::string>(static_cast<int>(context.langExcept->sourceLocation.begin.line) + 1, context.langExcept->message.c_str()));
        textEditor.SetErrorMarkers(markers);
    }
    // display the ast as a string
    if (context.ast) {
        OutputWindow::CODE_OUTPUT_RECONSTRUCTION = context.ast->toString();
    }
    // display all the variables from the symbol table
    if (context.symboltable) {
        OutputWindow::CODE_OUTPUT_VARIABLES = context.symboltable->variablesToVector(true);
    }
}

/*
Helper function thats executed whenever a key is pressed 
while in the text editor widget
*/
void TextEditor::AnyKeyPressed() {
    TextEditorWindow::codemodifysignal = true;
}



void TextEditorWindow::ShowWindow() {
    
    ImGui::Begin("Code Input", &show, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
    
    
    ImGui::SetWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(10, 600), ImGuiCond_FirstUseEver);

    std::string currentCodeFile = Settings::settingsFile["currentCodeFile"].get<std::string>();

    static bool errorHighlighting = Settings::settingsFile["errorhighlighting"].get<bool>();

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
        if (ImGui::BeginMenu("Options")) {
            if(ImGui::MenuItem("Error Highlighting", NULL, &errorHighlighting)) {
                textEditor.SetErrorMarkers({});
                Settings::settingsFile["errorhighlighting"] = errorHighlighting;
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }


    if (errorHighlighting) {
        if (codemodifysignal) {
            executeErrorHighlighting(TextEditorWindow::textEditor.GetText());
            codemodifysignal = false;
        }
    }

    if (openSaveAsFile) {
        TextEditorWindow::fbSave.Open();
    } else if (openLoadFile) {
        TextEditorWindow::fbOpen.Open();
    } else if (openSaveFile) {
        saveFile(currentCodeFile);
    } else if (openNewFile) {
        TextEditorWindow::textEditor.SetText("");
        Settings::settingsFile["currentCodeFile"] = "";
    }
    if (ImGui::Button("Execute")) {
        executeCode(TextEditorWindow::textEditor.GetText());
    }
    ImGui::SameLine();
    ImGui::InputScalar("Ticks", ImGuiDataType_U32, &InterpreterContext::ticks);

    TextEditorWindow::textEditor.Render("TextEditor");

    ImGui::End();

    /*
    Controls for "save as" dialog.
    */

    TextEditorWindow::fbSave.Display();

    if (TextEditorWindow::fbSave.IsOpened()) {
        Settings::settingsFile["lastCodeSaveDirectory"] = TextEditorWindow::fbSave.GetPwd().root_path().generic_string() + (TextEditorWindow::fbSave.GetPwd().relative_path()).generic_string();
    }

    if (TextEditorWindow::fbSave.HasSelected())
    {
        std::string fileName = TextEditorWindow::fbSave.GetSelected().filename().string() + ".al";
        std::string fullPath = TextEditorWindow::fbSave.GetSelected().string() + ".al";
        
        saveFile(fullPath);
        Settings::settingsFile["currentCodeFile"] = fullPath;

        TextEditorWindow::fbSave.ClearSelected();

    }

    /*
    Controls for "open" dialog.
    */

    TextEditorWindow::fbOpen.Display();

    if (TextEditorWindow::fbOpen.IsOpened()) {
        Settings::settingsFile["lastCodeOpenDirectory"] = TextEditorWindow::fbOpen.GetPwd().root_path().generic_string() + (TextEditorWindow::fbOpen.GetPwd().relative_path()).generic_string();
    }

    if (TextEditorWindow::fbOpen.HasSelected())
    {
        std::string openFile = (TextEditorWindow::fbOpen.GetSelected().string());
        loadFile(openFile);
        Settings::settingsFile["currentCodeFile"] = openFile;
        TextEditorWindow::fbOpen.ClearSelected();

    }
}
