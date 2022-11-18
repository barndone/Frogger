#include "MainMenuState.h"

MainMenuState::MainMenuState()
{

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
    
}

bool MainMenuState::StateShouldChange()
{
    return false;
}

GameStates MainMenuState::GetNextGameState()
{
    return GameLoop;
}