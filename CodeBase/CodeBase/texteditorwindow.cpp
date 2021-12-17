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


ImGui::FileBrowser TextEditorSingleton::fbSave(ImGuiFileBrowserFlags_EnterNewFilename);
ImGui::FileBrowser TextEditorSingleton::fbOpen;
TextEditor TextEditorSingleton::textEditor;


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
        std::ifstream inFile;
        inFile.open(currentCodeFile); //open the input file

        std::stringstream strStream;
        strStream << inFile.rdbuf(); //read the file
        std::string str = strStream.str(); //str holds the content of the file

        textEditor.SetText(str);
    }
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
    }

    if (openLoadFile) {
        TextEditorSingleton::fbOpen.Open();
    }

    if (openSaveFile) {
        std::ofstream file(currentCodeFile);
        file << TextEditorSingleton::textEditor.GetText();
        file.close();
    }

    if (openNewFile) {
        TextEditorSingleton::textEditor.SetText("");
        Settings::settingsFile["currentCodeFile"] = "";
    }

    if (ImGui::Button("Execute")) {
        DisplayInformation::CODE_OUTPUT = "";
        DisplayInformation::CODE_OUTPUT_RECONSTRUCTION = "";
        DisplayInformation::CODE_OUTPUT_VARIABLES = "";
        InterpreterContext context;
        context.execute(TextEditorSingleton::textEditor.GetText());


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
            DisplayInformation::CODE_OUTPUT_VARIABLES = context.symboltable->variablesToString(true);
        }
        DisplayInformation::CHART_LINE_DATA = context.output->chartData;
        DisplayInformation::CHART_MARK_DATA = context.output->markData;
        UpdateChart();
        //std::cout << "what" << std::endl;
    }

    TextEditorSingleton::textEditor.Render("TextEditor");

    ImGui::End();

    TextEditorSingleton::fbSave.Display();
    TextEditorSingleton::fbOpen.Display();
    if (TextEditorSingleton::fbSave.IsOpened()) {
        Settings::settingsFile["lastSaveDirectory"] = TextEditorSingleton::fbSave.GetPwd().root_path().generic_string() + (TextEditorSingleton::fbSave.GetPwd().relative_path()).generic_string();
    }

    if (TextEditorSingleton::fbOpen.IsOpened()) {
        Settings::settingsFile["lastOpenDirectory"] = TextEditorSingleton::fbOpen.GetPwd().root_path().generic_string() + (TextEditorSingleton::fbOpen.GetPwd().relative_path()).generic_string();
    }

    if (TextEditorSingleton::fbSave.HasSelected())
    {
        std::string fileName = TextEditorSingleton::fbSave.GetSelected().filename().string() + ".al";
        std::string fullPath = TextEditorSingleton::fbSave.GetSelected().string() + ".al";
        

        std::ofstream file(fullPath);
        file << TextEditorSingleton::textEditor.GetText();
        file.close();
        Settings::settingsFile["currentCodeFile"] = fullPath;


        TextEditorSingleton::fbSave.ClearSelected();

    }

    if (TextEditorSingleton::fbOpen.HasSelected())
    {
        std::string openFile = (TextEditorSingleton::fbOpen.GetSelected().string());
        std::ifstream inFile;
        inFile.open(openFile); //open the input file

        std::stringstream strStream;
        strStream << inFile.rdbuf(); //read the file
        std::string str = strStream.str(); //str holds the content of the file
        TextEditorSingleton::textEditor.SetText(str);
        Settings::settingsFile["currentCodeFile"] = openFile;

        TextEditorSingleton::fbOpen.ClearSelected();

    }



}
