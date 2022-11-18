#include "NextLevelState.h"

NextLevelState::NextLevelState()
{

}
NextLevelState::~NextLevelState()
{

}
void NextLevelState::Start()
{

}
void NextLevelState::Update()
{
    timer += GetFrameTime();
}
void NextLevelState::Draw()
{
    DrawText("Current Score: ", GetScreenWidth() / 3, GetScreenHeight() / 4, 50, BLACK);
    DrawText(TextFormat("Time Until Next Level: %i", (int)(timeToWait - timer)), GetScreenWidth() / 4, GetScreenHeight() / 3, 30, BLACK);
}

bool NextLevelState::StateShouldChange()
{
    return timer > timeToWait;
}

GameStates NextLevelState::GetNextGameState()
{
    return GameLoop;
}