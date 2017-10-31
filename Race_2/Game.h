#pragma once
#include "stdafx.h"
#include "Control.h"
#include "Statistic.h"

class Game
{
private: 
	Control control;
	Statistic statistic;
public:
	Game();
	void redrawing(int x, int y);
	void massageGameOver();

	void Run();
	~Game();
};

