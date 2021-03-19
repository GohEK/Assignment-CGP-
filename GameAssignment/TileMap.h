#pragma once
#include<vector>
#include "GGraphic.h"

using namespace std;

class TileMap
{
private:
	LPDIRECT3DTEXTURE9 texture;
	LPD3DXSPRITE sprite;
	D3DXMATRIX mat;
	D3DXVECTOR2 position;
	vector<vector<int>> map;
public:
	TileMap();
	~TileMap();
	void init();
	void loadmap(string name);
	void drawMap();
};

