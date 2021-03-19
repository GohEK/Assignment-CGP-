#include "Background.h"
#include "GGraphic.h"

Background::Background()
{
	sprite = NULL;
	texture = NULL;
}

Background::~Background()
{
	sprite->Release();
	sprite = NULL;

	texture->Release();
	texture = NULL;
}

void Background::init(std::string backgroundPath, int backgroundWidth, int backgroundHeight)
{
	D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &sprite);
	D3DXCreateTextureFromFileA(GGraphic::getInstance()->d3dDevice, backgroundPath.c_str(), &texture);

	spriteRect.left = spriteRect.top = 0;
	spriteRect.right = backgroundWidth;
	spriteRect.bottom = backgroundHeight;
}

void Background::draw()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	sprite->Draw(texture, &spriteRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	sprite->End();
}
