#pragma once

#include "GameObject.h"

class Background : public GameObject
{
	//	constructors:
public:
	Background();
	Background(bool isWater, bool isRoad, float xPos, float yPos);
	~Background() override;

	bool GetHazard();
	bool GetRoad();

	void Draw() override;
	void Update() override;

	//	Variables:
protected:
	bool Water = false;
	bool Road = false;


};