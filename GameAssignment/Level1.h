#pragma once
#include "GGraphic.h"
#include "GameState.h"
#include "Background.h"
#include "Player.h"
#include "TileMap.h"

class Level1 : public GameState
{
private:
	Background *background;
	TileMap *map;
	Player *player;
public:
	Level1();
	~Level1();
	void init();
	void update();
	void fixedUpdate();
	void draw();
	void release();
};

