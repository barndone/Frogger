#include "EndScreenState.h"

EndScreenState::EndScreenState(int score)
{
    Score += score;
}
EndScreenState::~EndScreenState()
{

}
void EndScreenState::Start()
{

}
void EndScreenState::Update()
{
    timer += GetFrameTime();
}
void EndScreenState::Draw()
{
	DrawText(TextFormat("Final Score: %i", Score), GetScreenWidth() / 4, GetScreenHeight() / 4, 50, BLACK);
    DrawText(TextFormat("Returning to menu in: %i", (int)(timeToWait-timer)), GetScreenWidth() / 4, GetScreenHeight() / 3, 30, BLACK);
}

bool EndScreenState::StateShouldChange()
{
    return timer > timeToWait;
}

GameStates EndScreenState::GetNextGameState()
{
    return Menu;
}