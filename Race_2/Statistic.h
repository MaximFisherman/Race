#ifndef __STATISTIC_H__
#define __STATISTIC_H__

#include "stdafx.h"
#include "State.h"

using namespace std;

class Statistic
{
	class State* state;
public:
	Statistic();
	void setCurrent(State* state);

	void setSpeed(CAR_CONTROL carControll);
	void setDistance();
	void setTime(int startTime);

	int getSpeed();
	int getDistance();

	int convertSpeed(int speed);

	void viewStatistic(bool isView);

	bool isView();
	~Statistic();

private:
	int timeGame;
	double distance;
	int speed;
};

#endif