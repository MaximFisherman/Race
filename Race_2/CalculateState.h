#ifndef __VIEW_H__
#define __VIEW_H__

#include "State.h"
#include "Statistic.h"

class CalculateState :
	public State
{
public:
	CalculateState(Statistic* _statistic);

	bool View();
	bool Clear();

	~CalculateState();

private: 
	Statistic* statistic;
};

#endif