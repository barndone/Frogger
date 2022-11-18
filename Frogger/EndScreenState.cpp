#include "EndScreenState.h"

EndScreenState::EndScreenState()
{

}
EndScreenState::~EndScreenState()
{

}
void EndScreenState::Start()
{

}
void EndScreenState::Update()
{

}
void EndScreenState::Draw()
{
	DrawText("Final Score", GetScreenWidth() / 3, GetScreenHeight() / 4, 50, BLACK);
}

bool EndScreenState::StateShouldChange()
{
    return false;
}

GameStates EndScreenState::GetNextGameState()
{
    return GameLoop;
}