#pragma once
#include "stdafx.h"

using namespace std;

class Statistic
{
private:
	int timeGame;
	double distance;
	int speed;
public:
	Statistic();
	void setSpeed(CAR_CONTROL carControll);
	void setDistance();
	void setTime(int startTime);

	int getSpeed();

	int convertSpeed(int speed);

	void viewStatistic();
	~Statistic();
};

