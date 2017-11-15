#include "stdafx.h"
#include "Game.h"
#include "CalculateState.h"
#include "CloseState.h"

Game::Game()
{
 
}

void Game::initObject()
{
	control = new Control();
	statistic = new Statistic();
	state = new CalculateState(statistic);
}

void Game::massageGameKey()
{
	cout << "TAB - close/view statistic" << endl;
	cout << "ENTER - pause game" << endl;
	cout << "SPACE - save game" << endl;
	cout << endl;
}

void Game::Run()
{
	initObject();

	choiceSizeRoad(control);
	statistic->setView(state);

	int count = 0;
	int countLevel = 0;
	int countPressTab = 0;
	int startTime = clock();

	while (true)
	{
		if (count == 1)
		{
			control->UpLevel(10);
		}

		if (statistic->getDistance() >= global::LEVEL_ONE && statistic->getDistance() <= global::LEVEL_TWO && countLevel == 0)
		{
			system("cls");
			cout << "level 2" << endl;
			system("pause");

			control->UpLevel(global::DIFFICULT_LEVEL_ONE);
			countLevel++;
			system("cls");
		}

		if (statistic->getDistance() >= global::LEVEL_TWO && statistic->getDistance() <= global::LEVEL_THREE && countLevel == 1)
		{
			system("cls");
			cout << "level 3" << endl;
			system("pause");

			control->UpLevel(global::DIFFICULT_LEVEL_TWO);
			countLevel++;
			system("cls");
		}

		if (statistic->getDistance() >= global::LEVEL_THREE && statistic->getDistance() <= global::LEVEL_FOUR && countLevel == 2)
		{
			system("cls");
			cout << "level 4" << endl;
			system("pause");

			control->UpLevel(global::DIFFICULT_LEVEL_THREE);
			countLevel++;
			system("cls");
		}

		if (statistic->getDistance() >= global::LEVEL_FOUR && countLevel == 3)
		{
			system("cls");
			cout << "level 5" << endl;
			system("pause");

			control->UpLevel(global::DIFFICULT_LEVEL_FOUR);
			countLevel++;
			system("cls");
		}

		// Save game
		if (GetAsyncKeyState(VK_SPACE))
		{
			system("cls");
			cout << "Game saving" << endl;
			system("pause");
			int x;
			control->saveGame(statistic);
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
			if (control->isFail(global::CAR_CONTROL::RIGHT))
			{
				break;
			}

			control->turnRight();
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			if (control->isFail(global::CAR_CONTROL::LEFT))
			{
				break;
			}

			control->turnLeft();
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			if (control->isFail(global::CAR_CONTROL::DOWN))
			{
				break;
			}

			statistic->setSpeed(global::CAR_CONTROL::DOWN);
			control->turnDown();
		}

		if (GetAsyncKeyState(VK_UP))
		{	
			if (control->isFail(global::CAR_CONTROL::UP))
			{
				break;
			}

			statistic->setSpeed(global::CAR_CONTROL::UP);
			control->turnUp();
		}


		statistic->setTime(startTime);
		statistic->viewStatistic(statistic->isView());

		control->setBlockOnRoad();
		control->viewRoad();

		// View game key 
		if (countPressTab % 2 == 0)
		{
			massageGameKey();
		}


		// Change state view statistic
		if (GetAsyncKeyState(VK_TAB))
		{
			++countPressTab;
			
			if (countPressTab & 1 == 1) 
			{
				state = new CloseState(statistic);
			}
			else {
				state = new CalculateState(statistic);
			}

			statistic->setView(state);
		}

		if (control->isFail(global::CAR_CONTROL::NONE))
		{
			break;
		}
	

		Sleep(statistic->getSpeed());
		
		redrawing(0, 0);

		if (GetAsyncKeyState(VK_ESCAPE)) break; //Exit loop.

		count++;
	}

	system("cls");
	statistic->viewStatistic(statistic->isView());
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

void Game::choiceSizeRoad(Control* control)
{
	int action = 0;

	while (true)
	{
		cout << "Choose a six-lane(press 1) or four-lane road(press 2), or start save game(press 3)" << endl;
		cin >> action;

		if(action == 1)
		{ 
			control->startGame(global::SIX_WAY_ROAD);
			break;
		}
			
		if (action == 2)
		{
			control->startGame(global::FOUR_WAY_ROAD);
			break;
		}

		if (action == 3)
		{
			if (control->startSaveGame() == true)
			{
				break;
			}
		}
	}
}

Game::~Game()
{
	// Clear memory.
	delete state;
	delete control;
	delete statistic;
}
