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
ScrollingObject::ScrollingObject(bool IsMovingRight, bool Hazard, float speed)
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
	this->Speed = speed;
}

ScrollingObject::~ScrollingObject()
{

}

void ScrollingObject::Update()
{
	//movement is dependant on whther it is a hazard or not:
	//	cars move faster in the "fast lane" (and faster than logs in general)
	//	logs move faster in one direction than the other (for this case towards the RIGHT)
	if (!isHazard)
	{
		if (Direction.x == 1)
		{
			Position = Vector2Add(Position, Vector2Scale(Direction, Speed));
		}
		else
		{
			Position = Vector2Add(Position, Vector2Scale(Direction, Speed));
		}
		//screen wrap check:
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
		if (Direction.x == 1)
		{
			Position = Vector2Add(Position, Vector2Scale(Direction, Speed));
		}
		else
		{
			Position = Vector2Add(Position, Vector2Scale(Direction, Speed));
		}
		//screen wrap check:
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
	rec.x = Position.x;
	rec.y = Position.y;
}

void ScrollingObject::Draw()
{
	//	check if the scrolling object is NOT a hazard
	if (!isHazard)
	{
		//if it isn't it's a log!
		DrawRectangle((int)Position.x, (int)Position.y + 5, rec.width, 40, BROWN);
	}
	//	if it is a hazard
	else
	{
		//	it's a car and will kill our poor frog
		DrawRectangle((int)Position.x, (int)Position.y + 5, 50, 40, DARKGRAY);
	}
}