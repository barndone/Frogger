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
		Position.x = x;
		Position.y = y;
	};

	void SetPosition(Vector2 V)
	{
		Position = V;
	};

	void SetColor(Color newColor)
	{
		color = newColor;
	};

	// Variables:
protected:
	Vector2 Position = { 0 , 0 };
	Color color = BLACK;

	// Methods:
	// Draw() abstraction for child gameobjects
	virtual void Draw() = 0;

	// Update() abstraction for child gameobjects
	virtual void Update() = 0;
};