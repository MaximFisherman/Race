#ifndef __VIEW_ROAD_COMMAND_H__
#define __VIEW_ROAD_COMMAND_H__

#include "Command.h"

class ViewRoadCommand : 
	public Command 
{
public:
	ViewRoadCommand(Road& road);

	void Execute();

	~ViewRoadCommand();
};

#endif