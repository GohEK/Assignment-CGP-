#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class GameWindow
{
private:
	static GameWindow* sInstance;
	GameWindow();
	~GameWindow();
	HWND g_hWnd;
	WNDCLASS wndClass;
	HINSTANCE hInstance;
public:
	static GameWindow* getInstance();
	static void releaseInstance();
	void createWindow();
	bool windowIsRunning();
	HWND getG_HEWND();
};

