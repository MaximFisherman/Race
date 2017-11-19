#ifndef __ROAD_COMMAND_H__
#define __ROAD_COMMAND_H__

#include "Road.h"
#include "Statistic.h"

class RoadCommand :
	public Road
{
public:
	RoadCommand();

	void turnLeft();
	void turnRight();
	void turnDown();
	void turnUp();

	void setBlockOppositeLine();
	void setBlockRoadLine();
	void setDifficult(int _difficult);

	void viewRoad();
	void clearRoad();

	bool isFail(global::CAR_CONTROL carControll);

	bool saveGame(Statistic* statistic);
	bool startSaveGame();
	~RoadCommand();
};

#endif