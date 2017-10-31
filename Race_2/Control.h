#pragma once
#include "Command.h"

class Control
{
private:
	Road road;
	Command* command;
public:
	Control();

	void turnLeft();
	void turnRight();
	void turnUp();
	void turnDown();

	void setBlockOnRoad();

	void clearRoad();
	void viewRoad();

	bool isFail(CAR_CONTROL carControll);
	~Control();
};

