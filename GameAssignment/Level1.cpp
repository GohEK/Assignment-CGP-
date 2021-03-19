#include "Level1.h"
#include "GInput.h"
#include "GameStateManager.h"

Level1::Level1()
{
	
}

Level1::~Level1()
{

}

void Level1::init()
{
	background = new Background();
	background->init("image/background1.jpg", 800, 600);
	map = new TileMap();
	map->init();
	player = new Player();
	player->init();
}

void Level1::update()
{
	player->update();
}

void Level1::fixedUpdate()
{
	player->fixedUpdate();
}

void Level1::draw()
{
	background->draw();
	map->loadmap("map/level1.txt");
	//map->drawMap();
	player->draw();
}

void Level1::release()
{
	delete background;
	delete map;
	delete player;
}
