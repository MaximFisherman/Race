#ifndef __ROAD_H__
#define __ROAD_H__

#include "stdafx.h"

using namespace std;

class Road
{
public:
	Road();
	void initializationRoad();

	void searchCoordinatePlayer();

	void turnLeft();
	void turnRight();
	void turnUp();
	void turnDown();

	void setBlockOppositeLine();
	void setBlockRoadLine();

	void viewRoad();
	void clearRoad();
    
	void setDifficult(int difficult);
	void setSizeRoad(int height, int width);

	bool isFail(global::CAR_CONTROL carControll);
	~Road();

private:
	vector<int> coordinateBlocksX;
	vector<int> coordinateBlocksY;

	int coordinatePlayerX;
	int coordinatePlayerY;

	int WIDTH_ROAD;
	int HEIGHT_ROAD;

protected:
    int difficult; // Affects the number of generated blocks.
	char** roadPlayer;
};

#endif