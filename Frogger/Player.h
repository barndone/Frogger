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
	float Score = 0.0f;	// variable for score, default to 0f

	Color color = LIME;

	// Methods:

	// Override Method Declarations:
	void Draw() override;
	void Update() override;

	// Unique Method Declarations:
	//void Respawn();
	//void OnCollision(GameObject & go);
	void SetSprite();
	void RidingObject(ScrollingObject * go);
};