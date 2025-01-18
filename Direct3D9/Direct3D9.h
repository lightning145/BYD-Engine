#ifndef DIRECT3D9
#define DIRECT3D9

#include "../Graphics.h"
#include "../Window.h"

#include <d3dx9.h>

class Direct3D9
{
public:
    Direct3D9(Window* window,bool windowed);
    ~Direct3D9();

    IDirect3D9* d3d9;
    IDirect3DDevice9* device; 
    D3DCAPS9 caps;

private:

};


#endif