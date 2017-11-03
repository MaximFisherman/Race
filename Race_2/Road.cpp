#include "stdafx.h"
#include "Road.h"


Road::Road()
{

}

void Road::initializationRoad()
{
	// Initialization player road 
	roadPlayer = new char*[HEIGHT_ROAD];
	for (int i = 0; i < HEIGHT_ROAD; i++)
	{
		roadPlayer[i] = new char[WIDTH_ROAD];
	}

	for (int i = 0; i < HEIGHT_ROAD; i++)
	{
		for (int j = 0; j < WIDTH_ROAD; j++)
		{
			if (i == ((HEIGHT_ROAD / 2) + 2) && j == (WIDTH_ROAD / 2))
			{
				roadPlayer[i][j] = global::SYMB_CAR;
			}
			else {
				roadPlayer[i][j] = global::SYMB_ROAD;
			}
		}
	}
}

// Search for a car symbol in a two-dimensional matrix.
void Road::searchCoordinatePlayer()
{
	for (int i = 0; i < HEIGHT_ROAD; i++)
	{
		for (int j = 0; j < WIDTH_ROAD; j++)
		{
			if (roadPlayer[i][j] == global::SYMB_CAR)
			{
				coordinatePlayerY = i;
				coordinatePlayerX = j;
			}
		}
	}
}


Road::~Road()
{
	// Delete road
	for (size_t i = 0; i < HEIGHT_ROAD; ++i)
		delete[] roadPlayer[i];

	delete[] roadPlayer;
}