#pragma once
#include "raylib.h"
#include "Player.h"
#include "ScrollingObject.h"
#include "LilyPad.h"
#include "Background.h"
#include "UIObject.h"
#include <vector>

enum GameStates
{
	Menu,
	GameLoop,
	NextLevel,
	EndScreen
};

class GameState
{
public:
	GameState() {}
	virtual ~GameState() {}
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual bool StateShouldChange() = 0;
	virtual GameStates GetNextGameState() = 0;
};


