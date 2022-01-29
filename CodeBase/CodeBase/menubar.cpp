#include "menubar.h"
#include "imgui.h"
#include "imgui_internal.h"
#include "window.h"


void ShowMenuBar() {
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar;
    float height = ImGui::GetFrameHeight();
    if (ImGui::BeginViewportSideBar("##SecondaryMenuBar", ImGui::GetMainViewport(), ImGuiDir_Up, height, window_flags)) {
        if (ImGui::BeginMenuBar()) {
            

            if (ImGui::BeginMenu("Windows")) {
               
                for (Window* window : Window::windows) {

                    if (ImGui::MenuItem(window->name.c_str(), NULL, window->show)) {
                        window->show = !window->show;
                    }
                }

                ImGui::EndMenu();
            }

            ImGui::EndMenuBar();
        }
        ImGui::End();
    }
}