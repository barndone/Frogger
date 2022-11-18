#pragma once

#include "GameState.h"
#include "GameStateLoop.h"

class EndScreenState : public GameState
{
public:
	EndScreenState();
	~EndScreenState() override;
	void Start() override;
	void Draw() override;
	void Update() override;
	bool StateShouldChange() override;
	GameStates GetNextGameState() override;
};
