#pragma once

#include "GameState.h"
#include "GameStateLoop.h"

class NextLevelState : public GameState
{
public:
	float timer = 0.0f;
	float timeToWait = 5.0f;

protected:
	int Score = 0;

public:
	NextLevelState(int score);
	~NextLevelState() override;
	void Start() override;
	void Draw() override;
	void Update() override;
	bool StateShouldChange() override;
	GameStates GetNextGameState() override;
};