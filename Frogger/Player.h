#pragma once

#include "GameObject.h"
#include "ScrollingObject.h"

class Player : public GameObject
{
	// Constructors:
public:
	Player();
	~Player() override;

	// Variables:
public:
	int Lives = 3;		// variable for lives, default to 3
	int Score = 0;	// variable for score, default to 0f

	Vector2 RespawnPos = { 0.0f , 0.0f };

	// Methods:

	// Override Method Declarations:
	void Draw() override;
	void Update() override;

	// Unique Method Declarations:
	void Respawn();
	void SetSprite();
	void RidingObject(ScrollingObject * go);
};