#include "OGL.h"

OGL::OGL(Window* window,int windowed)
{
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
    switch (windowed)
    {
    case 1:
        
        break;

    case 0:
        glfwSetWindowMonitor(window->w,
        window->Monitor,0,0,
        window->mode->width,
        window->mode->height,
        window->mode->refreshRate);    
        break;    
    
    default:
        break;
    }
    
}
OGL::~OGL()
{

}