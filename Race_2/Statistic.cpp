#include "stdafx.h"
#include "Statistic.h"


Statistic::Statistic()
{
	timeGame = 0;
	speed = BASE_SPEED;
	distance = 0;
}

void Statistic::setSpeed(CAR_CONTROL carControll)
{
	switch (carControll) {
		case CAR_CONTROL::UP :
			if (speed <= 0)
			{
				speed = 0;
			}
			else {
				speed -= 10;
			}

			break;
		case CAR_CONTROL::DOWN :
			if (speed >= BASE_SPEED + 60)
			{
				speed = BASE_SPEED + 60;
			}
			else {
				speed += 10;
			}

			break;
	}
}

void Statistic::setDistance()
{
	distance = (this->timeGame * (convertSpeed(this->speed) * 0.000277778));
}

void Statistic::setTime(int startTime)
{
	int endTime = clock();

	timeGame = (endTime - startTime) / CLK_TCK; 
}

int Statistic::getSpeed()
{
	return this->speed;
}

int Statistic::convertSpeed(int speed)
{
	int baseSpeedReal = BASE_SPEED + 20; // Conditionally 20 km/h.
	
	for (int i = speed; i >= 0; i -= 10)
	{
		baseSpeedReal -= 10;
	}

	return baseSpeedReal;
}

void Statistic::viewStatistic()
{ 
	setDistance();

	cout << "Time: " << (timeGame / 60 / 60) << ":" << (timeGame / 60) << ":" << (timeGame % 60) << endl;
	cout << "Speed: " << convertSpeed(speed) << " km" << endl;
	cout << "Distance: " << round(distance * 100) / 100. << " km"<< endl;
}

Statistic::~Statistic()
{
}
