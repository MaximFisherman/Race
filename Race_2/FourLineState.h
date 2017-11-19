#ifndef __FOUR_LINE_STATE_H__
#define __FOUR_LINE_STATE_H__

#include "StateRoad.h"
#include "Road.h"

class FourLineState :
	public StateRoad
{
public:
	FourLineState(const Road& _road);

	bool fourLineRoad();
	bool sixLineRoad();

	~FourLineState();
private: 
	Road* road;
};

#endif