#ifndef __VIEW_ROAD_COMMAND_H__
#define __VIEW_ROAD_COMMAND_H__

#include "Command.h"

class ViewRoadCommand : 
	public Command
{
public:
	ViewRoadCommand(RoadCommand& _roadCommand);

	void Execute();

	~ViewRoadCommand();
};

#endif