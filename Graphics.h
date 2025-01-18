#ifndef GRAPHICS_H
#define GRAPHICS_H

#define Direct3D 0
#define OpenGL 1 

#include "Window.h"

class Graphics
{
public:
    Graphics(Window* window,bool windowed,int Renderer);
    ~Graphics();

    void Clear(int r,int g,int b,int a);
    void Clear(float r,float g,float b,float a);

    void Present(Window* window);

private:
    int GraphicsRenderer;

};



#endif