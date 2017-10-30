#pragma once
#include "stdafx.h"
#include "Receiver.h"
#include "Statistic.h"

class Game
{
private: 
	Receiver receiver;
	Statistic statistic;
public:
	Game();
	void redrawing(int x, int y);
	void massageGameOver();

	void Run();
	~Game();
};

