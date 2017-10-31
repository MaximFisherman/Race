#include "stdafx.h"
#include "Statistic.h"


Statistic::Statistic()
{
	timeGame = 0;
	speed = BASE_SPEED;
	distance = 0;
}

void Statistic::setCurrent(State* state)
{
	this->state = state;
}

int Statistic::getDistance()
{
	return distance;
}

void Statistic::setSpeed(CAR_CONTROL carControll)
{
	switch (carControll) {
	case CAR_CONTROL::UP:
		if (speed <= 0)
		{
			speed = 0;
		}
		else {
			speed -= INCREASE_SPEED;
		}

		break;
	case CAR_CONTROL::DOWN:
		if (speed >= BASE_SPEED)
		{
			speed = BASE_SPEED;
		}
		else {
			speed += INCREASE_SPEED;
		}

		break;
	}
}

void Statistic::setDistance()
{
	distance = (this->timeGame * (convertSpeed(this->speed) * KILOMETR_PER_SECOND));
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

	for (int i = speed; i >= 0; i -= INCREASE_SPEED)
	{
		baseSpeedReal -= INCREASE_SPEED;
	}

	return baseSpeedReal;
}

void Statistic::viewStatistic(bool isView)
{
	if (isView == true)
	{
		setDistance();

		cout << "Time: " << (timeGame / CONVERT_TIME / CONVERT_TIME) << ":" << (timeGame / CONVERT_TIME) << ":" << (timeGame % CONVERT_TIME) << endl;
		cout << "Speed: " << convertSpeed(speed) << " km" << endl;
		cout << "Distance: " << round(distance * 100) / 100. << " km" << endl;
	}
	else{
		system("cls");
		cout << "for open statistic press 'TAB'";
	}
	
}

bool Statistic::isView()
{
	if(state->View() == true)
		return true;

	if(state->Clear() == true)
		return false;
}

Statistic::~Statistic()
{
}