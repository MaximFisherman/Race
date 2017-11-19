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
		roadPlayer[(coordinatePlayerY - 1) * WIDTH_ROAD + coordinatePlayerX] = global::SYMB_ROAD;
		roadPlayer[(coordinatePlayerY - 1) * WIDTH_ROAD + coordinatePlayerX - 1] = global::SYMB_CAR;
	}
}

void RoadCommand::turnRight()
{
	searchCoordinatePlayer();

	if (coordinatePlayerX + 1 != WIDTH_ROAD)
	{
		roadPlayer[(coordinatePlayerY - 1) * WIDTH_ROAD + coordinatePlayerX] = global::SYMB_ROAD;
		roadPlayer[(coordinatePlayerY - 1) * WIDTH_ROAD + coordinatePlayerX + 1] = global::SYMB_CAR;
	}
}

void RoadCommand::turnDown()
{
	searchCoordinatePlayer();

	if (coordinatePlayerY + 1 != HEIGHT_ROAD - 2)
	{
		roadPlayer[(coordinatePlayerY - 1) * WIDTH_ROAD + coordinatePlayerX] = global::SYMB_ROAD;
		roadPlayer[((coordinatePlayerY + 1) - 1) * WIDTH_ROAD + coordinatePlayerX] = global::SYMB_CAR;
	}
}

void RoadCommand::turnUp()
{
	searchCoordinatePlayer();

	if (coordinatePlayerY - 1 != 2)
	{
		roadPlayer[(coordinatePlayerY - 1) * WIDTH_ROAD + coordinatePlayerX] = global::SYMB_ROAD;
		roadPlayer[((coordinatePlayerY - 1) - 1) * WIDTH_ROAD + coordinatePlayerX] = global::SYMB_CAR;
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

	// Ñheck the number of lanes on the road.
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
			roadPlayer[(0) * WIDTH_ROAD + i] = global::SYMB_BLOCK;
		}
	}

	// Search for a block symbol in a two-dimensional matrix.
	for (int i = 1; i < HEIGHT_ROAD; i++)
	{
		for (int j = 0; j < WIDTH_ROAD / 2; j++)
		{
			if (roadPlayer[(i - 1) * WIDTH_ROAD + j] == global::SYMB_BLOCK)
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
			roadPlayer[(coordinateBlocksY[i] - 1) * WIDTH_ROAD + coordinateBlocksX[i]] = global::SYMB_ROAD;
			roadPlayer[((coordinateBlocksY[i] + 1) - 1) * WIDTH_ROAD + coordinateBlocksX[i]] = global::SYMB_BLOCK;
		}
		else {
			roadPlayer[(coordinateBlocksY[i] - 1) * WIDTH_ROAD + coordinateBlocksX[i]] = global::SYMB_ROAD;
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

	// Ñheck the number of lanes on the road.
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
			roadPlayer[((HEIGHT_ROAD - 1) - 1) * WIDTH_ROAD + i] = global::SYMB_BLOCK;
		}
	}


	// Search for a block symbol in a two-dimensional matrix.
	for (int i = 1; i < HEIGHT_ROAD; i++)
	{
		for (int j = WIDTH_ROAD / 2; j < WIDTH_ROAD; j++)
		{
			if (roadPlayer[(i - 1) * WIDTH_ROAD + j] == global::SYMB_BLOCK)
			{
				coordinateBlocksX.push_back(j);
				coordinateBlocksY.push_back(i);
			}
		}
	}

	// Moving blocks.
	for (int i = 0; i < coordinateBlocksX.size(); i++)
	{
		if (coordinateBlocksY[i] != 1)
		{
			roadPlayer[(coordinateBlocksY[i] - 1) * WIDTH_ROAD + coordinateBlocksX[i]] = global::SYMB_ROAD;
			roadPlayer[((coordinateBlocksY[i] - 1) - 1) * WIDTH_ROAD + coordinateBlocksX[i]] = global::SYMB_BLOCK;
		}
		else {
			roadPlayer[(coordinateBlocksY[i] - 1) * WIDTH_ROAD + coordinateBlocksX[i]] = global::SYMB_ROAD;
		}
	}
	coordinateBlocksX.clear();
	coordinateBlocksY.clear();
}

