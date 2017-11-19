#ifndef __SIX_LINE_STATE_H__
#define __SIX_LINE_STATE_H__

#include "StateRoad.h"
#include "Road.h"

class SixLineState :
	public StateRoad
{
public:
	SixLineState(const Road& _road);

	bool fourLineRoad();
	bool sixLineRoad();

	~SixLineState();

private: 
	Road* road;
};

#endif