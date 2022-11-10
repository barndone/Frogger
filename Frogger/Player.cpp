#include "Player.h"
#include <iostream>

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
	DrawCircleV(Position, 25.0f, PURPLE);
}

void Player::RidingObject(ScrollingObject* go)
{
	std::cout << "the frog is in fact, on a log" << std::endl;
	Position.x += go->Direction.x;
}