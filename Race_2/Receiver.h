#pragma once
#include "Command.h"

class Receiver
{
private:
	Road road;
	Command* command;
public:
	Receiver();

	void turnLeft();
	void turnRight();
	void turnUp();
	void turnDown();

	void setBlockOnRoad();

	void clearRoad();
	void viewRoad();

	bool isFail(CAR_CONTROL carControll);
	~Receiver();
};

