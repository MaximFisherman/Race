#include "stdafx.h"
#include "Statistic.h"


Statistic::Statistic()
{
	timeGame = 0;
	speed = global::BASE_SPEED;
	distance = 0;
}

void Statistic::setView(const State* _state)
{
	this->state = const_cast<State*> (_state); 
}

double Statistic::getDistance()
{
	return distance;
}

int Statistic::getTime()
{
	return timeGame;
}

int Statistic::convertToMinutes(int time)
{
	return (time / global::CONVERT_TIME);
}

int Statistic::convertToHour(int time)
{
	return (time / global::CONVERT_TIME / global::CONVERT_TIME);
}

int Statistic::convertToSecond(int time)
{
	return (time % global::CONVERT_TIME);
}

void Statistic::setSpeed(global::CAR_CONTROL carControll)
{
	switch (carControll) {
		case global::CAR_CONTROL::UP:
			if (speed <= 0)
			{
				speed = 0;
			}
			else {
				speed -= global::INCREASE_SPEED;
			}

			break;
		case global::CAR_CONTROL::DOWN:
			if (speed >= global::BASE_SPEED)
			{
				speed = global::BASE_SPEED;
			}
			else {
				speed += global::INCREASE_SPEED;
			}

			break;
	}
}

void Statistic::setDistance()
{
	distance = (this->timeGame * (convertSpeed(this->speed) * global::KILOMETR_PER_SECOND));
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
	int baseSpeedReal = global::BASE_SPEED + 20; // Conditionally 20 km/h.

	for (int i = speed; i >= 0; i -= global::INCREASE_SPEED)
	{
		baseSpeedReal -= global::INCREASE_SPEED;
	}

	return baseSpeedReal;
}

void Statistic::viewStatistic(bool isView)
{
	if (isView)
	{
		setDistance();

		cout << "Time: " << convertToHour(timeGame)  << ":" << convertToMinutes(timeGame) << ":" << convertToSecond(timeGame) << endl;
		cout << "Speed: " << convertSpeed(speed) << " km" << endl;
		cout << "Distance: " << round(distance * 100) / 100. << " km" << endl; // Rounding to hundredths. 
	}
	else{
		system("cls");
		cout << "for open statistic press 'TAB'";
	}
	
}

bool Statistic::isView()
{
	if (state->View() == true && state->Clear() == false)
	{
		return true;
	}
	else{ 
		return false;
	}
}

Statistic::~Statistic()
{
}