#include "Direct3D9.h"

Direct3D9::Direct3D9(Window* window,bool windowed)
{
    d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

    d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

    D3DPRESENT_PARAMETERS d3dpp;
    d3dpp.BackBufferWidth = window->GetWidth();
    d3dpp.BackBufferHeight = window->GetHeight();
    d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
    d3dpp.BackBufferCount = 1;
    d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
    d3dpp.MultiSampleQuality = 0;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.hDeviceWindow = window->GetHWND();
    d3dpp.Windowed = windowed;
    d3dpp.EnableAutoDepthStencil = true;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
    d3dpp.Flags = 0;
    d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
    d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

    d3d9->CreateDevice(
        D3DADAPTER_DEFAULT, 
		D3DDEVTYPE_HAL,      
		window->GetHWND(),            
		D3DCREATE_HARDWARE_VERTEXPROCESSING,            
	    &d3dpp,        
	    &device); 
}

Direct3D9::~Direct3D9()
{
    d3d9->Release();
    device->Release();
}