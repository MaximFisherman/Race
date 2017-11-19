#ifndef __STATISTIC_H__
#define __STATISTIC_H__

#include "stdafx.h"
#include "StateView.h"

using namespace std;

class Statistic
{
public:
	Statistic();
	void setView(const StateView& state);

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
	StateView* stateView;

	int timeGame;
	int speed;
	double distance;
};

#endif