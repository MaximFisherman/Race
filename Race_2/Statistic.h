#ifndef __STATISTIC_H__
#define __STATISTIC_H__

#include "stdafx.h"
#include "State.h"

using namespace std;

class Statistic
{
public:
	Statistic();
	void setView(const State* state);

	void setSpeed(global::CAR_CONTROL carControll);
	void setDistance();
	void setTime(int startTime);

	int getSpeed();
	int getTime();
	double getDistance();

	int convertToMinutes(int time);
	int convertToHour(int time);
	int convertToSecond(int time);
	int convertSpeed(int speed);

	void viewStatistic(bool isView);

	bool isView();
	~Statistic();

private:
	State* state;
	int timeGame;
	double distance;
	int speed;
};

#endif