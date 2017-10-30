#include "stdafx.h"
#include "Road.h"


Road::Road()
{
	for (int i = 0; i < HEIGHT_ROAD; i++)
	{
		for (int j = 0; j < WIDTH_ROAD; j++)
		{

			if (i == ((HEIGHT_ROAD / 2) + 2) && j == (WIDTH_ROAD / 2))
			{
				roadPlayer[i][j] = SYMB_CAR;
			}
			else {
				roadPlayer[i][j] = SYMB_ROAD;
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
			if (roadPlayer[i][j] == SYMB_CAR)
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
		roadPlayer[coordinatePlayerY][coordinatePlayerX] = SYMB_ROAD;
		roadPlayer[coordinatePlayerY][coordinatePlayerX - 1] = SYMB_CAR;
	}
}

void Road::turnRight()
{
	searchCoordinatePlayer();

	if (coordinatePlayerX + 1 != WIDTH_ROAD)
	{
		roadPlayer[coordinatePlayerY][coordinatePlayerX] = SYMB_ROAD;
		roadPlayer[coordinatePlayerY][coordinatePlayerX + 1] = SYMB_CAR;
	}
}

void Road::turnUp()
{
	searchCoordinatePlayer();

	if (coordinatePlayerY - 1 != 1)
	{
		roadPlayer[coordinatePlayerY][coordinatePlayerX] = SYMB_ROAD;
		roadPlayer[coordinatePlayerY - 1][coordinatePlayerX] = SYMB_CAR;
	}
}

void Road::turnDown()
{
	searchCoordinatePlayer();

	if (coordinatePlayerY + 1 != HEIGHT_ROAD - 2)
	{
		roadPlayer[coordinatePlayerY][coordinatePlayerX] = SYMB_ROAD;
		roadPlayer[coordinatePlayerY + 1][coordinatePlayerX] = SYMB_CAR;
	}
}

void Road::setBlockRoadLine()
{
	int randomPositionBlock = rand() % DIFFICULT + 1;

	if (randomPositionBlock == 4)
	{
		roadPlayer[HEIGHT_ROAD - 1][2] = SYMB_BLOCK;
	}

	if (randomPositionBlock == 5)
	{
		roadPlayer[HEIGHT_ROAD - 1][3] = SYMB_BLOCK;
	}
	// Search for a block symbol in a two-dimensional matrix.
	for (int i = 0; i < HEIGHT_ROAD; i++)
	{
		for (int j = WIDTH_ROAD / 2; j < WIDTH_ROAD; j++)
		{
			if (roadPlayer[i][j] == SYMB_BLOCK)
			{
				coordinateBlocksX.push_back(j);
				coordinateBlocksY.push_back(i);
			}
		}
	}

	// Moving blocks.
	for (int i = 0; i < coordinateBlocksX.size(); i++)
	{
		if (coordinateBlocksY[i] != -1)
		{
			roadPlayer[coordinateBlocksY[i]][coordinateBlocksX[i]] = SYMB_ROAD;
			roadPlayer[coordinateBlocksY[i] - 1][coordinateBlocksX[i]] = SYMB_BLOCK;
		}
		else {
			roadPlayer[coordinateBlocksY[i]][coordinateBlocksX[i]] = SYMB_ROAD;
		}
	}
	coordinateBlocksX.clear();
	coordinateBlocksY.clear();
}

void Road::setBlockOppositeLine()
{
	int randomPositionBlock = rand() % DIFFICULT + 1;

	if (randomPositionBlock == 1)
	{
		roadPlayer[0][0] = SYMB_BLOCK;
	}

	if (randomPositionBlock == 2)
	{
		roadPlayer[0][1] = SYMB_BLOCK;
	}

	// Search for a block symbol in a two-dimensional matrix.
	for (int i = 0; i < HEIGHT_ROAD; i++)
	{
		for (int j = 0; j < WIDTH_ROAD / 2; j++)
		{
			if (roadPlayer[i][j] == SYMB_BLOCK)
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
			roadPlayer[coordinateBlocksY[i]][coordinateBlocksX[i]] = SYMB_ROAD;
			roadPlayer[coordinateBlocksY[i] + 1][coordinateBlocksX[i]] = SYMB_BLOCK;
		}
		else {
			roadPlayer[coordinateBlocksY[i]][coordinateBlocksX[i]] = SYMB_ROAD;
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
				roadPlayer[i][j] = SYMB_CAR;
			}
			else {
				roadPlayer[i][j] = SYMB_ROAD;
			}
		}
	}
}

bool Road::isFail(CAR_CONTROL carControll)
{
	bool flag = false;

	searchCoordinatePlayer();

	switch (carControll) {
		case CAR_CONTROL::RIGHT : 
			if (roadPlayer[coordinatePlayerY][coordinatePlayerX + 1] == SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case CAR_CONTROL::LEFT :
			if (roadPlayer[coordinatePlayerY][coordinatePlayerX - 1] == SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case CAR_CONTROL::UP :
			if (roadPlayer[coordinatePlayerY - 1][coordinatePlayerX] == SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case CAR_CONTROL::DOWN :
			if (roadPlayer[coordinatePlayerY + 1][coordinatePlayerX] == SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case CAR_CONTROL::NONE :
			for (int i = 0; i < HEIGHT_ROAD; i++)
			{
				for (int j = 0; j < WIDTH_ROAD; j++)
				{
					if (roadPlayer[coordinatePlayerY + 1][coordinatePlayerX] == SYMB_BLOCK)
					{
						flag = true;
					}
					if (roadPlayer[coordinatePlayerY - 1][coordinatePlayerX] == SYMB_BLOCK)
					{
						flag = true;
					}
				}
			}
			break;
	}

	return flag;
}

Road::~Road()
{
}
