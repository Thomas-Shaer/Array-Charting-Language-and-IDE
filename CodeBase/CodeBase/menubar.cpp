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
            

            if (ImGui::BeginMenu("Windows")) {
               
                if (ImGui::BeginMenu("Charts")) {

                    for (auto pair : ChartWindow::allChartWindows) {
                        Window* window = pair.second;
                        if (ImGui::MenuItem(window->name.c_str(), NULL, window->show)) {
                            window->show = !window->show;
                        }
                    }
                    ImGui::EndMenu();
                }

                for (Window* window : Window::windows) {
                    if (window->windowTab) {
                        if (ImGui::MenuItem(window->name.c_str(), NULL, window->show)) {
                            window->show = !window->show;
                        }
                    }
                }
                
                

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Settings")) {
                /*if (ImGui::MenuItem("Full-screen", NULL, fullScreen)) {
                    fullScreen = !fullScreen;
                    GLFWwindow* window = glfwCreateWindow(Settings::settingsFile["windowwidth"].get<float>(), Settings::settingsFile["windowheight"].get<float>(), "Dear ImGui GLFW+OpenGL3 example", glfwGetPrimaryMonitor(), NULL);

                }*/
                ImGui::EndMenu();
            }

            ImGui::EndMenuBar();
        }
        ImGui::End();
    }
}