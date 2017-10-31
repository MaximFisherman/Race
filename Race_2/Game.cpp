#include "stdafx.h"
#include "Game.h"
#include "CalculateState.h"
#include "CloseState.h"

Game::Game()
{
}

void Game::Run()
{
	Control control;
	Statistic statistic;

	choiceSizeRoad(control);
	statistic.setCurrent(new CalculateState(statistic));

	int count = 0;
	int countLevel = 0;
	int countPressTab = 0;
	int startTime = clock();

	while (true)
	{
		if (count == 1)
		{
			control.UpLevel(10);
		}

		if (statistic.getDistance() >= LEVEL_ONE && statistic.getDistance() <= LEVEL_TWO && countLevel == 0)
		{
			system("cls");
			cout << "level 2" << endl;
			system("pause");

			control.UpLevel(7);
			countLevel++;
			system("cls");
		}

		if (statistic.getDistance() >= LEVEL_TWO && statistic.getDistance() <= LEVEL_THREE && countLevel == 1)
		{
			system("cls");
			cout << "level 3" << endl;
			system("pause");

			control.UpLevel(7);
			countLevel++;
			system("cls");
		}

		if (statistic.getDistance() >= LEVEL_THREE && statistic.getDistance() <= LEVEL_FOUR && countLevel == 2)
		{
			system("cls");
			cout << "level 4" << endl;
			system("pause");

			control.UpLevel(5);
			countLevel++;
			system("cls");
		}

		if (statistic.getDistance() >= LEVEL_FOUR && countLevel == 3)
		{
			system("cls");
			cout << "level 5" << endl;
			system("pause");

			control.UpLevel(4);
			countLevel++;
			system("cls");
		}

		// Pause manu
		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			cout << "Its a pause menu" << endl;
			system("pause");
			system("cls");
		}

		// Cranking pressing of keys of acceleration and turn of the car. 
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (control.isFail(CAR_CONTROL::RIGHT))
			{
				break;
			}

			control.turnRight();
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			if (control.isFail(CAR_CONTROL::LEFT))
			{
				break;
			}

			control.turnLeft();
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			if (control.isFail(CAR_CONTROL::DOWN))
			{
				break;
			}

			statistic.setSpeed(CAR_CONTROL::DOWN);
			control.turnDown();
		}

		if (GetAsyncKeyState(VK_UP))
		{	
			if (control.isFail(CAR_CONTROL::UP))
			{
				break;
			}

			statistic.setSpeed(CAR_CONTROL::UP);
			control.turnUp();
		}

		// Change state view statistic
		if (GetAsyncKeyState(VK_TAB))
		{
			++count;
			if (count & 1 == 1) 
			{
				statistic.setCurrent(new CloseState(statistic));
			}
			else {
				statistic.setCurrent(new CalculateState(statistic));
			}
		}

		if (control.isFail(CAR_CONTROL::NONE))
		{
			break;
		}

	
		statistic.setTime(startTime);
		statistic.viewStatistic(statistic.isView());

		control.setBlockOnRoad();
		control.viewRoad();
		
		Sleep(statistic.getSpeed());
		
		redrawing(0, 0);

		if (GetAsyncKeyState(VK_ESCAPE)) break; //Exit loop.

		count++;
	}

	system("cls");
	statistic.viewStatistic(statistic.isView());
	massageGameOver();
}

void Game::massageGameOver()
{
	cout << endl;
	cout << "Game over" << endl << endl;
	cout << endl;
	system("pause");
}

void Game::redrawing(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Game::choiceSizeRoad(Control& control)
{
	cout << "Please select road entered one for two-road, entered two for four-road" << endl;

	int action;
	cin >> action;

	if (action == 1)
		control.startGame(TWO_WAY_ROAD);

	if(action == 2)
		control.startGame(FOUR_WAY_ROAD);
}

Game::~Game()
{
}
