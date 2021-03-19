#pragma once
#include <string>
#include <d3dx9.h>

class Background
{
private:
	std::string backgroundPath;
	LPDIRECT3DTEXTURE9 texture;
	LPD3DXSPRITE sprite;
	RECT spriteRect;
public:
	Background();
	~Background();
	void init(std::string backgroundPath, int backgroundWidth, int backgroundHeight);
	void draw();
};

