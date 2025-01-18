#include "Direct3D9/Direct3D9.h"
#include "OpenGL4.6/OGL.h"

Direct3D9* d3d9;
OGL* ogl;

Graphics::Graphics(Window* window,bool windowed,int Renderer)
{
    switch (Renderer)
    {
    case Direct3D:
        d3d9 = new Direct3D9(window,windowed);
        GraphicsRenderer = Direct3D;
        break;
    
    case OpenGL:
        ogl = new OGL(window,windowed);
        GraphicsRenderer = OpenGL; 
        break;

    default:
        break;
    }
}

Graphics::~Graphics()
{
    delete ogl;
    delete d3d9;
}

void Graphics::Clear(int r,int g,int b,int a)
{

    d3d9->device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(r,g,b,a), 1.0f, 0);

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
    case Direct3D:
        d3d9->device->Present(0,0,0,0);
        break;

    case OpenGL:
        glfwSwapBuffers(window->w);
        break;

    default:
        break;
    }
}