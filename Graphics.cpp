
#include "OGL.h"

#include <iostream>

OGL* ogl;

Graphics::Graphics(Window* window,bool windowed,int Renderer)
{
    switch (Renderer)
    {
    case OpenGL:
        ogl = new OGL(window,windowed);
        GraphicsRenderer = OpenGL; 
        std::cout<<"Renderer: OpenGL 4.6\n";
        break;

    default:
        break;
    }
}

Graphics::~Graphics()
{
    delete ogl;

}

void Graphics::Clear(float r,float g,float b,float a)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(r,g,b,a);
}

void Graphics::Present(Window* window)
{
    switch (GraphicsRenderer)
    {

    case OpenGL:
        glfwSwapBuffers(window->w);
        break;

    default:
        break;
    }
}


void Graphics::DrawTriangle()
{
   
}