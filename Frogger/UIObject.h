#pragma once
#include "GameObject.h"
#include "Player.h"

class UIObject : public GameObject
{
public:
	UIObject();
	UIObject(Player* player, int score, float timer, float timeLimit, int x, int y);
	~UIObject() override;

protected:
	Player* playerObj = nullptr;
	float Timer = 0.0;
	const int LineBuffer = 15;
	float TimeLimit = 0.0;
	int Score = 0;

public:
	// Override Method Declarations:
	void Draw() override;
	void Update() override;
	void Update(float timer);
};