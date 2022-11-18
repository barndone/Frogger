#include "UIObject.h"

UIObject::UIObject()
{

}

UIObject::UIObject(Player* player, int score, float timer, float timeLimit, int x, int y)
{
	playerObj = player;
	rec.width = GetScreenWidth() - 100;
	rec.x = x;
	rec.y = y;
	Timer = timer;
	TimeLimit = timeLimit;
	Score = score;
}

UIObject::~UIObject()
{

}

void UIObject::Update()
{

}

void UIObject::Update(float timer)
{
	Timer = timer;
}

void UIObject::Draw()
{
	//draw score here (placeholder)
	//DrawText(TextFormat("Score: %i", Score), rec.x, rec.y, 14, BLACK);
	//draw lives here (placeholder)
	//DrawText(TextFormat("Lives: %i", playerObj->Lives), rec.x, rec.y + LineBuffer, 14, BLACK);
	//draw timer here
	DrawRectangle(rec.x, rec.y + (2 * LineBuffer), rec.width * ((TimeLimit - Timer) / TimeLimit), LineBuffer, BLACK);
	
}