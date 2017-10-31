#ifndef __SET_BLOCKS_ON_ROAD_COMMAND_H__
#define __SET_BLOCKS_ON_ROAD_COMMAND_H__

#include "Command.h"

class SetBloksOnRoadCommand : 
	public Command
{
public:
	SetBloksOnRoadCommand(Road& road);

	void Execute();

	~SetBloksOnRoadCommand();
};

#endif
