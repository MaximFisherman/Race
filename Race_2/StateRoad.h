#ifndef __STATE_ROAD_H__
#define __STATE_ROAD_H__

class StateRoad
{
public:
	StateRoad();

	virtual bool sixLineRoad() = 0;
	virtual bool fourLineRoad() = 0;

	virtual ~StateRoad();
};

#endif