#ifndef __CONTROL_H__
#define __CONTROL_H__

#include "Command.h"

class Control
{

public:
	Control();
	void startGame(int sizeRoad);

	void turnLeft();
	void turnRight();
	void turnUp();
	void turnDown();

	void setBlockOnRoad();

	void UpLevel(int difficult);

	void clearRoad();
	void viewRoad();

	bool isFail(global::CAR_CONTROL carControll);

	void saveGame(Statistic* statistic);
	void startSaveGame();
	~Control();

protected:
	RoadCommand roadCommand;
	Command* command;
};

#endif