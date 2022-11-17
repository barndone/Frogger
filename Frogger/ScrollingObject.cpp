#include "ScrollingObject.h"
#include <cstdlib>

//default constructor:
ScrollingObject::ScrollingObject()
{
	//default to moving towards the right
	Direction = { 1, 0 };
	//default to not a hazard
	isHazard = false;

	color = BROWN;
}

//2 param constructor:
//	TODO: implement as 3 parameter constructor with texture as third parameter
ScrollingObject::ScrollingObject(bool IsMovingRight, bool Hazard)
{
	//if IsMovingRight is true,
	if (IsMovingRight)
	{
		//	set direction to towards the positive X direction
		Direction = { 1 , 0 };
		//	set position to left side of screen
		//	y-component arbitrary for testing
		Position = {-200, 100};
	}

	//otherwise
	else
	{
		//	it should be moving towards the negative X direction
		Direction = { -1 , 0 };
		//	set position to the right side of the screen
		//	again, y-component is arbitrary for testing
		Position = { (float)GetScreenWidth() + Width , 200 };
	}

	//if it is a hazard:
	if (Hazard)
	{
		this->isHazard = Hazard;
		color = DARKGRAY;
		rec.width = 50;
	}
	else
	{
		this->isHazard = Hazard;
		color = BROWN;
		rec.width = 200;
	}
}

ScrollingObject::~ScrollingObject()
{

}

void ScrollingObject::Update()
{
	//update the position by adding the position to the direction
	Position = Vector2Add(Position, Direction);
	rec.x = Position.x;
	rec.y = Position.y;
	//check if it has come off of the LEFT side of the screen
	//	TODO: change the -10/10 to the width of the sprite (when sprites implemented)
	if (!isHazard)
	{
		if (Position.x < -200)
		{
			//if so, re-assign position
			Position.x = ((float)GetScreenWidth() + Width);
		}
		if (Position.x > GetScreenWidth() + Width)
		{
			Position.x = -200;
		}
	}
	else
	{
		if (Position.x < -50)
		{
			//if so, re-assign position
			Position.x = ((float)GetScreenWidth() + 50);
		}
		if (Position.x > GetScreenWidth() + 50)
		{
			Position.x = -50;
		}
	}

}

void ScrollingObject::Draw()
{
	//	check if the scrolling object is NOT a hazard
	if (!isHazard)
	{
		//if it isn't it's a log!
		DrawRectangle((int)Position.x, (int)Position.y, rec.width, 50, BROWN);
	}
	//	if it is a hazard
	else
	{
		//	it's a car and will kill our poor frog
		DrawRectangle((int)Position.x, (int)Position.y, 50, 50, DARKGRAY);
	}
}