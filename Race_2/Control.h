#ifndef __CONTROL_H__
#define __CONTROL_H__

#include "Command.h"

class Control
{
private:
	Road road;
	Command* command;
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
	~Control();
};

#endif