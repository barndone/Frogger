#pragma once

#include "GameObject.h"

class ScrollingObject : public GameObject
{
	// Constructor
public:
	ScrollingObject();
	ScrollingObject(bool IsMovingRight, bool isHazard, float speed);

		//
		// if IsMovingRight bool is true:
		// move to right
		//		direction -> right
		//		position -> left side of screen
		// else move to left
		//		direction -> left
		//		position -> right side of screen
		// assign isHazard
		//
	
	~ScrollingObject() override;
	// Variables:
public:
	Vector2 Direction = { 0, 0 };		// Stores the direction the ScrollingObject is moving
	bool isHazard = false;
	float Speed = 1.0f;

public:
	// Methods:
	// Override Method Declarations:
	void Draw() override;
	void Update() override;
	// Unique Method Declarations:
};