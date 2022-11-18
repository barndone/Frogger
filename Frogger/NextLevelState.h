#pragma once

#include "GameState.h"
#include "GameStateLoop.h"

class NextLevelState : public GameState
{
public:
	float timer = 0.0f;
	float timeToWait = 5.0f;

	NextLevelState();
	~NextLevelState() override;
	void Start() override;
	void Draw() override;
	void Update() override;
	bool StateShouldChange() override;
	GameStates GetNextGameState() override;
};