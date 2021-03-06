#pragma once

/*
NOTE
This file is a modified version of ImGui's screenshotting tool
found here https://github.com/ocornut/imgui/wiki/screenshot_tool
*/

#include "imgui.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui_internal.h"
#include <iostream>
#include <GLFW/glfw3.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE



struct ImageBuf
{
    /*
    Code from https://github.com/ocornut/imgui/wiki/screenshot_tool
    */
    typedef unsigned int u32;

    int             Width, Height;
    u32* Data;

    ImageBuf();
    ~ImageBuf();
    void Clear();
    void CreateEmpty(int w, int h);
    void CreateFromCaptureGL(int x, int y, int w, int h);
    void SaveFile(const char* filename);
    void RemoveAlpha();
    void BlitTo(ImageBuf* dst, int src_x, int src_y, int dst_x, int dst_y, int w, int h);
    void FlipVertical();
    u32* GetPtr(int x, int y);
    u32 GetPixel(int x, int y) const;

    /*
    My function.
    Save and take a screenshot at bounds
    */
    static void capture(int x, int y, int width, int height, const std::string& fileName);
};





