#pragma once
#include "GameWindow.h"
#include <d3d9.h>
#include <d3dx9.h>

class GGraphic
{
private:
	D3DPRESENT_PARAMETERS d3dPP;
	IDirect3D9* direct3D9;
	static GGraphic* sInstance;
	GGraphic();
	~GGraphic();
public:
	IDirect3DDevice9* d3dDevice;
	static GGraphic* getInstance();
	static void releaseInstance();
	void begin();
	void end();
};

