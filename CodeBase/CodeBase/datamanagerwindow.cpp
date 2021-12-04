#include "datamanagerwindow.h"
#include "imgui.h"
#include <iostream>
#include "jsonsettings.h"
#include "displayinformation.h"
#include <fstream>
#include <sstream>
#include "inputdata.h"
#include "implot.h"

std::vector<std::shared_ptr<InputData>> LoadInputData(std::string name) {

    std::vector<std::shared_ptr<InputData>> values;
    std::ifstream fin(name);
    for (std::string line; std::getline(fin, line); )
    {
        std::string firstWord = line.substr(0, line.find(","));
        line = line.substr(firstWord.size(), line.max_size());
        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream in(line);

        std::shared_ptr<InputData> newdata = std::make_shared<InputData>();
        newdata->name = firstWord;
        newdata->data = std::vector<float>(std::istream_iterator<float>(in), std::istream_iterator<float>());
        values.push_back(newdata);
    }

    return values;

}

void ShowDataWindow(ImGui::FileBrowser& fileDialog) {
    ImGui::Begin("Data Manager", nullptr, ImGuiWindowFlags_HorizontalScrollbar | ImGuiWindowFlags_MenuBar);
    ImGui::SetWindowSize(ImVec2(500, 600), ImGuiCond_FirstUseEver);
    ImGui::SetWindowPos(ImVec2(100, 600), ImGuiCond_FirstUseEver);

    if (ImGui::Button("open file dialog")) {
        fileDialog.Open();
    }


    static int selected = -1;

    ImGui::BeginChild("left pane", ImVec2(150, 0), true);
        for (int i = 0; i < DisplayInformation::LOADED_IN_DATA.size(); i ++) {
        // FIXME: Good candidate to use ImGuiSelectableFlags_SelectOnNav
        if (ImGui::Selectable(DisplayInformation::LOADED_IN_DATA.at(i)->name.c_str())) {
            selected = i;
        }
    }


    ImGui::EndChild();
    ImGui::SameLine();

    if (selected != -1) {
        std::shared_ptr<InputData> data = DisplayInformation::LOADED_IN_DATA.at(selected);

        ImGui::Text(data->name.c_str());
        ImGui::SameLine();

        if (ImGui::Button("Plot"))
        {
            ImPlot::SetNextAxisToFit(ImAxis_X1);
            ImPlot::SetNextAxisToFit(ImAxis_Y1);
            DisplayInformation::CHART_LINE_DATA.push_back(data->data);
        }
        //ImGui::BeginGroup();
        //ImGui::BeginChild("item view", ImVec2(0, -ImGui::GetFrameHeightWithSpacing())); // Leave room for 1 line below us
        //ImGui::Text(data->name.c_str());
        //ImGui::EndChild();
        //ImGui::EndGroup();
    }

    ImGui::End();

    fileDialog.Display();
    if(fileDialog.IsOpened()) {
        Settings::settingsFile["lastDirectory"] = fileDialog.GetPwd().root_path().generic_string() + (fileDialog.GetPwd().relative_path()).generic_string();
    }


    if (fileDialog.HasSelected())
    {
        DisplayInformation::LOADED_IN_DATA = LoadInputData(fileDialog.GetSelected().string());
        fileDialog.ClearSelected();
    }
}
