#pragma once

#include "GameState.h"
#include "GameStateLoop.h"

class MainMenuState : public GameState
{
public:
	MainMenuState();
	~MainMenuState() override;
	void Start() override;
	void Draw() override;
	void Update() override;
	bool StateShouldChange() override;
	GameStates GetNextGameState() override;

protected:
	Rectangle startButton = {};

	bool ClickedOnOption();
};