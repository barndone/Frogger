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
		Direction = { 1 , 0 };
		Position = { 100 , 100 };
	}
	else
	{

	}
}

ScrollingObject::~ScrollingObject()
{

}

void ScrollingObject::Update()
{

}