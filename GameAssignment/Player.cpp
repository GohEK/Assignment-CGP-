#include "Player.h"
#include "GGraphic.h"
#include "GInput.h"

Player::Player()
{
	sprite = NULL;
	texture = NULL;
}

Player::~Player()
{
	sprite->Release();
	sprite = NULL;

	texture->Release();
	texture = NULL;
}

void Player::init()
{
	D3DXCreateSprite(GGraphic::getInstance()->d3dDevice, &sprite);
	D3DXCreateTextureFromFileEx(GGraphic::getInstance()->d3dDevice, "image/character.png", D3DX_DEFAULT, D3DX_DEFAULT,
		D3DX_DEFAULT, NULL, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255, 255, 255),
		NULL,
		NULL,
		&texture);

	characterSize.x = 32;
	characterSize.y = 48;

	characterCurrentFrame = 0;
	characterSpriteRect.left = 0;
	characterSpriteRect.top = 0;
	characterSpriteRect.right = characterSpriteRect.left + characterSize.x;
	characterSpriteRect.bottom = characterSpriteRect.top + characterSize.y;

	scaling.x = 1.5f;
	scaling.y = 1.5f;

	animationTimer = 0;
	animationRate = 1.0f / 4;
	speed = 100.0f;
	animationRow = 0;
	isCharacterMoving = false;
	direction.x = 0;
	direction.y = 1;
	position.x = 50;
	position.y = 200;
}

void Player::update()
{
	if (GInput::getInstance()->isKeyDown(DIK_A))
	{
		animationRow = 1;
		isCharacterMoving = true;
		direction.x = -1;
		direction.y = 0;
	}
	else if (GInput::getInstance()->isKeyDown(DIK_W))
	{
		animationRow = 3;
		isCharacterMoving = true;
		direction.x = 0;
		direction.y = -1;
	}
	else if (GInput::getInstance()->isKeyDown(DIK_S))
	{
		animationRow = 0;
		isCharacterMoving = true;
		direction.x = 0;
		direction.y = 1;
	}
	else if (GInput::getInstance()->isKeyDown(DIK_D))
	{
		animationRow = 2;
		isCharacterMoving = true;
		direction.x = 1;
		direction.y = 0;
	}
	else
	{
		characterCurrentFrame = 0;
		isCharacterMoving = false;
	}
}

void Player::fixedUpdate()
{
	if (isCharacterMoving)
	{
		animationTimer += 1 / 60.0f;

		D3DXVECTOR2 velocity = direction * (speed / 60.0f);
		position += velocity;
	}
	if (animationTimer >= animationRate)
	{
		animationTimer -= animationRate;
		characterCurrentFrame++;
		characterCurrentFrame %= 3;
	}
	characterSpriteRect.left = characterSize.x * characterCurrentFrame;
	characterSpriteRect.top = animationRow * characterSize.y;
	characterSpriteRect.right = characterSpriteRect.left + characterSize.x;
	characterSpriteRect.bottom = characterSpriteRect.top + characterSize.y;

	D3DXMatrixTransformation2D(&mat, NULL, 0.0, &scaling, NULL, NULL, &position);
}

void Player::draw()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	sprite->SetTransform(&mat);

	sprite->Draw(texture, &characterSpriteRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	sprite->End();
}