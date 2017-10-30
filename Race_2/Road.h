#pragma once
#include "stdafx.h"

using namespace std;

class Road
{
private:
	vector<int> coordinateBlocksX;
	vector<int> coordinateBlocksY;
	int coordinatePlayerX;
	int coordinatePlayerY;
public:
	Road();
	char roadPlayer[HEIGHT_ROAD][WIDTH_ROAD];
	void searchCoordinatePlayer();

	void turnLeft();
	void turnRight();
	void turnUp();
	void turnDown();

	void setBlockOppositeLine();
	void setBlockRoadLine();

	void viewRoad();
	void clearRoad();
    
	bool isFail(CAR_CONTROL carControll);
	~Road();
};

