#ifndef __GAME_H__
#define __GAME_H__

#include "stdafx.h"
#include "RoadCommand.h"
#include "Statistic.h"
#include "Road.h"

class Game
{
private: 
	RoadCommand* roadCommand;
	Statistic* statistic;
	StateView* stateView;
	StateRoad* stateRoad;
public:
	Game();
	void initObject();
	void redrawing(int x, int y);
	void choiceSizeRoad(RoadCommand& roadCommand);

	void massageGameOver();
	void massageGameKey();
	void Run();
	~Game();
};

#endif