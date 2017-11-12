#include "stdafx.h"
#include "RoadCommand.h"


RoadCommand::RoadCommand()
{
	setDifficult(global::DIFFICULT_LEVEL_ONE);
}

void RoadCommand::turnLeft()
{
	searchCoordinatePlayer();

	if (coordinatePlayerX - 1 != -1)
	{
		roadPlayer[coordinatePlayerY][coordinatePlayerX] = global::SYMB_ROAD;
		roadPlayer[coordinatePlayerY][coordinatePlayerX - 1] = global::SYMB_CAR;
	}
}

void RoadCommand::turnRight()
{
	searchCoordinatePlayer();

	if (coordinatePlayerX + 1 != WIDTH_ROAD)
	{
		roadPlayer[coordinatePlayerY][coordinatePlayerX] = global::SYMB_ROAD;
		roadPlayer[coordinatePlayerY][coordinatePlayerX + 1] = global::SYMB_CAR;
	}
}

void RoadCommand::turnDown()
{
	searchCoordinatePlayer();

	if (coordinatePlayerY + 1 != HEIGHT_ROAD - 2)
	{
		roadPlayer[coordinatePlayerY][coordinatePlayerX] = global::SYMB_ROAD;
		roadPlayer[coordinatePlayerY + 1][coordinatePlayerX] = global::SYMB_CAR;
	}
}

void RoadCommand::turnUp()
{
	searchCoordinatePlayer();

	if (coordinatePlayerY - 1 != 1)
	{
		roadPlayer[coordinatePlayerY][coordinatePlayerX] = global::SYMB_ROAD;
		roadPlayer[coordinatePlayerY - 1][coordinatePlayerX] = global::SYMB_CAR;
	}
}

void RoadCommand::setBlockOppositeLine()
{
	int randomPositionBlock = 0;
	mt19937 gen(time(0));
	vector<int> roadLine;


	// Initialization roadLine
	for (size_t i = 0; i < WIDTH_ROAD / 2; i++)
	{
		roadLine.push_back(i);
	}

	// �heck the number of lanes on the road.
	if (WIDTH_ROAD == global::SIX_WAY_ROAD)
	{
		uniform_int_distribution<int> uid(0, difficult + 6);
		randomPositionBlock = uid(gen);
	}
	else {
		uniform_int_distribution<int> uid(0, difficult);
		randomPositionBlock = uid(gen);
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


void RoadCommand::setBlockRoadLine()
{
	int randomPositionBlock = 0;
	mt19937 gen(time(0));
	vector<int> roadLine;

	// Initialization roadLine
	for (size_t i = WIDTH_ROAD / 2; i < WIDTH_ROAD; i++)
	{
		roadLine.push_back(i);
	}

	// �heck the number of lanes on the road.
	if (WIDTH_ROAD == global::SIX_WAY_ROAD)
	{
		uniform_int_distribution<int> uid(0, difficult + 6);
		randomPositionBlock = uid(gen);
	}
	else {
		uniform_int_distribution<int> uid(0, difficult);
		randomPositionBlock = uid(gen);
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

void RoadCommand::clearRoad()
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

bool RoadCommand::isFail(global::CAR_CONTROL carControll)
{
	bool flag = false;

	searchCoordinatePlayer();

	switch (carControll) {
		case global::CAR_CONTROL::RIGHT:
			if (roadPlayer[coordinatePlayerY][coordinatePlayerX + 1] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case global::CAR_CONTROL::LEFT:
			if (roadPlayer[coordinatePlayerY][coordinatePlayerX - 1] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case global::CAR_CONTROL::UP:
			if (roadPlayer[coordinatePlayerY - 1][coordinatePlayerX] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case global::CAR_CONTROL::DOWN:
			if (roadPlayer[coordinatePlayerY + 1][coordinatePlayerX] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case global::CAR_CONTROL::NONE:
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

void RoadCommand::setDifficult(int _difficult)
{
	difficult = _difficult;
}

void RoadCommand::setSizeRoad(int _height, int _width)
{
	HEIGHT_ROAD = _height;
	WIDTH_ROAD = _width;
}

void RoadCommand::viewRoad()
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

void RoadCommand::saveGame(Statistic* statistic)
{
	ofstream outRoad("C:/Users/Maks_/Documents/Visual Studio 2015/Projects/Race/Release/RaceSave.txt");

	for (int i = 0; i < HEIGHT_ROAD; i++)
	{
		for (int j = 0; j < WIDTH_ROAD; j++)
		{
			if (roadPlayer[i][j] == ' ')
			{
				roadPlayer[i][j] = '*';
			}
			outRoad << roadPlayer[i][j];
		}
		outRoad << '\n';
	}

	outRoad.close();

	for (int i = 0; i < HEIGHT_ROAD; i++)
	{
		for (int j = 0; j < WIDTH_ROAD; j++)
		{
			if (roadPlayer[i][j] == '*')
			{
				roadPlayer[i][j] = ' ';
			}
		}
	}

	ofstream outStatistic("StatisticSave.txt");
	
	outStatistic << statistic->getDistance() << "\n";
	outStatistic << statistic->getTime();

	outStatistic.close();
}

void RoadCommand::startSaveGame()
{
	try {
		string s;
		string sTemp;
		ifstream file("RaceSave.txt");

		if (!file.is_open())
		{
			// The file doesn't exist.
			throw 11;
		}

		int width = 0;
		int height = 0;

		while (getline(file, s)) {
			sTemp += s;
			width = s.size();
			height++;
		}

		cout << sTemp << endl;
		setSizeRoad(height, width);
		initializationRoad();

		cout << "asd " << height << endl;
		cout << width << endl;
		system("pause");

		int count = 0;
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				roadPlayer[i][j] = sTemp[count];

				if (roadPlayer[i][j] == '*')
					roadPlayer[i][j] = ' ';
				count++;
			}
			count = 0;
		}

		file.close();
	}
	catch (int& error) {
		ofstream outLogError("Log.txt");
		outLogError << "Error open file, error code:" << error << "\n";
		outLogError.close();

		system("cls");
		cout << "you didn't have save" << endl;
		system("pause");
		exit(0);
	}

}

RoadCommand::~RoadCommand()
{
}
