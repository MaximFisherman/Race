#ifndef __OPEN_STATE_H__
#define __OPEN_STATE_H__

#include "StateView.h"
#include "Statistic.h"

class OpenState :
	public StateView
{

public:
	OpenState(const Statistic& _statistic);

	bool View();
	bool Clear();

	~OpenState();

private:
	Statistic* statistic;
};

#endif