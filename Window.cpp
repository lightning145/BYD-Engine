#include "Window.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

Window::Window(int width,int height,int vsync)
{
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
        printf("Failed to initialize GLFW!");
    }

    w = glfwCreateWindow(width, height, " ", NULL, NULL);
    Monitor = glfwGetPrimaryMonitor();
    mode = glfwGetVideoMode(Monitor);

    if (!w)
    {
        printf("Failed to initialize Window!");
        glfwTerminate();
    }

    glfwSetKeyCallback(w, key_callback);

    glfwMakeContextCurrent(w);

    glfwSwapInterval(vsync);
 
}

Window::~Window()
{
    glfwDestroyWindow(w);
    glfwTerminate();
}

void Window::PollEvents()
{
    glfwPollEvents();    
}

int Window::CloseWindow()
{
    return glfwWindowShouldClose(w);
}

void Window::error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    //if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        //glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void Window::SetTitle(const char* title)
{
    glfwSetWindowTitle(w,title);
}
    
HWND Window::GetHWND()
{
    return glfwGetWin32Window(w);
}

int Window::GetWidth()
{
    int width, height;
    glfwGetFramebufferSize(w, &width, &height);
    return width;
}

int Window::GetHeight()
{
    int width, height;
    glfwGetFramebufferSize(w, &width, &height);
    return height;
}

int Window::GetPosX()
{
    int x,y;
    glfwGetWindowPos(w,&x,&y);
    return x;
}

int Window::GetPosY()
{
    int x,y;
    glfwGetWindowPos(w,&x,&y);
    return y;
}