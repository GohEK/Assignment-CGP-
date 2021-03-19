#include "GameWindow.h"

GameWindow* GameWindow::sInstance = NULL;

GameWindow* GameWindow::getInstance()
{
	if (sInstance == NULL)
	{
		sInstance = new GameWindow();
	}

	return sInstance;
}

void GameWindow::releaseInstance()
{
	if (sInstance != NULL)
	{
		delete sInstance;
		sInstance = NULL;
	}
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	///*case WM_KEYDOWN:
	//	printf("%d\n", wParam);
	//	if (wParam == 27)
	//	{
	//		PostQuitMessage(0);
	//	}
	//	PWindow::keyPress = wParam;
	//	break;
	//case WM_KEYUP:
	//	PWindow::keyPress = 0;
	//	break;
	//case WM_MOUSEMOVE:
	//	PWindow::mouseX = LOWORD(lParam);
	//	PWindow::mouseY = HIWORD(lParam);*/
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

GameWindow::GameWindow()
{
	g_hWnd = NULL;
	hInstance = GetModuleHandle(NULL);
}
GameWindow::~GameWindow()
{
	UnregisterClass(wndClass.lpszClassName, hInstance);
}

void GameWindow::createWindow()
{
	ZeroMemory(&wndClass, sizeof(wndClass));

	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACKONWHITE);
	wndClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	wndClass.lpfnWndProc = WindowProcedure;
	wndClass.lpszClassName = "My Window";
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, "My Window's Name", WS_OVERLAPPEDWINDOW, 0, 100, 800, 600, NULL, NULL, hInstance, NULL);
	ShowWindow(g_hWnd, 1);
}
bool GameWindow::windowIsRunning()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{

		if (msg.message == WM_QUIT)
			break;

		TranslateMessage(&msg);

		DispatchMessage(&msg);
	}

	return msg.message != WM_QUIT;
}
HWND GameWindow::getG_HEWND()
{
	return g_hWnd;
}

