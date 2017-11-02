#include "stdafx.h"
#include "Road.h"


Road::Road()
{
	setDifficult(10);
	srand(time(NULL)); // Initialize random seed.
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


void Road::turnLeft()
{
	searchCoordinatePlayer();

	if (coordinatePlayerX - 1 != -1)
	{
		roadPlayer[coordinatePlayerY][coordinatePlayerX] = global::SYMB_ROAD;
		roadPlayer[coordinatePlayerY][coordinatePlayerX - 1] = global::SYMB_CAR;
	}
}

void Road::turnRight()
{
	searchCoordinatePlayer();

	if (coordinatePlayerX + 1 != WIDTH_ROAD)
	{
		roadPlayer[coordinatePlayerY][coordinatePlayerX] = global::SYMB_ROAD;
		roadPlayer[coordinatePlayerY][coordinatePlayerX + 1] = global::SYMB_CAR;
	}
}

void Road::turnUp()
{
	searchCoordinatePlayer();

	if (coordinatePlayerY - 1 != 1)
	{
		roadPlayer[coordinatePlayerY][coordinatePlayerX] = global::SYMB_ROAD;
		roadPlayer[coordinatePlayerY - 1][coordinatePlayerX] = global::SYMB_CAR;
	}
}

void Road::turnDown()
{
	searchCoordinatePlayer();

	if (coordinatePlayerY + 1 != HEIGHT_ROAD - 2)
	{
		roadPlayer[coordinatePlayerY][coordinatePlayerX] = global::SYMB_ROAD;
		roadPlayer[coordinatePlayerY + 1][coordinatePlayerX] = global::SYMB_CAR;
	}
}

void Road::setBlockRoadLine()
{
	int randomPositionBlock = 0;
	vector<int> roadLine;

	// Initialization roadLine
	for (size_t i = WIDTH_ROAD / 2; i < WIDTH_ROAD; i++)
	{
		roadLine.push_back(i);
	}

	// Ñheck the number of lanes on the road.
	if (WIDTH_ROAD == global::SIX_WAY_ROAD)
	{
		randomPositionBlock = rand() % (difficult + 6) + 0;
	}
	else {
		randomPositionBlock = rand() % difficult + 0;
	}

	// Set block on road line.
	for (int i = WIDTH_ROAD / 2; i < WIDTH_ROAD; i++)
	{
		if (randomPositionBlock == i)
		{
			roadPlayer[HEIGHT_ROAD - 1][i] = global::SYMB_BLOCK;
		}
	}

	// Search for a block symbol in a two-dimensional matrix.
	for (int i = 0; i < HEIGHT_ROAD; i++)
	{
		for (int j = WIDTH_ROAD / 2; j < WIDTH_ROAD; j++)
		{
			if (roadPlayer[i][j] == global::SYMB_BLOCK)
			{
				coordinateBlocksX.push_back(j);
				coordinateBlocksY.push_back(i);
			}
		}
	}

	// Moving blocks.
	for (int i = 0; i < coordinateBlocksX.size(); i++)
	{
		if (coordinateBlocksY[i] != 0)
		{
			roadPlayer[coordinateBlocksY[i]][coordinateBlocksX[i]] = global::SYMB_ROAD;
			roadPlayer[coordinateBlocksY[i] - 1][coordinateBlocksX[i]] = global::SYMB_BLOCK;
		}
		else {
			roadPlayer[coordinateBlocksY[i]][coordinateBlocksX[i]] = global::SYMB_ROAD;
		}
	}
	coordinateBlocksX.clear();
	coordinateBlocksY.clear();
}

void Road::setBlockOppositeLine()
{
	int randomPositionBlock = 0;
	vector<int> roadLine;

	// Initialization roadLine
	for (size_t i = 0; i < WIDTH_ROAD / 2; i++)
	{
		roadLine.push_back(i);
	}

	// Ñheck the number of lanes on the road.
	if (WIDTH_ROAD == global::SIX_WAY_ROAD)
	{
		randomPositionBlock = rand() % (difficult + 6) + 0;
	}
	else {
		randomPositionBlock = rand() % difficult + 0;
	}


	// Set block on road line.
	for (int i = 0; i < WIDTH_ROAD / 2; i++)
	{
		if (randomPositionBlock == i)
		{
			roadPlayer[0][i] = global::SYMB_BLOCK;
		}
	}

	// Search for a block symbol in a two-dimensional matrix.
	for (int i = 0; i < HEIGHT_ROAD; i++)
	{
		for (int j = 0; j < WIDTH_ROAD / 2; j++)
		{
			if (roadPlayer[i][j] == global::SYMB_BLOCK)
			{
				coordinateBlocksX.push_back(j);
				coordinateBlocksY.push_back(i);
			}
		}
	}

	// Moving blocks.
	for (int i = 0; i < coordinateBlocksX.size(); i++)
	{
		if (coordinateBlocksY[i] != HEIGHT_ROAD - 1)
		{
			roadPlayer[coordinateBlocksY[i]][coordinateBlocksX[i]] = global::SYMB_ROAD;
			roadPlayer[coordinateBlocksY[i] + 1][coordinateBlocksX[i]] = global::SYMB_BLOCK;
		}
		else {
			roadPlayer[coordinateBlocksY[i]][coordinateBlocksX[i]] = global::SYMB_ROAD;
		}
	}

	coordinateBlocksX.clear();
	coordinateBlocksY.clear();
}

void Road::viewRoad()
{
	cout << endl;
	srand(time(NULL));

	int DisplayMarkup = 0;
	int ReversDisplay = rand() % 2 + 1;

	for (int i = 0; i < HEIGHT_ROAD; i++)
	{
		cout << "|";
		if (i & 1 == 1)
		{
			DisplayMarkup++;
		}

		for (int j = 0; j < WIDTH_ROAD; j++)
		{
			if (j == WIDTH_ROAD - 1)
			{
			    cout << roadPlayer[i][j];
			}
			else {
				if (ReversDisplay == 1)
				{
					if (DisplayMarkup == 1)
					{
						cout << roadPlayer[i][j] << " ";
					}
					if (DisplayMarkup == 0)
					{
						cout << roadPlayer[i][j] << (char)58;
					}
				}
				if (ReversDisplay == 2)
				{
					if (DisplayMarkup == 1)
					{
						cout << roadPlayer[i][j] << (char)58;
					}
					if (DisplayMarkup == 0)
					{
						cout << roadPlayer[i][j] << " ";
					}
				}
			}
		}
		DisplayMarkup = 0;
		cout << "|" << endl;
	}
}

void Road::clearRoad()
{
	coordinateBlocksX.clear();
	coordinateBlocksY.clear();

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

void Road::setDifficult(int difficult)
{
	this->difficult = difficult;
}

void Road::setSizeRoad(int height, int width)
{
	this->HEIGHT_ROAD = height;
	this->WIDTH_ROAD = width;
}

bool Road::isFail(global::CAR_CONTROL carControll)
{
	bool flag = false;

	searchCoordinatePlayer();

	switch (carControll) {
		case global::CAR_CONTROL::RIGHT : 
			if (roadPlayer[coordinatePlayerY][coordinatePlayerX + 1] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case global::CAR_CONTROL::LEFT :
			if (roadPlayer[coordinatePlayerY][coordinatePlayerX - 1] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case global::CAR_CONTROL::UP :
			if (roadPlayer[coordinatePlayerY - 1][coordinatePlayerX] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case global::CAR_CONTROL::DOWN :
			if (roadPlayer[coordinatePlayerY + 1][coordinatePlayerX] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case global::CAR_CONTROL::NONE :
			if (roadPlayer[coordinatePlayerY + 1][coordinatePlayerX] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			if (roadPlayer[coordinatePlayerY - 1][coordinatePlayerX] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			break;
	}

	return flag;
}

Road::~Road()
{
	// Delete road
	for (size_t i = 0; i < HEIGHT_ROAD; ++i)
		delete[] roadPlayer[i];

	delete[] roadPlayer;
}