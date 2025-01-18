#include "OGL.h"

OGL::OGL(Window* window,bool windowed)
{
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
    switch (windowed)
    {
    case true:
        
        break;

    case false:
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