#include "stdafx.h"
#include "Road.h"


Road::Road()
{

}

void Road::initializationRoad()
{
	for (int i = 0; i < HEIGHT_ROAD; i++)
	{
		for (int j = 0; j < WIDTH_ROAD; j++)
		{
			if (i == ((HEIGHT_ROAD / 2) + 2) && j == (WIDTH_ROAD / 2))
			{
				roadPlayer.push_back(global::SYMB_CAR);
			}
			else {
				roadPlayer.push_back(global::SYMB_ROAD);
			}
		}
	}
}

// Search for a car symbol in a two-dimensional matrix.
void Road::searchCoordinatePlayer()
{
	for (int i = 1; i < HEIGHT_ROAD; i++)
	{
		for (int j = 0; j < WIDTH_ROAD; j++)
		{
			if (roadPlayer[(i - 1) * WIDTH_ROAD + j] == global::SYMB_CAR)
			{
				coordinatePlayerY = i;
				coordinatePlayerX = j;
			}
		}
	}
}


Road::~Road()
{
	roadPlayer.clear();
	coordinateBlocksX.clear();
	coordinateBlocksY.clear();
}