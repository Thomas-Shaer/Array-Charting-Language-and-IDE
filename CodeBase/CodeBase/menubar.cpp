#include "menubar.h"
#include "imgui.h"
#include "imgui_internal.h"
#include "window.h"
#include <GLFW/glfw3.h>
#include "imgui_impl_glfw.h"
#include "jsonsettings.h"
#include "chartwindow.h"


void Test::ShowMenuBar(GLFWwindow* glfwwindow) {
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar;

    static bool fullScreen = false;

    float height = ImGui::GetFrameHeight();
    if (ImGui::BeginViewportSideBar("##SecondaryMenuBar", ImGui::GetMainViewport(), ImGuiDir_Up, height, window_flags)) {
        if (ImGui::BeginMenuBar()) {
            //ImGui::PushItemFlag(ImGuiItemFlags_SelectableDontClosePopup, true);
            if (ImGui::BeginMenu("Windows")) {
               
                if (ImGui::BeginMenu("Charts")) {

                    for (auto pair : ChartWindow::allChartWindows) {
                        Window* window = pair.second;
                       
                        ImGui::MenuItem(window->name.c_str(), NULL, &window->show);
                    }
                    ImGui::EndMenu();
                }

                for (Window* window : Window::windows) {
                    if (window->windowTab) {
                        ImGui::MenuItem(window->name.c_str(), NULL, &window->show);
                    }
                }
                
                

                ImGui::EndMenu();
            }


            if (ImGui::BeginMenu("Settings")) {
                if (ImGui::BeginMenu("Size")) {
                    static float textScale = Settings::settingsFile["zoom"].get<float>();
                    if (ImGui::SliderFloat("Text scale", &textScale, 1, 3)) {
                        Settings::settingsFile["zoom"] = textScale;
                    }
                    ImGui::EndMenu();
                }
                ImGui::EndMenu();
            }

            //ImGui::PopItemFlag();

            ImGui::EndMenuBar();
        }
        ImGui::EndMenuBar();
        ImGuiContext& g = *GImGui;
        if (g.CurrentWindow == g.NavWindow && g.NavLayer == ImGuiNavLayer_Main && !g.NavAnyRequest)
            ImGui::FocusTopMostWindowUnderOne(g.NavWindow, NULL);
        ImGui::End();
    }
}