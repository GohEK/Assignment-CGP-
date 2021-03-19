#pragma once
#include <dinput.h>
#include <d3dx9.h>

class GInput
{
private:
	static GInput* sInstance;
	LPDIRECTINPUTDEVICE8  dInputKeyboardDevice;
	LPDIRECTINPUT8 dInput;
	LPDIRECTINPUTDEVICE8 mouseDevice;
	DIMOUSESTATE mouseState;
	BYTE  diKeys[256];
	HRESULT result;
	GInput();
	~GInput();

public:
	D3DXVECTOR2 mousePosition;
	static GInput* getInstance();
	static void releaseInstance();
	void update();
	bool isKeyDown(int index);
	bool isButtonDown(int index);
};

