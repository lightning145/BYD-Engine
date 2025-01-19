
#include "Graphics.h"
#include "Triangle.h"
#include "Cube.h"

int main()
{
    Window window = Window(1280,720,0);
    Graphics gx = Graphics(&window,1,OpenGL);
    Triangle tri = Triangle();
    Cube c = Cube();
    Cube c2 = Cube();

    window.SetTitle("Hello, GLFW!");
    
    while (!window.CloseWindow())
    {
        gx.Clear(1.0f,1.0f,1.0f,1.0f);

           c.Draw(-0.9f,0.0f,0.0f);
           c2.Draw(0.9f,0.0f,0.0f);

        gx.Present(&window);
        window.PollEvents();
    }
    
    return 0;
}

