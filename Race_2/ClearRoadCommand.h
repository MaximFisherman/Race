#ifndef __CLEAR_ROAD_COMMAND_H__
#define __CLEAR_ROAD_COMMAND_H__

#include "Command.h"

class ClearRoadCommand :
	public Command
{
public:
	ClearRoadCommand(RoadCommand& _roadCommand);

	void Execute();

	~ClearRoadCommand();
};

#endif