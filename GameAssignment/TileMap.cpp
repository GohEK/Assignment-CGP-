#include "TileMap.h"
#include <iostream>
#include <fstream>
#include <string>

#define MAX_MAP_Y 800;
#define MAX_MAP_X 600;

TileMap::TileMap()
{
	sprite = NULL;
	texture = NULL;
}

TileMap::~TileMap()
{
	sprite->Release();
	sprite = NULL;

	texture->Release();
	texture = NULL;
}

void TileMap::init()
{
	D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &sprite);
	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "image/rock.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255),
		NULL,
		NULL,
		&texture);
}

void TileMap::loadmap(string name)
{
	ifstream levelFile(name.c_str());
	string line;

	if (levelFile)
	{

	}
	//int x, y;

	//FILE *fp;
	//fp = fopen("map/level1.txt", "rb");

	///* if we can't open the map then exit */

	//if (fp == NULL) {

	//	printf("failed to open map %s\n", name);

	//	exit(1);

	//}

	///* read the data from the file into the map */

	//for (y = 0; y < 20; y++) {

	//	for (x = 0; x < 20; x++) {

	//		fscanf(fp, "%d", &map[y][x]); //map[][] is a 2d array

	//	}

	//}

	///* close the file afterwards */

	//fclose(fp);
}

void TileMap::drawMap()
{
	int x, y;
	int tileHeight = 32, tileWidth = 32;

	RECT clipwindow;

	/* draw the map */

	for (y = 0; y < 20; y++) {

		for (x = 0; x < 20; x++) {

			if (map[y][x] != 0) {

				clipwindow.top = (map[y][x] - 1)*(tileHeight);//height

				clipwindow.left = 0;

				clipwindow.bottom = clipwindow.top + tileWidth;//width

				clipwindow.right = clipwindow.left + tileHeight;//height

				//render the tile at correct position

				position.x = x * tileWidth;

				position.y = y * tileHeight;

				D3DXMatrixTransformation2D(&mat, NULL, 0.0, NULL, NULL, NULL, &position);

				sprite->Begin(D3DXSPRITE_ALPHABLEND);
				sprite->SetTransform(&mat);
				sprite->Draw(texture, &clipwindow, NULL, NULL, D3DCOLOR_XRGB(255, 255,
					255));

				sprite->End();

			}

		}

	}
}
