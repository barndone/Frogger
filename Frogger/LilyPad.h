#pragma once

#include "GameObject.h"

class LilyPad : public GameObject
{
	//constructor / deconstructor
public:
	LilyPad();
	LilyPad(float xPos, float yPos);
	~LilyPad() override;

public:
	bool activated = false;

	// Override Method Declarations:
	void Draw() override;
	void Update() override;
};