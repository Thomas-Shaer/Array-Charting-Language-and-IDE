//// Dear ImGui: standalone example application for DirectX 11
//// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
//// Read online: https://github.com/ocornut/imgui/tree/master/docs
//#include "maingui.h"
//
//#include <tchar.h>
#include "chartwindow.h"
//#include "TextEditor.h"
#include "texteditorwindow.h"
#include "outputwindow.h"
#include "documentationwindow.h"
//
#include "datamanagerwindow.h"
//#include "jsonsettings.h"
//#include "imfilebrowser.h"
//#include "inputseries.h"
#include "maingui.h"
#include "jsonsettings.h"
#include "implot.h"
#include "imgui_internal.h"
#include "menubar.h"
//#include "screenshot.h"
//
//
ImFont* Fonts::SMALLFONT;
ImFont* Fonts::DEFAULTFONT;



int start()
{
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(Settings::settingsFile["windowwidth"].get<float>(), Settings::settingsFile["windowheight"].get<float>(), "Chart Building Software - Thomas Shaer Comp Sci. Disseration", NULL, NULL);

    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync
    glfwSetWindowPos(window, Settings::settingsFile["windowX"].get<float>(), Settings::settingsFile["windowY"].get<float>());

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    //ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImPlot::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();
    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


    // default chart window instance
    //ChartWindow chartWindow(0);
    ChartWindow::allChartWindows[DEFAULT_CHART_WINDOW_ID] = new ChartWindow(DEFAULT_CHART_WINDOW_ID);
    ChartWindow::allChartWindows[DEFAULT_CHART_WINDOW_ID]->saveOpenStatus = true;

    /*
    The order of these declarations matter. Default first.
    */
    Fonts::DEFAULTFONT = io.Fonts->AddFontFromFileTTF("misc\\fonts\\ProggyClean.ttf", 13);
    Fonts::SMALLFONT = io.Fonts->AddFontFromFileTTF("misc\\fonts\\ProggyClean.ttf", 10);

    //ScreenshotMaker sm;

    TextEditorWindow texteditorwindow;
    texteditorwindow.windowTab = true;
    texteditorwindow.saveOpenStatus = true;

    OutputWindow outputWindow;
    outputWindow.windowTab = true;
    outputWindow.saveOpenStatus = true;

    DocumentationWindow documentationWindow;
    documentationWindow.windowTab = true;
    documentationWindow.saveOpenStatus = true;


    DataManagerWindow datamanagerWindow;
    datamanagerWindow.windowTab = true;
    datamanagerWindow.saveOpenStatus = true;


    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        


        //ChartWindow::getOrCreateChartWindow(0).ShowChartWindow(&show_demo_window);



        for (Window* window : Window::windows) {
            if (window->show) {
                window->ShowWindow();
            }
            if (window->saveOpenStatus) {
                Settings::settingsFile[window->saveJSONName] = window->show;
            }
        }
        ImGui::GetIO().FontGlobalScale = Settings::settingsFile["zoom"].get<float>();


        Test::ShowMenuBar(window);


        Window::manageNewWindows();

        Settings::autoSave();

        // Rendering
        ImGui::Render();

        int windowWidth, windowHeight;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);

        // if window width or height are not 0 window is not minimised therefore save its settings
        if (windowWidth != 0 || windowHeight != 0) {
            Settings::settingsFile["windowwidth"] = windowWidth;
            Settings::settingsFile["windowheight"] = windowHeight;

            int windowX, windowY;
            glfwGetWindowPos(window, &windowX, &windowY);
            Settings::settingsFile["windowX"] = windowX;
            Settings::settingsFile["windowY"] = windowY;
        }



        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        /*if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }*/

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImPlot::DestroyContext();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

