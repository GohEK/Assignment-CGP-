#include "GameWindow.h"
#include "GGraphic.h"
#include "GInput.h"
#include"GameStateManager.h"

int main()
{
	GameWindow* gameWindow = GameWindow::getInstance();
	gameWindow->createWindow();
	GGraphic* graphic = GGraphic::getInstance();
	GInput* gInput = GInput::getInstance();
	GameStateManager* gameStateManager = GameStateManager::getInstance();
	
	while (gameWindow->windowIsRunning())
	{
		gInput->update();

		gameStateManager->update();

		graphic->begin();

		gameStateManager->draw();

		graphic->end();
	}

	gameStateManager->releaseInstance();
	gInput->releaseInstance();
	graphic->releaseInstance();
	gameWindow->releaseInstance();
	return 0;
}