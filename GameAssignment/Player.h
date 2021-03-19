#pragma once
#include <d3dx9.h>

class Player
{
private:
	LPDIRECT3DTEXTURE9 texture;
	LPD3DXSPRITE sprite;
	RECT characterSpriteRect;
	D3DXMATRIX mat;
	D3DXVECTOR2 spriteCentre;
	D3DXVECTOR2 position;
	D3DXVECTOR2 scaling;
	int characterCurrentFrame;
	D3DXVECTOR2 characterSize;
	float animationRate;
	float animationTimer;
	int animationRow;
	bool isCharacterMoving;
	float speed;
	D3DXVECTOR2 direction;
	
public:
	Player();
	~Player();
	void init();
	void update();
	void fixedUpdate();
	void draw();
};

