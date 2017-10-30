#include "stdafx.h"
#include "Game.h"


Game::Game()
{
}

void Game::Run()
{
	Receiver receiver;
	Statistic statistic;

	int count = 0;
	int startTime = clock();

	while (true)
	{
		if (count = 1)
		{
			statistic.setTime(startTime);
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
			receiver.turnRight();
			if (receiver.isFail(CAR_CONTROL::RIGHT))
			{
				break;
			}
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			receiver.turnLeft();

			if (receiver.isFail(CAR_CONTROL::LEFT))
			{
				break;
			}
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			receiver.turnDown();
			if (receiver.isFail(CAR_CONTROL::DOWN))
			{
				break;
			}
			statistic.setSpeed(CAR_CONTROL::DOWN);
		}

		if (GetAsyncKeyState(VK_UP))
		{
			receiver.turnUp();
			
			if (receiver.isFail(CAR_CONTROL::UP))
			{
				break;
			}

			statistic.setSpeed(CAR_CONTROL::UP);
		}

		if (receiver.isFail(CAR_CONTROL::NONE))
		{
			break;
		}

		statistic.viewStatistic();

		receiver.setBlockOnRoad();
		receiver.viewRoad();
		
		Sleep(statistic.getSpeed());
		
		redrawing(0, 0);

		if (GetAsyncKeyState(VK_ESCAPE)) break; //Exit loop.

		count++;
	}

	massageGameOver();
}

void Game::massageGameOver()
{
	system("cls");
	cout << "Game over" << endl << endl;

	statistic.viewStatistic();

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

Game::~Game()
{
}
