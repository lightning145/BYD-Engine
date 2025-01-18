
#include "Graphics.h"

int main()
{
    Window* window = new Window(1280,720,0);
    Graphics* gx = new Graphics(window,true,OpenGL);

    window->SetTitle("Hello, GLFW!");
    
    while (!window->CloseWindow())
    {
        gx->Clear(1.0f,1.0f,1.0f,1.0f);

        gx->Present(window);

        window->PollEvents();
    }
    
    delete gx;
    delete window;
    return 0;
}

