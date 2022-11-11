#include "Background.h"

//	default constructor:
Background::Background()
{

}

//	2-param constructor:
Background::Background(bool isWater, bool isRoad, float x, float y)
{
	//assignt the isWater bool to the background object
	Water = isWater;
	//assign the isRoad bool to the background object
	Road = isRoad;
	//set the position of the background object using the passed x and y components
	this->SetPosition(x, y);
}

Background::~Background()
{

}

bool Background::GetHazard()
{
	return Water;
}

bool Background::GetRoad()
{
	return Road;
}

void Background::Update()
{

}

void Background::Draw()
{
	if (Water)
	{
		DrawRectangle(Position.x, Position.y, 50, 50, SKYBLUE);
	}
	else
	{
		if (Road)
		{
			DrawRectangle(Position.x, Position.y, 50, 50, BLACK);
		}
		else
		{
			DrawRectangle(Position.x, Position.y, 50, 50, LIGHTGRAY);
		}
	}
}
