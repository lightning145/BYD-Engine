#ifndef WINDOW_H
#define WINDOW_H

#include "main.h"

#include <windows.h>

class Window
{
private:
    static void error_callback(int error, const char* description);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

public:
    Window(int width,int height,int vsync);
    ~Window();

    GLFWwindow *w;
    GLFWmonitor* Monitor;
    const GLFWvidmode* mode;

    void PollEvents();
    int CloseWindow();
    
    void SetTitle(const char* title);

    int GetWidth();
    int GetHeight();

    int GetPosX();
    int GetPosY();
    
    HWND GetHWND();
};

#endif