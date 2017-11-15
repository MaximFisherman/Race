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

	~Road();

protected:
	vector<int> coordinateBlocksX;
	vector<int> coordinateBlocksY;

	int coordinatePlayerX;
	int coordinatePlayerY;

    int difficult; // Affects the number of generated blocks.

	int WIDTH_ROAD;
	int HEIGHT_ROAD;

	vector<char> roadPlayer;
};

#endif