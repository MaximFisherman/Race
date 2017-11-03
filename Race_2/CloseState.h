#ifndef __CLOSE_STATE_H__
#define __CLOSE_STATE_H__

#include "State.h"
#include "Statistic.h"

class CloseState :
	public State
{
public:
	CloseState(const Statistic& _statistic);

	bool View();
	bool Clear();

	~CloseState();

private:
	Statistic statistic;
};

#endif
