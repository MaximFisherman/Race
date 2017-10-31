#ifndef __VIEW_H__
#define __VIEW_H__

#include "State.h"
class CalculateState :
	public State
{
public:
	CalculateState(Statistic& statistic);

	bool View();
	bool Clear();

	~CalculateState();

private: 
	Statistic statistic;
};

#endif