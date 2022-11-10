#include "Player.h"
#include <iostream>

#include <fstream>

Player::Player()
{
	this->Position.x = (GetScreenWidth() / 2) - 25;
	this->Position.y = GetScreenHeight() - 25;		//hard coded to bottom of screen, update with half the height of the player sprite
}

Player::~Player()
{
	
}

void Player::Update()
{
	// check for movement
	// TODO:	constrain movement to the screen!
	//			implement "frogger-like" movement
	
	// move in the negative X direction
	if (IsKeyPressed(KEY_A))
	{
		Position.x -= 50;
	}

	// move in the positive X direction
	else if (IsKeyPressed(KEY_D))
	{
		Position.x += 50;
	}

	// move in the positive Y direction (down the screen)
	else if (IsKeyPressed(KEY_S))
	{
		Position.y += 50;
	}
	// move in the negative Y direction (up the screen)
	else if (IsKeyPressed(KEY_W))
	{
		Position.y -= 50;
	}
}

void Player::Draw()
{
	//test draw
	DrawCircleV(Position, 25.0f, color);

	//show the location of the center
	DrawCircleV(Position, 2.0f, RED);
}

void Player::RidingObject(ScrollingObject * go)
{
	this->Position.x += go->Direction.x;
}