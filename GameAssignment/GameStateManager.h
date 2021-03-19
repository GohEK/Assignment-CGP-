#pragma once
#include <vector>
#include "GameState.h"
#include "GTimer.h"

class GameStateManager
{
private:
	GameStateManager();
	~GameStateManager();
	static GameStateManager* sInstance;
	std::vector<GameState*> gameStateList;
	GTimer* gTimer = NULL;
public:
	enum GAMESTATENAME {
		LEVEL_1,
		LEVEL_2
	};
	static GameStateManager* getInstance();
	static void releaseInstance();
	GameState* currentGameState;
	void changeGameState(int index);

	void update();
	void draw();
};

