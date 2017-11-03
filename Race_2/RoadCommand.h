#pragma once
#include "Road.h"

class RoadCommand :
	public Road
{
public:
	RoadCommand();

	void turnLeft();
	void turnRight();
	void turnDown();
	void turnUp();

	void setBlockOppositeLine();
	void setBlockRoadLine();
	void setDifficult(int _difficult);
	void setSizeRoad(int _height, int _width);

	void viewRoad();
	void clearRoad();

	bool isFail(global::CAR_CONTROL carControll);

	~RoadCommand();
};

