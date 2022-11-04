#include "Player.h"

Player::Player()
{
	this->Position.x = 50;
	this->Position.y = 50;
}

Player::~Player()
{
	
}

void Player::Update()
{
	//check for movement
	// move in the negative X direction
	if (IsKeyDown(KEY_A))
	{
		Position.x -= 1;
	}

	// move in the positive X direction
	if (IsKeyDown(KEY_D))
	{
		Position.x += 1;
	}

	// move in the positive Y direction (down the screen)
	if (IsKeyDown(KEY_S))
	{
		Position.y += 1;
	}
	// move in the negative Y direction (up the screen)
	if (IsKeyDown(KEY_W))
	{
		Position.y -= 1;
	}
	//check for collision with scrolling object
	//	check what kind of scrolling object
}

void Player::Draw()
{
	//test draw
	DrawCircleV(Position, 20.0f, PURPLE);
}