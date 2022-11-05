#include "ScrollingObject.h"

ScrollingObject::ScrollingObject()
{
	Direction = { 1, 0 };
	isHazard = false;
}

ScrollingObject::ScrollingObject(bool IsMovingRight, bool isHazard)
{
	if (IsMovingRight)
	{
		Direction = { -1 , 0 };
		Position = { 100 , 100 };
	}
	else
	{
		Direction = { 1 , 0 };
		Position = { 0 , 100 };
	}
}

ScrollingObject::~ScrollingObject()
{

}

void ScrollingObject::Update()
{
	Position = Vector2Add(Position, Direction);
}

void ScrollingObject::Draw()
{
	DrawRectangle((int)Position.x, (int)Position.y, 10,10,BLUE);
}