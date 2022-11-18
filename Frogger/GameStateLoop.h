#pragma once

#include "GameState.h"

class GameStateLoop : public GameState
{
public:
	GameStateLoop();
	~GameStateLoop() override;
	void Start() override;
	void Draw() override;
	void Update() override;
	bool StateShouldChange() override;
	GameStates GetNextGameState() override;
	int GetScore();
};
