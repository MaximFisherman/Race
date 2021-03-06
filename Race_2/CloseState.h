#ifndef __CLOSE_STATE_H__
#define __CLOSE_STATE_H__

#include "StateView.h"
#include "Statistic.h"

class CloseState :
	public StateView
{
public:
	CloseState(const Statistic& _statistic);

	bool View();
	bool Clear();

	~CloseState();

private:
	Statistic* statistic;
};

#endif
