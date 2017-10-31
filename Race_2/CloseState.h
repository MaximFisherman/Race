#ifndef __CLOSE_STATE_H__
#define __CLOSE_STATE_H__

#include "State.h"

class CloseState :
	public State
{
public:
	CloseState(Statistic& _statistic);

	bool View();
	bool Clear();

	~CloseState();

private:
	Statistic statistic;
};

#endif
