#pragma once

#include "raylib.h"
#include "raymath.h"

class GameObject
{
	// Constructors:
public:
	GameObject() {}
	virtual ~GameObject() {}

	Vector2 GetPosition()
	{
		return Position;
	};

	float GetXPos()
	{
		return Position.x;
	};

	float GetYPos()
	{
		return Position.y;
	};

	void SetPosition(float x, float y)
	{

	};

	// Variables:
protected:
	Vector2 Position = { 0 , 0 };

	// Methods:
	// Draw() abstraction for child gameobjects
	virtual void Draw() = 0;

	// Update() abstraction for child gameobjects
	virtual void Update() = 0;
};