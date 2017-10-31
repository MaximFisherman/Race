#ifndef __GAME_H__
#define __GAME_H__

#include "stdafx.h"
#include "Control.h"
#include "Statistic.h"
#include "Road.h"

class Game
{
private: 
	Control control;
	Statistic statistic;
public:
	Game();
	void redrawing(int x, int y);
	void choiceSizeRoad(Control& control);
	void massageGameOver();
	void Run();
	~Game();
};

#endif