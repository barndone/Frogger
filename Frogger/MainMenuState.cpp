#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
    startButton.x = GetScreenWidth() / 3;
    startButton.y = GetScreenHeight() / 2;
    startButton.width = 250;
    startButton.height = 50;
}
MainMenuState::~MainMenuState()
{

}
void MainMenuState::Start()
{

}
void MainMenuState::Update()
{

}
void MainMenuState::Draw()
{
    ClearBackground(BLACK);
    DrawText("Frog no SPLAT", GetScreenWidth() / 4, GetScreenHeight() / 4, 50, WHITE);
    DrawText("Start", startButton.x + 55, startButton.y + 2, 50, WHITE);
}

bool MainMenuState::StateShouldChange()
{
    return ClickedOnOption() && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}

GameStates MainMenuState::GetNextGameState()
{
    return GameLoop;
}

bool MainMenuState::ClickedOnOption()
{
    return CheckCollisionPointRec(GetMousePosition(), startButton);
}