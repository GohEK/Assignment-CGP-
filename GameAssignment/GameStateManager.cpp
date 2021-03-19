#include "GameStateManager.h"
#include "Level1.h"

GameStateManager* GameStateManager::sInstance = 0;

GameStateManager* GameStateManager::getInstance()
{
	if (sInstance == 0)
	{
		sInstance = new GameStateManager();
	}
	return sInstance;
}

void GameStateManager::releaseInstance()
{
	if (sInstance != 0)
	{
		delete sInstance;
		sInstance = 0;
	}
}

GameStateManager::GameStateManager()
{
	Level1* level1 = new Level1();
	level1->init();

	gameStateList.push_back(level1);

	currentGameState = level1;

	gTimer = new GTimer();
	gTimer->init(60);
}

GameStateManager::~GameStateManager()
{
	delete gTimer;
	gTimer = NULL;

	for (int i = 0; i < gameStateList.size(); i++)
	{
		delete gameStateList[i];
		gameStateList[i] = NULL;
	}
}

void GameStateManager::changeGameState(int index)
{
	currentGameState = gameStateList[index];
}

void GameStateManager::update()
{
	int frameToUpdate = gTimer->framesToUpdate();

	currentGameState->update();

	for (int i = 0; i < frameToUpdate; i++)
	{
		currentGameState->fixedUpdate();
	}
}

void GameStateManager::draw()
{
	currentGameState->draw();
}
