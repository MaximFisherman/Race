#include "stdafx.h"
#include "Game.h"
#include "OpenState.h"
#include "FourLineState.h"
#include "SixLineState.h"
#include "CloseState.h"

Game::Game()
{
 
}

void Game::initObject()
{
	roadCommand = new RoadCommand();
	statistic = new Statistic();
	stateView = new OpenState(*statistic);
	stateRoad = nullptr;
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
	bool isGameOver = false;
	int count = 0;
	int countLevel = 0;
	int countPressTab = 0;
	int startTime = clock();

	while (isGameOver != true)
	{
		++count;
		// Start game 
		if (count == 1)
		{
			initObject();
			choiceSizeRoad(*roadCommand);
			statistic->setView(*stateView);

			// Set level game 1.
			roadCommand->setDifficult(global::DIFFICULT_LEVEL_ONE);
		}

		// Level game 2. 
		if (statistic->getDistance() >= global::LEVEL_ONE && statistic->getDistance() <= global::LEVEL_TWO && countLevel == 0)
		{
			system("cls");
			cout << "level 2" << endl;
			system("pause");

			roadCommand->setDifficult(global::DIFFICULT_LEVEL_TWO);
			countLevel++;
			system("cls");
		}

		// Level game 3.
		if (statistic->getDistance() >= global::LEVEL_TWO && statistic->getDistance() <= global::LEVEL_THREE && countLevel == 1)
		{
			system("cls");
			cout << "level 3" << endl;
			system("pause");

			roadCommand->setDifficult(global::DIFFICULT_LEVEL_THREE);
			countLevel++;
			system("cls");
		}

		// Level game 4.
		if (statistic->getDistance() >= global::LEVEL_THREE && statistic->getDistance() <= global::LEVEL_FOUR && countLevel == 2)
		{
			system("cls");
			cout << "level 4" << endl;
			system("pause");

			roadCommand->setDifficult(global::DIFFICULT_LEVEL_FOUR);
			countLevel++;
			system("cls");
		}

		// Level game 5
		if (statistic->getDistance() >= global::LEVEL_FOUR && countLevel == 3)
		{
			system("cls");
			cout << "level 5" << endl;
			system("pause");

			roadCommand->setDifficult(global::DIFFICULT_LEVEL_FIVE);
			countLevel++;
			system("cls");
		}

		// Save game.
		if (GetAsyncKeyState(VK_SPACE))
		{
			system("cls");
			cout << "Game saving" << endl;
			system("pause");

			roadCommand->saveGame(statistic);
			system("cls");
		}

		// Pause menu.
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
			if (roadCommand->isFail(global::CAR_CONTROL::RIGHT))
			{
				isGameOver = true;
			}

			roadCommand->turnRight();
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			if (roadCommand->isFail(global::CAR_CONTROL::LEFT))
			{
				isGameOver = true;
			}

			roadCommand->turnLeft();
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			if (roadCommand->isFail(global::CAR_CONTROL::DOWN))
			{
				isGameOver = true;
			}

			statistic->setSpeed(global::CAR_CONTROL::DOWN);
			roadCommand->turnDown();
		}

		if (GetAsyncKeyState(VK_UP))
		{	
			if (roadCommand->isFail(global::CAR_CONTROL::UP))
			{
				isGameOver = true;
			}

			statistic->setSpeed(global::CAR_CONTROL::UP);
			roadCommand->turnUp();
		}


		statistic->setTime(startTime);
 		statistic->viewStatistic(statistic->isView());

		roadCommand->setBlockOppositeLine();
		roadCommand->setBlockRoadLine();
		roadCommand->viewRoad();

		// View game key.
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
				stateView = new CloseState(*statistic);
			}
			else {
				stateView = new OpenState(*statistic);
			}

			statistic->setView(*stateView);
		}

		if (roadCommand->isFail(global::CAR_CONTROL::NONE))
		{
			isGameOver = true;
		}
	

		Sleep(statistic->getSpeed());
		
		redrawing(0, 0);

		if (GetAsyncKeyState(VK_ESCAPE)) break; //Exit loop.

		if (isGameOver == true)
		{
			int choiceUser = 0;

			system("cls");
			cout << "Do you want to play again, 1-yes, 2-no ?" << endl;

			while (choiceUser != 1 && choiceUser != 2)
			{
				cin >> choiceUser;
				switch (choiceUser) {
					case 1:
						isGameOver = false;
						count = 0;
						break;
					case 2:
						isGameOver = true;
						break;
				}
			}	
		
			if (choiceUser == 2) break;
			system("cls");
		}
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

void Game::choiceSizeRoad(RoadCommand& roadCommand)
{
	int action = 0;

	while (true)
	{
		cout << "Choose a six-lane(press 1) or four-lane road(press 2), or start save game(press 3)" << endl;
		cin >> action;

		if(action == 1)
		{ 
			stateRoad = new SixLineState(roadCommand);
			roadCommand.setSizeRoad(*stateRoad);
			roadCommand.sizeRoad();
			roadCommand.initializationRoad();
			break;
		}
			
		if (action == 2)
		{
			stateRoad = new FourLineState(roadCommand);
			roadCommand.setSizeRoad(*stateRoad);
			roadCommand.sizeRoad();
			roadCommand.initializationRoad();
			break;
		}

		if (action == 3)
		{
			if (roadCommand.startSaveGame() == true)
			{
				break;
			}
		}
	}
}

Game::~Game()
{
	// Clear memory.
	delete stateView;
	delete roadCommand;
	delete statistic;
}
