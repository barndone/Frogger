#include "Player.h"
#include <iostream>

#include <fstream>

Player::Player()
{
	this->Position.x = (GetScreenWidth() / 2);		//hard coded to the half-way point of the x-axis component of the window
	this->Position.y = GetScreenHeight() - 75;		//hard coded to bottom of screen, update with half the height of the player sprite
	this->color = LIME;

	this->RespawnPos = Position;
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
		rec.x -= 50;
	}
	// move in the positive X direction
	else if (IsKeyPressed(KEY_D))
	{
		Position.x += 50;
		rec.x += 50;
	}
	// move in the positive Y direction (down the screen)
	else if (IsKeyPressed(KEY_S))
	{
		Position.y += 50;
		rec.y += 50;
	}
	// move in the negative Y direction (up the screen)
	else if (IsKeyPressed(KEY_W))
	{
		Position.y -= 50;
		rec.y -= 50;
	}

	if (Position.x < 0 || Position.x > GetScreenWidth() ||
		Position.y < 0 || Position.y > GetScreenHeight() - 50)
	{
		Respawn();
	}
}

void Player::Draw()
{
	//test draw
	DrawCircleV(Position, 25.0f, color);
}

void Player::RidingObject(ScrollingObject * go)
{
	this->Position.x += (go->Direction.x * go->Speed);
}

void Player::Respawn()
{
	Lives--;
	if (Lives < 0)
	{
		//GAME OVER
	}
	else
	{
		//	also remove one of the UI elements for lives
		//	when we add that
		//	oh god there's so much to do and so little time
		Position = RespawnPos;
		rec.x = RespawnPos.x;
		rec.y = RespawnPos.y;
	}
}