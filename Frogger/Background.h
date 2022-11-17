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
	bool GetActive();
	void Draw() override;
	void Update() override;

	void SetActive(bool val);

	//	Variables:
protected:
	bool Water = false;
	bool Road = false;
	bool Active = true;


};