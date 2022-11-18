#include "LilyPad.h"

LilyPad::LilyPad()
{
	this->Position = { 0.0f , 0.0f };
	this->color = DARKGREEN;
}

LilyPad::LilyPad(float xPos, float yPos)
{
	this->Position = { xPos, yPos };
	this->color = DARKGREEN;
}

LilyPad::~LilyPad()
{

}

//Update will do nothing
void LilyPad::Update()
{
	//do nothing! for now?
}

void LilyPad::Draw()
{
	//position is from the top left corner of the grid-space
	//	convert position to the center of the circle (x+25, y+25)
	if (visible)
	{
		DrawCircle((int)Position.x + 25, (int)Position.y + 25, 25.0f, color);
		DrawCircleLines((int)Position.x + 25, (int)Position.y + 25, 25.0f, BLACK);
	}
}