void RoadCommand::clearRoad()
{
	coordinateBlocksX.clear();
	coordinateBlocksY.clear();

	for (int i = 1; i < HEIGHT_ROAD; i++)
	{
		for (int j = 0; j < WIDTH_ROAD; j++)
		{

			if (i == ((HEIGHT_ROAD / 2) + 2) && j == (WIDTH_ROAD / 2))
			{
				roadPlayer[(i - 1) * WIDTH_ROAD + j] = global::SYMB_CAR;
			}
			else {
				roadPlayer[(i - 1) * WIDTH_ROAD + j] = global::SYMB_ROAD;
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
			if (roadPlayer[(coordinatePlayerY - 1) * WIDTH_ROAD + (coordinatePlayerX + 1)] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case global::CAR_CONTROL::LEFT:
			if (roadPlayer[(coordinatePlayerY - 1) * WIDTH_ROAD + (coordinatePlayerX - 1)] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case global::CAR_CONTROL::UP:
			if (roadPlayer[((coordinatePlayerY - 1) - 1) * WIDTH_ROAD + coordinatePlayerX] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case global::CAR_CONTROL::DOWN:
			if (roadPlayer[((coordinatePlayerY + 1) - 1) * WIDTH_ROAD + coordinatePlayerX] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			break;
		case global::CAR_CONTROL::NONE:
			if (coordinatePlayerY != 3 && roadPlayer[((coordinatePlayerY + 1) - 1) * WIDTH_ROAD + coordinatePlayerX] == global::SYMB_BLOCK)
			{
				flag = true;
			}
			if (coordinatePlayerY != 0 && roadPlayer[((coordinatePlayerY - 1) - 1) * WIDTH_ROAD + coordinatePlayerX] == global::SYMB_BLOCK)
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

void RoadCommand::viewRoad()
{
	cout << endl;
	srand(time(NULL));

	int DisplayMarkup = 0;
	int ReversDisplay = rand() % 2 + 1;

	for (int i = 1; i < HEIGHT_ROAD; i++)
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
				cout << roadPlayer[(i - 1) * WIDTH_ROAD + j];
			}
			else {
				if (ReversDisplay == 1)
				{
					if (DisplayMarkup == 1)
					{
						cout << roadPlayer[(i - 1) * WIDTH_ROAD + j] << " ";
					}
					if (DisplayMarkup == 0)
					{
						cout << roadPlayer[(i - 1) * WIDTH_ROAD + j] << (char)58;
					}
				}
				if (ReversDisplay == 2)
				{
					if (DisplayMarkup == 1)
					{
						cout << roadPlayer[(i - 1) * WIDTH_ROAD + j] << (char)58;
					}
					if (DisplayMarkup == 0)
					{
						cout << roadPlayer[(i - 1) * WIDTH_ROAD + j] << " ";
					}
				}
			}
		}
		DisplayMarkup = 0;
		cout << "|" << endl;
	}
}

bool RoadCommand::saveGame(Statistic* statistic)
{
	bool flag = false;

	try {
		ofstream outRoad("RaceSave.txt");

		for (int i = 1; i < HEIGHT_ROAD; i++)
		{
			for (int j = 0; j < WIDTH_ROAD; j++)
			{
				if (roadPlayer[(i - 1) * WIDTH_ROAD + j] == ' ')
				{
					roadPlayer[(i - 1) * WIDTH_ROAD + j] = '*';
				}
				outRoad << roadPlayer[(i - 1) * WIDTH_ROAD + j];
			}
		}

		if (outRoad.bad())    // bad() function will check for badbit
		{
			throw 1;
		}

		outRoad << "\n" << WIDTH_ROAD << "\n";
		outRoad << HEIGHT_ROAD << "\n";

		outRoad.close();

		for (int i = 1; i < HEIGHT_ROAD; i++)
		{
			for (int j = 0; j < WIDTH_ROAD; j++)
			{
				if (roadPlayer[(i - 1) * WIDTH_ROAD + j] == '*')
				{
					roadPlayer[(i - 1) * WIDTH_ROAD + j] = ' ';
				}
			}
		}

		ofstream outStatistic("StatisticSave.txt");

		outStatistic << statistic->getDistance() << "\n";
		outStatistic << statistic->getTime();

		if (outStatistic.bad())    // bad() function will check for badbit
		{
			throw 2;
		}

		outStatistic.close();
		flag = true;
	}
	catch (int& error){
		system("cls");
		cout << "Error writing in file, error code:" << error;
		system("pause");
		system("cls");

		flag = false;
	}

	return flag;
}

bool RoadCommand::startSaveGame() 
{
	bool flag = false;

	try {
		string sTemp;

		int width = 0;
		int height = 0;
		double distance = 0;
		int timeGame = 0;

		ifstream file("RaceSave.txt");

		if (!file.is_open())
		{
			// The file doesn't exist.
			throw 11;
		}



		int countLine = 0;
		while (!file.eof()) {
			string s;

			if (countLine == 0)
			{
				getline(file, s);
				sTemp = s;
			}
				
			if (countLine == 1)
			{
				getline(file, s);
				width = stoi(s);
			}
				
			if (countLine == 2)
			{
				getline(file, s);
				height = stoi(s);
				break;
			}
			
			countLine++;
		}

		// Initialization size road.
		HEIGHT_ROAD = height;
		WIDTH_ROAD = width;
		initializationRoad();

		int count = 0;
		for (int i = 1; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				roadPlayer[(i - 1) * WIDTH_ROAD + j] = sTemp[count];

				if (roadPlayer[(i - 1) * WIDTH_ROAD + j] == '*')
					roadPlayer[(i - 1) * WIDTH_ROAD + j] = ' ';
				count++;
			}
			count = 0;
		}

		file.close();


		ifstream fileStatistic("StatisticSave.txt");

		if (!fileStatistic.is_open())
		{
			// The file doesn't exist.
			throw 12;
		}

	    countLine = 0;
		while (!fileStatistic.eof()) {
			string s;

			if (countLine == 0)
			{
				getline(fileStatistic, s);
				distance = stod(s);
				countLine++;
			}

			if (countLine == 1)
			{
				getline(fileStatistic, s);
				timeGame = stoi(s);
				break;
			}
			
		}
		
		flag = true;
	}
	catch (int& error) {
		ofstream outLogError("Log.txt");

		outLogError << "Error open file, error code:" << error << "\n";
		outLogError.close();

		system("cls");
		cout << "you didn't have save" << endl;
		system("pause");
		system("cls");

		flag = false;
	}

	return flag;
}

RoadCommand::~RoadCommand()
{
}
