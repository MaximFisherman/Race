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
	void setSizeRoad(int _height, int _width);

	void viewRoad();
	void clearRoad();

	bool isFail(global::CAR_CONTROL carControll);

	void saveGame(Statistic* statistic);
	void startSaveGame();
	~RoadCommand();
};

#endif