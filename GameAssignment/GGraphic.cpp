#include "GGraphic.h"

GGraphic* GGraphic::sInstance = NULL;

GGraphic* GGraphic::getInstance()
{
	if (sInstance == NULL)
	{
		sInstance = new GGraphic();
	}

	return sInstance;
}

void GGraphic::releaseInstance()
{
	if (sInstance != NULL)
	{
		delete sInstance;
		sInstance = NULL;
	}
}

GGraphic::GGraphic()
{
	IDirect3D9 * direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);

	ZeroMemory(&d3dPP, sizeof(d3dPP));

	d3dPP.Windowed = true;
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dPP.BackBufferCount = 1;
	d3dPP.BackBufferWidth = 800;
	d3dPP.BackBufferHeight = 600;
	d3dPP.hDeviceWindow = GameWindow::getInstance()->getG_HEWND();

	HRESULT hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, GameWindow::getInstance()->getG_HEWND(), D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);
}

GGraphic::~GGraphic()
{
	d3dDevice->Release();
	d3dDevice = NULL;
}

void GGraphic::begin()
{
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(135, 206, 235), 1.0f, 0);
	d3dDevice->BeginScene();
}

void GGraphic::end()
{
	d3dDevice->EndScene();
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

