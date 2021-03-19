#include "GInput.h"
#include"GameWindow.h"

GInput* GInput::sInstance = NULL;

GInput* GInput::getInstance()
{
	if (sInstance == NULL)
	{
		sInstance = new GInput();
	}

	return sInstance;
}

void GInput::releaseInstance()
{
	if (sInstance != NULL)
	{
		delete sInstance;
		sInstance = NULL;
	}
}

GInput::GInput()
{
	//	Create the Direct Input object.
	DirectInput8Create(GetModuleHandle(NULL), 0x0800, IID_IDirectInput8, (void**)&dInput, NULL);

	//	Direct Input keyboard device.
	dInput->CreateDevice(GUID_SysKeyboard, &dInputKeyboardDevice, NULL);
	dInputKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	dInputKeyboardDevice->SetCooperativeLevel(GameWindow::getInstance()->getG_HEWND(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	dInput->CreateDevice(GUID_SysMouse, &mouseDevice, NULL);
	mouseDevice->SetDataFormat(&c_dfDIMouse);
	mouseDevice->SetCooperativeLevel(GameWindow::getInstance()->getG_HEWND(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	//DIMOUSESTATE prevMouseState;
	ZeroMemory(diKeys, sizeof(diKeys));
	ZeroMemory(diKeys, sizeof(mouseState));
}

void GInput::update() {
	result = dInputKeyboardDevice->GetDeviceState(256, diKeys);
	if (FAILED(result))
	{
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
		{
			dInputKeyboardDevice->Acquire();
		}
	}

	result = mouseDevice->GetDeviceState(sizeof(mouseState), (LPVOID)&mouseState);
	if (FAILED(result))
	{
		if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED))
		{
			mouseDevice->Acquire();
		}
	}

	mousePosition.x += mouseState.lX;
	mousePosition.x = max(mousePosition.x, 0);
	mousePosition.x = min(mousePosition.x, 800);
	mousePosition.y += mouseState.lY;
	mousePosition.y = max(mousePosition.y, 0);
	mousePosition.y = min(mousePosition.y, 600);
}

bool GInput::isKeyDown(int index)
{
	return diKeys[index] & 0x80;
}

bool GInput::isButtonDown(int index)
{
	return mouseState.rgbButtons[index] & 0x80;
}

GInput::~GInput()
{
	dInputKeyboardDevice->Unacquire();
	dInputKeyboardDevice->Release();
	dInputKeyboardDevice = NULL;

	//	Release DirectInput.

	mouseDevice->Unacquire();
	mouseDevice->Release();
	mouseDevice = NULL;

	dInput->Release();
	dInput = NULL;
}

